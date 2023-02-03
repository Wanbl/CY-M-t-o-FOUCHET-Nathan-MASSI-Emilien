#include "header.h"

//Crée ABR en fonction des paramètres utiles
pArbre creerABRtemp2(int date, float temp){
	pArbre nouveau = malloc(sizeof(Arbre));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->equ = 0;
	
	nouveau->date = date;
	nouveau->moyenne = temp;
	nouveau->total = 1;
	nouveau->droit = NULL;
	nouveau->gauche = NULL;
	return nouveau;
}

//Crée Liste chaînée en fonction des paramètres utiles
pChainon creerChainontemp2(int date, float temp){
	pChainon nouveau = malloc(sizeof(Chainon));
	if(nouveau == NULL){
		exit(4);
	}
	nouveau->date = date;
	nouveau->moyenne = temp;
	nouveau->total = 1;
	nouveau->suivant = NULL;
	return nouveau;
}

//Insère élément dans un AVL
pArbre insertionAVLtemp2(pArbre a, int date, float temp, int*h){
	if (a == NULL){
		*h = 1;
		return creerABRtemp2(date, temp);
	}
	else if (date< a->date){
		a->gauche = insertionAVLtemp2(a->gauche, date, temp, h);
		*h = -*h;
	}
	else if (date> a->date){
		a->droit = insertionAVLtemp2(a->droit, date, temp, h);
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
pArbre insertionABRtemp2(pArbre a, int date, float temp){
	if (a == NULL){
		return creerABRtemp2(date, temp);
	}
	else if (date< a->date){
		a->gauche = insertionABRtemp2(a->gauche, date, temp);
	}
	else if (date> a->date){
		a->droit = insertionABRtemp2(a->droit, date, temp);
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
pChainon insertionChainontemp2(pChainon a, int date, float temp){
	pChainon nouveau = creerChainontemp2(date, temp);
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
pArbre traitementLignetemp2(pArbre tri, int date, float temp,int methode){

	if (methode==1){
		tri=insertionABRtemp2(tri,date,temp);
	}
	else if (methode==0){
		int* h = malloc(sizeof(int));
		*h = 0;
		tri = insertionAVLtemp2(tri, date, temp, h);
	}
	else{
		printf("pas de méthode de tri donnée");
		exit(4);
	}
	return tri;
}

//Traite la ligne du fichier par liste chaînée
pChainon traitementLignetemp2Liste(pChainon tri, int date, float temp){
	tri = insertionChainontemp2(tri, date, temp);
	return tri;
}
