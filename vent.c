#include "header.h"

//Crée ABR en fonction des paramètres utiles
pArbre creerABRvent(int station, int dirvent, float vitvent, float longi, float lati){
	pArbre nouveau = malloc(sizeof(Arbre));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->equ = 0;
	
	nouveau->station = station;
	nouveau->moyenne = dirvent;
	nouveau->moyenne2 = vitvent;
	nouveau->total = 1;
	nouveau->total2 = 1;
	nouveau->longi = longi;
	nouveau->lati = lati;
	nouveau->droit = NULL;
	nouveau->gauche = NULL;
	return nouveau;
}

//Crée Liste chaînée en fonction des paramètres utiles
pChainon creerChainonvent(int station, int dirvent, float vitvent, float longi, float lati){
	pChainon nouveau = malloc(sizeof(Chainon));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->station = station;
	nouveau->moyenne = dirvent;
	nouveau->moyenne2 = vitvent;
	nouveau->total = 1;
	nouveau->total2 = 1;
	nouveau->longi = longi;
	nouveau->lati = lati;
	nouveau->suivant = NULL;
	return nouveau;
}

//Insère élément dans un AVL
pArbre insertionAVLvent(pArbre a, int station, int dirvent, float vitvent, float longi, float lati, int*h){
	if (a == NULL){
		*h = 1;
		return creerABRvent(station, dirvent, vitvent, longi, lati);
	}
	else if (station< a->station){
		a->gauche = insertionAVLvent(a->gauche, station, dirvent, vitvent, longi, lati, h);
		*h = -*h;
	}
	else if (station> a->station){
		a->droit = insertionAVLvent(a->droit, station, dirvent, vitvent, longi, lati, h);
	}
	else{
		*h = 0;
		a->moyenne = a->moyenne+dirvent;
		a->total = a->total +1;
		a->dirvent = (a->moyenne)/(a->total);
		a->moyenne2 = a->moyenne2+vitvent;
		a->total2 = a->total2 +1;
		a->vitvent = (a->moyenne2)/(a->total2);
		return a;
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
pArbre insertionABRvent(pArbre a, int station, int dirvent, float vitvent, float longi, float lati){
	if (a == NULL){
		return creerABRvent(station, dirvent, vitvent, longi, lati);
	}
	else if (station< a->station){
		a->gauche = insertionABRvent(a->gauche, station, dirvent, vitvent, longi, lati);
	}
	else if (station> a->station){
		a->droit = insertionABRvent(a->droit, station, dirvent, vitvent, longi, lati);
	}
	else{
		a->moyenne = a->moyenne+dirvent;
		a->total = a->total +1;
		a->dirvent = (a->moyenne)/(a->total);
		a->moyenne2 = a->moyenne2+vitvent;
		a->total2 = a->total2 +1;
		a->vitvent = (a->moyenne2)/(a->total2);
		return a;
	}
	return a;
}

//Insère élément dans une liste chaînée
pChainon insertionChainonvent(pChainon a, int station, int dirvent, float vitvent, float longi, float lati){
	pChainon nouveau = creerChainonvent(station, dirvent, vitvent, longi, lati);
	pChainon p1 = a;
	if(a == NULL){
		a=nouveau;
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
				p1->suivant->moyenne = p1->suivant->moyenne+dirvent;
				p1->suivant->total = p1->suivant->total +1;
				p1->suivant->dirvent = (p1->suivant->moyenne)/(p1->suivant->total);
				p1->suivant->moyenne2 = p1->suivant->moyenne2+vitvent;
				p1->suivant->total2 = p1->suivant->total2 +1;
				p1->suivant->vitvent = (p1->suivant->moyenne2)/(p1->suivant->total2);
			}
			else{
				nouveau->suivant=p1->suivant;
				p1->suivant = nouveau;
			}
		}
	}
	return a;
}

//Traite la ligne du fichier en fonction de la méthode de tri choisie par Arbre
pArbre traitementLignevent(pArbre tri, int station, int dirvent, float vitvent, float longi, float lati,int methode){
	if (methode==1){
		tri = insertionABRvent(tri,station,dirvent,vitvent,longi,lati);
	}
	else if (methode==0){
		int* h = malloc(sizeof(int));
		*h = 0;
		tri = insertionAVLvent(tri, station, dirvent, vitvent, longi, lati, h);
	}
	else{
		printf("pas de méthode de tri donnée");
		exit(4);
	}
	return tri;
}

//Traite la ligne du fichier par liste chaînée
pChainon traitementLigneventListe(pChainon tri, int station, int dirvent, float vitvent, float longi, float lati){
	tri = insertionChainonvent(tri, station, dirvent, vitvent, longi, lati);
	return tri;
}
