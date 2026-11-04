
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


}

void station_wait_for_car(struct station *station) {


}

void station_on_board(struct station *station) {


}
