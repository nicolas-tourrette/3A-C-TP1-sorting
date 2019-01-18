/*******************************************
    Programme   : comparaison
    Fichier     : events.h
    Objectif    : Prototypes des fonctions utilisées et types de données
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 12-01-2019
    Version     : V1.3
********************************************/

#ifndef EVENTS_H
#define EVENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct date{
    int day ;
    char month[10] ;
    int year ;
} date ;

typedef struct event{
    char description[128] ;
    date date_of_event ;
} event ;

void create_events(int n, event tableau_evenements[]) ;
void display_events(int n, event tableau_evenements[]) ;
int compare_events(event e1, event e2) ;
void swap_events(event tableau_evenements[], int index1, int index2) ;
void basic_sort(int n, event tableau_evenements[]) ;
void selection_sort(int n, event tableau_evenements[]) ;
void bubble_sort(int n, event tableau_evenements[]) ;
void insertion_sort(int n, event tableau_evenements[]) ;
int partition(event tableau_evenements[], int debut, int fin) ;
void quick_sort(event tableau_evenements[], int debut, int fin) ;

#endif
