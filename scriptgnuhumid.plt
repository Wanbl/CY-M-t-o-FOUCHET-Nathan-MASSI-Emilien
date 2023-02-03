#!/usr/local/bin/gnuplot -persist

# Définir le terminal pour générer une image PNG
set terminal pngcairo
# Définir le fichier de sortie
set output 'sortie/humidite.png'

# Définir le label pour l'axe x
set xlabel "Longitude"
# Définir le label pour l'axe y
set ylabel "Latitude"

# Désactiver la légende
set key off
# Configurer la vue pour l'affichage de la carte
set view map
# Configurer l'affichage en mode pm3d
set pm3d at b map
# Configurer la grille en 3 dimensions avec un nombre de cellules spécifié
set dgrid3d 100,100,2
# Tracer la courbe en utilisant les colonnes 3, 4 et 2 du fichler de données 'sortie.txt'
splot 'sortie.txt' using 3:4:2

# Définir le terminal pour l'interface graphique
set terminal wx
# Retracer la courbe
replot
# Pause du programme jusqu'à ce que la fenêtre soit fermée par l'utilisateur
pause mouse close
