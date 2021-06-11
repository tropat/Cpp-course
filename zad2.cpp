#include <iostream>
using namespace std;

class B1 {
    public: 
        B1() { cout << "Tworze obiekt klasy B1\n"; }
        ~B1() { cout << "Niszcze obiekt klasy B1\n"; }
};
class V1 : public B1 {
    public :
        V1() { cout << "Tworze obiekt klasy V1\n"; }
        ~V1() { cout << "Niszcze obiekt klasy V1\n"; }
};
class D1 : virtual public V1 {
    public:
        D1() { cout << "Tworze obiekt klasy D1\n"; }
        ~D1() { cout << "Niszcze obiekt klasy D1\n"; }
};

class B2 {
    public :
        B2() { cout << "Tworze obiekt klasy B2\n"; }
        ~B2() { cout << "Niszcze obiekt klasy B2\n"; }
};

class B3 {
    public:
        B3() { cout << "Tworze obiekt klasy B3\n"; }
        ~B3() { cout << "Niszcze obiekt klasy B3\n"; }
};
class V2 : public B1, public B2 {
    public :
        V2() { cout << "Tworze obiekt klasy V2\n"; }
        ~V2() { cout << "Niszcze obiekt klasy V2\n"; }
};
class D2 : virtual public V2, public B3 {
    public:
        D2() { cout << "Tworze obiekt klasy D2\n"; }
        ~D2() { cout << "Niszcze obiekt klasy D2\n"; }
};

class M1 {
    public:
        M1() { cout << "Tworze obiekt klasy M1\n"; }
        ~M1() { cout << "Niszcze obiekt klasy M1\n"; }
};
class M2 {
    public:
        M2() { cout << "Tworze obiekt klasy M2\n"; }
        ~M2() { cout << "Niszcze obiekt klasy M2\n"; }
};

class X : public D1, public D2 {
    M1 m1;
    M2 m2;
};

int main() {
    X x;
}