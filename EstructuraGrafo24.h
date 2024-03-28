#ifndef EGRAFO_H
#define EGRAFO_H

typedef unsigned int u32;
typedef u32 color ;

/*name*/ 
typedef struct GrafoSt GrafoSt ;
typedef struct VerticeSt VerticeSt ;
typedef struct LadoSt LadoSt ;

/*4arrays maybe*/
typedef VerticeSt *Vertices  ; 
typedef LadoSt *Lados ; 

struct VerticeSt {
    u32 nombre;
    u32 grado; 
    color c ; 
    u32 *vecinos ; // array dinamico con todos los vertices vecinos  
}; 
struct GrafoSt {
    u32 delta; 
    u32 numero_lados ; 
    u32 numero_vertices ; 
    Vertices ver ; // array dinamico con todos los vertices del grafo 
    //color *colres; /*array dinamico con los colores de cada vertice*/
    //u32 *grados ; /*array dinamico con los grados de cada vertice*/;
}; 
struct LadoSt {
    u32 ladox; 
    u32 ladoy;
};



#endif