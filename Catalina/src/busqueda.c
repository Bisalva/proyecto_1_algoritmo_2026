#include <base.h>

/*Busqueda Secuencial
Recorre el arreglo de inicio a fin comparando cada ID.
no requiere que el arreglo este ordenado 
Peor caso: O(n) - el elemento no existe o esta al fianl
*/

int busqueda_secuencial(Deportista *arr, int n, int id){
    for (int i = 0; i < n; i++){
        if (arr[i].id == id)
            return i;   /*retorna el indice donde lo encontro*/
    }
    return -1; 
}

/*Busqueda binaria (iterativa)
divide el espacio de busqueda a la mitad en cada paso
Peor caso: O(log n) el elemento no existe
*/

int busqueda_binaria(Deportista *arr, int n, int id){
    int izq = 0;
    int der = n - 1;

    while (izq <= der){
        int mid = izq + (der - izq) / 2;
        if (arr[mid].id == id)
            return mid; /*encontrado*/
        else if (arr[mid].id < id)
            izq = mid + 1;  //busca en la mitad derecha
        else
            der = mid - 1; //busca en la mitad izquierda
    }

    return -1; 
}