#include "header.h"


//Crée ABR en fonction des paramètres utiles
pArbre creerABRalt(int station, float longi, float lati, int alt){
	pArbre nouveau = malloc(sizeof(Arbre));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->equ = 0; //Atribution des valeurs utiles au noeud
	
	nouveau->station = station;
	nouveau->longi = longi;
	nouveau->lati = lati;
	nouveau->alt = alt;
	nouveau->droit = NULL;
	nouveau->gauche = NULL;
	return nouveau;
}

//Crée Liste chaînée en fonction des paramètres utiles
pChainon creerChainonalt(int station, float longi, float lati, int alt){
	pChainon nouveau = malloc(sizeof(Chainon));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->station = station;
	nouveau->longi = longi;
	nouveau->lati = lati;
	nouveau->alt = alt;
	nouveau->suivant = NULL;
	return nouveau;
}

//Insère élément dans un AVL
pArbre insertionAVLalt(pArbre a, int station, float longi, float lati, int alt, int*h){
	if (a == NULL){
		*h = 1;
		return creerABRalt(station, longi, lati, alt);
	}
	else if (alt< a->alt){
		a->gauche = insertionAVLalt(a->gauche, station, longi, lati, alt, h);
		*h = -*h;
	}
	else if (alt> a->alt){
		a->droit = insertionAVLalt(a->droit, station, longi, lati, alt, h);
	}
	else{
		if(station != a->station){	//On ajoute à gauche que si c'est une station différente à la même altitude
			a->gauche = insertionAVLalt(a->gauche, station, longi, lati, alt, h);
			*h = -*h;
		}
	}
	if(*h != 0){
		a->equ = a->equ + *h;
		a = equilibrerAVL(a);
		if(a->equ == 0){
			*h = 0;
		}
		else *h = 1;
	}
	return a;
}

//Insère élément dans un ABR
pArbre insertionABRalt(pArbre a, int station, float longi, float lati, int alt){
	if (a == NULL){
		return creerABRalt(station, longi, lati, alt);
	}
	else if (alt< a->alt){
		a->gauche = insertionABRalt(a->gauche, station, longi, lati, alt);
	}
	else if (alt> a->alt){
		a->droit = insertionABRalt(a->droit, station, longi, lati, alt);
	}
	else{
		if(station != a->station){
			a->gauche = insertionABRalt(a->gauche, station, longi, lati, alt);
		}
	}
	return a;
}

//Insère élément dans une liste chaînée
pChainon insertionChainonalt(pChainon a, int station, float longi, float lati, int alt){
	pChainon nouveau = creerChainonalt(station, longi, lati, alt);
	pChainon p1 = a;
	if(a == NULL){
		a=nouveau;
	}
	else if(a->alt > alt){
		nouveau->suivant = a;
		a = nouveau;
	}
	else{
		while(p1->suivant!=NULL && p1->suivant->alt < alt){
			p1=p1->suivant;
		}
		if(p1->suivant==NULL){
			p1->suivant = nouveau;
		}
		else{
			if(p1->suivant->station != station){
				nouveau->suivant=p1->suivant;
				p1->suivant = nouveau;
			}
		}
	}
	return a;
}

//Traite la ligne du fichier en fonction de la méthode de tri choisie par Arbre
pArbre traitementLignealt(pArbre tri, int station, float longi, float lati, int alt,int methode){
	if (methode==1){
		tri=insertionABRalt(tri,station,longi,lati,alt);
	}
	else if(methode==0){
		int* h = malloc(sizeof(int));
		*h = 0;
		tri = insertionAVLalt(tri, station, longi, lati, alt, h);
	}
	else{
		printf("pas de méthode de tri donnée");
		exit(4);
	}
	return tri;
}

//Traite la ligne du fichier par liste chaînée
pChainon traitementLignealtListe(pChainon tri, int station, float longi, float lati, int alt){
	tri = insertionChainonalt(tri, station, longi, lati, alt);
	return tri;
}
