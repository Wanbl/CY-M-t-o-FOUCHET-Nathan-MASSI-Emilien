#include "header.h"

void creationSortie(pArbre a, FILE* fichier, char* codeSortie){	//Convertit le "codeSortie" pour savoir quelles variables nous avons besoin pour la fonction choisis
	if (a){
		creationSortie(a->gauche, fichier, codeSortie);
		if(codeSortie[0] == '1'){
			fprintf(fichier, "%d ", a->station);	//Station en 1er
		}
		if(codeSortie[1] == '1'){
			fprintf(fichier, "%d ", a->date);	//Date en 2eme
		}
		if(codeSortie[2] == '1'){
			fprintf(fichier, "%d ", a->dirvent);	//direction du vent en 3eme
		}
		if(codeSortie[3] == '1'){
			fprintf(fichier, "%f ", a->vitvent);	//Vitesse du vent en 4eme
		}
		if(codeSortie[4] == '1'){
			fprintf(fichier, "%d ", a->humid);	//Humidité en 5eme
		}
		if(codeSortie[5] == '1'){
			fprintf(fichier, "%f ", a->press);	//Pression en 6eme
		}
		if(codeSortie[6] == '1'){
			fprintf(fichier, "%f ", a->longi);	//Longitude en 7eme
		}
		if(codeSortie[7] == '1'){
			fprintf(fichier, "%f ", a->lati);	//Latitude en 8eme
		}
		if(codeSortie[8] == '1'){
			fprintf(fichier, "%f ", a->temp);	//Température en 9eme
		}
		if(codeSortie[9] == '1'){
			fprintf(fichier, "%f ", a->tempmin);	//Température minimum en 10eme
		}
		if(codeSortie[10] == '1'){
			fprintf(fichier, "%f ", a->tempmax);	//Température maximum en 11eme
		}
		if(codeSortie[11] == '1'){
			fprintf(fichier, "%d ", a->alt);	//Altitude en 12eme
		}
		fprintf(fichier, "\n");
		creationSortie(a->droit, fichier, codeSortie);
	}
}

void creationSortieListe(pChainon a, FILE* fichier, char* codeSortie){	//Convertit le "codeSortie" pour savoir quelles variables nous avons besoin pour la fonction choisis
	if (a){
		if(codeSortie[0] == '1'){
			fprintf(fichier, "%d ", a->station);	//Station en 1er
		}
		if(codeSortie[1] == '1'){
			fprintf(fichier, "%d ", a->date);	//Date en 2eme
		}
		if(codeSortie[2] == '1'){
			fprintf(fichier, "%d ", a->dirvent);	//direction du vent en 3eme
		}
		if(codeSortie[3] == '1'){
			fprintf(fichier, "%f ", a->vitvent);	//Vitesse du vent en 4eme
		}
		if(codeSortie[4] == '1'){
			fprintf(fichier, "%d ", a->humid);	//Humidité en 5eme
		}
		if(codeSortie[5] == '1'){
			fprintf(fichier, "%f ", a->press);	//Pression en 6eme
		}
		if(codeSortie[6] == '1'){
			fprintf(fichier, "%f ", a->longi);	//Longitude en 7eme
		}
		if(codeSortie[7] == '1'){
			fprintf(fichier, "%f ", a->lati);	//Latitude en 8eme
		}
		if(codeSortie[8] == '1'){
			fprintf(fichier, "%f ", a->temp);	//Température en 9eme
		}
		if(codeSortie[9] == '1'){
			fprintf(fichier, "%f ", a->tempmin);	//Température minimum en 10eme
		}
		if(codeSortie[10] == '1'){
			fprintf(fichier, "%f ", a->tempmax);	//Température maximum en 11eme
		}
		if(codeSortie[11] == '1'){
			fprintf(fichier, "%d ", a->alt);	//Altitude en 12eme
		}
		fprintf(fichier, "\n");
		creationSortieListe(a->suivant, fichier, codeSortie);
	}
}

void creationSortieReverse(pArbre a, FILE* fichier, char* codeSortie){	//Convertit le "codeSortie" pour savoir quelles variables nous avons besoin pour la fonction choisis(mais dans le sens inverse)
	if (a){
		creationSortieReverse(a->droit, fichier, codeSortie);
		if(codeSortie[0] == '1'){
			fprintf(fichier, "%d ", a->station);	//Station en 1er
		}
		if(codeSortie[1] == '1'){
			fprintf(fichier, "%d ", a->date);	//Date en 2eme
		}
		if(codeSortie[2] == '1'){
			fprintf(fichier, "%d ", a->dirvent);	//direction du vent en 3eme
		}
		if(codeSortie[3] == '1'){
			fprintf(fichier, "%f ", a->vitvent);	//Vitesse du vent en 4eme
		}
		if(codeSortie[4] == '1'){
			fprintf(fichier, "%d ", a->humid);	//Humidité en 5eme
		}
		if(codeSortie[5] == '1'){
			fprintf(fichier, "%f ", a->press);	//Pression en 6eme
		}
		if(codeSortie[6] == '1'){
			fprintf(fichier, "%f ", a->longi);	//Longitude en 7eme
		}
		if(codeSortie[7] == '1'){
			fprintf(fichier, "%f ", a->lati);	//Latitude en 8eme
		}
		if(codeSortie[8] == '1'){
			fprintf(fichier, "%f ", a->temp);	//Température en 9eme
		}
		if(codeSortie[9] == '1'){
			fprintf(fichier, "%f ", a->tempmin);	//Température minimum en 10eme
		}
		if(codeSortie[10] == '1'){
			fprintf(fichier, "%f ", a->tempmax);	//Température maximum en 11eme
		}
		if(codeSortie[11] == '1'){
			fprintf(fichier, "%d ", a->alt);	//Altitude en 12eme
		}
		fprintf(fichier, "\n");
		creationSortieReverse(a->gauche, fichier, codeSortie);
	}
}

