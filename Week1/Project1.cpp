#include <iostream>
#define PI 3.14159265
class Point { //기본적으로 private: 외부 참조 불가
public:     //: 외부참조가능
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    Point(){}
    int GetX() { return x; }
    int GetY() { return y; }
    void SetX(int a) { x = a; }
    void SetY(int b) { y = b; }
    Point operator+(int n)
    {
        Point p1;
        p1.x = x + n; p1.y = y + n;
        return p1;
    }
    Point operator+(Point p)
    {
        Point p1;
        p1.x = x + p.x; 
        p1.y = y + p.y;
        return p1;
    }
};
class Rect {
private:
    Point p1, p2;
public:
    Rect(Point pp1, Point pp2) :p1(pp1), p2(pp2)
    {
        p1 = pp1;
        p2 = pp2;//class 변수의 대입문
    }
    Rect() :p1(0, 0), p2(0, 0) {}
    //Rect(Point& pp1, Point& pp2)
    void SetP1(Point p) { p1 = p; }
    void SetP2(Point p) { p2 = p; }
    int GetX() { return abs(p1.x - p2.x); }
    int GetY() { return abs(p1.y - p2.y); }
    int area() {
        int x = p1.x - p2.x;
        int y = p1.y - p2.y;
        return abs(x * y);
    }
};
//  Point 클래스와 Rect 클래스는 은닉되어 있음
//  공개된 정보는 Point 생성자와 Rect 생성자가 알려져 있음
//  Rect 클래스에는 사각형의 면적을 구하는 area 함수가 존재
//
//  ---> Rect의 대각선 길이를 구하는 Distance 함수가 필요함
//  dist=sqrt(x*x+y*y)
class RectEx : public Rect //Rect class를 상속 private
{
public:
    RectEx(Point pp1, Point pp2, int a) : Rect(pp1, pp2)
    {
        /*SetP1(pp1);
        SetP2(pp2);*/
    }
    double distance() {
        int x = GetX();
        int y = GetY();
        return sqrt(x * x + y * y);
    }
};
//Mission : Circle 클래스를 정의하고 멤버 함수를 구현하세요
//Member Fuction: 지름(diameter), 원둘레(CLen), 원면적(area)
class Circle :public Rect
{
    // 원의 넓이 원의 둘레 원의 지름
public:
    Circle(Point pp1, Point pp2) : Rect(pp1, pp2)
    {
    }
    double diameter() {
        int x = GetX();
        int y = GetY();
        return sqrt(x * x + y * y);
    }
    double CLen() {
        int x = GetX();
        int y = GetY();
        double len = sqrt(x * x + y * y);
        return PI * len;
    }
    double Area() {
        int x = GetX();
        int y = GetY();
        double len = sqrt(x * x + y * y);
        len = len / 2;
        return PI * len * len;
    }
};

int func1(Rect* r);
int func2(Rect& r);

int main()
{
    int n1 = 10, n2 = 20;
    Point p1(n1, n1), p2(n2, n2);
    //Rect r1 = { {10, 10}, {20, 20} };//struct type 초기화
    Rect r1(p1, p2); //Rect class 생성자 이용 초기화
    Rect r2;
    Circle r3(p1, p2);
    p1.SetX(15); p1.SetY(15);
    Point p3 = p1 + 10;
    Point p4 = p1 + p3;
    Point* p5 = &p4;
    func1(&r1);//포인터 변수 전달을 위해 변수(클래스)의 주소 전달
    func2(r1);//레퍼런스 타입은 그냥 변수명 전달
    printf("여기는 main입니다: \n두 점 p1(10, 10)과 p2(20, 20)으로 이루어진 사각형의 면적은 %d 입니다\n", r2.area());
    printf("두 점 p1(10, 10)과 p2(20,20)을 지나는 원의 지름은 %lf입니다\n", r3.diameter());
    printf("두 점 p1(10, 10)과 p2(20,20)을 지나는 원의 둘레는 %lf입니다\n", r3.CLen());
    printf("두 점 p1(10, 10)과 p2(20,20)을 지나는 원의 넓이는 %lf입니다\n", r3.Area());
    printf("Point 클래스의 연산자 오버로딩 테스트1 (+): p1(%d, %d) +%d ---> (%d, %d)\n", p1.x, p1.y, 10, p3.x, p3.y);
    printf("Point 클래스의 연산자 오버로딩 테스트2 (+): p1(%d, %d) +p3(%d, %d) ---> (%d, %d)\n", p1.x, p1.y, p3.x, p3.y, p4.x, p4.y);
    printf("Point 클래스의 연산자 오버로딩 테스트2 (+): p1(%d, %d) +p3(%d, %d) ---> (%d, %d)\n", p1.x, p1.y, p3.x, p3.y, p5->x, p5->y);
}

int func1(Rect* r1) {
    printf("두 점 p1(10, 10)과 p2(20, 20)으로 이루어진 사각형의 면적은 %d 입니다\n", r1->area());
    return 0;
}

int func2(Rect& r1) {
    printf("두 점 p1(10, 10)과 p2(20, 20)으로 이루어진 사각형의 면적은 %d 입니다\n", r1.area());
    return 0;
}