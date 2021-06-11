#include <iostream>
using namespace std;

class Drawing {
    public:
        virtual void drawLine() = 0;
        virtual void drawCircle() = 0;
        virtual ~Drawing() {}
};

class DP1 {
    public:
        void draw_a_line() { cout << "(dp1)Rysuje linie\n"; }
        void draw_a_circle() { cout << "(dp1)Rysuje okrag\n"; }
};

class DP2 {
    public:
        void drawline() { cout << "(dp2)Rysuje linie\n"; }
        void drawcircle() { cout << "(dp2)Rysuje okrag\n"; }
};

class V1Drawing : public Drawing {
    public:
        V1Drawing(DP1 d) : dp(d) {}
        virtual void drawLine() override { dp.draw_a_line(); }
        virtual void drawCircle() override { dp.draw_a_circle(); }
    protected:
        DP1 dp;
};

class V2Drawing : public Drawing {
    public:
        V2Drawing(DP2 d) : dp(d) {}
        virtual void drawLine() override { dp.drawline(); }
        virtual void drawCircle() override { dp.drawcircle(); }
    protected:
        DP2 dp;
};

class Shape {
    public:
        virtual void draw() = 0;
        virtual void drawLine() {drw->drawLine();}
        virtual void drawCircle() {drw->drawCircle();}
        virtual void setLib(Drawing *ptr) { drw = ptr; }
        Shape(Drawing *ptr) : drw(ptr) {}
        ~Shape() { drw=NULL; }
    protected:
        Drawing *drw;
};

class Rectangle : public Shape {
    public:
        virtual void draw() override { 
            drawLine(); 
            }
        Rectangle(Drawing *ptr) : Shape(ptr) {}
};

class Circle : public Shape {
    public:
        virtual void draw() override {
            drawCircle();
        }
        Circle(Drawing *ptr) : Shape(ptr) {}
};

int main() {
    DP1 library1;
    DP2 library2;

    Drawing *d1 = new V1Drawing( library1 );
    Drawing *d2 = new V2Drawing( library2 );
    
    Shape *p1 = new Rectangle( d1 );
    Shape *p2 = new Circle( d2 );

    cout << "p1: \n";
    p1->draw();
    cout << "\np2: \n";
    p2->draw();
    p1->setLib( d2 );
    p2->setLib( d1 );
    cout << "\np1: \n";
    p1->draw();
    cout << "\np2: \n";
    p2->draw();

    delete p1;
    delete p2;
    delete d1;
    delete d2;
}