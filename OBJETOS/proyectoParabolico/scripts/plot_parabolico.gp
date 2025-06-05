set title "Trayectoria del proyectil"
set xlabel "x (m)"
set ylabel "y (m)"
set grid
plot 'results/datos.dat' using 2:3 with lines title 'Trayectoria'
