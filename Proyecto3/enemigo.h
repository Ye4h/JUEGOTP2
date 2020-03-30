#ifndef	__enemigo_H__
#define __enemigo_H__
#include "Pantalla.h"
#include "personaje.h"

typedef struct EnemigoRep * Enemigo;

Enemigo EnemigoCrea(Imagen i,int x,int y,int w,int h,int vx,int vy);

void EnemigoLibera(Enemigo e);

void EnemigoMueve(Enemigo e);

int EnemigoColision(Enemigo e,Personaje p);




#endif
