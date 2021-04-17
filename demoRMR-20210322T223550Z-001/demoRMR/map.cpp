#include "map.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>
#include <fstream>


Map::Map(int resolutionX,int resolutionY,int realX,int realY)
{

    this->arrayX=realX/resolutionX;
    this->arrayY=realY/resolutionY;


    this->map=(int **)malloc(arrayY* sizeof(int *));
    this->floatingmap=(int **)malloc(arrayY* sizeof(int *));

        for (int i=0;i<this->arrayY;i++){
            this->map[i]=(int *)malloc(this->arrayX*sizeof(int));
this->floatingmap[i]=(int *)malloc(this->arrayX*sizeof(int));
}

    for(int y=0;y<this->arrayY;y++){
        for(int x=0;x<this->arrayX;x++){
            map[y][x]=0;
            floatingmap[y][x]=0;
        }
    }
}

void Map::updateMap(){

    this->floatingAlgorithm(0,3.5);
    this->writeFile();

}


void Map::readMap(){
    //FILE *myfile;
    string buff;
    ifstream myfile("rightCoordinates.txt");
    for(int y=0;y<this->arrayY;y++){
        for(int x=0;x<this->arrayX;x++){
            this->map[y][x]=0;
        }
        }

    for(int y=0;y<this->arrayY;y++){
        getline(myfile,buff);
        for(int x=0;x<this->arrayX;x++){


           if ((int)buff[x]==49) {
                this->map[y][x]=1;
                for(int p=-3;p<7;p++){
                    this->map[y][x+p]=1;
                }

                for(int p=-3;p<4;p++){
                    this->map[y+p][x]=1;
                }
                }

        }
    }
myfile.close();
}


void Map::floatingAlgorithm(float destinationX,float destinationY){
    this->readMap();
    int mapPositionX=destinationX*100/5;
    int mapPositionY=destinationY*100/5;

    this->map[this->arrayY-mapPositionY-15][mapPositionX+15]=2;
    writeFile();

    this->floatingmap=this->map;
for(int p=0;p<10000;p++){

    for(int y=this->arrayY-1;y>=0;y--){
        for(int x=this->arrayX-1;x>=0;x--){

            if((this->floatingmap[y][x]!=0)&&(this->floatingmap[y][x]!=1)){

              if((this->floatingmap[y+1][x]==0)&&((y+1)<this->arrayY)){
                  this->floatingmap[y+1][x]=this->floatingmap[y][x]+1;
              }

              if((this->floatingmap[y-1][x]==0)&&((y-1)>0)){
                  this->floatingmap[y-1][x]=this->floatingmap[y][x]+1;
              }

              if((this->floatingmap[y][x-1]==0)&&((x-1)>0)){
                  this->floatingmap[y][x-1]=this->floatingmap[y][x]+1;
              }

              if((this->floatingmap[y][x+1]==0)&&((x+1)<this->arrayX)){
                  this->floatingmap[y][x+1]=this->floatingmap[y][x]+1;
              }
          }


        }
    }

}


    findTheWay(destinationX,destinationY);

    writeFloatingFile();

}
struct coordinates{
    int x;
    int y;
    bool flag=false;
};

