#include <iostream>
#include <memory>
using namespace std;

class DisplayDrv {
    public:
        virtual ~DisplayDrv() {}
        virtual void wykonaj() = 0;
};

class LowResDispDrv : public DisplayDrv {
    public:
        virtual void wykonaj() override final{
            cout << "Wykonuje LowResDispDrv\n";
        }
};

class HighResDispDrv : public DisplayDrv {
    public:
        virtual void wykonaj() override final{
            cout << "Wykonuje HighResDispDrv\n";
        }
};

class PrinterDrv {
    public:
        virtual ~PrinterDrv() {}
        virtual void wykonaj() = 0;
};

class LowResPrtDrvr : public PrinterDrv {
    public:
        virtual void wykonaj() override final{
            cout << "Wykonuje LowResPrtDrv\n";
        }
};

class HighResPrtDrvr : public PrinterDrv {
    public:
        virtual void wykonaj() override final{
            cout << "Wykonuje HighResPrtDrv\n";
        }
};

class ResFactory {
    public:
        virtual ~ResFactory() {}
        virtual unique_ptr<DisplayDrv> getDispDrv() = 0;
        virtual unique_ptr<PrinterDrv> getPrintDrv() = 0;
};

class LowResFactory : public ResFactory {
    public:
        virtual unique_ptr<DisplayDrv> getDispDrv() {
            return unique_ptr<DisplayDrv> {new LowResDispDrv()};
        }
        virtual unique_ptr<PrinterDrv> getPrintDrv() {
            return unique_ptr<PrinterDrv> {new LowResPrtDrvr()};
        }
};

class HighResFactory : public ResFactory {
    public:
        virtual unique_ptr<DisplayDrv> getDispDrv() {
            return unique_ptr<DisplayDrv> {new HighResDispDrv()};
        }
        virtual unique_ptr<PrinterDrv> getPrintDrv() {
            return unique_ptr<PrinterDrv> {new HighResPrtDrvr()};
        }
};

int main() {
    unique_ptr<ResFactory> fabryka(new LowResFactory);
    unique_ptr<DisplayDrv> ddrv = fabryka->getDispDrv();
    unique_ptr<PrinterDrv> pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();

    fabryka.reset(new HighResFactory);
    ddrv = fabryka->getDispDrv();
    pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();
}