#ifndef	__personaje_H__
#define __personaje_H__
#include "Pantalla.h"



typedef struct PersonajeRep * Personaje;  //para no poner personajerep asterisco

Personaje PersonajeCrea(Imagen i,int x,int y,int w,int h);

void PersonajeLibera(Personaje p);

void PersonajeMueve(Personaje p,int velx, int vely);

void PersonajeDibuja(Personaje p);

int PersonajeColision(Personaje p,int x,int y,int w,int h);


#endif
