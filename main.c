#include <assert.h>
#include <stdbool.h>

/*------------------------------------------*/
#include "EstructuraGrafo24.h"
#include "APIG24.h"

#include <stdio.h>
/*------------------------------------------*/
#include "APIG24.h" 


/*testear todas las funciones de la primera etapa y hacerlas andar */
/* 1 - testear construir grafo grafo 
        --debera agarrar un grafo y ordenarlo esto lo voy a testear manualmente
        -- en cargar grafo esta lo importante
            --- aca vamos a un array de lados y lo vamos a cargar capaz que a mano con las cosas del grafo 
            --- tambien lo vamos a ordenar 
            --- vamos a chequear que en el grafo sean iguales 
        */

void printGrafo(Grafo G){
    printf("Grafo :\n");
    printf("Numero de vertices : %u \n", G->numero_vertices);
    printf("Numero de lados : %u \n", G->numero_lados);
    printf("Delta : %u \n",G->delta);
    printf("Vertices: ");
    for(u32 i =0 ; i<G->numero_vertices;i++){
        printf(" %u , ", G->ver[i].nombre);
    }
    printf("\n");
}

//void printVecinos(Grafo G , u32 *vecinos){}

void printVecinos(Grafo G ){
    printf("print vecinos : \n");
    for(u32 i =0 ; i<G->numero_vertices; i++){
        printf("vecinos de %u : \n" , G->ver[i].nombre);
        for(u32 j =0 ; j<G->ver[i].grado;j++)
            printf(" %u ",G->ver[i].vecinos[j]);
    }
}/*guarda mal obvio */
int main (int agrc, char * argv[]){
    FILE *file = fopen(argv[0],"r");
    if(file == NULL){
        printf ("Archivo no encontrado \n");
    }
    Grafo g = ConstruirGrafo();
    printGrafo(g);
    printVecinos(g);
    fclose(file);
    return 0;

}