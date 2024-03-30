#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "EstructuraGrafo24.h"
#include "APIG24.h"
#include "test.h"

int main (){
    Grafo g = ConstruirGrafo();
    printGrafo(g);
    printVecinos(g);
    //printColores(g);
    DestruirGrafo(g);
    return 0;
}