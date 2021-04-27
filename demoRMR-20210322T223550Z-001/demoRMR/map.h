#ifndef MAP_H
#define MAP_H

#include "rplidar.h"
#include "coordinates.cpp"

class Map
{

    int arrayX=0;
    int arrayY=0;
    int **map;
    int **floatingmap;


public:
    Map(int resolutionX,int resolutionY,int realX,int realY);
    struct coordinates coor[20];
void readMap();
    void writeFile();
     void updateMap();
     void procesLaserData(LaserMeasurement measurments,float currentX,float currentY,float phis);
     int floatingAlgorithm(float destinationX,float destinationY);
    void writeFloatingFile();
    int findTheWay(float destinationX,float destinationY);
};

#endif // MAP_H
