#include "EstructuraGrafo24.h"
#include "APIG24.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void printVecinos(Grafo G ){
    printf("print vecinos : \n");
    for(u32 i =0 ; i<G->numero_vertices; i++){
        printf("vecinos de %u : \n" , G->ver[i].nombre);
        for(u32 j =0 ; j<G->ver[i].grado;j++){
            printf(" %u ,",G->ver[i].vecinos[j]);
        }
        printf("\n");
    }
}
void printColores(Grafo G){
    color *aux =NULL;
    color *color = NULL;
    srand(time(NULL)); // 2 generate rand 
    ExtraerColores(G, &color);
    /*extrae los colores de un grafo cualquiera , en este punto deben ser todos 0 */ 
    printf("Colores extraidos : \n");
    for(u32 t =0 ; t <G->numero_vertices;t++){
        printf(" %u ," , color[t]);
    }
    printf("\n");
    /*asigno un color cualquier a cada uno de los vertices testeando la funcion import*/
    printf("colores asignados :\n");
    for(u32 t =0 ; t <G->numero_vertices;t++){
       aux[t]= rand()%10 ; /*rand entre 0 y 10 */
       printf("%u ," , aux[t]);
    }
    printf("\n");
    ImportarColores(aux ,&G);/*testeo la funcion y vuevlo a imprimir*/

    printf("Coloreado : \n");
    for(u32 t =0 ; t <G->numero_vertices;t++){
        printf(" %u ," , color[t]);
    }
    printf("\n");
 /*provoca cores chequear este test! */   
}