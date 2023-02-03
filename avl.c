#include "header.h"


//Renvoie le nombre maximal
int max2(int a, int b){
	if (a>b) return a;
	return b;
}

//Renvoie le nombre maximal
int max3(int a, int b, int c){
	int max = a;
	if (b>max) max = b;
	if (c>max) max = c;
	return max;
}

//Renvoie le nombre minimal
int min2(int a, int b){
	if (a<b) return a;
	return b;
}

//Renvoie le nombre minimal
int min3(int a, int b, int c){
	int min = a;
	if (b<min) min = b;
	if (c<min) min = c;
	return min;
}


//Effectue rotation gauche de l'arbre
pArbre rotationgauche(pArbre a){
	pArbre pivot = a->droit;
	a->droit = pivot->gauche;
	pivot->gauche = a;
	int equa = a->equ;
	int equp = pivot->equ;
	a->equ = equa - max2(equp, 0) -1;
	pivot->equ = min3(equa-2, equa+equp-2, equp-1);
	return pivot;
}

//Effectue rotation droite de l'arbre
pArbre rotationdroit(pArbre a){
	pArbre pivot = a->gauche;
	a->gauche = pivot->droit;
	pivot->droit = a;
	int equa = a->equ;
	int equp = pivot->equ;
	a->equ = equa - min2(equp, 0) +1;
	pivot->equ = max3(equa+2, equa+equp+2, equp+1);
	return pivot;
}


//Effectue double rotation gauche de l'arbre
pArbre doublerotationgauche(pArbre a){
	a->droit = rotationdroit(a->droit);
	return (rotationgauche(a));
}

//Effectue rotation droite de l'arbre
pArbre doublerotationdroit(pArbre a){
	a->gauche = rotationgauche(a->gauche);
	return (rotationdroit(a));
}


//Equilibre l'AVL
pArbre equilibrerAVL(pArbre a){
	if(a->equ > 1){
		if(a->droit->equ >=0){
			return rotationgauche(a);
		}
		else return doublerotationgauche(a);
	}
	else if(a->equ < -1){
		if(a->gauche->equ <= 0){
			return rotationdroit(a);
		}
		else return doublerotationdroit(a);
	}
	return a;
}
