#ifndef SYNC_CAR_H
#define SYNC_CAR_H

#include <pthread.h>

struct station {
    int passageiros_esperando;
    int lugares_livres;
    int aguardando_embarcar;

    pthread_mutex_t mutex;
    pthread_cond_t embarque_liberado;
    pthread_cond_t terminou_embarque;
};

void station_init(struct station *station);
void station_load_car(struct station *station, int count);
void station_wait_for_car(struct station *station);
void station_on_board(struct station *station);

#endif