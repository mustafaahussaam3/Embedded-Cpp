#include <iostream>

struct Point{
    int x, y;
    Point ( int x = 0, int y = 0 ): x(x), y(y){}
};

void f1(Point p){
    //copy constructor will be used on the argument
    p.x = 4;
    p.y = 5;
}

void f2(Point& p){
    p.x = 10;
    p.y = 11;
}

void f3(const Point& p){
    //only const methods of the class can be invoked on this argument
    std::cout<< p.x << " " << p.y << std::endl; // 10, 11
}

void f4(Point *p){
     p->x = 20;
     p->y = 30;
}

int main(){

    Point p1(3, 3);
    f1(p1);
    std::cout<< p1.x << " " << p1.y << std::endl; // 3, 3
    f2(p1);
    std::cout<< p1.x << " " << p1.y << std::endl; // 10, 11
    f3(p1);
    f4(&p1);
    std::cout<< p1.x << " " << p1.y << std::endl; // 20, 30

return 0;
}