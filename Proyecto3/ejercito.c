#include "galaxia.h"
#include "pantalla.h"
#include "ejercito.h"
#include "enemigo.h"
#include <stdlib.h>
#include <stdio.h>

struct EjercitoRep
{
    Enemigo  en;
    Ejercito sig;
};

Ejercito EjercitoCrea()
{
    Ejercito e= malloc(sizeof(struct EjercitoRep));
    e->sig = NULL;
    return e;
}

void EjercitoLibera(Ejercito e)
{
    while(e->sig!=NULL)
    {
        Ejercito aux = e->sig;
        e->sig = e->sig->sig;
        EnemigoLibera(aux->en);
        free(aux);
    }
    free(e);
}

void EjercitoInserta(Ejercito e, Imagen i, int x,int y,int w,int h , int vx,int vy)
{
 Ejercito aux = malloc(sizeof(struct EjercitoRep));
 aux->en = EnemigoCrea( i, x, y, w, h ,  vx, vy);
 aux->sig = e->sig;
 e->sig = aux;
}



void EjercitoDibuja(Ejercito e)
{
    while(e->sig!=NULL)
    {
        EnemigoDibuja(e->sig->en);
        e=e->sig;
    }
}

void EjercitoMueve(Ejercito e)
{
    while(e->sig!=NULL)
    {
        EnemigoMueve(e->sig->en);
        e=e->sig;
    }
}


int EjercitoColision(Ejercito e, Personaje p)
{
    int prueba=0;
    while(e->sig!=NULL)
    {
        if ( EnemigoColision( e->sig->en, p) )
        {
            Ejercito aux = e->sig;
            e->sig = e->sig->sig;
            EnemigoLibera(aux->en);
            free(aux);
            prueba=1;
        }
        else
            e=e->sig;
    }
    return prueba;
}

















/*#include "galaxia.h"
#include "pantalla.h"
#include "ejercito.h"
#include <stdlib.h>
#include <stdio.h>

struct EjercitoRep {

Enemigo  en;
Ejercito sig;
};


Ejercito EjercitoCrea() {

    Ejercito e= malloc(sizeof(struct EjercitoRep));

    e->sig = NULL;

 return e;
}

void EjercitoLibera(Ejercito e) {


 while(e->sig!=NULL)
 {

 Ejercito aux = e->sig;

 e->sig = e->sig->sig;

 EnemigoLibera(aux->en);

 free(aux);

 }
 free(e);
}

void EjercitoMueve(Ejercito e)
{
    while(e->sig!=NULL)
    {
        EnemigoMueve(e->sig->en);
        e=e->sig;
    }
}


void EjercitoInserta(Ejercito e, Imagen i, int x,int y,int w,int h , int vx,int vy)
{
 Ejercito aux = malloc(sizeof(struct EjercitoRep));
 aux->en = EnemigoCrea( i, x, y, w, h ,  vx, vy);
 aux->sig = e->sig;
 e->sig = aux;
}

void EjercitoDibuja(Ejercito e){

while(e->sig!=NULL){


    EnemigoDibuja(e->en);
    e=e->sig;


}




}

int EjercitoColision(Ejercito e, Personaje p){

int prueba=0;
while(e->sig!=NULL)
 {
 if ( EnemigoColision( e->en, p) )
 {
 Ejercito aux = e->sig;
 e->sig = e->sig->sig;
 EnemigoLibera(aux->en);
 free(aux);
 prueba=1;
 }
 else e=e->sig;
 }



return prueba;
}

*/


