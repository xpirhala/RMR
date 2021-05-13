
#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>
#include <fstream>
#include <map.h>
#include "mainwindow.h"
breakpoints breakPointcoor[100];
int breakpoints=0;


coordinates navigation(float destinationX,float destinationY, LaserMeasurement laserData,float currentX,float currentY,float phi){
    float wallX, wallY,wallX2,wallY2;
    coordinates chosen;

    if(breakpoints<50){
    for(int i=1;i<laserData.numberOfScans;i++){
        if((laserData.Data[i-1].scanDistance<3000)&&(laserData.Data[i-1].scanDistance>0)){

               //cout << "   dist  "<<laserData.Data[i-1].scanDistance;
              wallX=currentX*100+laserData.Data[i-1].scanDistance*cos(phi-laserData.Data[i-1].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
              wallY=currentY*100+laserData.Data[i-1].scanDistance*sin(phi-laserData.Data[i-1].scanAngle*3.1415/180)/10;

              if((laserData.Data[i].scanDistance<3000)&&(laserData.Data[i].scanDistance>0)){
                  wallX2=currentX*100+laserData.Data[i].scanDistance*cos(phi-laserData.Data[i].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
                  wallY2=currentY*100+laserData.Data[i].scanDistance*sin(phi-laserData.Data[i].scanAngle*3.1415/180)/10;

                  if((sqrt((wallX-wallX2)*(wallX-wallX2)+(wallY-wallY2)*(wallY-wallY2)))>50){
                      breakPointcoor[breakpoints].x=wallX;
                      breakPointcoor[breakpoints].y=wallY;
                      breakpoints++;
                      breakPointcoor[breakpoints].x=wallX2;
                      breakPointcoor[breakpoints].y=wallY2;
                      breakpoints++;
                  }
                }else{
                  breakPointcoor[breakpoints].x=wallX;
                  breakPointcoor[breakpoints].y=wallY;
                  breakpoints++;
              }





    }else{
            breakPointcoor[breakpoints].x=wallX2;
            breakPointcoor[breakpoints].y=wallY2;
            breakpoints++;
        }



}}

    float new_distance,old_distance=100000;
cout<<"velkost "<<breakpoints;
     for(int y=0;y<breakpoints;y++){
        new_distance=sqrt((breakPointcoor[y].x-destinationX)*(breakPointcoor[y].x-destinationX)+(breakPointcoor[y].y-destinationY)*(breakPointcoor[y].y-destinationY));
        if(new_distance<old_distance){
            chosen.x=breakPointcoor[y].x/100;
            chosen.y=breakPointcoor[y].y/100;
            old_distance=new_distance;
        }
     }

     cout << "breakpoints x:" << chosen.x <<"y:  " << chosen.flag;
breakpoints=0;
return chosen;
}
