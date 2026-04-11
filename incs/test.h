#include <stdio.h>

#define MAX_CHAR_NOMBRE 25
#define MAX_CHAR_EQUIPO 25
#define NMS_EQUIPOS 8
#define NMS_NOMBRES 30

typedef struct {
    int id;
    char nombre[MAX_CHAR_NOMBRE];
    char equipo[MAX_CHAR_EQUIPO];
    float puntaje;
    int competencias;
} Deportista;

// Arrays de 
extern const char *equipos[NMS_EQUIPOS];
extern const char *nombres[NMS_NOMBRES];