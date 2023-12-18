#include "polygonmodel.h"

Point::Point(double x, double y, double z)
{
    coordinates[0] = x; coordinates[1] = y; coordinates[2] = z;
}

/*----------*/

Triangle::Triangle()
{
    _num = 3;
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    _num = 3;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
}
/*--------*/
PolygonModel::PolygonModel(): _centre{0, 0, 0}
{}

void PolygonModel::changeCentre(double x, double y, double z)
{
    _setCentre(x, y, z);
    polygonize();
}

void PolygonModel::_setCentre(double x, double y, double z)
{
    //_xc = x; _yc = y; _zc = z;
    //_centre[0] = x; _centre[1] = y; _centre[2] = z;
    _centre.coordinates[0] = x; _centre.coordinates[1] = y; _centre.coordinates[2] = z;

}


