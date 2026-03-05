#include "Point.h"
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

Point::Point() {
    x = new double(0.0);
    y = new double(0.0);
}

Point::Point(double x, double y) {
    this->x = new double(x);
    this->y = new double(y);
}

Point::Point(const Point& p) {
    this->x = new double(*p.x);
    this->y = new double(*p.y);
}

Point::~Point() {
    delete x;
    delete y;
}

Point& Point::operator=(const Point& p) {
    if (this != &p) {
        *(this->x) = *p.x;
        *(this->y) = *p.y;
    }
    return *this;
}

double Point::getX() const 
{ 
    return *(this->x); 
}
double Point::getY() const 
{ 
    return *(this->y); 
}

void Point::setX(double x) 
{
    *this->x = x; 
}
void Point::setY(double y) 
{ 
    *this->y = y; 
}

Point Point::operator+(const Point& p) const 
{
    return Point(*(this->x) + *p.x, *(this->y) + *p.y);
}

Point Point::operator-(const Point& p) const 
{
    return Point(*(this->x) - *p.x, *(this->y) - *p.y);
}

bool Point::operator==(const Point& p) const 
{
    return *(this->x) == *p.x && *(this->y) == *p.y;
}

bool Point::operator!=(const Point& p) const 
{
    return !(*this == p);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    double x, y;
    is >> x >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

double Point::distanceTo(const Point& p) const {
    double dx = *(this->x) - *p.x;
    double dy = *(this->y) - *p.y;
    return std::sqrt(dx * dx + dy * dy);
}

// fonction de test : ne pas modifier !
void testPoint() {
    // test des constructeurs
    Point p1(1,0);
    Point p2(p1);
    Point p3;

    // test des constructeurs avec allocation dynamique
    Point* pp1 = new Point(2,3);
    Point* pp2 = new Point(*pp1);
    Point* pp3 = new Point();

    // affichage
    cout << p1;
    cout << p2;
    cout << p3;
    cout << *pp1;
    cout << *pp2;
    cout << *pp3;

    // modificateurs
    pp3->setX(10);
    pp3->setY(-5.6);

    // accesseurs
    cout<<pp3->getX()<<endl;
    cout<<pp3->getY()<<endl;

    // saisie
    cout << "Saisissez x et y : ";
    cin >> p1;
    cout << p1;

    // egalite
    cout << (*pp1==*pp2?"true":"false") << endl;
    cout << (*pp1==*pp3?"true":"false") << endl;

    // translation
    cout<<"p2->translation(-1,3);"<<endl;
    pp2->translation(-1,3);
    cout << *pp2;

    // rotation
    cout<<"p->rotation(180);"<<endl;
    pp1->rotation(180);
    cout << *pp1;

    cout<<"p->rotation(90);"<<endl;
    pp1->rotation(90);
    cout << *pp1;

    // NE PAS OUBLIER !
    delete pp1;
    delete pp2;
    delete pp3;
}