#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    double* x;
    double* y;

public:
    Point();
    Point(double=0, double=0);
    Point(const Point&);
    ~Point();
    Point& operator=(const Point&);

    double getX() const;
    double getY() const;

    void setX(double);
    void setY(double);

    Point operator+(const Point&) const;
    Point operator-(const Point&) const;

    bool operator==(const Point&) const;
    bool operator!=(const Point&) const;
    double distanceTo(const Point&) const;
};
std::ostream& operator<<(std::ostream&,const Point&);
std::istream& operator>>(std::istream&,Point&);

#endif
