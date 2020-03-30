#ifndef	__galaxia_H__
#define __galaxia_H__
#include "Pantalla.h"
#include "personaje.h"


typedef struct GalaxiaRep * Galaxia;


int GalaxiaLleno(Galaxia g);

                        // Crea una galaxia con un máximo de nmax estrellas
Galaxia GalaxiaCrea(int nmax);
                        // Libera la memoria asociada a la galaxia g
void GalaxiaLibera(Galaxia g);
                        // Inserta una nueva estrella con imagen i y coordenadas x,y,w,h
                        // en la galaxia g, si no ha llegado a su tamaño máximo.
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h);
                        // Dibuja la galaxia g
void GalaxiaDibuja(Galaxia g);
                        // Elimina de la galaxia g todas las estrellas que colisionan con el personaje p.
                        // Devuelve el número de estrellas que han colisionado
int GalaxiaColision(Galaxia g, Personaje p);

#endif
