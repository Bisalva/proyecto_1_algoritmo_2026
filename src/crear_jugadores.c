#include "test.h"


void crear_csv(){

    Jugador jugador[MAX_JUGADORES];

    FILE *file = fopen(DATA_DIR "jugadores_db.csv", "w");
    if (file == NULL) {
        printf("Error al crear archivo CSV\n");
        return;
    }

    fprintf(file, "id,nombres,equipo,puntaje,competencias\n");

    for(int i=0;i<MAX_JUGADORES;i++){

        char *temp = crear_nombre();

        jugador[i].id = i;
        strcpy(jugador[i].nombre, temp);
        strcpy(jugador[i].equipo, equipos[random_num(NMS_EQUIPOS)]);
        jugador[i].puntaje = random_num(MAX_PUNTAJE_OBTENIBLE);
        jugador[i].competencias = random_num(MAX_COMPETENCIAS);

        free(temp);
    }

    fisher_yates(jugador,MAX_JUGADORES);

    for(int i=0;i<MAX_JUGADORES;i++){
        // Guardar en CSV
        fprintf(file,
            "%d,%s,%s,%d,%d\n",
            jugador[i].id,
            jugador[i].nombre,
            jugador[i].equipo,
            jugador[i].puntaje,
            jugador[i].competencias
        );
    }

    fclose(file);
}
