#!/usr/local/bin/gnuplot -persist

# Définir le terminal pour générer une image PNG
set terminal pngcairo
# Définir le fichier de sortie
set output 'sortie/temp3.png'

# Ne ppas afficher la légende
set key off
# Définir le label pour l'axe x
set xlabel "Années"


#Affiche pour chaque horaire différent une courbe de la couleur correspondante à l'horaire pour chaque station en fonction des années
plot for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==0) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==0) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#800080", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==1) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==1) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#000080", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==2) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==2) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#FF0000", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==3) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==3) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#006400", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==4) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==4) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#FFA500", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==5) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==5) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#FF69B4", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==6) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==6) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#FFFF00", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==7) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==7) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#A9A9A9", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==8) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==8) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#ADD8E6", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==9) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==9) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#A52A2A", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==10) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==10) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#90EE90", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==11) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==11) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#000000", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==12) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==12) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#808000", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==13) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==13) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#808080", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==14) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==14) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#87CEEB", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==15) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==15) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#FF00FF", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==16) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==16) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#00FFFF", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==17) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==17) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#E6E6FA", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==18) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==18) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#C0C0C0", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==19) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==19) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#CD7F32", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==20) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==20) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#FFD700", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==21) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==21) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#F5F5DC", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==22) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==22) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#40E0D0", \
	for [file in system("ls tempstation/")] "tempstation/".file using ((int($3)==23) ? (($1/3600/24/365 + 1970)) : NaN):((int($3)==23) ? $2 : NaN) with lines linewidth 0.01 lc rgb "#008080"

# Définir le terminal pour l'interface graphique
set terminal wx
# Retracer la courbe
replot
# Pause du programme jusqu'à ce que la fenêtre soit fermée par l'utilisateur
pause mouse close