void Map::findTheWay(float destinationX,float destinationY){
    int pathX=15;
    int pathY=15;

    int endX=destinationX*100/5;
    int endY=arrayY-destinationY*100/5-15;
int lastDirection=1;
    int direction=1;
    int numberOfCoordinates=100;
    int lastCoorIndex=0;
    coordinates pathCoordinate,*pathCoordinates;
    pathCoordinates =  (coordinates *) malloc(sizeof(coordinates)*numberOfCoordinates);



  //  if((pathX!=endX)&&(pathY!=endY)){
/*
    switch(direction){
    case 1:
        if(floatingmap[pathY][pathX]>floatingmap[pathY+1][pathX]){
            direction=1;
            pathCoordinate.x=pathX;
            pathCoordinate.y=pathY+1;
            pathY=pathY+1;
            break;
        }

    case 2:
        if(floatingmap[pathY][pathX]>floatingmap[pathY][pathX+1]){
            direction=2;
            pathCoordinate.x=pathX+1;
            pathCoordinate.y=pathY;
            pathX=pathX+1;
            break;
            }

    case 3:
        if(floatingmap[pathY][pathX]>floatingmap[pathY-1][pathX]){
            direction=3;
            pathCoordinate.x=pathX;
            pathCoordinate.y=pathY-1;
            pathY=pathY-1;
            break;
            }

    case 4:
        if(floatingmap[pathY][pathX]>floatingmap[pathY][pathX-1]){
            direction=4;
            pathCoordinate.x=pathX-1;
            pathCoordinate.y=pathY;
            pathX=pathX-1;
            break;
            }
     default:
        if(floatingmap[pathY][pathX]>floatingmap[pathY+1][pathX]){
            direction=1;
            pathCoordinate.x=pathX;
            pathCoordinate.y=pathY+1;
            pathY=pathY+1;
        }else if(floatingmap[pathY][pathX]>floatingmap[pathY-1][pathX]){
            direction=3;
            pathCoordinate.x=pathX;
            pathCoordinate.y=pathY-1;
            pathY=pathY-1;
        }else if(floatingmap[pathY][pathX]>floatingmap[pathY][pathX+1]){
            direction=2;
            pathCoordinate.x=pathX+1;
            pathCoordinate.y=pathY;
            pathX=pathX+1;

        }else if(floatingmap[pathY][pathX]>floatingmap[pathY][pathX-1]){
            direction=4;
            pathCoordinate.x=pathX-1;
            pathCoordinate.y=pathY;
            pathX=pathX-1;
        }
    }

*/
    int randomFlag=1;
    for(int p=0;p<1000;p++){




    if(randomFlag==1){

        if(floatingmap[pathY][pathX]>floatingmap[pathY+1][pathX]){
             if((this->floatingmap[pathY+1][pathX]!=0)&&(this->floatingmap[pathY+1][pathX]!=1)){
            direction=1;
            pathCoordinate.x=pathX;
            pathCoordinate.y=pathY+1;
            pathY=pathY+1;
             randomFlag=0;
             cout<<" chcem vidiet1 "<<floatingmap[pathY][pathX+1]<<"\n";}
        }}

        if(randomFlag==1){
        if(floatingmap[pathY][pathX]>floatingmap[pathY-1][pathX]){
            if((this->floatingmap[pathY-1][pathX]!=0)&&(this->floatingmap[pathY-1][pathX]!=1)){
            direction=3;
            pathCoordinate.x=pathX;
            pathCoordinate.y=pathY-1;
            pathY=pathY-1;
            randomFlag=0;
            cout<<" chcem vidiet3 "<<floatingmap[pathY][pathX+1]<<"\n";}
        }}


        if(randomFlag==1){
        if(floatingmap[pathY][pathX]>floatingmap[pathY][pathX+1]){
            if((this->floatingmap[pathY][pathX+1]!=0)&&(this->floatingmap[pathY][pathX+1]!=1)){
            direction=2;
            pathCoordinate.x=pathX+1;
            pathCoordinate.y=pathY;
            pathX=pathX+1;
            randomFlag=0;
            cout<<" chcem vidiety "<<floatingmap[pathY][pathX+1]<<"\n";
}
        }}

        if(randomFlag==1){
        if(floatingmap[pathY][pathX]>floatingmap[pathY][pathX-1]){
            if((this->floatingmap[pathY][pathX-1]!=0)&&(this->floatingmap[pathY][pathX-1]!=1)){

            direction=4;
            pathCoordinate.x=pathX-1;
            pathCoordinate.y=pathY;
            pathX=pathX-1;
            randomFlag=0;}
        }}

    randomFlag=1;
        cout<<floatingmap[pathY][pathX]<<"\n";


    if(lastDirection==direction){
        pathCoordinates[lastCoorIndex].x=pathCoordinate.x;
        pathCoordinates[lastCoorIndex].y=pathCoordinate.y;

    }else{
         lastCoorIndex=lastCoorIndex+1;
         pathCoordinates[lastCoorIndex].x=pathCoordinate.x;
         pathCoordinates[lastCoorIndex].y=pathCoordinate.y;
         cout<<"kokotisko "<< lastCoorIndex;
    }
cout<<" last "<< lastDirection << "  aktual  "<<direction<<"\n";
cout<<" pathX "<< pathX << "  pathY  "<<pathY<<"\n";
    lastDirection=direction;

 // }
}
    cout<<" chcem vidiety "<<floatingmap[68][27]<<"\n";
cout<<"kokot \n";
//cout<<pathCoordinates[0].x<<"  "<<pathCoordinates[0].y;

    for(int i=0;i<=lastCoorIndex;i++){
        cout<<(pathCoordinates[i].x-15)*5/100.0<<"  "<<(pathCoordinates[i].y-15)*5/100.0 << "\n";
    }

}
void Map::writeFloatingFile(){
    ofstream myfile;
    myfile.open("./mapFloatingDeli.txt");
      if (myfile.is_open())
      {
          for(int y=0;y<this->arrayY;y++){
              for(int x=0;x<this->arrayX;x++){
                   myfile << floatingmap[y][x]<<";";
              }
              myfile <<'\n';
          }
        myfile.close();
      }else cout << "Unable to open file";
}

void Map::writeFile(){
    ofstream myfile;
    myfile.open("./map.txt");
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


              int mapPositionY=wallY/5;

              this->map[this->arrayY-mapPositionY-15][mapPositionX+15]=1;

}
    }

    this->writeFile();



}
