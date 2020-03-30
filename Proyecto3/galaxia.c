#include "galaxia.h"
#include "pantalla.h"
#include "estrella.h"
#include <stdlib.h>
#include <stdio.h>


struct GalaxiaRep {
Estrella * e;
int n, nmax;
};



// Crea un conjunto de puntos vacío que puede contener hasta nmaxpuntos.
// Pre: nmax>0


Galaxia GalaxiaCrea(int nmax) {

Galaxia g = malloc(sizeof(struct GalaxiaRep));
g->e = malloc(nmax*sizeof(Estrella));
g->n = 0;
g->nmax= nmax;
return g;
}


                                                    // Libera la memoria asignada al conjunto de puntos c.
void GalaxiaLibera(Galaxia g) {
for(int i=0;i<g->n;i++) EstrellaLibera(g->e[i]);
free(g->e);
free(g);
}
                                                                     // P ES G  //  C ES E

// Devuelve 0 si el conjunto de puntos c no está lleno
// y un valor distinto en caso contrario


int GalaxiaLleno(Galaxia g)
{
return(g->n==g->nmax);
}


// Inserta en el conjunto de puntos c un nuevo punto de coordenadas x e y.
// Pre: !ConjuntoLleno(c)


void GalaxiaInserta(Galaxia g, Imagen i,int x,int y,int w,int h)
{

    if (!GalaxiaLleno(g)){


g->e[g->n] = EstrellaCrea(i,x,y,w,h);
g->n++;}
}


// Suprime del conjunto de puntos c todos los puntos cuya distancia al punto p
// sea menor que d.


int GalaxiaColision(Galaxia g, Personaje p)
{
int i=0;
int prueba = 0;
while(i<g->n)
{
if (EstrellaColision(g->e[i],p))
{
EstrellaLibera(g->e[i]);
g->e[i] = g->e[g->n-1];
g->n--;
prueba=prueba+1;


}
else i++;


}
return prueba;
}


// Imprime los puntos del conjunto c


void GalaxiaDibuja(Galaxia g)
{
for(int i=0;i<g->n;i++)
{
EstrellaDibuja(g->e[i]);
printf(" ");
}
}


