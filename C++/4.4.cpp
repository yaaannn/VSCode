#include <iostream>
using namespace std;
class Circle
{
private:
    double radius, area, perimeter;

public:
    Circle();
    ~Circle();
    void set_radius(double Radius);
    double get_radius();
    double get_area();
    double get_perimeter();
    void disp();
};
Circle::Circle() {  }
Circle::~Circle() {}
void Circle::set_radius(double Radius) { radius = Radius; }
double Circle::get_radius() { return radius; }
double Circle::get_area()
{
    area = 3.14 * radius * radius;
    return area;
}
double Circle::get_perimeter()
{
    perimeter = 2 * 3.14 * radius;
    return perimeter;
}
void Circle::disp()
{
    get_area();
    get_perimeter();
    cout << "面积是" << area << endl;
    cout << "周长是" << perimeter << endl;
}
int main()
{
    Circle c1;
    c1.set_radius(2);
    c1.get_radius();
    c1.disp();
    return 0;
}
