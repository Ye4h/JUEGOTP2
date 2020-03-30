#include "Colision.h"
#include <math.h>

int Colision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    double cx1 = x1 + w1/2.0;   //Calculo el centro de los personajes
    double cy1 = y1 + h1/2.0;
    double cx2 = x2 + w2/2.0;
    double cy2 = y2 + h2/2.0;


    double r1 = sqrt(pow(w1/2.0,2) + pow(h1/2.0,2));   //Calculo el radio de los personajes
    double r2 = sqrt(pow(w2/2.0,2) + pow(h2/2.0,2));


    double dc1c2 = sqrt(pow(cx1-cx2,2) + pow(cy1-cy2,2));

    return (dc1c2 < r1+r2);
}
