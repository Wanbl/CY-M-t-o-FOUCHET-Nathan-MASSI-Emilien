#include "header.h"

pArbre creerABRhumid(int station, int humid, float longi, float lati){	//Crée l'arbre si il n'y en a pas
	pArbre nouveau = malloc(sizeof(Arbre));
	nouveau->equ = 0;
	
	nouveau->station = station;
	nouveau->longi = longi;
	nouveau->lati = lati;		//On initialise toutes les variables
	nouveau->humid = humid;
	nouveau->droit = NULL;
	nouveau->gauche = NULL;
	return nouveau;
}

pChainon creerChainonhumid(int station, int humid, float longi, float lati){	//Crée la liste chaînée si il n'y en a pas
	pChainon nouveau = malloc(sizeof(Chainon));
	if(nouveau == NULL){		
		exit(15);
	}
	nouveau->station = station;
	nouveau->longi = longi;		//On initialise toutes les variables
	nouveau->lati = lati;
	nouveau->humid = humid;
	nouveau->suivant = NULL;
	return nouveau;
}

//AVL
pArbre insertionAVLhumidstation(pArbre a, int station, int humid, float longi, float lati, int*h){ //Pré-tri en fonction des stations pour avoir le max de l'humidité pour chaque
	if (a == NULL){
		*h = 1;
		return creerABRhumid(station, humid, longi, lati);	//Crée l'arbre si il n'y en a pas
	}
	else if (station< a->station){
		a->gauche = insertionAVLhumidstation(a->gauche, station, humid, longi, lati, h);	
		*h = -*h;
	}
	else if (station> a->station){
		a->droit = insertionAVLhumidstation(a->droit, station, humid, longi, lati, h);		//Insert la variable au bon endroit afin que ce soit trié
	}
	else{
		*h = 0;
		if(humid>a->humid){
			a->humid = humid;
		}
		return a;
	}
	if(*h != 0){
		a->equ = a->equ + *h;		//Bouge l'AVL avec des rotations si l'arbre n'est pas équilibré
		a = equilibrerAVL(a);
		if(a->equ == 0){
			*h = 0;
		}
		else *h = 1;
	}
	return a;
}

pArbre insertionAVLhumid(pArbre a, pArbre final, int* h){ //Tri en fonction de l'humidité
	if (final == NULL){
		*h = 1;
		return creerABRhumid(a->station, a->humid, a->longi, a->lati);	//Crée l'arbre si il n'y en a pas
	}
	else if (a->humid<= final->humid){
		final->gauche = insertionAVLhumid(a, final->gauche, h);
		*h = -*h;
	}
	else if (a->humid> final->humid){
		final->droit = insertionAVLhumid(a, final->droit, h);		//Insert la variable au bon endroit
	}
	if(*h != 0){
		final->equ = final->equ + *h;
		final = equilibrerAVL(final);	//Bouge l'AVL si il n'est éq
		if(final->equ == 0){
			*h = 0;
		}
		else *h = 1;
	}
	return final;
}


pArbre insertionABRhumidstation(pArbre a, int station, int humid, float longi, float lati){	//Pré-tri en fonction des stations pour avoir le max de l'humidité pour chaque
	if (a == NULL){
		return creerABRhumid(station, humid, longi, lati);	//Crée l'arbre si il n'y en a pas
	}
	else if (station< a->station){
		a->gauche = insertionABRhumidstation(a->gauche, station, humid, longi, lati);
	}
	else if (station> a->station){
		a->droit = insertionABRhumidstation(a->droit, station, humid, longi, lati);	//Insert la variable au bon endroit
	}
	else{
		if(humid>a->humid){
			a->humid = humid;
		}
		return a;
	}
	return a;
}

pArbre insertionABRhumid(pArbre a, pArbre final){	//Tri en fonction de l'humidité
	if (final == NULL){
		return creerABRhumid(a->station, a->humid, a->longi, a->lati);	//Crée l'arbre si il n'y en a pas
	}
	else if (a->humid<= final->humid){
		final->gauche = insertionABRhumid(a, final->gauche);
	}
	else if (a->humid> final->humid){
		final->droit = insertionABRhumid(a, final->droit);	//Insert la variable au bon endroit
	}
	return final;
}



