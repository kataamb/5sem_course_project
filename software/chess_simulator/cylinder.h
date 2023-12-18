#ifndef CYLINDER_H
#define CYLINDER_H

#include "polygonmodel.h"



class Cylinder: public PolygonModel
{
public:
    Cylinder(double x, double y, double z, double radius, double height);
    void polygonize(int n) override;

};

#endif // CYLINDER_H
