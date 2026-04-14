#include "base.h"

int main(void) {
    srand(time(NULL));

    Deportista arr[MAX_DEPORTISTAS];
    //Deportista copia[MAX_DEPORTISTAS]; -- TESTING

    //Generar y guardar varios tamaños 
    int tamanios[]   = {100, 500, 1000, 5000, 10000};
    int num_tamanios = 5;

    for (int t = 0; t < num_tamanios; t++) {
        int tam = tamanios[t];
        generar_deportistas(arr, tam);
        mezclar_fisher_yates(arr, tam);
        char archivo[64];
        sprintf(archivo, DATA_DIR "deportistas_%d.csv", tam);
        guardar_csv(arr, tam, archivo);
    }

    //Cargar y mostrar 
    int n = cargar_csv(arr, DATA_DIR "deportistas_100.csv");

  /*printf("\nPrimeros 5 deportistas:\n");
    printf("%-6s %-12s %-10s %6s  %s\n",
        "ID", "Nombre", "Equipo", "Puntaje", "Competencias");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < 5 && i < n; i++)
        imprimir_deportista(&arr[i]); */

   /* //Probar ordenamiento 
    printf("\n=== Original (primeros 10) ===\n");
    for (int i = 0; i < 10 && i < n; i++) imprimir_deportista(&arr[i]);*/

  /*const char *nombres[] = {"Bubble", "Insertion", "Selection", "Cocktail"};
    void (*algoritmos[])(Deportista*, int, int) = {
        bubble_sort, insertion_sort, selection_sort, cocktail_sort
    }; */

 /* for (int a = 0; a < 4; a++) {
        memcpy(copia, arr, n * sizeof(Deportista));
        algoritmos[a](copia, n, CAMPO_PUNTAJE);
        printf("\n=== %s Sort (por puntaje, primeros 10) ===\n", nombres[a]);
        for (int i = 0; i < 10 && i < n; i++) imprimir_deportista(&copia[i]);
    } */

    /*Probar busqueda
    printf("\n=== Prueba de Búsqueda ===\n");
    int id_buscar = arr[50].id;
    printf("Buscando ID %d...\n", id_buscar);

    int idx = busqueda_secuencial(arr, n, id_buscar);
    if (idx != -1)
        printf("Secuencial: encontrado en posicion %d -> ", idx);
    else
        printf("Secuencial: no encontrado\n");
    if (idx != -1) imprimir_deportista(&arr[idx]);

    memcpy(copia, arr, n * sizeof(Deportista));
    bubble_sort(copia, n, CAMPO_ID);

    idx = busqueda_binaria(copia, n, id_buscar);
    if (idx != -1)
        printf("Binaria: encontrado en posicion %d -> ", idx);
    else
        printf("Binaria: no encontrado\n");
    if (idx != -1) imprimir_deportista(&copia[idx]);

    printf("\nBuscando ID 9999 (no existe)...\n");
    idx = busqueda_secuencial(arr, n, 9999);
    printf("Secuencial: %s\n", idx != -1 ? "encontrado" : "no encontrado");
    idx = busqueda_binaria(copia, n, 9999);
    printf("Binaria:    %s\n", idx != -1 ? "encontrado" : "no encontrado");*/

    //Lanzar menu interactivo 
    printf("\nPresiona Enter para entrar al menu...");
    getchar();
    run_experimento();
    menu_principal(arr, &n);

    return 0;
}