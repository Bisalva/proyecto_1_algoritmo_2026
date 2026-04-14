set terminal png size 800,500
set output "../plots/comparatives/caso_promedio.png"

set title  "Tiempos en un caso Promedio"
set xlabel "Jugadores"
set ylabel "Tiempo (segundos)"

# CSV usa coma como separador
set datafile separator ","
  
set grid  
set key left top  
set logscale y

plot "../db/exp_caso_promedio.csv" using 1:1 with linespoints title "Bubble Sort" , \
     "../db/exp_caso_promedio.csv" using 1:2 with linespoints title "Insertion Sort" , \
     "../db/exp_caso_promedio.csv" using 1:3 with linespoints title "Selectiom Sort" , \
     "../db/exp_caso_promedio.csv" using 1:4 with linespoints title "Cocktail Sort" , \