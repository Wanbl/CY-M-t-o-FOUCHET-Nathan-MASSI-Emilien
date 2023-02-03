#include "header.h"

int main(int argc, char *argv[]){
	int methode = 0;
	pArbre tri = NULL;
	pChainon triListe = NULL;
	if (argc <4){
		printf("Pas assez d'arguments");
		return 4;	//Remplace par le bon return pour les erreurs
	}
	char* input_file = argv[1];	//Chaîne de cracatère correspondant au nom du fichier pris en paramètre
	FILE* entree = fopen(input_file, "r");
	if(entree == NULL){
		printf("Impossible d'ouvrir le fichier");
		return 2;	//Remplacer par le bon return pour les erreurs
	}
	
	char* codeSortie; //Code pour l'écriture en sortie, savoir quelles données écrire
	codeSortie = malloc(sizeof(char));
	char ligne[1024];
	int modeTri = atoi(argv[2]);
	
	methode = atoi(argv[3]);
	
	switch (modeTri){	//Prends le deuxième argument qui est le mode de tri
		case 0:	//Cas pour -t1
			codeSortie = "100000001110"; //Le code comprenant station, temp, tempmin et tempmax
			while (fgets(ligne, sizeof(ligne), entree)){
				char* donnee = strtok(ligne, ";");
				
				int station1;	//Initialisation des différentes variables d'ou nous aurons besoin pour cette fonction
				float temp1;
				float tempmin1;
				float tempmax1;
				
				station1 = atoi(donnee); //Récupere le premier champ qui est le numéro de la station
				
				donnee = strtok(NULL, ";");
				temp1 = atof(donnee);	//Récupere la température
				
				donnee = strtok(NULL, ";");
				if(donnee == NULL || donnee == ""){
					tempmin1 = temp1;	//Récupere la température minimum et si nulle on prend le temps à la place
				}
				else{
					tempmin1 = atof(donnee);
				}
				
				donnee = strtok(NULL, ";");
				if(donnee == NULL || donnee == "") tempmax1 = temp1;
				else tempmax1 = atof(donnee);	//Récupere la température maximum
				if(methode <2){		//Vérifie si la méthode choisis existe
					if(temp1 != 0) tri = traitementLignetemp1(tri, station1, temp1, tempmin1, tempmax1, methode);
				}
				else{
					if(temp1 != 0) triListe = traitementLignetemp1Liste(triListe, station1, temp1, tempmin1, tempmax1);
				}
			}
			if(methode <2){
				creationFichierSortie(tri, "sortie.txt", codeSortie);
			}
			else{
				creationFichierSortieListe(triListe, "sortie.txt", codeSortie);
			}
			break;
		case 1: //Cas de -t2
			codeSortie = "010000001000";	//Le code comprenant la date et la température
			while (fgets(ligne, sizeof(ligne), entree)){
				char* donnee = strtok(ligne, ";");
				int date2;
				float temp2;
				
				struct tm tm2;		//Convertit la date en secondes
				strptime(donnee, "%Y-%m-%dT%H:%M:%S%z", &tm2);
				date2 = mktime(&tm2);
				
				donnee = strtok(NULL, ";");
				temp2 = atof(donnee);	//Récupere la température
				if(methode <2){
					if(temp2 != 0) tri = traitementLignetemp2(tri, date2, temp2, methode);
				}
				else{
					if(temp2 != 0) triListe = traitementLignetemp2Liste(triListe, date2, temp2);
				}	
			}
			if(methode < 2){
				creationFichierSortie(tri, "sortie.txt", codeSortie);
			}
			else{
				creationFichierSortieListe(triListe, "sortie.txt", codeSortie);
			}
			break;
		case 2: //Cas de -t3
			while (fgets(ligne, sizeof(ligne), entree)){
				char* donnee = strtok(ligne, ";");
				int station3;
				int date3;
				float temp3;
				
				station3 = atoi(donnee);	//Récupere le premier champ qui est le numéro de la station
				
				donnee = strtok(NULL, ";");
				struct tm tm3;		//Convertit la date en secondes
				strptime(donnee, "%Y-%m-%dT%H:%M:%S", &tm3); //Cette fois on ne prend pas le décalage horaire car il faut comparer les horaires en fonction du moment de la journée
				date3 = mktime(&tm3);
				
				
				donnee = strtok(NULL, ";");
				temp3 = atof(donnee);		//Récupere la température
				if(methode < 2){
					if(temp3 != 0) tri = traitementLignetemp3(tri, station3, date3, temp3, methode);
				}
				else{
					if(temp3 != 0) triListe = traitementLignetemp3Liste(triListe, station3, date3, temp3);
				}
			}
			if(methode < 2){
				creationFichierIndividuel(tri);
			}
			else{
				creationFichierIndividuelListe(triListe);
			}
			break;
		case 6: //Cas de -w
			codeSortie = "101100110000";	//Le code comprenant la station, la direction du vent, la vitesse du vent, la longitude et la latitude
			while (fgets(ligne, sizeof(ligne), entree)){
				char* donnee = strtok(ligne, ";");
				int station7;
				int dirvent7;
				float vitvent7;
				float longi7;
				float lati7;
				
				station7 = atoi(donnee);	//Récupere le premier champ qui est le numéro de la station
				
				donnee = strtok(NULL, ";");
				dirvent7 = atoi(donnee);	//Récupere la direction du vent

				donnee = strtok(NULL, ";");
				vitvent7 = atof(donnee);	//Récupere la vitesse du vent

				donnee = strtok(NULL, ";");
				sscanf(donnee, "%f,%f", &longi7, &lati7);
				if(methode < 2){
					if(dirvent7 !=0) tri = traitementLignevent(tri, station7, dirvent7, vitvent7, longi7, lati7, methode);
				}
				else{
					if(dirvent7 !=0) triListe = traitementLigneventListe(triListe, station7, dirvent7, vitvent7, longi7, lati7);
				}
			}
			if(methode < 2){
				creationFichierSortie(tri, "sortie.txt", codeSortie);
			}
			else{
				creationFichierSortieListe(triListe, "sortie.txt", codeSortie);
			}
			break;
		case 7: //Cas de -h
			codeSortie = "100000110001";	//Le code comprenant la station, la longitude, la latitude et l'altitude
			while (fgets(ligne, sizeof(ligne), entree)){
				char* donnee = strtok(ligne, ";");
				int station8;
				float longi8;
				float lati8;
				int alt8;
				
				station8 = atoi(donnee);	//Récupere le premier champ qui est le numéro de la station
				
				donnee = strtok(NULL, ";");
				sscanf(donnee, "%f,%f", &longi8, &lati8);
				
				donnee = strtok(NULL, ";");
				alt8 = atoi(donnee);	//Récupere l'altitude
				if(methode < 2){
					tri = traitementLignealt(tri, station8, longi8, lati8, alt8, methode);
				}
				else{
					triListe = traitementLignealtListe(triListe, station8, longi8, lati8, alt8);
				}
			}
			if(methode < 2){
				creationFichierSortieReverse(tri, "sortie.txt", codeSortie);
			}
			else{
				creationFichierSortieReverseListe(triListe, "sortie.txt", codeSortie);
			}
			break;
		case 8: //Cas de -m
			codeSortie = "100010110000";	//Le code comprenant la station,l'humidité, la longitude et la latitude
			while (fgets(ligne, sizeof(ligne), entree)){
				char* donnee = strtok(ligne, ";");
				int station9;
				int humid9;
				float longi9;
				float lati9;
				
				station9 = atoi(donnee);	//Récupere le premier champ qui est le numéro de la station
				
				donnee = strtok(NULL, ";");
				humid9 = atoi(donnee);		//Récupere l'humidité
				
				donnee = strtok(NULL, ";");
				sscanf(donnee, "%f,%f", &longi9, &lati9);
				if(methode < 2){
					tri = traitementLignehumidstation(tri, station9, humid9, longi9, lati9, methode);
				}
				else{
					triListe = traitementLignehumidstationListe(triListe, station9, humid9, longi9, lati9);
				}
			}
			pArbre final = NULL;
			pChainon finalListe = NULL;
			if(methode < 2){
				final = traitementLignehumid(tri, final, methode); //Arbre final avec les stations triées par humidité max
				creationFichierSortieReverse(final, "sortie.txt", codeSortie);
			}
			else{
				finalListe = traitementLignehumidListe(triListe, finalListe);
				creationFichierSortieReverseListe(finalListe, "sortie.txt", codeSortie);
			}
			free(final);
			free(finalListe);
			break;
		default:
			printf("Pas de mode de tri");	//Erreur si aucun mode n'a été réccupérer
			return 1;
	}
	fclose(entree);
	free(tri);
	return 0;
}
