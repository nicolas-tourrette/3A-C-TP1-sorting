/*******************************************
    Programme   : comparaison
    Fichier     : performances.h
    Objectif    : Prototypes des fonctions utilisées et types de données pour les mesures de performances
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 13-01-2019
    Version     : V1.1
********************************************/

#ifndef PERFORMANCES_H
#define PERFORMANCES_H

#include "events.h"

typedef struct perf{
    char algorithme[14] ;
    int comparaison, echange ;
    double temps_execution ;
} perf ;

void reset_performances() ;
perf save_performances(char algorithme[]) ;
void print_performances(perf performances) ;
void record_performances(perf performances, double ecart_type) ;
void moyenne(perf tableau_performances[], int taille) ;

#endif
