#ifndef    estrella_H
#define estrella_H

#include "Pantalla.h"
#include "personaje.h"

typedef struct EstrellaRep * Estrella;

Estrella EstrellaCrea(Imagen i, int x, int y, int w, int h);
void EstrellaLibera(Estrella e);
void EstrellaDibuja(Estrella e);
int EstrellaColision(Estrella e, Personaje p);

#endif
