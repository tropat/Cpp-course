#include <iostream>
#include <string>
using namespace std;

bool isnumber(string s) {
    int i=0;
    while(s[i]!='\0') {
        if(!(isdigit(s[i]) || (i==0&&s[i]=='-'))) return false;
        ++i;
    }
    return true;
}

class Konwerter {
    public:
        Konwerter()  : liczba(0) {}
        Konwerter(unsigned long n) : liczba(n) {} 
        Konwerter(int n) {
            if(n<0) liczba = -n;
            else liczba = n;
        } 
        Konwerter(char n) : liczba(n) {}
        Konwerter(const char* n) : liczba(0) {
            int i=0;
            while(n[i]!='\0') {
                liczba += n[i];
                ++i;
            }
        }
        Konwerter(string n) : liczba(0) {
            int i=0;
            while(n[i]!='\0') {
                liczba += n[i];
                ++i;
            }
        }
        ~Konwerter() {}

    private:
        unsigned long liczba;

        friend ostream& operator<<( ostream& strumien, const Konwerter& n);
        friend istream& operator>>( istream& strumien, Konwerter& n); 
};

ostream& operator<<( ostream& strumien, const Konwerter& n) {
        return strumien << n.liczba;
}

istream& operator>>( istream& strumien, Konwerter& n) {
    string tmp;
    getline(strumien, tmp);
    if(isnumber(tmp)) {
        int l = stoi(tmp);
        if(l<0) n.liczba = -l;
        else n.liczba = l;
    }
    else {
        n.liczba = 0;
        int i=0;
        while(tmp[i]!='\0') {
            n.liczba += tmp[i];
            ++i;
        }
    }
    return strumien;
}

int main() {
    Konwerter obj1(5);
    char c = 'a';
    Konwerter obj2(c);
    const char* cc = "aa";
    Konwerter obj3(cc);
    string s = "aa";
    Konwerter obj4(s);
    Konwerter obj5;
    cout << "Obj5: ";
    cin >> obj5;
    cout << obj1 << endl;
    cout << obj2 << endl;
    cout << obj3 << endl;
    cout << obj4 << endl;
    cout << obj5 << endl;
}