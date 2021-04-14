#ifndef MAP_H
#define MAP_H

#include "rplidar.h"


class Map
{

    int arrayX=0;
    int arrayY=0;
    int **map;
public:
    Map(int resolutionX,int resolutionY,int realX,int realY);

    void writeFile();
     void updateMap();
     void procesLaserData(LaserMeasurement measurments,float currentX,float currentY,float phis);
     void floatingAlgorithm(float destinationX,float destinationY);
};

#endif // MAP_H
