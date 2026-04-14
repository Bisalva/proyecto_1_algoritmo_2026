#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Configuracion 

#define MAX_NOMBRE     12
#define MAX_DEPORTISTAS 10000
#define DATA_DIR       "db/"


//Estructura principal
typedef struct {
    int    id;
    char   nombre[MAX_NOMBRE];
    char   equipo[20];
    double puntaje;
    int    competencias;
} Deportista;

//Declaraciones deportistas
void generar_nombre(char *buf);
void generar_deportistas(Deportista *arr, int n);
void mezclar_fisher_yates(Deportista *arr, int n);
void guardar_csv(Deportista *arr, int n, const char *archivo);
int  cargar_csv(Deportista *arr, const char *archivo);
void imprimir_deportista(Deportista *d);

//Declaraciones ordenamiento
void bubble_sort(Deportista *arr, int n, int campo);
void insertion_sort(Deportista *arr, int n, int campo);
void selection_sort(Deportista *arr, int n, int campo);
void cocktail_sort(Deportista *arr, int n, int campo);

//Declaraciones busqueda
int busqueda_secuencial(Deportista *arr, int n, int id);
int busqueda_binaria(Deportista *arr, int n, int id);

//Declaraciones menu
void menu_principal(Deportista *arr, int *n);

void run_experimento(void);

//Campos de ordenamiento 
#define CAMPO_ID           0
#define CAMPO_NOMBRE       1
#define CAMPO_EQUIPO       2
#define CAMPO_PUNTAJE      3
#define CAMPO_COMPETENCIAS 4

#endif 