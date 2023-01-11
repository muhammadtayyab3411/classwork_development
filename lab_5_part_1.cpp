#include <iostream>

class Shape
{
protected:
    double area;
    double volume;

public:
    virtual double computeArea() = 0;
    virtual double computeVolume() = 0;
    virtual void display() = 0;
};

class Point : public Shape
{
protected:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double computeArea() override
    {
        return 0; // Point has no area
    }
    double computeVolume() override
    {
        return 0; // Point has no volume
    }
    void display() override
    {
        std::cout << "Point at (" << x << ", " << y << ")" << std::endl;
    }
};

class Circle : public Point
{
protected:
    double radius;

public:
    Circle() : Point(), radius(1) {}
    Circle(double x, double y, double radius) : Point(x, y), radius(radius) {}

    double computeArea() override
    {
        return 3.14159 * radius * radius;
    }
    double computeVolume() override
    {
        return 0; // Circle has no volume
    }
    void display() override
    {
        std::cout << "Circle of radius " << radius << " at (" << x << ", " << y << ")" << std::endl;
    }
};

class Cylinder : public Circle
{
protected:
    double height;

public:
    Cylinder() : Circle(), height(1) {}
    Cylinder(double x, double y, double radius, double height) : Circle(x, y, radius), height(height) {}

    double computeArea() override
    {
        return 2 * 3.14159 * radius * (radius + height);
    }
    double computeVolume() override
    {
        return 3.14159 * radius * radius * height;
    }
    void display() override
    {
        std::cout << "Cylinder of height " << height << " and radius " << radius << " at (" << x << ", " << y << ")" << std::endl;
    }
};

int main()
{
    Cylinder c1(12.0, 4.0, 23.6, 2.4);
    const double cylinder_area = c1.computeArea();
    std::cout << "Area : " << cylinder_area << std::endl;

    const double cylinder_volume = c1.computeVolume();
    std::cout << "Volume : " << cylinder_area << std::endl;

    c1.display();
}