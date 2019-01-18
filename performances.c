/*******************************************
    Programme   : comparaison
    Fichier     : performances.c
    Objectif    : Implémentation des fonctions de performances.h
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 13-01-2019
    Version     : V1.1
********************************************/

#include "performances.h"

int nombre_comparaison = 0 ;
int nombre_echange = 0 ;
clock_t t_debut = 0 ;
clock_t t_fin = 0 ;


/*
    reset_performances : réinitialise les variables de mesure de performances
                         Utilise les variables globales définies en haut du programme.
*/
void reset_performances(){
    nombre_comparaison = 0 ;
    nombre_echange = 0 ;
    t_debut = 0 ;
    t_fin = 0 ;
}

/*
    save_performances   : enregistre dans un tableau les mesures de performances
    @algorithme         : algorithme concerné par l'analyse des performances
*/
perf save_performances(char algorithme[]){
    perf performances ;
    strcpy(performances.algorithme, algorithme) ;
    performances.comparaison = nombre_comparaison ;
    performances.echange = nombre_echange ;
    performances.temps_execution = t_fin - t_debut ;

    return performances ;
}

/*
    print_performance   : affiche la mesure des performances de l'algorithme de tri
    @performances       : structure de données de type perf pour le stockage de l'analyse des performances
*/
void print_performances(perf performances){
    printf("\n- Affichage des performances enregistrées :\n") ;
    printf("Algorithme utilisé                      : %s\n", performances.algorithme) ;
    printf("Nombre moyen de comparaisons effectuées : %d\n", performances.comparaison) ;
    printf("Nombre moyen d'échanges effectués       : %d\n", performances.echange) ;
    printf("Temps moyen d'exécution de l'algorithme : %f\n", performances.temps_execution) ;
}

/*
    moyenne                  : calcul de la moyenne des nombres de tris et d'échanges, du temps moyen et de l'écart-type de temps
    @tableau_performances    : tableau des résultats de l'analyse des performances pour calcul de ses moyennes et des écarts-types
*/
void moyenne(perf tableau_performances[], int taille){
    perf resultats_finaux ;
    double moyenne_temps = 0, moyenne_comparaisons = 0, moyenne_echanges = 0 ;

    for(int i=0 ; i<taille ; i++){
        moyenne_comparaisons += tableau_performances[i].comparaison ;
        moyenne_echanges += tableau_performances[i].echange ;
        moyenne_temps += tableau_performances[i].temps_execution ;
    }

    strcpy(resultats_finaux.algorithme, tableau_performances[0].algorithme) ;
    resultats_finaux.comparaison = moyenne_comparaisons/taille ;
    resultats_finaux.echange = moyenne_echanges/taille ;
    resultats_finaux.temps_execution = moyenne_temps/taille ;

    double ecart_type_temps = 0 ;
    for(int i=0 ; i<taille ; i++){
        ecart_type_temps += (tableau_performances[i].temps_execution - resultats_finaux.temps_execution)*(tableau_performances[i].temps_execution - resultats_finaux.temps_execution) ;
    }
    ecart_type_temps = sqrt(ecart_type_temps/taille) ;

    print_performances(resultats_finaux) ;
    printf("L'écart-type de temps de cette série de mesure est %f.\n", ecart_type_temps) ;
    record_performances(resultats_finaux, ecart_type_temps) ;
}

void record_performances(perf performances, double ecart_type){
    char filename[50] = "recorded_performances_" ;
    strcat(filename, performances.algorithme) ;
    FILE* fichier = fopen(filename, "a") ;
    if(fichier != NULL){
        fprintf(fichier, "Algorithme utilisé                                    : %s\n", performances.algorithme) ;
        fprintf(fichier, "Nombre moyen de comparaisons effectuées               : %d\n", performances.comparaison) ;
        fprintf(fichier, "Nombre moyen d'échanges effectués                     : %d\n", performances.echange) ;
        fprintf(fichier, "Temps moyen d'exécution de l'algorithme               : %f\n", performances.temps_execution) ;
        fprintf(fichier, "Ecart-type du temps moyen d'exécution de l'algorithme : %f\n\n", ecart_type) ;
    }
    else{
        printf("/!\\ ERREUR /!\\\nLe fichier de sauvegarde n'a pas pu être ouvert correctement...");
    }
    fclose(fichier) ;
}
