#include <iostream>
#include <vector>

class Shape
{
public:
    virtual double area() = 0;
};
class Triangle : public Shape // 1/2 * osnova * vysota
{
private:
    double base;
    double height;
public:
    Triangle(double a, double h) : base{ a }, height{ h } {}
    double area() override
    {
        return 0.5 * base * height;
    }
};
class Circle : public Shape // pi * r^2
{
private:
    double const pi = 3.14;
    double radius;
public:
    Circle(double r) : radius{ r } {}
    double area() override
    {
        return pi * (radius * radius);
    }
};
class Rectangle : public Shape // a * b
{
private:
    double width;
    double height;
public:
    Rectangle(double a, double b) : width{ a }, height{ b } {}
    double area() override
    {
        return width * height;
    }
};


int main()
{
    Triangle triangle(5, 7.5);
    Circle circle(8);
    Rectangle rectangle(9, 6);
    Shape* figures[3];
    double sum = 0.0;

    figures[0] = static_cast<Shape*>(&triangle);
    figures[1] = static_cast<Shape*>(&circle);
    figures[2] = static_cast<Shape*>(&rectangle);

    for (int i = 0; i < 3; i++)
    {
        sum += figures[i]->area();
    }
    std::cout << "Sum: " << sum << std::endl;
}

