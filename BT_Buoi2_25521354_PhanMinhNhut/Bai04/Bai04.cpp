#include <iostream>
#include <iomanip>

using namespace std;

class ThoiGian
{
private:
    int gio, phut, giay;

    void QuyDinh()
    {
        phut += giay / 60;
        giay %= 60;
        if (giay < 0)
        {
            giay += 60;
            phut--;
        }
        gio += phut / 60;
        phut %= 60;
        if (phut < 0)
        {
            phut += 60;
            gio--;
        }

        gio %= 24;
        if (gio < 0)
            gio += 24;
    }

public:
    ThoiGian()
    {
        gio = 0;
        phut = 0;
        giay = 0;
        QuyDinh();
    }
    int getGio()
    {
        return gio;
    }
    int getPhut()
    {
        return phut;
    }
    int getGiay()
    {
        return giay;
    }
    void setGio(int h)
    {
        gio = h;
        QuyDinh();
    }
    void setPhut(int m)
    {
        phut = m;
        QuyDinh();
    }
    void setGiay(int s)
    {
        giay = s;
        QuyDinh();
    }
    void nhap()
    {
        cout << "Nhap gio, phut, giay: ";
        cin >> gio >> phut >> giay;
        QuyDinh();
    }
    void xuat() const
    {
        cout << setfill('0') << setw(2) << gio << ":"
             << setw(2) << phut << ":"
             << setw(2) << giay << endl;
    }
    void tangGiay()
    {
        giay++;
        QuyDinh();
    }
    void giamGiay()
    {
        giay--;
        QuyDinh();
    }

    void tangPhut()
    {
        phut++;
        QuyDinh();
    }
    void giamPhut()
    {
        phut--;
        QuyDinh();
    }
};

int main()
{
    ThoiGian t1;
    cout << "Thoi gian ban dau t1: ";
    t1.xuat();
    cout << "Tang t1 len 1 giay: ";
    t1.tangGiay();
    t1.xuat();

    cout << "Tang t1 them 1 giay nua (sang ngay moi): ";
    t1.tangGiay();
    t1.xuat();
    ThoiGian t2;
    cout << "\nNhap thoi gian cho t2:\n";
    t2.nhap();
    cout << "Thoi gian t2 vua nhap: ";
    t2.xuat();
    t2.setGio(12);
    cout << "Sau khi set t2 ve 12 gio: ";
    t2.xuat();

    return 0;
}