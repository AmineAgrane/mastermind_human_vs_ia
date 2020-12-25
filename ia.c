#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "params.h"

void resolution_automatique (int combi_a_deviner[], int combi_joueur[])
{
    int bien_place=0;	//Nombre de pions bien plac�s
	int mal_place=0;	//Nombre de pions pr�sents dans la combinaison mais mal plac�s
    int nb_tentative=0;
    int i, j, k;
    int temp=-1,drap=-1;
    int nbi=-1;  
    int nombre_deja_trouve=0;
    int combi_temp[NB_PIONS];
    int combi_trouve[NB_PIONS];

    // Initialisation des tableaux � -1
	for (i=0 ; i<NB_PIONS ; i++) {
		combi_temp[i]=-1;
		combi_trouve[i]=-1;
	}

    printf("\nLa combinaison a deviner est la suivante : ");
	for (j=0 ; j<NB_PIONS ; j++) printf(" %d ", combi_a_deviner[j]);
    printf("\nDebut de la resolution automatique...");

//Pour chaque couleur
for (i=0 ; i<NB_PIONS ; i++) {
    //Si solution non trouv�e et encore des essais possibles
	if(bien_place != NB_PIONS) {
        printf("\nOn affecte tous les pions pas encore trouves a ''%i'' (la couleur en cours).",i);
        printf("\nCombinaison testee : ");
		//On affecte tous les pions pas encore trouv�s � "i" (la couleur en cours)
        for (j=0 ; j < NB_PIONS ; j++)
		{
			if (combi_trouve[j] == -1)   combi_joueur[j]=i;
			printf("%i", combi_joueur[j]);
        }

        //On teste cette solution pour connaitre le nombre de pions bien et mal plac�s
		well_placed(combi_a_deviner, combi_joueur, &bien_place, &mal_place);
        nb_tentative++;
        printf("\n\nBien places : %i ; Mal places  : %i", bien_place, mal_place);

        //Nombre d'occurence de la couleur en cours ("i")
		nbi = bien_place - nombre_deja_trouve;
        printf("\nNombre d'occurence de la couleur %i : %i\n", i, nbi);
		
        //Tant que tous les pions de couleur i ne sont pas bien plac�s...
		while (nbi > 0) {
                printf("\nTant que tous les pions de couleur i ne sont pas bien places...");
                temp=-1;
                drap=-1;
                
                for(k=0 ; k<NB_PIONS ; k++)   combi_temp[k]=combi_trouve[k];
                
                //Tant que le pion de couleur i courant est mal plac�...
                do {   
                    //Si on a d�j� test� une position non valable
        			if ( temp != -1 ) {
                        printf("\nOn deplace d'un cran le pion dont on cherche la position.");
                    	combi_joueur[temp] = i+1;
        				combi_temp[temp]=-1;
        				drap=-1;
                    }
        				for (j=(temp+1) ; j < NB_PIONS ; j++) {   
                            //Si le pion courant est d�j� connu,
                            if (combi_trouve[j] != -1) {
                               //On le copie dans la combinaison � la bonne position.
                               combi_joueur[j] = combi_trouve[j];
                            }
        						
        					else if (drap==-1) {
        						combi_joueur[j]=i;
        						combi_temp[j]=i;
                                temp=j;
                                drap=0;
        					}	
        					
        					else {
                                   combi_joueur[j]=i+1;
                            }
                        }   
                            printf("\nCombinaison testee : ");
                            for (k=0 ; k<NB_PIONS ; k++) printf("%i", combi_joueur[k]);
        					well_placed(combi_a_deviner, combi_joueur, &bien_place, &mal_place);
        					nb_tentative++;
        					printf("\n\nBien places : %i ; Mal places  : %i", bien_place, mal_place);
        	
     			} while ( mal_place != 0);
            
                for (j=0 ; j<NB_PIONS ; j++)  {
                    combi_trouve[j]=combi_temp[j];
                }
                nombre_deja_trouve++;
                nbi--;
    	}
     }
}
if(bien_place == NB_PIONS)   printf("\n\n\t\tL'ordinateur a trouve la combinaison en %i essais !", nb_tentative);
}
