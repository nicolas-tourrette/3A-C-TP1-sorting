/*******************************************
    Programme   : comparaison
    Fichier     : main.c ## MAINFILE
    Objectif    : comparer différents types de données
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 12-01-2019
    Version     : V1.4
********************************************/

//#include "events.h"
#include "performances.h"

extern int nombre_comparaison ;
extern int nombre_echange ;
extern clock_t t_debut ;
extern clock_t t_fin ;

int main(){
    srand(time(NULL)) ; // On initialise la fonction rand à NULL pour la génération aléatoire dans create_events()
    // On déclare un tableau de cinq élément qu'on remplira pour tester nos algorithmes de tri
    int n=5 ;
    event mon_tableau[n] ;
    create_events(n, mon_tableau) ;
    printf("On crée un tableau d'événements de %d événements :\n", n) ;
    display_events(n, mon_tableau) ;
    // Test des algorithmes de tri. On regénère un nouveau tableau à trier à chaque algorithme testé.
    printf("\nOn trie le tableau par BASIC SORT :\n") ;
    create_events(n, mon_tableau) ;
    basic_sort(n, mon_tableau) ;
    display_events(n, mon_tableau) ;
    printf("\nOn trie le tableau par SELECTION SORT :\n") ;
    create_events(n, mon_tableau) ;
    selection_sort(n, mon_tableau) ;
    display_events(n, mon_tableau) ;
    printf("\nOn trie le tableau par BUBBLE SORT :\n") ;
    create_events(n, mon_tableau) ;
    bubble_sort(n, mon_tableau) ;
    display_events(n, mon_tableau) ;
    printf("\nOn trie le tableau par INSERTION SORT :\n") ;
    create_events(n, mon_tableau) ;
    insertion_sort(n, mon_tableau) ;
    display_events(n, mon_tableau) ;
    printf("\nOn trie le tableau par QUICK SORT :\n") ;
    create_events(n, mon_tableau) ;
    quick_sort(mon_tableau, 0, n-1) ;
    display_events(n, mon_tableau) ;

    /*
        ==== PARTIE MESURE DE PERFORMANCES ===
        Dans cette partie, on mesure les performances des algorithmes de tri en faisant 100 tris sur des tableaux de grande taille.
        @iterations_nb      : nombre de tri à réaliser
        @tableau_taille     : différentes tailles à tester
        @resultats_finaux   : résultats escomptés avec la moyenne et l'écart-type
    */

    int iterations_nb = 100 ;

    int nombre_taille = 5 ;
    int tableau_taille[7] = {100,200,500,1000,2000,5000,10000} ;

    reset_performances() ;
    perf resultat[iterations_nb] ;

    // Mesure de performances pour l'algorithme de tri BASIC_SORT
    printf("\n===  Mesure des performances de l'algorithme BASIC_SORT  ===\n") ;
    for(int i=0 ; i<nombre_taille ; i++){
        printf("On trie %d fois un tableau de %d événements.\n", iterations_nb, tableau_taille[i]) ;
        event mon_tableau[tableau_taille[i]] ;
        for(int j=0 ; j<iterations_nb ; j++){
            create_events(tableau_taille[i], mon_tableau) ;
            reset_performances() ;
            t_debut = clock() ;
            basic_sort(tableau_taille[i], mon_tableau) ;
            t_fin = clock() ;
            resultat[j] = save_performances("BASIC_SORT") ;
        }
    }
    moyenne(resultat, iterations_nb) ;

    // Mesure de performances pour l'algorithme de tri SELECTION_SORT
    printf("\n===  Mesure des performances de l'algorithme SELECTION_SORT  ===\n") ;
    reset_performances() ;
    for(int i=0 ; i<nombre_taille ; i++){
        printf("On trie %d fois un tableau de %d événements.\n", iterations_nb, tableau_taille[i]) ;
        event mon_tableau[tableau_taille[i]] ;
        for(int j=0 ; j<iterations_nb ; j++){
            create_events(tableau_taille[i], mon_tableau) ;
            reset_performances() ;
            t_debut = clock() ;
            selection_sort(tableau_taille[i], mon_tableau) ;
            t_fin = clock() ;
            resultat[j] = save_performances("SELECTION_SORT") ;
        }
    }
    moyenne(resultat, iterations_nb) ;

    // Mesure de performances pour l'algorithme de tri BUBBLE_SORT
    printf("\n===  Mesure des performances de l'algorithme BUBBLE_SORT  ===\n") ;
    reset_performances() ;
    for(int i=0 ; i<nombre_taille ; i++){
        printf("On trie %d fois un tableau de %d événements.\n", iterations_nb, tableau_taille[i]) ;
        event mon_tableau[tableau_taille[i]] ;
        for(int j=0 ; j<iterations_nb ; j++){
            create_events(tableau_taille[i], mon_tableau) ;
            reset_performances() ;
            t_debut = clock() ;
            bubble_sort(tableau_taille[i], mon_tableau) ;
            t_fin = clock() ;
            resultat[j] = save_performances("BUBBLE_SORT") ;
        }
    }
    moyenne(resultat, iterations_nb) ;

    // Mesure de performances pour l'algorithme de tri INSERTION_SORT
    printf("\n===  Mesure des performances de l'algorithme INSERTION_SORT  ===\n") ;
    reset_performances() ;
    for(int i=0 ; i<nombre_taille ; i++){
        printf("On trie %d fois un tableau de %d événements.\n", iterations_nb, tableau_taille[i]) ;
        event mon_tableau[tableau_taille[i]] ;
        for(int j=0 ; j<iterations_nb ; j++){
            create_events(tableau_taille[i], mon_tableau) ;
            reset_performances() ;
            t_debut = clock() ;
            insertion_sort(tableau_taille[i], mon_tableau) ;
            t_fin = clock() ;
            resultat[j] = save_performances("INSERTION_SORT") ;
        }
    }
    moyenne(resultat, iterations_nb) ;

    // Mesure de performances pour l'algorithme de tri QUICK_SORT
    printf("\n===  Mesure des performances de l'algorithme QUICK_SORT  ===\n") ;
    reset_performances() ;
    for(int i=0 ; i<nombre_taille ; i++){
        printf("On trie %d fois un tableau de %d événements.\n", iterations_nb, tableau_taille[i]) ;
        event mon_tableau[tableau_taille[i]] ;
        for(int j=0 ; j<iterations_nb ; j++){
            create_events(tableau_taille[i], mon_tableau) ;
            reset_performances() ;
            t_debut = clock() ;
            quick_sort(mon_tableau, 0, tableau_taille[i]-1) ;
            t_fin = clock() ;
            resultat[j] = save_performances("QUICK_SORT") ;
        }
    }
    moyenne(resultat, iterations_nb) ;

    return 0 ;
}
