#include "base.h"

#define NUM_EQUIPOS    8

static const char *EQUIPOS[NUM_EQUIPOS] = {
    "Chiefs",
    "Broncos",
    "Cowboys",
    "Vikings",
    "Bears",
    "Jaguars",
    "Eagles",
    "Seahawks"
};


// Genera un nombre aleatorio de letras minusculas
void generar_nombre(char *buf) {
    int largo = 4 + rand() % (MAX_NOMBRE - 4);  // entre 4 y MAX_NOMBRE-1
    for (int i = 0; i < largo; i++)
        buf[i] = 'a' + rand() % 26;
    buf[0] -= 32;   // primera letra mayuscula 
    buf[largo] = '\0';
}

//Llena el arreglo con deportistas generados aleatoriamente
void generar_deportistas(Deportista *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        generar_nombre(arr[i].nombre);
        strcpy(arr[i].equipo, EQUIPOS[rand() % NUM_EQUIPOS]);
        arr[i].puntaje     = 10.0 + (rand() % 9001) / 100.0;  
        arr[i].competencias = 1 + rand() % 100;
    }
}

//Fisher-Yates shuffle 
void mezclar_fisher_yates(Deportista *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Deportista tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

//Guarda el arreglo en un CSV
void guardar_csv(Deportista *arr, int n, const char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (!f) { printf("Error al crear %s\n", archivo); return; }

    fprintf(f, "ID,Nombre,Equipo,Puntaje,Competencias\n");
    for (int i = 0; i < n; i++)
        fprintf(f, "%d,%s,%s,%.2f,%d\n",
            arr[i].id, arr[i].nombre, arr[i].equipo,
            arr[i].puntaje, arr[i].competencias);

    fclose(f);
    printf("Guardado: %s (%d deportistas)\n", archivo, n);
}

//Carga un CSV al arreglo, retorna cantidad leida 
int cargar_csv(Deportista *arr, const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (!f) { printf("Error al abrir %s\n", archivo); return 0; }

    char linea[256];
    fgets(linea, sizeof(linea), f);  //saltar encabezado 

    int i = 0;
    while (i < MAX_DEPORTISTAS && fgets(linea, sizeof(linea), f)) {
        sscanf(linea, "%d,%11[^,],%19[^,],%lf,%d",
            &arr[i].id,
            arr[i].nombre,
            arr[i].equipo,
            &arr[i].puntaje,
            &arr[i].competencias);
        i++;
    }

    fclose(f);
    printf("Cargados %d deportistas desde %s\n", i, archivo);
    return i;
}

//Imprime un deportista en una linea 
void imprimir_deportista(Deportista *d) {
    printf("%-6d %-12s %-10s %6.2f  %3d competencias\n",
        d->id, d->nombre, d->equipo, d->puntaje, d->competencias);
}