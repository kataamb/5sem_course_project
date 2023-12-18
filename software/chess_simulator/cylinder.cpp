#include "cylinder.h"
#include <cmath>

Cylinder::Cylinder(double x, double y, double z, double radius, double height)
{
   _setCentre(x, y, z);
   _radius = radius;
   _height = height;
   polygonize(PARTS);
}


void Cylinder::polygonize(int n)
{
    double delta_angle = M_PI * 2 / n;
    //double rst_angle = M_PI * 2 - delta_angle * n + delta_angle;

    double xp, xn;
    double yp, yn;
    double z_up = _centre.coordinates[2] + _height/2, z_dwn = _centre.coordinates[2] - _height/2;
    double xc = _centre.coordinates[0], yc = _centre.coordinates[1];

    for (int i = 1; i < n - 1; i++) // because of rest angle
    {
        //upper triangle
        xp = _centre.coordinates[0] + cos( (i-1) * delta_angle ) * _radius;
        yp = _centre.coordinates[1] + sin( (i-1) * delta_angle ) * _radius;

        xn = _centre.coordinates[0] + cos( (i) * delta_angle )* _radius;
        yn = _centre.coordinates[1] + sin( (i) * delta_angle )* _radius;

        triangles.push_back({{xp, yp, z_up},
                                {xn, yn, z_up},
                                {xc, yc, z_up}});
        //down triangle
        triangles.push_back({{xp, yp, z_dwn},
                                {xn, yn, z_dwn},
                                {xc, yc, z_dwn}});
       //middle
       //upper traingle
        triangles.push_back({{xp, yp, z_up},
                                {xn, yn, z_up},
                                {xn, yn, z_dwn}});
        //down triangle
        triangles.push_back({{xp, yp, z_up},
                                {xp, yp, z_dwn},
                                {xn, yn, z_dwn}});
    }
    //last iteration -
    //upper triangle
    xp = xn;
    yp = yn;

    xn = _centre.coordinates[0] + cos( (0) * delta_angle ) * _radius;
    yn = _centre.coordinates[1] + sin( (0) * delta_angle ) * _radius;

    triangles.push_back({{xp, yp, z_up},
                            {xn, yn, z_up},
                            {xc, yc, z_up}});
    //down triangle
    triangles.push_back({{xp, yp, z_dwn},
                            {xn, yn, z_dwn},
                            {xc, yc, z_dwn}});
   //middle
   //upper traingle
    triangles.push_back({{xp, yp, z_up},
                            {xn, yn, z_up},
                            {xn, yn, z_dwn}});
    //down triangle
    triangles.push_back({{xp, yp, z_up},
                            {xp, yp, z_dwn},
                            {xn, yn, z_dwn}});

}
