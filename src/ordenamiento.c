#include "base.h"

static int comparar(Deportista *a, Deportista *b, int campo) {
    switch (campo) {
        case CAMPO_ID:           return a->id - b->id;
        case CAMPO_NOMBRE:       return strcmp(a->nombre, b->nombre);
        case CAMPO_EQUIPO:       return strcmp(a->equipo, b->equipo);
        case CAMPO_PUNTAJE:      return (a->puntaje > b->puntaje) - (a->puntaje < b->puntaje);
        case CAMPO_COMPETENCIAS: return a->competencias - b->competencias;
        default:                 return 0;
    }
}

static void swap(Deportista *a, Deportista *b) {
    Deportista tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(Deportista *arr, int n, int campo) {
    for (int i = 0; i < n - 1; i++) {
        int hubo_swap = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (comparar(&arr[j], &arr[j+1], campo) > 0) {
                swap(&arr[j], &arr[j+1]);
                hubo_swap = 1;
            }
        }
        if (!hubo_swap) break;
    }
}

void insertion_sort(Deportista *arr, int n, int campo) {
    for (int i = 1; i < n; i++) {
        Deportista clave = arr[i];
        int j = i - 1;
        while (j >= 0 && comparar(&arr[j], &clave, campo) > 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = clave;
    }
}

void selection_sort(Deportista *arr, int n, int campo) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++) {
            if (comparar(&arr[j], &arr[idx_min], campo) < 0)
                idx_min = j;
        }
        if (idx_min != i)
            swap(&arr[i], &arr[idx_min]);
    }
}

void cocktail_sort(Deportista *arr, int n, int campo) {
    int inicio = 0;
    int fin    = n - 1;
    while (inicio < fin) {
        int hubo_swap = 0;
        for (int i = inicio; i < fin; i++) {
            if (comparar(&arr[i], &arr[i+1], campo) > 0) {
                swap(&arr[i], &arr[i+1]);
                hubo_swap = 1;
            }
        }
        fin--;
        for (int i = fin; i > inicio; i--) {
            if (comparar(&arr[i-1], &arr[i], campo) > 0) {
                swap(&arr[i-1], &arr[i]);
                hubo_swap = 1;
            }
        }
        inicio++;
        if (!hubo_swap) break;
    }
}