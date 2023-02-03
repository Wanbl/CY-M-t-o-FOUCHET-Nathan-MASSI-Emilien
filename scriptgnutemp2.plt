#!/usr/local/bin/gnuplot -persist

# Définir le terminal pour générer une image PNG
set terminal pngcairo
# Définir le fichier de sortie
set output 'sortie/temp2.png'

# Définir le label pour l'axe x
set xlabel "Années"

# Tracer la courbe des moyennes de températures
plot 'sortie.txt' using (($1/3600/24/365 + 1970)):2 with lines title "Moyenne température"

# Définir le terminal pour l'interface graphique
set terminal wx
# Retracer la courbe
replot
# Pause du programme jusqu'à ce que la fenêtre soit fermée par l'utilisateur
pause mouse close
