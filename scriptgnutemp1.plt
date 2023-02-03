#!/usr/local/bin/gnuplot -persist

# Définir le terminal pour générer une image PNG
set terminal pngcairo
# Définir le fichier de sortie
set output 'sortie/temp1.png'

# Définir le label pour l'axe x
set xlabel "Stations"


# Tracer le remplissage de courbes entre les valeurs minimales et maximales de la colonne 4 et 3,
# et les représenter en gris
# Tracer la courbe moyenne de la colonne 2, représentée par des lignes et étiquetée "Moyenne"
plot 'sortie.txt' using 1:3:4 with filledcurve lc rgb "gray" title "Minimal/Maximal", \
	'sortie.txt' using 1:2 with lines title "Moyenne"


# Définir le terminal pour l'interface graphique
set terminal wx
# Retracer la courbe
replot
# Pause du programme jusqu'à ce que la fenêtre soit fermée par l'utilisateur
pause mouse close
