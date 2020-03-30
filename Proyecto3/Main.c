#include "Pantalla.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "personaje.h"
#include "Colision.h"
#include "enemigo.h"
#include "estrella.h"
#include "galaxia.h"
#include "ejercito.h"


int main(int argc, char * argv[])
{

    Pantalla_Crea("pantalla_juego",800,600);


    Imagen imagenPersonaje= Pantalla_ImagenLee("pikachudef.bmp",255);
    int anchuraPersonaje=75;
    int alturaPersonaje=75;

    Imagen imagenEnemigo= Pantalla_ImagenLee("charmanderdef.bmp",255);
    int anchuraEnemigo=75;
    int alturaEnemigo=75;

    Imagen imagenEstrella=Pantalla_ImagenLee("estrella.bmp",255);
    int anchuraEstrella=100;
    int alturaEstrella=100;

    Imagen fondo=Pantalla_ImagenLee("start1.bmp",0);
    Imagen fondo1=Pantalla_ImagenLee("retrowave.bmp",0);
    Imagen fondo2=Pantalla_ImagenLee("gameover.bmp",0);
    int terminar = 0;
    int record=0;
    int fin=0;

    char s[100];
    int t1=time(NULL); //tiempo total del programa
    int t2=0;  //tiempo transcurrido
    int t=0;


    Personaje personaje=PersonajeCrea(imagenPersonaje,rand()%(Pantalla_Anchura()-anchuraPersonaje),Pantalla_Altura()-alturaPersonaje,anchuraPersonaje,alturaPersonaje);
    Galaxia  galaxia=GalaxiaCrea(10);
    Ejercito ejercito=EjercitoCrea();

    while (Pantalla_Activa() && !terminar )
    {

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_F1))
            terminar =1;

        Pantalla_DibujaImagen(fondo,0,0, Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(163, 73, 164,255);
        Pantalla_DibujaTexto("PRESS *F1* TO \n START",315,200);
        Pantalla_Actualiza();

    }


    terminar =0;



    int puntos = 0;

    while (Pantalla_Activa() && !terminar )
    {

        if (rand()%200==0)
        {
            EjercitoInserta(ejercito,imagenEnemigo,rand()%(Pantalla_Anchura()-anchuraEnemigo),0,anchuraEnemigo,alturaEnemigo,2,2);
        }


        if (rand()%100==0)
        {
            GalaxiaInserta(galaxia, imagenEstrella, rand()%(Pantalla_Anchura()-anchuraEstrella), rand()%(Pantalla_Altura()-alturaEstrella), anchuraEstrella, alturaEstrella);
        }



        if (Pantalla_TeclaPulsada(SDL_SCANCODE_1))
            terminar =1;


        //if (EnemigoColision(Enemigodefinitivo,Personajedefinitivo)==1) terminar = 1;

        if (EjercitoColision(ejercito,personaje)==1)
            terminar=1;


        puntos += GalaxiaColision(galaxia,personaje);  // suma 5 cuando tocas estrella

        //Tiempo
        t2=time(NULL);
        t=t2-t1 + puntos*10;    //mediante la resta calcula el tiempo
        sprintf(s,"Tiempo: %d",t);
        //Fin tiempo


        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))
        {
            PersonajeMueve(personaje,-5,0);
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP))
        {
            PersonajeMueve(personaje,0,-5);
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))
        {
            PersonajeMueve(personaje,0,5);
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))
        {
            PersonajeMueve(personaje,5,0);
        }

        EjercitoMueve(ejercito);  //NUEVO


        Pantalla_DibujaImagen(fondo1,0,0, Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(0,255,255,255);
        Pantalla_DibujaTexto("press *1* to ADVANCE",0,0);
        Pantalla_DibujaTexto(s,700,40);

        GalaxiaDibuja(galaxia);
        EjercitoDibuja(ejercito);
        PersonajeDibuja(personaje);



        Pantalla_Actualiza();

        Pantalla_Espera(20);
    }

    FILE * f=fopen("resultados.txt","r");
    fscanf(f,"%d",&record);
    fclose(f);

    if(t>record)
    {

        FILE * f=fopen("resultados.txt","w");
        fprintf(f," El mayor record es:%d",t);
        fclose(f);

    }



    while (Pantalla_Activa()&&!fin)
    {

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_2))
            fin=1;

        Pantalla_DibujaImagen(fondo2,0,0,Pantalla_Anchura(),Pantalla_Altura());

        Pantalla_ColorTrazo(255,0,0,255);
        Pantalla_DibujaTexto("pulsa 2 para salir",0,0);
        sprintf(s,"has permanecido %d segundos en la partida",t);

        Pantalla_DibujaTexto(s,300,400);
        Pantalla_Actualiza();




    }


    PersonajeLibera(personaje);
    GalaxiaLibera(galaxia);
    EjercitoLibera(ejercito);


    Pantalla_ImagenLibera(imagenPersonaje);
    Pantalla_ImagenLibera(imagenEnemigo);
    Pantalla_ImagenLibera(imagenEstrella);
    Pantalla_ImagenLibera(fondo);
    Pantalla_ImagenLibera(fondo1);
    Pantalla_ImagenLibera(fondo2);

    Pantalla_Libera();
    return 0;
}

























