#include "base.h"

//Invierte el arreglo para el peor caso
static void invertir(Deportista *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        Deportista tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

//Mide el tiempo de un algoritmo en segundos 
static double medir(void (*algoritmo)(Deportista*, int, int), Deportista *arr, int n, int campo) {
    clock_t inicio = clock();
    algoritmo(arr, n, campo);
    clock_t fin    = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

//Corre el experimento completo 
void run_experimento(void) {
    int tamanios[]   = {100, 500, 1000, 5000, 10000};
    int num_tamanios = 5;

    const char *nombres_alg[] = {
        "bubble", "insertion", "selection", "cocktail"
    };
    void (*algoritmos[])(Deportista*, int, int) = {
        bubble_sort, insertion_sort, selection_sort, cocktail_sort
    };
    int num_alg = 4;

    Deportista base[MAX_DEPORTISTAS];
    Deportista copia[MAX_DEPORTISTAS];

    //Abrir CSVs de resultados  
    FILE *f_mejor   = fopen(DATA_DIR "exp_mejor_caso.csv",   "w");
    FILE *f_peor    = fopen(DATA_DIR "exp_peor_caso.csv",    "w");
    FILE *f_promedio= fopen(DATA_DIR "exp_caso_promedio.csv","w");

    if (!f_mejor || !f_peor || !f_promedio) {
        printf("Error al crear archivos de experimento\n");
        return;
    }

    //Encabezados
    fprintf(f_mejor, "n,bubble,insertion,selection,cocktail\n");
    fprintf(f_peor, "n,bubble,insertion,selection,cocktail\n");
    fprintf(f_promedio, "n,bubble,insertion,selection,cocktail\n");

    printf("\n=== Experimento de tiempos ===\n");
    printf("%-8s %-12s %-8s %-8s %-8s\n",
        "n", "algoritmo", "mejor", "peor", "promedio");
    printf("----------------------------------------------------\n");

    for (int t = 0; t < num_tamanios; t++) {
        int n = tamanios[t];

        //Cargar datos base desde CSV
        char archivo[64];
        sprintf(archivo, DATA_DIR "deportistas_%d.csv", n);
        cargar_csv(base, archivo);

        //Ordenar base para mejor caso 
        memcpy(copia, base, n * sizeof(Deportista));
        bubble_sort(copia, n, CAMPO_PUNTAJE);
        memcpy(base, copia, n * sizeof(Deportista));

        fprintf(f_mejor, "%d", n);
        fprintf(f_peor,  "%d", n);
        fprintf(f_promedio, "%d", n);

        for (int a = 0; a < num_alg; a++) {

            //Mejor caso: arreglo ya ordenado 
            memcpy(copia, base, n * sizeof(Deportista));
            double t_mejor = medir(algoritmos[a], copia, n, CAMPO_PUNTAJE);

            //Peor caso: arreglo invertido 
            memcpy(copia, base, n * sizeof(Deportista));
            invertir(copia, n);
            double t_peor = medir(algoritmos[a], copia, n, CAMPO_PUNTAJE);

            //Caso promedio: arreglo mezclado (promedio de 5 runs) 
            double t_prom = 0.0;
            int runs = 5;
            for (int r = 0; r < runs; r++) {
                memcpy(copia, base, n * sizeof(Deportista));
                mezclar_fisher_yates(copia, n);
                t_prom += medir(algoritmos[a], copia, n, CAMPO_PUNTAJE);
            }
            t_prom /= runs;

            fprintf(f_mejor,    ",%f", t_mejor);
            fprintf(f_peor,     ",%f", t_peor);
            fprintf(f_promedio, ",%f", t_prom);

            printf("%-8d %-12s %-8.6f %-8.6f %-8.6f\n",
                n, nombres_alg[a], t_mejor, t_peor, t_prom);
        }

        fprintf(f_mejor,    "\n");
        fprintf(f_peor,     "\n");
        fprintf(f_promedio, "\n");
    }

    fclose(f_mejor);
    fclose(f_peor);
    fclose(f_promedio);

    printf("\nResultados guardados en db/\n");
    printf("  exp_mejor_caso.csv\n");
    printf("  exp_peor_caso.csv\n");
    printf("  exp_caso_promedio.csv\n");
}
