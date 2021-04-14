#include "map.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>


Map::Map(int resolutionX,int resolutionY,int realX,int realY)
{

    this->arrayX=realX/resolutionX;
    this->arrayY=realY/resolutionY;


    this->map=(int **)malloc(arrayY* sizeof(int *));
        for (int i=0;i<this->arrayY;i++)
            this->map[i]=(int *)malloc(this->arrayX*sizeof(int));



    for(int y=0;y<this->arrayY;y++){
        for(int x=0;x<this->arrayX;x++){
            map[y][x]=0;
        }
    }
}

void Map::updateMap(){

    for(int y=0;y<this->arrayY;y++){
        for(int x=0;x<this->arrayX;x++){
            map[y][x]=0;
        }
    }
    this->writeFile();
    /*
    for(int y=0;y<this->arrayY;y++){
        for(int x=0;x<this->arrayX;x++){
            cout << map[x][y];
        }
        cout << "\n";
    }*/
}

void Map::writeFile(){
    ofstream myfile;
    myfile.open("./example.txt");
      if (myfile.is_open())
      {
          for(int y=0;y<this->arrayY;y++){
              for(int x=0;x<this->arrayX;x++){
                   myfile << map[y][x] ;
              }
              myfile <<'\n';
          }
        myfile.close();
      }else cout << "Unable to open file";
}

void Map::procesLaserData(LaserMeasurement measurments,float currentX,float currentY,float phi){
    float wallX,wallY;


    for(int i=0;i<measurments.numberOfScans;i++){
        if((measurments.Data[i].scanDistance<3000)&&(measurments.Data[i].scanDistance>0)){


      wallX=currentX*100+measurments.Data[i].scanDistance*cos(phi-measurments.Data[i].scanAngle*3.1415/180)/10; //premena jednotiek z m na cm
      wallY=currentY*100+measurments.Data[i].scanDistance*sin(phi-measurments.Data[i].scanAngle*3.1415/180)/10;

      int mapPositionX=wallX/5;
      //mapPositionX=mapPositionX*5;

      int mapPositionY=wallY/5;
      //mapPositionY=mapPositionY*5;
       // cout << " x  " << mapPositionX<<"  y  "<<mapPositionY ;
      //if((mapPositionX>0)&&(mapPositionY>0)){
          this->map[this->arrayY-mapPositionY-15][mapPositionX+15]=3;
    // }else {
    //       cout << " x  " << mapPositionX<<"  y  "<<mapPositionY;
    //  }
}
    }

    this->writeFile();



}
