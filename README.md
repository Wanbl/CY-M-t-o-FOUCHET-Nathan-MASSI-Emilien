# CY-Meteo-FOUCHET-Nathan-MASSI-Emilien
Rendu du projet CY-Météo de Nathan FOUCHET et Emilien MASSI de classe MI-6

Avant utilisation :
	-Accorder les droits avec chmod 777 CYmeteo.shell
	-Ajouter un fichier de data en .csv dans le dossier du projet (à sa racine)
Utilisation : ./CYmeteo.shell [OPTIONS] -f [FICHIER] 
But : Permet de traiter les données météorologiques d'un fichier csv en fonction de divers options obligatoires ou facultatives
Options obligatoires (Au moins une est nécessaire) :
	-t<mode> Affiche la température suivant le mode entré :
		1 : Températures moyennes, maximales et minimales par station
		2 : Températures moyennes dans le temps
		3 : Températures moyennes par station par heure (chaque heure de la journée) dans le temps
	-p<mode> Affiche la pression suivant le mode entré : 
		1 : Pressions moyennes, maximales et minimales par station
		2 : Pressions moyennes dans le temps
		3 : Pressions moyennes par station par heure (chaque heure de la journée) dans le temps
	-w Affiche une carte des vents
	-h Affiche une carte des altitudes
	-m Affiche une carte de l'humidité maximale
Options facultatives :
	-d AAAA-MM-JJ AAAA-MM-JJ Sélectionne une période avec une date de début dans le format AAAA-MM-JJ puis de fin
	Localisation : Sélectionne une zone géographique : 
		-F : France métropolitaine et Corse
		-G : Guyane française
		-S : Saint-Pierre et Miquelon
		-A : Antilles
		-O : Océan Indien
		-Q : Antarctique
	Mode de tri des données : 
		--avl : tri à l'aide d'un arbre binaire de recherche équilibré
		--abr : tri à l'aide d'un arbre binaire de recherche simple
		--tab : tri à l'aide d'une liste chaînée"
Afficher l’aide :
	./CYmeteo.shell --help
Si problème avec les fichiers de compilation, entrer "make clean" dans le terminal
