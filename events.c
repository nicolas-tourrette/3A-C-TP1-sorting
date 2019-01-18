/*******************************************
    Programme   : comparaison
    Fichier     : events.c
    Objectif    : Implémentation des fonctions de events.h
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 12-01-2019
    Version     : V1.3
********************************************/

#include "events.h"

// On déclare le tableau global pour les mois de l'année
char tableau_mois[12][10] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"} ;

// Variables globales pour la mesure de performances, déclarées dans performances.c
extern int nombre_comparaison ;
extern int nombre_echange ;
extern clock_t t_debut ;
extern clock_t t_fin ;

/*
    create_events        : remplit un tableau d'événements
    @n                   : nombre d'événements à créer
    @tableau_evenements  : tableau contenant les événements
*/
void create_events(int n, event tableau_evenements[]){
    int jour, mois, annee ;
    char tmp[20] ;
    for(int i=0 ; i<n ; i++){
        jour = rand()%30+1 ;
        mois = rand()%11 ;
        annee = rand()%2018 ;
        tableau_evenements[i].date_of_event.day = jour ;
        strcpy(tableau_evenements[i].date_of_event.month, tableau_mois[mois]) ;
        tableau_evenements[i].date_of_event.year = annee ;
        sprintf(tmp, "Event-%d%d%d", annee, mois+1, jour) ;
        strcpy(tableau_evenements[i].description, tmp) ;
    }
}

/*
    display_events       : affiche un tableau d'événements
    @n                   : nombre d'événements à créer
    @tableau_evenements  : tableau contenant les événements
*/
void display_events(int n, event tableau_evenements[]){
    for(int i=0 ; i<n ; i++){
        printf("%s : %d %s %d\n", tableau_evenements[i].description, tableau_evenements[i].date_of_event.day, tableau_evenements[i].date_of_event.month, tableau_evenements[i].date_of_event.year) ;
    }
}

/*
    FindMonth   : renvoie l'indice du mois dans tableau_mois
    @evenement  : événement dont on cherche le mois décimal
*/
int FindMonth(event evenement){
    int i = 0 ;
    while(strcmp(tableau_mois[i],evenement.date_of_event.month) != 0){
        i++ ;
    }
    return i ;
}

/*
    compare_events  : compare deux événements et retourne une valeur entière
    @e1, @e2        : les deux événements à comparer
    retourne        :   - si e1 plus récent que e2     1
                        - si e1 identique à e2         0
                        - si e1 plus ancien que e2    -1
*/
int compare_events(event e1, event e2){
    nombre_comparaison++ ;
    if(e1.date_of_event.year > e2.date_of_event.year){
        return 1 ;
    }
    else if(e1.date_of_event.year < e2.date_of_event.year){
        return -1 ;
    }
    else{
        if(FindMonth(e1) > FindMonth(e2)){
            return 1 ;
        }
        else if(FindMonth(e1) < FindMonth(e2)){
            return -1 ;
        }
        else{
            if(e1.date_of_event.day > e2.date_of_event.day){
                return 1 ;
            }
            else if(e1.date_of_event.day < e2.date_of_event.day){
                return -1 ;
            }
            else{
                return 0 ;
            }
        }
    }
}

/*
    swap_events             : échange deux événements du tableau d'événements
    @index1, @index2        : index des positions des événements à échanger
    @tableau_evenements     : tableau contenant les événements
*/
void swap_events(event tableau_evenements[], int index1, int index2){
    event tmp = tableau_evenements[index1] ;
    tableau_evenements[index1] = tableau_evenements[index2] ;
    tableau_evenements[index2] = tmp ;
    nombre_echange++ ;
}

/*
    basic_sort           : trie un tableau d'événements suivant l'algorithme BASIC SORT par ordre croissant
    @n                   : nombre d'événements du tableau d'événements
    @tableau_evenements  : tableau contenant les événements à trier
*/
void basic_sort(int n, event tableau_evenements[]){
    //int compteur_echange = 0 ;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            if(compare_events(tableau_evenements[i], tableau_evenements[j]) == 1){
                swap_events(tableau_evenements, i, j) ;
            }
        }
    }
}

/*
    selection_sort       : trie un tableau d'événements suivant l'algorithme SELECTION SORT par ordre croissant
    @n                   : nombre d'événements du tableau d'événements
    @tableau_evenements  : tableau contenant les événements à trier
*/
void selection_sort(int n, event tableau_evenements[]){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(compare_events(tableau_evenements[i], tableau_evenements[j]) == 1){
				swap_events(tableau_evenements, i, j) ;
			}
		}
	}
}

/*
    bubble_sort          : trie un tableau d'événements suivant l'algorithme BUBBLE SORT par ordre croissant
    @n                   : nombre d'événements du tableau d'événements
    @tableau_evenements  : tableau contenant les événements à trier
*/
void bubble_sort(int n, event tableau_evenements[]){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=0 ; j<n-i-1 ; j++){
			if(compare_events(tableau_evenements[j], tableau_evenements[j+1]) == 1){
				swap_events(tableau_evenements, j, j+1) ;
			}
		}
	}
}

/*
    insertion_sort       : trie un tableau d'événements suivant l'algorithme INSERTION SORT par ordre croissant
    @n                   : nombre d'événements du tableau d'événements
    @tableau_evenements  : tableau contenant les événements à trier
*/
void insertion_sort(int n, event tableau_evenements[]){
    event a_echanger ;
    int j ;
    for(int i=1 ; i<n ; i++){
		a_echanger = tableau_evenements[i] ;
		j = i-1 ;
		while((compare_events(a_echanger, tableau_evenements[j]) == -1) && (j >= 0)){
			tableau_evenements[j+1] = tableau_evenements[j];
            nombre_echange++ ;
			j--;
		}
		tableau_evenements[j+1] = a_echanger ;
    }
}

/*
    partition            : partitionne le tableau en définissant un pivot et échange les éléments par rapport à lui, afin que tous ceux à gauche soient plus anciens et tous ceux à droite soient plus récent que l'événement pivot
    quick_sort           : trie un tableau d'événements suivant l'algorithme QUICK SORT par ordre croissant
    @tableau_evenements  : tableau contenant les événements à trier
    @debut               : indice de départ du tri, pris pour pivot
    @fin                 : indice de fin du tri
    Code issu de http://www.dailly.info/ressources/tri/c/rapide.html. Ce code a été modifié et adapté pour l'utilisation dans ce programme.
*/
int partition(event tableau_evenements[], int debut, int fin){
    int compteur = debut ;
    // On prend le premier élément du tableau comme pivot (choix arbitraire)
    for(int i=debut+1 ; i<=fin ; i++){
        if(compare_events(tableau_evenements[i], tableau_evenements[debut]) == -1){
            compteur++ ;
            swap_events(tableau_evenements, compteur, i) ;
        }
    }
    swap_events(tableau_evenements, compteur, debut) ;
    return(compteur) ;
}
void quick_sort(event tableau_evenements[], int debut, int fin){
    if(debut < fin){
        int pivot = partition(tableau_evenements,debut,fin) ;
        quick_sort(tableau_evenements,debut,pivot-1) ;
        quick_sort(tableau_evenements,pivot+1,fin) ;
    }
}
