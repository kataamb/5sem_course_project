#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "polygonmodel.h"



class Cylinder: public PolygonModel
{
public:
    Cylinder(double x, double y, double z, double radius, double height);
    void polygonize(int n) override;

};

class Parallelepiped: public PolygonModel
{
public:
    Parallelepiped(double x, double y, double z, double length, double width, double height);
    void polygonize(int n) override;
};

#endif // PARALLELEPIPED_H
