#ifndef    ejercito_H
#define ejercito_H
#include "pantalla.h"
#include "personaje.h"
#include "enemigo.h"


typedef struct EjercitoRep * Ejercito;

Ejercito EjercitoCrea();

void EjercitoLibera(Ejercito e);


void EjercitoInserta(Ejercito e, Imagen i, int x, int y, int w, int h, int vx, int vy);

void EjercitoDibuja(Ejercito e);


int EjercitoColision(Ejercito e, Personaje p);


void EjercitoMueve(Ejercito e);




#endif
