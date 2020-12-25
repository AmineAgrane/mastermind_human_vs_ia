enum 
{
	// Nombre de pions dans la combinaison
	NB_PIONS=4,

	//Nombre d'essais autoris�s pour trouver la combinaison
	NB_ESSAIS=8  
};

// Pour d�terminer le nombre de pions biens et mal plac�s dans la combinaison donn�e en entr�e.
void well_placed(const int combi_a_deviner[], int combi_joueur[], int *bien_place, int *mal_place);

// Jeu en mode classique
void jeu_classique(int combi_a_deviner[], int combi_joueur[], int trouve);

// Jeu en mode automatique (Intelligence artificielle)
void resolution_automatique(int combi_a_deviner[], int combi_joueur[]);

// G�n�ration de nombre pseudos al�atoires pour cr�er les combinaisons
int random_number(int nb_pions);