/*#include "Pantalla.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "personaje.h"
#include "Colision.h"
#include "enemigo.h"
#include "estrella.h"
#include "galaxia.h"
#include "ejercito.h"


int main(int argc, char * argv[])
{

    Pantalla_Crea("pantalla_juego",800,600);


    Imagen entradaimagen= Pantalla_ImagenLee("pikachudef.bmp",255);
    int alturapersonaje=75;
    int anchurapersonaje=75;
    int posiciony=Pantalla_Altura() - alturapersonaje;
    int posicionx=rand() % Pantalla_Anchura() - anchurapersonaje;



    //Imagen entradaimagenenemigo= Pantalla_ImagenLee("charmanderdef.bmp",255);
    //int alturaenemigo=75;
    //int anchuraenemigo=75;
    //int posicionyenemigo= 100;    //Pantalla_Altura() - alturaenemigo;
    //int posicionxenemigo=(rand()%600)+100- anchuraenemigo;







    Imagen imagenestrella=Pantalla_ImagenLee("estrella.bmp",255);

    Imagen imagenejercito= Pantalla_ImagenLee("charmanderdef.bmp",255);
    int alturaejercito=75;
    int anchuraejercito=75;
    int posicionyejercito=Pantalla_Altura() - alturapersonaje;
    int posicionxejercito=rand() % Pantalla_Anchura() - anchurapersonaje;





    Imagen fondo=Pantalla_ImagenLee("start1.bmp",0);
    Imagen fondo1=Pantalla_ImagenLee("retrowave.bmp",0);
    Imagen fondo2=Pantalla_ImagenLee("gameover.bmp",0);
    int terminar = 0;int record=0;int fin=0;

    char s[100];
    int t1=time(NULL); //tiempo total del programa
    int t2=0;  //tiempo transcurrido
    int t=0;


    //Enemigo Enemigodefinitivo = EnemigoCrea(entradaimagenenemigo,posicionxenemigo,posicionyenemigo,anchuraenemigo,alturaenemigo,3,3);
    Personaje Personajedefinitivo=PersonajeCrea(entradaimagen,posicionx,posiciony,anchurapersonaje,alturapersonaje);
    Galaxia  galaxiadefinitiva=GalaxiaCrea(10);
    Ejercito ejercitodefinitivo=EjercitoCrea();

    while (Pantalla_Activa() && !terminar )
    {

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_F1)) terminar =1;

        Pantalla_DibujaImagen(fondo,0,0, Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(163, 73, 164,255);
        Pantalla_DibujaTexto("PRESS *F1* TO \n START",315,200);
        Pantalla_Actualiza();

    }


    terminar =0;




    while (Pantalla_Activa() && !terminar )
    {

    //EnemigoMueve(Enemigodefinitivo);


if (rand()%10==2 || rand()%10==3){

    EjercitoInserta(ejercitodefinitivo,imagenejercito,posicionxejercito,posicionyejercito,alturaejercito,anchuraejercito,3,3);

}




    if(Pantalla_TeclaPulsada(SDL_SCANCODE_A)){
            GalaxiaInserta(galaxiadefinitiva, imagenestrella, rand()%(Pantalla_Anchura()-100), rand()%(Pantalla_Altura()-100), 100, 100);
        }



    if (Pantalla_TeclaPulsada(SDL_SCANCODE_1)) terminar =1;


    //if (EnemigoColision(Enemigodefinitivo,Personajedefinitivo)==1) terminar = 1;

    if (EjercitoColision(ejercitodefinitivo,Personajedefinitivo)==1) terminar=1;


    GalaxiaColision(galaxiadefinitiva,Personajedefinitivo);
    EjercitoColision(ejercitodefinitivo,Personajedefinitivo);


    if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)){PersonajeMueve(Personajedefinitivo,-5,0);}
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)){PersonajeMueve(Personajedefinitivo,0,-5);}
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)){PersonajeMueve(Personajedefinitivo,0,5);}
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)){PersonajeMueve(Personajedefinitivo,5,0);}





        Pantalla_DibujaImagen(fondo1,0,0, Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(0,255,255,255);
        Pantalla_DibujaTexto("press *1* to ADVANCE",0,0);

        GalaxiaDibuja(galaxiadefinitiva);
        PersonajeDibuja(Personajedefinitivo);
        //EnemigoDibuja(Enemigodefinitivo);
        EjercitoDibuja(ejercitodefinitivo);


    //Tiempo
    t2=time(NULL);
    t=t2-t1;    //mediante la resta calcula el tiempo
    sprintf(s,"Tiempo: %d",t);
    Pantalla_DibujaTexto(s,700,40);
    //Fin tiempo

    Pantalla_Actualiza();

    Pantalla_Espera(20);
    }

    FILE * f=fopen("resultados.txt","r");
    fscanf(f,"%d",&record);
    fclose(f);

    if(t>record){

       FILE * f=fopen("resultados.txt","w");
       fprintf(f," El mayor record es:%d",t);
       fclose(f);

      }



    while (Pantalla_Activa()&&!fin){

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_2))fin=1;

        Pantalla_DibujaImagen(fondo2,0,0,Pantalla_Anchura(),Pantalla_Altura());

        Pantalla_ColorTrazo(255,0,0,255);
        Pantalla_DibujaTexto("pulsa 2 para salir",0,0);
        sprintf(s,"has permanecido %d segundos en la partida",t);

        Pantalla_DibujaTexto(s,300,400);
        Pantalla_Actualiza();




    }


    PersonajeLibera(Personajedefinitivo)   ;      //Personajedefinitivo es el nombre del personaje declarado
    //EnemigoLibera(Enemigodefinitivo);
    GalaxiaLibera(galaxiadefinitiva);
    EjercitoLibera(ejercitodefinitivo);


    Pantalla_ImagenLibera(fondo);
    Pantalla_ImagenLibera(fondo1);
    Pantalla_ImagenLibera(fondo2);

    Pantalla_Libera();
    return 0;
}
*/
