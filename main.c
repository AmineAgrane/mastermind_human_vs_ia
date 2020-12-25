#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "params.h"

// Détermine le nombre de pions qui sont bien placés et
// le nombre de pions existant mais mal placés dans la combinaison combi_joueur
void well_placed(const int combi_a_deviner[], int combi_joueur[], int *bien_place, int *mal_place)
{	
	int j, k;
	int combi_temporaire[NB_PIONS], combi_tentative[NB_PIONS];


	for (j=0 ; j<NB_PIONS ; j++) {
		combi_temporaire[j]=combi_a_deviner[j];
		combi_tentative[j]=combi_joueur[j];
	}

	*bien_place = 0;
	*mal_place = 0;

	for (j=0 ; j<NB_PIONS ; j++) {
		// Si un pion proposé est similaire à celui de la combinaison à deviner
		if (combi_temporaire[j]==combi_tentative[j]) {
			//C'est un pion bien placé
			(*bien_place)++; 
			combi_temporaire[j]=999; 

			//On saura que le pion est déjà pris en compte dans le test
			combi_tentative[j]=999;
		}
	}
	for (j=0 ; j<NB_PIONS ; j++) {
		//On vérifie que le pion n'a pas déjà été traité
		if (combi_tentative[j]!=999 && combi_tentative[j]!=997) {

			for(k=0 ; (k<NB_PIONS)  && (combi_tentative[j] != 997) ; k++) {

				//Si le pion proposé est similaire à un des pions de la combinaison pas encore traité
				if(combi_tentative[j] == combi_temporaire[k]) {
					(*mal_place)++; //Pion qui existe dans la combinaison mais est mal placé
					combi_tentative[j]=997; //On saura que le pion est déjà pris en compte dans le test
					combi_temporaire[k]=997;
				}
			}
		}
	}
}



// Retourne un nombre aléatoire entre [0, nb_pions-1] 
int random_number(int nb_pions) {
    return (rand()%nb_pions); 
}


int main(void)
{
	//(1 : classique, 2 : résolution automatique)
	int mode;          

	// Combinaison secrète à deviner
	int combi_a_deviner[NB_PIONS];	

	// Combinaison proposée par le joueur
	int combi_joueur[NB_PIONS];	

	// True quand la combinaison aura été trouvée	
	int trouve = 0;	

	int i;
	srand( (unsigned int) time(NULL) );       


    /************** Regles du jeu **************/ 
	printf("\n\n\n\t\t\t\t MASTER MIND\n\n\n\n");
	printf("Regles du Jeu : vous devez trouver la combinaison que l'ordinateur ");
    printf("a genere\n\t\ten un plus petit nombre de coups possibles.");
	printf("\n\n\n\tParametres actuels : \t%i essais", NB_ESSAIS);
	printf("\n\t\t\t\t%i pions dans la combinaison\n\n\n", NB_PIONS);


    /************** Génération combinaison aléatoire **************/ 
	for (i=0 ; i<NB_PIONS ; i++) {
		combi_a_deviner[i]=random_number(NB_PIONS);
		combi_joueur[i]=0;
	}
	
	/************** Choix manuel de la combinaison **************/ 
	//combi_joueur[0]=0;
	//combi_joueur[1]=1;
	//combi_joueur[2]=0;
	//combi_joueur[3]=4;
	//combi_joueur[4]=2;


	/************** Choix du mode de jeu **************/
	printf("\nDans quel mode voulez vous lancer le jeu ?\n\n");
	printf("\t 1 - Jeu contre l'ordinateur\n");
	printf("\t 2 - Resolution automatique\n");
	printf("\n Choix : ");
	scanf("%d", &mode);

	switch (mode) {
		case 1 : jeu_classique(combi_a_deviner, combi_joueur, trouve);
				 break;
		case 2 : resolution_automatique(combi_a_deviner, combi_joueur);         
				 break;
		default : printf("\nMauvais choix !");
				  break;
	}

    /************** On sort du programme **************/
	printf("\n\n\tAppuyez sur une touche pour quitter le jeu");
	fflush (stdin);
	getchar();
	return 0;

}