void creationSortieReverseListe(pChainon a, FILE* fichier, char* codeSortie){	//Convertit le "codeSortie" pour savoir quelles variables nous avons besoin pour la fonction choisis(mais dans le sens inverse)
	if (a){
		creationSortieReverseListe(a->suivant, fichier, codeSortie);
		if(codeSortie[0] == '1'){
			fprintf(fichier, "%d ", a->station);	//Station en 1er
		}
		if(codeSortie[1] == '1'){
			fprintf(fichier, "%d ", a->date);	//Date en 2eme
		}
		if(codeSortie[2] == '1'){
			fprintf(fichier, "%d ", a->dirvent);	//direction du vent en 3eme
		}
		if(codeSortie[3] == '1'){
			fprintf(fichier, "%f ", a->vitvent);	//Vitesse du vent en 4eme
		}
		if(codeSortie[4] == '1'){
			fprintf(fichier, "%d ", a->humid);	//Humidité en 5eme
		}
		if(codeSortie[5] == '1'){
			fprintf(fichier, "%f ", a->press);	//Pression en 6eme
		}
		if(codeSortie[6] == '1'){
			fprintf(fichier, "%f ", a->longi);	//Longitude en 7eme
		}
		if(codeSortie[7] == '1'){
			fprintf(fichier, "%f ", a->lati);	//Latitude en 8eme
		}
		if(codeSortie[8] == '1'){
			fprintf(fichier, "%f ", a->temp);	//Température en 9eme
		}
		if(codeSortie[9] == '1'){
			fprintf(fichier, "%f ", a->tempmin);	//Température minimum en 10eme
		}
		if(codeSortie[10] == '1'){
			fprintf(fichier, "%f ", a->tempmax);	//Température maximum en 11eme
		}
		if(codeSortie[11] == '1'){
			fprintf(fichier, "%d ", a->alt);	//Altitude en 12eme
		}
		fprintf(fichier, "\n");
	}
}

void creationFichierSortie(pArbre tri, char* nomFichier, char* codeSortie){	//Transforme en int pour faire des return si erreur
	FILE* sortie = fopen(nomFichier, "a");
	if (sortie == NULL){
		printf("Erreur lors de la création du fichier");	//Vérifie de maniere classique
		exit(3);
	}
	creationSortie(tri, sortie, codeSortie);
	fclose(sortie);
}

void creationFichierSortieListe(pChainon tri, char* nomFichier, char* codeSortie){	//Transforme en int pour faire des return si erreur
	FILE* sortie = fopen(nomFichier, "a");
	if (sortie == NULL){
		printf("Erreur lors de la création du fichier");	//Vérifie de maniere classique
		exit(3);
	}
	creationSortieListe(tri, sortie, codeSortie);
	fclose(sortie);
}

void creationFichierSortieReverse(pArbre tri, char* nomFichier, char* codeSortie){	//Transforme en int pour faire des return si erreur
	FILE* sortie = fopen(nomFichier, "a");
	if (sortie == NULL){
		printf("Erreur lors de la création du fichier");	//Vérifie de maniere classique
		exit(3);
	}
	creationSortieReverse(tri, sortie, codeSortie);
	fclose(sortie);
}

void creationFichierSortieReverseListe(pChainon tri, char* nomFichier, char* codeSortie){	//Transforme en int pour faire des return si erreur
	FILE* sortie = fopen(nomFichier, "a");
	if (sortie == NULL){
		printf("Erreur lors de la création du fichier");	//Vérifie de maniere classique
		exit(3);
	}
	creationSortieReverseListe(tri, sortie, codeSortie);
	fclose(sortie);
}

void creationFichierIndividuel(pArbre a){
	if (a){
		creationFichierIndividuel(a->gauche);
		char nomFichier[20];
		FILE* sortie;
		sprintf(nomFichier, "tempstation/%d_temp%d.txt", (((a->date)/3600)%24), a->station);
		sortie = fopen(nomFichier, "a");
		if (sortie == NULL){
			perror("fopen");
			printf("Impossible d'ouvrir le fichier individuel %s", nomFichier);	//Vérifie de maniere classique
			exit (3);
		}
		if (a->temp != 0){
			fprintf(sortie, "%d %f %d\n", a->date, a->temp, ((a->date)/3600)%24);
		}
		fclose(sortie);
		creationFichierIndividuel(a->droit);
	}
}

void creationFichierIndividuelListe(pChainon a){
	if (a){
		char nomFichier[20];
		FILE* sortie;
		sprintf(nomFichier, "tempstation/%d_temp%d.txt", (((a->date)/3600)%24), a->station);
		sortie = fopen(nomFichier, "a");
		if (sortie == NULL){
			perror("fopen");
			printf("Impossible d'ouvrir le fichier individuel %s", nomFichier);	//Vérifie de maniere classique
			exit (3);
		}
		if (a->temp != 0){
			fprintf(sortie, "%d %f %d\n", a->date, a->temp, ((a->date)/3600)%24);
		}
		fclose(sortie);
		creationFichierIndividuelListe(a->suivant);
	}
}
