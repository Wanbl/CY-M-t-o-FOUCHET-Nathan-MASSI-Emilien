#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_XOPEN	//Nécessaire pour utiliser strptime
#include <time.h>
#include <math.h>
#include <unistd.h>


//Structure Arbre généraliste
typedef struct Arbre{
	struct Arbre* gauche;
	struct Arbre* droit;
	int equ;	//Valeur d'équilibre du noeud
	int station;	//station
	int date;	//date
	int dirvent;	//direction vent
	float vitvent;	//vitesse vent
	int humid;	//humidité
	float press;	//pression
	float longi;	//longitude
	float lati;	//latitude
	float temp;	//température
	float tempmin;	//température minimale
	float tempmax;	//température maximale
	int alt;	//altitude
	int decalh;	//Décalage horaire
	double moyenne;	//Somme de la valeur totale dont on doit faire une moyenne(ça peut être ultra grand)
	int total;	//Nombre d'itérations de cette station
	double moyenne2;	//Somme de la valeur totale dont on doit faire une moyenne si on doit en faire une deuxième
	int total2;	//Nombre d'itérations de cette station
} Arbre;

typedef Arbre* pArbre;

//Structure Chaînon généraliste
typedef struct Chainon{
	struct Chainon* suivant;
	int station;	//station
	int date;	//date
	int dirvent;	//direction vent
	float vitvent;	//vitesse vent
	int humid;	//humidité
	float press;	//pression
	float longi;	//longitude
	float lati;	//latitude
	float temp;	//température
	float tempmin;	//température minimale
	float tempmax;	//température maximale
	int alt;	//altitude
	int decalh;	//Décalage horaire
	double moyenne;	//Somme de la valeur totale dont on doit faire une moyenne(ça peut être ultra grand)
	int total;	//Nombre d'itérations de cette station
	double moyenne2;	//Somme de la valeur totale dont on doit faire une moyenne si on doit en faire une deuxième
	int total2;	//Nombre d'itérations de cette station
} Chainon;

typedef Chainon* pChainon;


//Pour AVL
int max2(int a, int b);
int max3(int a, int b, int c);
int min2(int a, int b);
int min3(int a, int b, int c);

pArbre rotationgauche(pArbre a);
pArbre rotationdroit(pArbre a);
pArbre doublerotationgauche(pArbre a);
pArbre doublerotationdroit(pArbre a);
pArbre equilibrerAVL(pArbre a);


//Temp_Press1
pArbre creerABRtemp1(int station, float temp, float tempmin, float tempmax);
pChainon creerChainontemp1(int station, float temp, float tempmin, float tempmax);

pArbre insertionAVLtemp1(pArbre a, int station, float temp, float tempmin, float tempmax, int*h);
pArbre insertionABRtemp1(pArbre a, int station, float temp, float tempmin, float tempmax);
pChainon insertionChainontemp1(pChainon a, int station, float temp, float tempmin, float tempmax);

pArbre traitementLignetemp1(pArbre tri, int station, float temp, float tempmin, float tempmax,int methode);
pChainon traitementLignetemp1Liste(pChainon tri, int station, float temp, float tempmin, float tempmax);

//Temp_Press2
pArbre creerABRtemp2(int date, float temp);
pChainon creerChainontemp2(int date, float temp);

pArbre insertionAVLtemp2(pArbre a, int date, float temp, int*h);
pArbre insertionABRtemp2(pArbre a, int date, float temp);
pChainon insertionChainontemp2(pChainon a, int date, float temp);

pArbre traitementLignetemp2(pArbre tri, int date, float temp,int methode);
pChainon traitementLignetemp2Liste(pChainon tri, int date, float temp);

//Temp_Press3
pArbre creerABRtemp3(int station, int date, float temp);
pChainon creerChainontemp3(int station, int date, float temp);

pArbre insertionAVLtemp3(pArbre a, int station, int date, float temp, int*h);
pArbre insertionABRtemp3(pArbre a, int station, int date, float temp);
pChainon insertionChainontemp3(pChainon a, int station, int date, float temp);

pArbre traitementLignetemp3(pArbre tri, int station, int date, float temp,int methode);
pChainon traitementLignetemp3Liste(pChainon tri, int station, int date, float temp);

//Vent
pArbre creerABRvent(int station, int dirvent, float vitvent, float longi, float lati);
pChainon creerChainonvent(int station, int dirvent, float vitvent, float longi, float lati);

pArbre insertionAVLvent(pArbre a, int station, int dirvent, float vitvent, float longi, float lati, int*h);
pArbre insertionABRvent(pArbre a, int station, int dirvent, float vitvent, float longi, float lati);
pChainon insertionChainonvent(pChainon a, int station, int dirvent, float vitvent, float longi, float lati);

pArbre traitementLignevent(pArbre tri, int station, int dirvent, float vitvent, float longi, float lati,int methode);
pChainon traitementLigneventListe(pChainon tri, int station, int dirvent, float vitvent, float longi, float lati);

//Altitude
pArbre creerABRalt(int station, float longi, float lati, int alt);
pChainon creerChainonalt(int station, float longi, float lati, int alt);

pArbre insertionAVLalt(pArbre a, int station, float longi, float lati, int alt, int*h);
pArbre insertionABRalt(pArbre a, int station, float longi, float lati, int alt);
pChainon insertionChainonalt(pChainon a, int station, float longi, float lati, int alt);

pArbre traitementLignealt(pArbre tri, int station, float longi, float lati, int alt,int methode);
pChainon traitementLignealtListe(pChainon tri, int station, float longi, float lati, int alt);

//Humidite
pArbre creerABRhumid(int station, int humid, float longi, float lati);
pChainon creerChainonhumid(int station, int humid, float longi, float lati);

pArbre insertionAVLhumidstation(pArbre a, int station, int humid, float longi, float lati, int*h);
pArbre insertionAVLhumid(pArbre a, pArbre final, int* h);
pArbre insertionABRhumidstation(pArbre a, int station, int humid, float longi, float lati);
pArbre insertionABRhumid(pArbre a, pArbre final);
pChainon insertionChainonhumidstation(pChainon a, int station, int humid, float longi, float lati);
pChainon insertionChainonhumid(pChainon a, pChainon final);

pArbre traitementLignehumidstation(pArbre tri, int station, int humid, float longi, float lati,int methode);
pArbre traitementLignehumid(pArbre tri, pArbre final,int methode);
pChainon traitementLignehumidstationListe(pChainon tri, int station, int humid, float longi, float lati);
pChainon traitementLignehumidListe(pChainon tri, pChainon final);


//Sortie
void creationSortie(pArbre a, FILE* fichier, char* codeSortie);
void creationSortieListe(pChainon a, FILE* fichier, char* codeSortie);
void creationSortieReverse(pArbre a, FILE* fichier, char* codeSortie);
void creationSortieReverseListe(pChainon a, FILE* fichier, char* codeSortie);

void creationFichierSortie(pArbre tri, char* nomFichier, char* codeSortie);
void creationFichierSortieListe(pChainon tri, char* nomFichier, char* codeSortie);
void creationFichierSortieReverse(pArbre tri, char* nomFichier, char* codeSortie);
void creationFichierSortieReverseListe(pChainon tri, char* nomFichier, char* codeSortie);

void creationFichierIndividuel(pArbre a);
void creationFichierIndividuelListe(pChainon a);
