#include "estrella.h"
#include <stdlib.h>

struct EstrellaRep
{
    Imagen i;
    int x,y,w,h;
};

Estrella EstrellaCrea(Imagen i, int x, int y, int w, int h){
    Estrella e    = malloc(sizeof(struct EstrellaRep));
    e->i = i;
    e->x = x;
    e->y = y;
    e->w = w;
    e->h = h;
    return e;
}

void EstrellaLibera(Estrella e){
    free(e);
}

void EstrellaDibuja (Estrella e)
{
    Pantalla_DibujaImagen(e->i,e->x,e->y,e->w,e->h);
}

int EstrellaColision(Estrella e, Personaje p){
    return PersonajeColision(p,e->x,e->y,e->w,e->h);
}
