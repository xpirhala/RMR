#include<cstdlib>
#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>
#include <fstream>
#include <map.h>
#include "mainwindow.h"
breakpoints breakPointcoor[1000];
int breakpoints=0;



struct breakpoints navigation(float destinationX,float destinationY, LaserMeasurement laserData,float currentX,float currentY,float phi){
    float wallX, wallY,wallX2,wallY2,wallX3,wallY3,wallX4,wallY4;
    struct breakpoints chosen;

    if(breakpoints<50){
    for(int i=1;i<laserData.numberOfScans;i++){
        wallX=currentX*100+laserData.Data[i-1].scanDistance*cos(+phi-laserData.Data[i-1].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
        wallY=currentY*100+laserData.Data[i-1].scanDistance*sin(+phi-laserData.Data[i-1].scanAngle*3.1415/180)/10;

        cout <<  "laser position "<<wallX<< " y: "<< wallY <<" \n";



        if((laserData.Data[i-1].scanDistance<3000)&&(laserData.Data[i-1].scanDistance>0)){


               //cout << "   dist  "<<laserData.Data[i-1].scanDistance;
              wallX=currentX*100+laserData.Data[i-1].scanDistance*cos(+phi-laserData.Data[i-1].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
              wallY=currentY*100+laserData.Data[i-1].scanDistance*sin(+phi-laserData.Data[i-1].scanAngle*3.1415/180)/10;
 cout <<  "laser position2 "<<wallX<< " y: "<< wallY <<" \n";
              if((laserData.Data[i].scanDistance<3000)&&(laserData.Data[i].scanDistance>0)){

                  wallX2=currentX*100+laserData.Data[i].scanDistance*cos(+phi-laserData.Data[i].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
                  wallY2=currentY*100+laserData.Data[i].scanDistance*sin(+phi-laserData.Data[i].scanAngle*3.1415/180)/10;
                     cout <<  "laser position2 "<<wallX2<< " y: "<< wallY2 <<" \n";
cout << sqrt((wallX-wallX2)*(wallX-wallX2)+(wallY-wallY2)*(wallY-wallY2))<<"\n\n";

                    if(i==laserData.numberOfScans-1){
                        wallX=currentX*100+laserData.Data[i].scanDistance*cos(+phi-laserData.Data[i].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
                        wallY=currentY*100+laserData.Data[i].scanDistance*sin(+phi-laserData.Data[i].scanAngle*3.1415/180)/10;
int index;
                        for(int z=0;z<laserData.numberOfScans;z++){
                            if((laserData.Data[z].scanDistance<3000)&&(laserData.Data[z].scanDistance>0)){
                                index=z;
                                cout<< "index: "<<index;
                                break;
                            }
                        }
                        if((laserData.Data[index].scanDistance<3000)&&(laserData.Data[index].scanDistance>0)){
                            wallX2=currentX*100+laserData.Data[index].scanDistance*cos(+phi-laserData.Data[index].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
                            wallY2=currentY*100+laserData.Data[index].scanDistance*sin(+phi-laserData.Data[index].scanAngle*3.1415/180)/10;
                    }}

                  if((sqrt((wallX-wallX2)*(wallX-wallX2)+(wallY-wallY2)*(wallY-wallY2)))>60){

                      if(breakpoints!=0){
                          if((breakPointcoor[breakpoints-1].x!=wallX) &&( breakPointcoor[breakpoints-1].y!=wallY)){
                          breakPointcoor[breakpoints].x=wallX;
                          breakPointcoor[breakpoints].y=wallY;
                          breakPointcoor[breakpoints].obchadzanie=1;

                          }

                          if((breakPointcoor[breakpoints-1].x!=wallX2) &&( breakPointcoor[breakpoints-1].y!=wallY2)){
                          breakPointcoor[breakpoints+1].x=wallX2;
                          breakPointcoor[breakpoints+1].y=wallY2;
                          breakPointcoor[breakpoints+1].obchadzanie=4;
                          }

                      }else{
                          breakPointcoor[breakpoints].x=wallX;
                          breakPointcoor[breakpoints].y=wallY;
                          breakPointcoor[breakpoints].obchadzanie=1;

                          breakPointcoor[breakpoints+1].x=wallX2;
                          breakPointcoor[breakpoints+1].y=wallY2;
                          breakPointcoor[breakpoints+1].obchadzanie=4;
                      }



                      if(i>2){
                          wallX3=currentX*100+laserData.Data[i-2].scanDistance*cos(phi-laserData.Data[i-2].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
                          wallY3=currentY*100+laserData.Data[i-2].scanDistance*sin(phi-laserData.Data[i-2].scanAngle*3.1415/180)/10;

                          if((fabs(fabs(wallY)-fabs(wallY3))<0.5)&&(wallX<wallX3)){
                              breakPointcoor[breakpoints].obchadzanie=2;
                          }
                      }

                      breakpoints++;




                      if(i<laserData.numberOfScans-1){

                      wallX4=currentX*100+laserData.Data[i+1].scanDistance*cos(phi-laserData.Data[i+1].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
                      wallY4=currentY*100+laserData.Data[i+1].scanDistance*sin(phi-laserData.Data[i+1].scanAngle*3.1415/180)/10;

                      if((fabs(fabs(wallY)-fabs(wallY4))<0.5)&&(wallX>wallX4)){
                          breakPointcoor[breakpoints].obchadzanie=3;
                      }
                      }

                      breakpoints++;
                      cout<<"velkost "<<breakpoints;
                  }else if(breakpoints==0){



                      breakPointcoor[breakpoints].x=wallX;
                      breakPointcoor[breakpoints].y=wallY;
                      breakPointcoor[breakpoints].obchadzanie=4;
                      breakpoints++;
                  }
                }else if(laserData.Data[i].scanDistance>0){
                  if(breakpoints>0){
                  if((breakPointcoor[breakpoints-1].x!=wallX) &&( breakPointcoor[breakpoints-1].y!=wallY)){
                  breakPointcoor[breakpoints].x=wallX;
                  breakPointcoor[breakpoints].y=wallY;
                  breakPointcoor[breakpoints].obchadzanie=1;
                  breakpoints++;
                  }
                  }else{
                      breakPointcoor[breakpoints].x=wallX;
                      breakPointcoor[breakpoints].y=wallY;
                      breakPointcoor[breakpoints].obchadzanie=1;
                      breakpoints++;}
              }

    }else if(i>0){
            if(laserData.Data[i-1].scanDistance>0){
                if(breakpoints>0){
            if((breakPointcoor[breakpoints-1].x!=wallX2) &&( breakPointcoor[breakpoints-1].y!=wallY2)){
            breakPointcoor[breakpoints].x=wallX2;
            breakPointcoor[breakpoints].y=wallY2;
            breakPointcoor[breakpoints].obchadzanie=1;
            breakpoints++;}
        }else{
                    breakPointcoor[breakpoints].x=wallX2;
                    breakPointcoor[breakpoints].y=wallY2;
                    breakPointcoor[breakpoints].obchadzanie=1;
                    breakpoints++;
                 } }}



}}

    float new_distance,old_distance=100000;
cout<<"velkost "<<breakpoints;
     for(int y=0;y<breakpoints;y++){

         if((breakPointcoor[y].x>0)&&((breakPointcoor[y].y>0))){
        new_distance=sqrt((currentX-fabs(breakPointcoor[y].x))*(currentX-fabs(breakPointcoor[y].x))+(currentY-fabs(breakPointcoor[y].y))*(currentY-fabs(breakPointcoor[y].y)))+sqrt((fabs(breakPointcoor[y].x)-destinationX)*(fabs(breakPointcoor[y].x)-destinationX)+(fabs(breakPointcoor[y].y)-destinationY)*(fabs(breakPointcoor[y].y)-destinationY));
cout << "\nbreakpoints x:" << breakPointcoor[y].x <<"y:  " << breakPointcoor[y].y << " distance  "<< new_distance;
        if(new_distance<old_distance){
            chosen.x=breakPointcoor[y].x/100;
            chosen.y=breakPointcoor[y].y/100;
            old_distance=new_distance;
            chosen.obchadzanie=breakPointcoor[y].obchadzanie;
// cout << "\nbreakpoints x:" << chosen.x <<"y:  " << chosen.y << "smer obchadzania "<<breakPointcoor[y].obchadzanie;
        }
     }
     }



     cout << "\n final breakpoint x:" << chosen.x <<"y:  " << chosen.y << "  cur "<<destinationX << "  "<<destinationY;
breakpoints=0;
return chosen;
}

void hladacPrekazok(float destinationX,float destinationY, LaserMeasurement laserData,float currentX,float currentY,float phi,struct coordinates coor[3]){
   struct breakpoints edge;
  edge= navigation(destinationX,destinationY,laserData, currentX,currentY,phi);
 // struct coordinates coor[3];

  coor[2].x=destinationX;
  coor[2].y=destinationY;

  switch(edge.obchadzanie){
  case 1:
      coor[0].y=edge.y+0.30;
      coor[1].y=edge.y+0.30;
      if(currentX<destinationX){
          coor[0].x=edge.x-0.30;
          coor[1].x=edge.x+0.30;
      }else{
          coor[0].x=edge.x+0.30;
          coor[1].x=edge.x-0.30;
      }
      break;
   case 4:
      coor[0].y=edge.y-0.30;
      coor[1].y=edge.y-0.30;
      if(currentX<destinationX){
          coor[0].x=edge.x-0.30;
          coor[1].x=edge.x+0.30;
      }else{
          coor[0].x=edge.x+0.30;
          coor[1].x=edge.x-0.30;
      }
      break;
  case 2:
     coor[0].x=edge.x+0.30;
     coor[1].x=edge.x+0.30;
     if(currentY<destinationY){
         coor[0].y=edge.y-0.30;
         coor[1].y=edge.y+0.30;
     }else{
         coor[0].y=edge.y+0.30;
         coor[1].y=edge.y-0.30;
     }
     break;
  case 3:
     coor[0].x=edge.x+0.30;
     coor[1].x=edge.x+0.30;
     if(currentY<destinationY){
         coor[0].y=edge.y+0.30;
         coor[1].y=edge.y-0.30;
     }else{
         coor[0].y=edge.y-0.30;
         coor[1].y=edge.y+0.30;
     }
     break;
  }

  for(int i=0;i<3;i++){
      cout << coor[i].x << "  "<<coor[i].y<<"\n";
  }

}
