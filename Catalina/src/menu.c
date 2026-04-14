#include<base.h>
//limpiar pantalla 
static void limpiar(void){
    printf("\033[2J\033[H");
}

//pausa hasta enter 
static void pausar(void){
    printf("Presiona ENTER para continuar");
    getchar();
    getchar();
}

//Muestra el encabezado de la tabla
static void encabezado(void){
    printf("%-6s %-12s %-10s %8s  %s\n",
        "ID", "Nombre", "Equipo", "Puntaje", "Competencias");
    printf("------------------------------------------------------------\n");
}

//menu campo de ordenamiento

static int elegir_campo(void){
    printf("\nOrdenar por:\n");
    printf("1. ID\n");
    printf("2. Nombre\n");
    printf("3. Equipo\n");
    printf("4. Puntaje\n");
    printf("5. Competencias");
    printf("Opcion: ");
    int op;
    scanf("%d", &op);
    switch (op){
        case 1: 
            return CAMPO_ID;
        case 2:
            return CAMPO_NOMBRE;
        case 3:
            return CAMPO_EQUIPO;
        case 4: 
            return CAMPO_PUNTAJE;
        case 5:
            return CAMPO_COMPETENCIAS;
        default:
            printf("Campo invalido, ordenado por ID\n");
            return CAMPO_ID;                    
    }
}

//elegir algoritmo de ordenamiento 

static void elegir_algoritmo(Deportista *arr, int n, int campo) {
    printf("\nAlgoritmo:\n");
    printf("  1. Bubble Sort\n");
    printf("  2. Insertion Sort\n");
    printf("  3. Selection Sort\n");
    printf("  4. Cocktail Sort\n");
    printf("Opcion: ");
    int op;
    scanf("%d", &op);
    switch (op) {
        case 1: bubble_sort(arr, n, campo);    printf("Bubble Sort aplicado.\n");    break;
        case 2: insertion_sort(arr, n, campo); printf("Insertion Sort aplicado.\n"); break;
        case 3: selection_sort(arr, n, campo); printf("Selection Sort aplicado.\n"); break;
        case 4: cocktail_sort(arr, n, campo);  printf("Cocktail Sort aplicado.\n");  break;
        default: printf("Opcion invalida.\n"); break;
    }
}

static void opcion_ordenar(Deportista *arr, int n){
    int campo = elegir_campo();
    elegir_algoritmo(arr, n, campo);
    printf("\n Primeros 10 deportistas ordenados:\n ");
    encabezado();
    for(int i = 0; i < 10 && i < n; i++)
        imprimir_deportista(&arr[i]);
    pausar();    
}

static void opcion_buscar(Deportista *arr, int n){
    printf("\n Ingresa el ID a buscar:");
    int id;
    scanf("%d", &id);
    int idx = busqueda_secuencial(arr, n, id);
    if (idx != -1){
        printf("\n Encontrado con busqueda secuencial:\n");
        encabezado();
        imprimir_deportista(&arr[idx]);
    }else{
        printf("ID %d no encontrado.\n", id);
    }
    pausar();
}


static void opcion_ranking(Deportista *arr, int n) {
    printf("\n¿Cuantos deportistas mostrar en el ranking? ");
    int top;
    scanf("%d", &top);
    if (top > n) top = n;

    Deportista copia[MAX_DEPORTISTAS];
    memcpy(copia, arr, n * sizeof(Deportista));
    bubble_sort(copia, n, CAMPO_PUNTAJE);

    printf("\n=== Ranking Top %d (por puntaje) ===\n", top);
    encabezado();
    for (int i = n - 1; i >= n - top; i--)
        imprimir_deportista(&copia[i]);
    pausar();
}

static void opcion_generar(Deportista *arr, int *n) {
    printf("\n¿Cuantos deportistas generar? ");
    scanf("%d", n);
    if (*n > MAX_DEPORTISTAS) *n = MAX_DEPORTISTAS;
    generar_deportistas(arr, *n);
    mezclar_fisher_yates(arr, *n);
    char archivo[64];
    sprintf(archivo, DATA_DIR "deportistas_%d.csv", *n);
    guardar_csv(arr, *n, archivo);
    printf("Datos generados y guardados en %s\n", archivo);
    pausar();
}

void menu_principal(Deportista *arr, int *n) {
    int opcion = 0;
    while (opcion != 5) {
        limpiar();
        printf("╔══════════════════════════════════════╗\n");
        printf("║     SISTEMA DE DEPORTISTAS           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  Deportistas cargados: %-4d          ║\n", *n);
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Ordenar deportistas              ║\n");
        printf("║  2. Buscar por ID                    ║\n");
        printf("║  3. Ranking top N                    ║\n");
        printf("║  4. Generar nuevos datos             ║\n");
        printf("║  5. Salir                            ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: opcion_ordenar(arr, *n);  break;
            case 2: opcion_buscar(arr, *n);   break;
            case 3: opcion_ranking(arr, *n);  break;
            case 4: opcion_generar(arr, n);   break;
            case 5: printf("Hasta luego.\n"); break;
            default: printf("Opcion invalida.\n"); pausar(); break;
        }
    }
}

