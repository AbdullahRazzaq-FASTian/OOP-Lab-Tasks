#include <bits/stdc++.h>
#define nl (cout << endl)
#define PI 3.14
using namespace std;

class Shape
{
protected:
    pair<float, float> position;
    string colors;

public:
    Shape(string color, pair<float, float> pos) : position(pos), colors(color) {};

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() {};
};

class Circle : Shape
{
protected:
    float radius;

public:
    Circle(string color, pair<float, float> pos, float radius) : Shape(color, pos), radius(radius) {}
    void draw() const override
    {
        cout << "Drawing a circle with center at position (" << position.first << ", " << position.second << ") with radius " << radius << endl;
    }
    double calculateArea() const override
    {
        return PI * pow(radius, 2);
    }

    double calculatePerimeter() const override
    {
        return 2 * PI * radius;
    }
};

class Rectangle : Shape
{
protected:
    float width, height;

public:
    Rectangle(string color, pair<float, float> pos, float width, float height)
        : Shape(color, pos), width(width), height(height) {};

    void draw() const override
    {
        cout << "Drawing a rectangle with its top-left corner at position (" << position.first << ", " << position.second << ") with width " << width << " and height " << height << endl;
    }

    double calculateArea() const override
    {
        return width * height;
    }

    double calculatePerimeter() const override
    {
        return 2 * (width + height);
    }
};

class Triangle : Shape
{
protected:
    float base, height;

public:
    Triangle(string color, pair<float, float> pos, float base, float height)
        : Shape(color, pos), base(base), height(height) {};

    void draw() const override
    {
        cout << "Drawing a triangle with median at position (" << position.first << ", " << position.second << ") with base " << base << " and height " << height << endl;
    }
    double calculateArea() const override
    {
        return 0.5 * base * height;
    }

    double calculatePerimeter() const override
    {
        double s = (base + height + sqrt(pow(base, 2) + pow(height, 2)));
        return s;
    }
};
class Polygon : Shape
{
    //Due to shortage of time i cannot implement this Class as it will make it further complex. 
    // To implement this class i would do these things
    // Member Variables: noOfVertices, arrayOfVertices of size noOfVertices and datatype Pair<float, float>
    // To override calculateParameter() and calculateArea() functions i'll use formulae 
};

int main()
{
    Circle circle("Red", {0.0, 0.0}, 5.0);
    Rectangle rectangle("Blue", {2.0, 3.0}, 4.0, 6.0);
    Triangle triangle("Green", {1.0, 1.0}, 3.0, 4.0);

    cout << "--- Shape Details ---" << endl;

    // Circle
    circle.draw();
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl;
    nl;

    // Rectangle
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;
    nl;

    // Triangle
    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << endl;
    cout << "Perimeter: " << triangle.calculatePerimeter() << endl;
    nl;

    return 0;
}