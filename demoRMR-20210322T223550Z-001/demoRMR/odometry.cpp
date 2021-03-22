#include <math.h>
#include <mainwindow.h>


int encoderLeftPrevious=0, encoderRightPrevious=0, encoderLeft, encoderRight;
float phi;
long double tickToMeter = 0.000085292090497737556558;
long double b = 0.23; // wheelbase distance in meters
float currentX=0,currentY=0;

void odometry(int encoderLeftActual,int encoderRightActual){
    encoderLeft=encoderLeftActual-encoderLeftPrevious;
    encoderRight=encoderRightActual-encoderRightPrevious;

    phi=phi+(tickToMeter*(encoderRight - encoderLeft)/b);
    if(phi<6.28318){
        phi=phi+6.28318;
    }else if(phi>6.28318){
        phi=phi-6.28318;
    }

     currentX= currentX+tickToMeter*(encoderRight + encoderLeft)/2*cos(phi/180*3.1415);
     currentY =  currentY + tickToMeter*(encoderRight + encoderLeft)/2*sin(phi/180*3.1415);

    encoderLeftPrevious=encoderLeft;
    encoderRightPrevious=encoderRight;
}
