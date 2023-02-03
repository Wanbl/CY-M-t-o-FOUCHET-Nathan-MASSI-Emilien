#!/usr/local/bin/gnuplot -persist

set terminal pngcairo
set output 'sortie/vent.png'
set key off

set xlabel "Longitude"
set ylabel "Latitude"

plot 'sortie.txt' using 4:5:($3*cos($2*pi/180)):($3*sin($2*pi/180)) with vectors

set terminal wx

replot

pause mouse close
