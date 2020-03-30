#include	"enemigo.h"
#include	<stdlib.h>
#include "personaje.h"




struct EnemigoRep{
    Imagen i;
    int x,y,w,h,velox,veloy;
    };

Enemigo EnemigoCrea(Imagen i,int x,int y,int w,int h,int vx,int vy){

    Enemigo e=malloc(sizeof(struct EnemigoRep));
    e->i=i;
    e->x=x;            //rand()%600)+100; //meterselo al incializarlo en la x inicial
    e->y=y;
    e->w=w;
    e->h=h;
    e->velox=vx;
    e->veloy=vy;


return e;

}

void EnemigoLibera(Enemigo e){

        free(e);

}

void EnemigoMueve(Enemigo e)
{

    e->y=e->y+e->veloy;
    e->x=e->x+e->velox;
    if (e->x<0) {e->x=0;e->velox=e->velox*-1;}
    if (e->y<0){e->y=0;e->veloy=e->veloy*-1;}
    if (e->x>Pantalla_Anchura()-e->w) {e->x=Pantalla_Anchura()-e->w ;   e->velox=e->velox*-1;  }
    if (e->y>Pantalla_Altura()-e->h) { e->y=Pantalla_Altura()-e->h;   e->veloy=e->veloy*-1;           }
}


void EnemigoDibuja(Enemigo e)
{
    Pantalla_DibujaImagen(e->i,e->x,e->y,e->w,e->h);
}

int EnemigoColision(Enemigo e, Personaje p){


return PersonajeColision(p,e->x,e->y,e->w,e->h);

}





