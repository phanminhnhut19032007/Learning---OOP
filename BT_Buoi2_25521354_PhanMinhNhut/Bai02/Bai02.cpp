#include <iostream>

using namespace std;

class cPoint
{
private:
    double x;
    double y;

public:
    cPoint()
    {
        this->x = 0;
        this->y = 0;
    }
    void NhapPoint()
    {
        cout << "Moi ban nhap tung do: ";
        cin >> this->x;
        cout << "Moi ban nhap hoanh do: ";
        cin >> this->y;
    }
    double GetX()
    {
        return this->x;
    }
    double GetY()
    {
        return this->y;
    }
    void TinhTien(cPoint &a)
    {
        double n;
        cout << "Moi ban nhap gia tri can tinh tien: ";
        cin >> n;
        this->x = this->x + n;
        this->y = this->y + n;
    }
    void XuatPoint()
    {
        cout << "(" << this->x << ", " << this->y << ")";
    }
};
int main()
{
    cPoint a;
    a.NhapPoint();
    cout << "Diem da nhap la: ";
    a.XuatPoint();
    cout << "\n";
    a.TinhTien(a);
    cout << "Diem sau khi duoc tinh tien la:";
    a.XuatPoint();
    return 0;
}