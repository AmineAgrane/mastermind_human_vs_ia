enum 
{
	// Nombre de pions dans la combinaison
	NB_PIONS=4,

	//Nombre d'essais autorisés pour trouver la combinaison
	NB_ESSAIS=8  
};

// Pour déterminer le nombre de pions biens et mal placés dans la combinaison donnée en entrée.
void well_placed(const int combi_a_deviner[], int combi_joueur[], int *bien_place, int *mal_place);

// Jeu en mode classique
void jeu_classique(int combi_a_deviner[], int combi_joueur[], int trouve);

// Jeu en mode automatique (Intelligence artificielle)
void resolution_automatique(int combi_a_deviner[], int combi_joueur[]);

// Génération de nombre pseudos aléatoires pour créer les combinaisons
int random_number(int nb_pions);



