#include <math.h>
#include "mainwindow.h"

#define b 0.23
#define tickToMeter 0.000085292090497737556558


short encoderLeftPrevios = 0, encoderRightPrevios = 0,encoderLeft, encoderRight;
float phi = 0, currentX = 0, currentY = 0;


void odometry(short encoderLeft_new, short encoderRight_new)
{
    //odometria
    encoderLeft = encoderLeft_new - encoderLeftPrevios;
    encoderRight = encoderRight_new - encoderRightPrevios;

    phi = phi + (tickToMeter*(encoderRight - encoderLeft)/b); //radians

    currentX = currentX + tickToMeter*(encoderRight + encoderLeft)/2*cos(phi);
    currentY = currentY + tickToMeter*(encoderRight + encoderLeft)/2*sin(phi);

    encoderLeftPrevios = encoderLeft_new;
    encoderRightPrevios = encoderRight_new;
}

