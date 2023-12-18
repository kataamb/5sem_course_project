#ifndef POLYGONMODEL_H
#define POLYGONMODEL_H

#include <QPolygon>
#include <vector>

constexpr int PARTS = 100;


struct Point
{
    std::vector<double> coordinates;
    const int _num = 3;
    Point(double, double, double);
};

struct Triangle
{
    std::vector<Point> points;
    int _num;
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
};

class PolygonModel
{
protected:
    std::vector<Triangle> triangles;
    Point _centre;
    double _height;
    double _width;
    double _length;
    double _radius;
    void _setCentre(double x, double y, double z);
public:
    PolygonModel();
    virtual void changeCentre(double x, double y, double z);
    virtual void polygonize() = 0;
    virtual void polygonize(int n) = 0;
};

#endif // POLYGONMODEL_H
