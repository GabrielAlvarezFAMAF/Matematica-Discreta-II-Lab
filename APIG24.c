#include "APIG24.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
Lados build_lados(u32 total_lados) {
    printf("entre a build lados \n");
    Lados l = (Lados)calloc(total_lados , sizeof (struct LadoSt)); 
    return l ; 
}
Lados store_lados(Lados l , u32 x,u32 y , u32 i ){
    l[2*i].ladox = x ;
    l[2*i].ladoy = y ; 
    l[2*i+1].ladox = y ;
    l[2*i+1].ladoy= x ;
    return l ;
}

int comparar_lados(const void *a, const void *b)
{
    LadoSt *x1 = (LadoSt *)a;
    LadoSt *x2 = (LadoSt *)b;
    if (x1->ladox < x2->ladox)
    {
        return -1;
    }
    else if (x1->ladox > x2->ladox)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Lados ordenar_lados(Lados l, u32 m)
{
    qsort(l, m, sizeof(struct LadoSt), comparar_lados);
    return l ;
}
/*--------------------------------------------------------------------------------------------------------*/  
Lados load_lados(u32 *m , u32 *n ){
    u32 x = 0 , y = 0 , count = 0,i = 0;
    bool finder = false ; 
    Lados lados = NULL; 
    char k ; 
    while (fscanf(stdin ,"%c" , &k ) != EOF && !finder){
        /*reservar memoria para lados*/
        if (k == 'p') {
            count = fscanf(stdin , " edge %u %u" , n,m); 
            if(count != 2 ) {
                printf ("READING ERROR ! \n"); 
                exit (EXIT_FAILURE);
            }/*este lo pasa*/
            lados = build_lados(2*(*m)); //el dos es por la repeticion ojo
        } 
        /*leer el lado */ 
        else if(k == 'e'){
            count= fscanf(stdin , "%u %u " , &x ,&y ); 
            if (count != 2) {
                printf ("READING ERROR 2 ! "); 
                exit (EXIT_FAILURE);
            }
            lados = store_lados(lados, x, y, i ) ; 
            i++; 
            if(i== (*m)) {
                finder = true;
            }
        }
        /*posiblemente haya que hacer un pedacito mas para ingnorar algunas */ 
    }
    return lados;
}
bool busqueda_binaria_vertices(u32 numero, Grafo g ,u32 al) {
    assert(g!= NULL);
    if (al ==0){return false;}
    else{
        u32 inicio = 0;
        u32 fin=al;
        //if( g->numero_lados !=0) {fin = (g->numero_lados)-1;} 
        while (inicio <= fin) {
            u32 medio = inicio + (fin - inicio) / 2; 
            if (g->ver[medio].nombre == numero) {
                return true; 
            } else if (g->ver[medio].nombre < numero) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }
    }
    return false; 
}

/*4 Grafo */ 
u32 *inicializar_vecinos(){
    u32 *vecinos = (u32 *) calloc(1, sizeof(u32));
    return vecinos;
}
Grafo inicializar_grafo(u32 n, u32 m)
{
    Grafo G = (Grafo)calloc(1, sizeof(struct GrafoSt));
    G->numero_vertices = n;
    G->numero_lados = m;
    G->delta = 0;
    G->ver = (Vertices)calloc(n, sizeof(struct VerticeSt));
    return G;
}
Grafo cargar_grafo(Grafo g , Lados l ) {
    l = ordenar_lados(l , g->numero_lados*2);
    u32 i =0 , k=0;
    while(k < g->numero_lados*2){
            if(!busqueda_binaria_vertices(l[k].ladox,g ,i)){
                g->ver[i].nombre = l[k].ladox; 
                g->ver[i].c = 0 ; 
                g->ver[i].vecinos=inicializar_vecinos();
                for (u32 q =0 ; q< (g->numero_lados)*2 ; q++){
                    if (g->ver[i].nombre == l[q].ladox)
                    {
                        if (g->ver[i].grado ==0){
                            g->ver[i].vecinos[g->ver[i].grado] = l[q].ladoy;
                            g->ver[i].grado++;
                        }else{
                        g->ver[i].vecinos = (u32*)realloc(g->ver[i].vecinos , (g->ver[i].grado) * sizeof(u32));
                        g->ver[i].vecinos[g->ver[i].grado] = l[q].ladoy;
                        g->ver[i].grado++;
                        }
                    }
                }                
                if(g->delta < g->ver[i].grado){g->delta = g->ver[i].grado;}
                i++;
            }
            else{k++;}
        }
        return g;
    }
    /*complejidad aproximada O(n log n)*/
Grafo ConstruirGrafo(){
    u32 n,m; 
    Lados l = load_lados(&m,&n);
    l = ordenar_lados(l,2*m);
    Grafo G =  inicializar_grafo(n,m); 
    assert(G != NULL);
    G = cargar_grafo(G,l);
    free (l);
    return G ;
}
void DestruirGrafo(Grafo G ){
    free(G->ver);
    G->ver = NULL;
    free(G);
    G = NULL ;
    assert(G==NULL);
}
u32 NumeroDeVertices(Grafo G)
{
    return G->numero_vertices;
}

u32 NumeroDeLados(Grafo G)
{
    return G->numero_lados;
}

u32 Delta(Grafo G)
{
    return G->delta;
}

u32 Nombre(u32 i, Grafo G)
{
    return G->ver[i].nombre;
}

u32 Grado(u32 i, Grafo G)
{
    return G->ver[i].grado;
}
color Color(u32 i,Grafo G){
    return G->ver[i].c;
}
u32 Vecino(u32 j,u32 i,Grafo G){
    u32 vecino; 
    if(i >= G->numero_vertices || (i < G->numero_vertices && j >= G->ver[i].grado)){
        vecino= (2^32) -1 ;
    }else if (i<= G->numero_vertices){
        vecino = G->ver[i].vecinos[j];
    }
    return vecino; 
}
void AsignarColor(color x,u32 i,Grafo  G){
    if(i<G->numero_vertices){
        G->ver[i].c = x;
    }
}
void ExtraerColores(Grafo G,color* Color){
    Color = (u32*)calloc(G->numero_vertices , sizeof(u32));
    /*hace falta o lo pruebo en el main? */
    for(u32 i=0 ; i<G->numero_vertices ; i++){
        Color[i]= G->ver[i].c;
    }
}
void ImportarColores(color* Color,Grafo  G){
    for(u32 i=0 ; i<G->numero_vertices ; i++){
        G->ver[i].c=Color[i]; 
    }
}