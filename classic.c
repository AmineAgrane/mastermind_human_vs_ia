#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "params.h"

void jeu_classique (int combi_a_deviner[], int combi_joueur[], int trouve)
{
	int i, j;
    int bien_place=0;	//Nombre de pions bien placés
	int mal_place=0;	//Nombre de pions présents dans la combinaison mais mal placés
	int tentative;
     
	//////// DEBUT DE LA PARTIE //////////////////////
	for (i=0 ; i<NB_ESSAIS && trouve==0 ; i++)
	{
		printf("\n\n\t\t\tTentative %d : ", i+1);
		fflush (stdin);
	    scanf("%d", &tentative);
		for (j=NB_PIONS ; j>0 ; j--)
		{
			combi_joueur[j-1]=tentative % 10;
			tentative/=10;
		}

		well_placed(combi_a_deviner, combi_joueur, &bien_place, &mal_place);

		printf("\n\n\tBien places : %i", bien_place);
		printf("\n\tMal places  : %i", mal_place);

		if (bien_place == NB_PIONS)
		{
			trouve = 1;
		}		
	}
	///////////////////////////////////////////////////////////////////////////

	/////////////////// VERDICT... FIN DE LA PARTIE ///////////////////////////
	if (trouve == 1)
	{
		printf("\n\n\t\tBRAVO !\n\n");
		printf("\t\tVous avez trouve la combinaison en %i essais !", i);
	}

	else
	{
		printf("\n\n\t\t\tDESOLE !\n\n");
		printf("\t\tVous avez perdu !");
		printf("\n\n\t\tLa combinaison a deviner etait : ");
		for (i=0 ; i<NB_PIONS ; i++)
		{
			printf("%i", combi_a_deviner[i]);
		}
	}
	////////////////////////////////////////////////////////////////////////////
}
