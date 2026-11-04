
#include <pthread.h>
#include "sync_car.h"

void station_init(struct station *station) {

    station->passageiros_esperando = 0;
    station->lugares_livres = 0;
    station->aguardando_embarcar = 0;

    pthread_mutex_init(&station->mutex, NULL);

    pthread_cond_init(&station->embarque_liberado, NULL);
    pthread_cond_init(&station->terminou_embarque, NULL);

}

void station_load_car(struct station *station, int count) {

    
    station->lugares_livres = count;
    
    pthread_cond_broadcast(&station->embarque_liberado);
    
    pthread_mutex_lock(&station->mutex);

    while ((station->passageiros_esperando > 0 && station->lugares_livres > 0) || station->aguardando_embarcar > 0) {

        pthread_cond_wait(&station->terminou_embarque, &station->mutex);
    }

    pthread_mutex_unlock(&station->mutex);
    
    station->lugares_livres = 0;

}

void station_wait_for_car(struct station *station) {

    pthread_mutex_lock(&station->mutex);

    station->passageiros_esperando++;

    while (station->lugares_livres == 0) {
        pthread_cond_wait(&station->embarque_liberado, &station->mutex);
    }

    station->passageiros_esperando--;
    station->lugares_livres--;
    station->aguardando_embarcar++;

    pthread_mutex_unlock(&station->mutex);
    
}


void station_on_board(struct station *station) {

    station->aguardando_embarcar--;

    pthread_cond_signal(&station->terminou_embarque);

}