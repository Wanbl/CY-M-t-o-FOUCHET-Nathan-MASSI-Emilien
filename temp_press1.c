#include "header.h"

pArbre creerABRtemp1(int station, float temp, float tempmin, float tempmax){	//Crée l'arbre si il n'y en a pas
	pArbre nouveau = malloc(sizeof(Arbre));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->station = station;
	nouveau->equ = 0;
	nouveau->temp = temp;
	nouveau->tempmin = tempmin;	//Initialise les variables de l'arbre
	nouveau->tempmax = tempmax;
	nouveau->droit = NULL;
	nouveau->gauche = NULL;
	nouveau->moyenne = temp;
	nouveau->total = 1;
	return nouveau;
}

pChainon creerChainontemp1(int station, float temp, float tempmin, float tempmax){	//Crée la liste chaînée si il n'y en a pas
	pChainon nouveau = malloc(sizeof(Chainon));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->station = station;
	nouveau->temp = temp;
	nouveau->tempmin = tempmin;	//Initialise les variables de la liste chaînée
	nouveau->tempmax = tempmax;
	nouveau->suivant = NULL;
	nouveau->moyenne = temp;
	nouveau->total = 1;
	return nouveau;
}

pArbre insertionAVLtemp1(pArbre a, int station, float temp, float tempmin, float tempmax, int*h){	//Insert et tri l'AVL
	if (a == NULL){
		*h = 1;
		return creerABRtemp1(station, temp, tempmin, tempmax);	//Crée l'AVL si il n'y en a pas
	}
	else if (station< a->station){
		a->gauche = insertionAVLtemp1(a->gauche, station, temp, tempmin, tempmax, h);
		*h = -*h;
	}
	else if (station> a->station){
		a->droit = insertionAVLtemp1(a->droit, station, temp, tempmin, tempmax, h);	//Insert la variable dans l'AVL
	}
	else{
		*h = 0;
		if(temp<a->tempmin) a->tempmin = temp;
		if(tempmin<a->tempmin) a->tempmin = tempmin;
		if(temp>a->tempmax) a->tempmax = temp;
		if(tempmax>a->tempmax) a->tempmax = tempmax;
		a->moyenne = a->moyenne+temp;
		a->total = a->total +1;
		a->temp = ((a->moyenne)/(a->total));		//Récupere la température moyenne
		return a;
	}
	if(*h != 0){
		a->equ = a->equ + *h;		//Equilibre l'AVL si besoin
		a = equilibrerAVL(a);
		if(a->equ == 0){
			*h = 0;
		}
		else *h = 1;
	}
	return a;
}

pArbre insertionABRtemp1(pArbre a, int station, float temp, float tempmin, float tempmax){	//Insert et tri l'ABR
	if (a == NULL){
		return creerABRtemp1(station, temp, tempmin, tempmax);	//Crée l'ABR si il n'y en a pas
	}
	else if (station< a->station){
		a->gauche = insertionABRtemp1(a->gauche, station, temp, tempmin, tempmax);
	}
	else if (station> a->station){
		a->droit = insertionABRtemp1(a->droit, station, temp, tempmin, tempmax);	//Insert la variable dans l'ABR
	}
	else{
		if(temp<a->tempmin) a->tempmin = temp;
		if(tempmin<a->tempmin) a->tempmin = tempmin;
		if(temp>a->tempmax) a->tempmax = temp;
		if(tempmax>a->tempmax) a->tempmax = tempmax;
		a->moyenne = a->moyenne+temp;
		a->total = a->total +1;
		a->temp = ((a->moyenne)/(a->total));	//Récupere la température moyenne
		return a;
	}
	return a;
}

pChainon insertionChainontemp1(pChainon a, int station, float temp, float tempmin, float tempmax){	//Insert et "tri" la liste chaînée
	pChainon nouveau = creerChainontemp1(station, temp, tempmin, tempmax);
	pChainon p1 = a;
	if(a == NULL){
		a=nouveau;		//Crée la liste chaînée si il n'y en a pas (suffisament court pour ne pas avoir besoin d'une fonction séparée)
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
			p1->suivant = nouveau;	//Insert la variable dans la liste chaînée
		}
		else{
			if(p1->suivant->station == station){
				if(temp<p1->suivant->tempmin) p1->suivant->tempmin = temp;
				if(tempmin<p1->suivant->tempmin) p1->suivant->tempmin = tempmin;
				if(temp>p1->suivant->tempmax) p1->suivant->tempmax = temp;
				if(tempmax>p1->suivant->tempmax) p1->suivant->tempmax = tempmax;
				p1->suivant->moyenne = p1->suivant->moyenne+temp;
				p1->suivant->total = p1->suivant->total +1;
				p1->suivant->temp = ((p1->suivant->moyenne)/(p1->suivant->total));	//Récupere la température moyenne
			}
			else{
				nouveau->suivant=p1->suivant;
				p1->suivant = nouveau;
			}
		}
	}
	return a;
}

pArbre traitementLignetemp1(pArbre tri, int station, float temp, float tempmin, float tempmax,int methode){	//Lance la fonction par rapport a la méthode voulu (ABR ou AVL)
	if (methode==1){
		tri=insertionABRtemp1(tri,station,temp,tempmin,tempmax);	//Lance la fonction pour l'ABR
	}
	else if (methode==0){
		int* h = malloc(sizeof(int));
		*h = 0;			//"h" est un pointeur utile pour équilibrer les AVL
		tri = insertionAVLtemp1(tri, station, temp, tempmin, tempmax, h);	//Lance la fonction pour l'AVL
	}
	else{
		printf("pas de méthode de tri donnée");		//Erreur si aucune des méhodes n'a été donnée (n'est pas censé arriver)
		exit(1);
	}
	return tri;
}

pChainon traitementLignetemp1Liste(pChainon tri, int station, float temp, float tempmin, float tempmax){	//Lance la fonction pour la liste chaînée
	tri = insertionChainontemp1(tri, station, temp, tempmin, tempmax);	//Lance la fonction pour la liste chaînée
	return tri;
}
