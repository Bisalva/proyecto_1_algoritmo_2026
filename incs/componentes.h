#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_DIR "db/"

// parametros de construccion
#define MAX_CHAR_NOMBRE 25
#define MAX_CHAR_EQUIPO 25
#define NMS_EQUIPOS 8
#define NMS_NOMBRES 30
#define MAX_PUNTAJE_OBTENIBLE 101
#define MAX_COMPETENCIAS 51
//----

// parametros limitantes
#define MAX_JUGADORES 30
#define MAX_LARGO_NOMBRE 10
//----


typedef struct {
    int id;
    char nombre[MAX_CHAR_NOMBRE];
    char equipo[MAX_CHAR_EQUIPO];
    int puntaje;
    int competencias;
} Jugador;

// Arrays de 
extern const char *equipos[NMS_EQUIPOS];
extern const char *silabas_nombres[NMS_NOMBRES];

// Prototipos void
void crear_csv();
//----

// Prototipos return
int random_num(int n);
char *crear_nombre();
//----

// Prototipos de Ordenamiento
void fisher_yates(Jugador jugador[],int n);
//----