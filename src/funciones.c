#include "componentes.h"

// Nombre de equipos asignables
const char *equipos[NMS_EQUIPOS] = 
{
    "Uno",
    "Dos",
    "Tres",
    "Cuatro",
    "Cinco",
    "Seis",
    "Siete",
    "Ocho"
};

// Silabas random para generar nombres randoms
const char *silabas_nombres[NMS_NOMBRES] = 
{
    "FA" , "FE" , "FI" , "FO" , "FU",
    "RA" , "RE" , "RI" , "RO" , "RU",
    "MA" , "ME" , "MI" , "MO" , "MU",
    "LA" , "LE" , "LI" , "LO" , "LU",
    "TA" , "TE" , "TI" , "TO" , "TU",
    "SA" , "SE" , "SI" , "SO" , "SU"
};

// Funcion de numero random  - reutilizable
int random_num(int n){
    int x = 0;

    x = rand() % n;

    return x;
}

// Funcion creadora de nombres a partir de las silabas y random (MALLOC)
char *crear_nombre(){

    char *nombre = malloc(MAX_LARGO_NOMBRE);
    int largo = 0;

    nombre[0] = '\0';

    // Garantiza al menos 1 silaba como nombre
    do{

        const char *parte = silabas_nombres[random_num(NMS_NOMBRES)];
        int len = strlen(parte);

        if(largo + len >= MAX_LARGO_NOMBRE-1)
            break;

        strcat(nombre, parte);
        largo += len;

    }while(largo == 0 || rand()%2);

    return nombre;
}

void fisher_yates(Jugador jugador[],int n){

    for(int i = n-1; i > 0; i--){
        int j = rand() % (i+1);

        Jugador temp = jugador[i];
        jugador[i] = jugador[j];
        jugador[j] = temp;
    }
}