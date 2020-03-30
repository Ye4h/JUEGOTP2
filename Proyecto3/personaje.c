#include	"Personaje.h"
#include	<stdlib.h>


struct PersonajeRep{
    Imagen i;
    int x,y,w,h;
    };


Personaje PersonajeCrea(Imagen i,int x,int y,int w,int h){


    Personaje p=malloc(sizeof(struct PersonajeRep));
    p->i=i;
    p->x=x;
    p->y=y;
    p->w=w;
    p->h=h;



return p;

}
void PersonajeLibera(Personaje p){

        free(p);
}

void PersonajeMueve(Personaje p,int velx,int vely)
{
    p->y+=vely;
    p->x+=velx;
    if (p->x<0) p->x=0;
    if (p->y<0) p->y=0;
    if (p->x>Pantalla_Anchura()-p->w) p->x=Pantalla_Anchura()-p->w;
    if (p->y>Pantalla_Altura()-p->h)  p->y=Pantalla_Altura()-p->h;
}

void PersonajeDibuja(Personaje p)
{
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

int PersonajeColision(Personaje p, int x, int y, int w, int h){
    return Colision(p->x,p->y,p->w,p->h,x,y,w,h);


}
