#include "header.h"


//Crée ABR en fonction des paramètres utiles
pArbre creerABRtemp3(int station, int date, float temp){
	pArbre nouveau = malloc(sizeof(Arbre));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->equ = 0; //Atribution des valeurs utiles au noeud
	
	nouveau->station = station;
	nouveau->date = date;
	nouveau->moyenne = temp;
	nouveau->total = 1;
	nouveau->droit = NULL;
	nouveau->gauche = NULL;
	return nouveau;
}

//Crée Liste chaînée en fonction des paramètres utiles
pChainon creerChainontemp3(int station, int date, float temp){
	pChainon nouveau = malloc(sizeof(Chainon));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->station = station;
	nouveau->date = date;
	nouveau->moyenne = temp;
	nouveau->total = 1;
	nouveau->suivant = NULL;
	return nouveau;
}

//Insère élément dans un AVL
pArbre insertionAVLtemp3(pArbre a, int station, int date, float temp, int*h){
	if (a == NULL){
		*h = 1;
		return creerABRtemp3(station, date, temp);
	}
	else if (date< a->date){
		a->gauche = insertionAVLtemp3(a->gauche, station, date, temp, h);
		*h = -*h;
	}
	else if (date> a->date){
		a->droit = insertionAVLtemp3(a->droit, station, date, temp, h);
	}
	else{
		*h = 0;
		a->moyenne = a->moyenne+temp;
		a->total = a->total +1;
		a->temp = (a->moyenne)/(a->total);
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
pArbre insertionABRtemp3(pArbre a, int station, int date, float temp){
	if (a == NULL){
		return creerABRtemp3(station, date, temp);
	}
	else if (date< a->date){
		a->gauche = insertionABRtemp3(a->gauche, station, date, temp);
	}
	else if (date> a->date){
		a->droit = insertionABRtemp3(a->droit, station, date, temp);
	}
	else{
		a->moyenne = a->moyenne+temp;
		a->total = a->total +1;
		a->temp = (a->moyenne)/(a->total);
		return a;
	}
	return a;
}

//Insère élément dans une liste chaînée
pChainon insertionChainontemp3(pChainon a, int station, int date, float temp){
	pChainon nouveau = creerChainontemp3(station, date, temp);
	pChainon p1 = a;
	if(a == NULL){
		a=nouveau;
	}
	else if(a->date > date){
		nouveau->suivant = a;
		a = nouveau;
	}
	else{
		while(p1->suivant!=NULL && p1->suivant->date < date){
			p1=p1->suivant;
		}
		if(p1->suivant==NULL){
			p1->suivant = nouveau;
		}
		else{
			if(p1->suivant->date == date){
				p1->suivant->moyenne = p1->suivant->moyenne+temp;
				p1->suivant->total = p1->suivant->total +1;
				p1->suivant->temp = (p1->suivant->moyenne)/(p1->suivant->total);
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
pArbre traitementLignetemp3(pArbre tri, int station, int date, float temp,int methode){
	if (methode==1){
		tri=insertionABRtemp3(tri,station,date,temp);
	}
	else if (methode==0){
		int* h = malloc(sizeof(int));
		*h = 0;
		tri = insertionAVLtemp3(tri, station, date, temp, h);
	}
	else{
		printf("pas de méthode de tri donnée");
		exit(4);
	}
	return tri;
}

//Traite la ligne du fichier par liste chaînée
pChainon traitementLignetemp3Liste(pChainon tri, int station, int date, float temp){
	tri = insertionChainontemp3(tri, station, date, temp);
	return tri;
}
