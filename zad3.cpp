#include <iostream>
using namespace std;

class TOsoba {
    public:
        TOsoba() { cout << "Jestem na uczelni\n"; }
};
class MozeWykBadania {
    public:
        MozeWykBadania() { cout << "Wykonuje badania\n"; }
};
class MozeNauczac {
    public:
        MozeNauczac() { cout << "Ucze studentow\n"; }
};
class MozeBycStudentem {
    public:
        MozeBycStudentem() { cout << "Ucze sie\n"; }
};

class TStudent : public MozeBycStudentem, public TOsoba {
    public:
        TStudent() { cout << "Jestem studentem\n"; }
};

class TDoktorant : public TStudent {
    public:
        TDoktorant() { cout << "Jestem doktorantem\n"; }
};

class TDoktorantNaucz : public TDoktorant, public MozeNauczac {
    public:
        TDoktorantNaucz() { cout << "Jestem doktorantem nauczycielem\n"; }
};

class TNauczyciel : public TOsoba, public MozeNauczac {
    public:
        TNauczyciel() { cout << "Jestem nauczycielem\n"; }
};

class TAsystentBadan : public MozeWykBadania, public TOsoba {
    public:
        TAsystentBadan() { cout << "Jestem asystentem badan\n"; }
};

class TDoktorantBadacz : public TDoktorant, public TAsystentBadan {
    public:
        TDoktorantBadacz() { cout << "Jestem doktorantem badaczem\n"; }
};

int main() {
    cout << "Doktorant: \n";
    TDoktorant doktorant;
    cout << "\nOsoba: \n";
    TOsoba osoba;
    cout << "\nNauczyciel: \n";
    TNauczyciel nauczyciel;
    cout << "\nStudent: \n";
    TStudent student;
    cout << "\nAsystent: \n";
    TAsystentBadan asystent;
    cout << "\nDoktorant nauczyciel: \n";
    TDoktorantNaucz doktorantnaucz;
    cout << "\nDoktorant badacz: \n";
    TDoktorantBadacz doktorantbadacz;
}