pChainon insertionChainonhumidstation(pChainon a, int station, int humid, float longi, float lati){	//Pré-tri en fonction des stations pour avoir le max de l'humidité pour chaque
	pChainon nouveau = creerChainonhumid(station, humid, longi, lati);
	pChainon p1 = a;
	if(a == NULL){
		a=nouveau;	//Crée la liste chaînée si il n'y en a pas
	}
	else if(a->station > station){
		nouveau->suivant = a;
		a = nouveau;
	}
	else{
		while(p1->suivant!=NULL && p1->suivant->station < station){
			p1=p1->suivant;
		}
		if(p1->suivant==NULL){
			p1->suivant = nouveau;
		}
		else{
			if(p1->suivant->station == station){
				if(humid>p1->suivant->humid){
					p1->suivant->humid = humid;	//Insert la variable au bon endroit
				}
			}
			else{
				nouveau->suivant=p1->suivant;
				p1->suivant = nouveau;
			}
		}
	}
	return a;
}

pChainon insertionChainonhumid(pChainon a, pChainon final){	//Tri en fonction de l'humidité
	if(a){
		pChainon nouveau = creerChainonhumid(a->station, a->humid, a->longi, a->lati);
		pChainon p1 = final;
		if(final == NULL){
			final=nouveau;	//Crée la liste chaînée si il n'y en a pas
		}
		else if(final->station > a->station){
			nouveau->suivant = final;
			final = nouveau;
		}
		else{
			while(p1->suivant!=NULL && p1->suivant->humid < a->humid){
				p1=p1->suivant;
			}
			if(p1->suivant==NULL){
				p1->suivant = nouveau;
			}
			else{
				nouveau->suivant=p1->suivant;
				p1->suivant = nouveau;		//Insert la variable au bon endroit
			}
		}
	}
	return final;
}

pArbre traitementLignehumidstation(pArbre tri, int station, int humid, float longi, float lati,int methode){	//Lance la fonction d'insert en fonction de la méthode choisie
	if (methode==1){
		tri=insertionABRhumidstation(tri,station,humid,longi,lati);	//Lance la fonction pour l'ABR
	}
	else if (methode==0){
		int* h = malloc(sizeof(int));	//"h" est un pointeur utile pour équilibrer les AVL
		*h = 0;
		tri = insertionAVLhumidstation(tri, station, humid, longi, lati, h);	//Lance la fonction pour l'AVL
	}
	else{
		printf("pas de méthode de tri donnée");	//Erreur si il n'y a pas de méthode de tri choisis (n'est pas censé arriver)
		exit(200);
	}
	return tri;
}

pArbre traitementLignehumid(pArbre tri, pArbre final,int methode){	//Lance la fonction de tri en fonction de la méthode choisie
	if(tri){
		if (methode==1){
			final = traitementLignehumid(tri->gauche, final,methode);
			final = insertionABRhumid(tri, final);			//Lance le tri pour l'ABR
			final = traitementLignehumid(tri->droit, final,methode);
		}
		else if (methode==0){
			final = traitementLignehumid(tri->gauche, final,methode);
			int* h = malloc(sizeof(int));				//"h" est un pointeur utile pour équilibrer les AVL
			*h = 0;
			final = insertionAVLhumid(tri, final, h);		//Lance le tri pour l'AVL
			final = traitementLignehumid(tri->droit, final,methode);
		}
		else{
			printf("pas de méthode de tri donnée");	//Erreur si il n'y a pas de méthode de tri choisis (n'est pas censé arriver)
		}
	}
	return final;
}

pChainon traitementLignehumidstationListe(pChainon tri, int station, int humid, float longi, float lati){	//Lance la fonction de la liste chaînée (permet de garder la meme méthode que pour les arbres
	tri = insertionChainonhumidstation(tri, station, humid, longi, lati);	//Lance la fonction pour la liste chaînée
	return tri;
}

pChainon traitementLignehumidListe(pChainon tri, pChainon final){	//Lance la fonction de tri de la liste chaîné (permet de garder la meme méthode que pour les arbres)
	if(tri){
		final = insertionChainonhumid(tri, final);	//Lance le tri pour la liste chaînée
		final = traitementLignehumidListe(tri->suivant, final);
	}
	return final;
}
