#include <math.h>
#include "mainwindow.h"

short encoderLeftPrevios = 0, encoderRightPrevios = 0;
float phi = 0, currentX = 0, currentY = 0;
long double tickToMeter = 0.000085292090497737556558; // [m/tick]
long double b = 0.23; // wheelbase distance in meters
short encoderLeft, encoderRight;


void odometry(short encoderLeft_new, short encoderRight_new)
{
    //odometria
    encoderLeft = encoderLeft_new - encoderLeftPrevios;
    encoderRight = encoderRight_new - encoderRightPrevios;

    encoderLeftPrevios = encoderLeft_new;
    encoderRightPrevios = encoderRight_new;

    phi = phi + (tickToMeter*(encoderRight - encoderLeft)/b);

    currentX = currentX + tickToMeter*(encoderRight + encoderLeft)/2*cos(phi);
    currentY = currentY + tickToMeter*(encoderRight + encoderLeft)/2*sin(phi);
}

