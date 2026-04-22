#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
class Diem
{
private:
    double x, y;

public:
    Diem()
    {
        this->x = 0;
        this->y = 0;
    }
    Diem(double xx = 0, double yy = 0) : x(xx), y(yy) {}

    void NhapDiem()
    {
        cout << "Moi ban nhap diem x: ";
        cin >> this->x;
        cout << "Moi ban nhap diem y: ";
        cin >> this->y;
    }
    void XuatDiem()
    {
        cout << "Diem co toa do la: (" << this->x << "," << this->y << ")";
    }
    double TinhDoDaiCanh(Diem other)
    {
        return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
    }
    void TinhTien(double dx, double dy)
    {
        cout << "Nhap toa do tinh tien cua x: \n";
        cin >> dx;
        cout << "Nhap toa do tinh tien cua y: \n";
        cin >> dy;
        this->x += dx;
        this->y += dy;
    }
    void PhongTo(double k)
    {

        this->x *= k;
        this->y *= k;
    }
    void ThuNho(double l)
    {

        this->x /= l;
        this->y /= l;
    }
    void Quay(double goc)
    {

        double xmoi = this->x * cos(goc / 180 * PI) - this->y * sin(goc / 180 * PI);
        double ymoi = this->x * sin(goc / 180 * PI) + this->y * cos(goc / 180 * PI);
        this->x = xmoi;
        this->y = ymoi;
    }
};

class cTamGiac
{
private:
    Diem A, B, C;

public:
    void NhapDinh()
    {
        cout << "Nhap dinh A: \n";
        A.NhapDiem();
        cout << "Nhap dinh B: \n";
        B.NhapDiem();
        cout << "Nhap dinh C: \n";
        C.NhapDiem();
    }
    // Kiem tra
    void KiemTraTamGiac()
    {
        double a = B.TinhDoDaiCanh(C);
        double b = A.TinhDoDaiCanh(C);
        double c = A.TinhDoDaiCanh(B);
        // Kiem tra
        if (a + b <= c || a + c <= b || b + c <= a)
        {
            cout << "Day khong phai tam giac!";
            return;
        }
        if (a == b && b == c)
        {
            cout << "Day la tam giac deu\n";
        }
        else if (a == b || b == c || a == c)
        {
            cout << "Day la tam giac can\n";
        }
        else
        {
            cout << "Day la tam giac thuong\n";
        }
    }
    double TinhChuVi()
    {
        double a = B.TinhDoDaiCanh(C);
        double b = A.TinhDoDaiCanh(C);
        double c = A.TinhDoDaiCanh(B);
        return a + b + c;
    }
    double TinhDienTich()
    {
        double a = B.TinhDoDaiCanh(C);
        double b = A.TinhDoDaiCanh(C);
        double c = A.TinhDoDaiCanh(B);
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c)); // Heron
    }
    void TinhTienTamGiac()
    {
        double dx, dy;
        cout << "Nhap toa do tinh tien cua x: \n";
        cin >> dx;
        cout << "Nhap toa do tinh tien cua y: \n";
        cin >> dy;
        A.TinhTien(dx, dy);
        B.TinhTien(dx, dy);
        C.TinhTien(dx, dy);
    }
    void PhongToTamGiac()
    {
        double k;
        cout << "Moi ban nhap kich thuoc muon phong to: ";
        cin >> k;
        A.PhongTo(k);
        B.PhongTo(k);
        C.PhongTo(k);
    }
    void ThuNhoTamGiac()
    {
        cout << "Moi ban nhap kich thuoc muon thu nho(khac 0): ";
        double l;
        do
        {
            cin >> l;
        } while (l > 0);
        A.ThuNho(l);
        B.ThuNho(l);
        C.ThuNho(l);
    }
    void QuayTamGiac()
    {
        double goc;
        cout << "Moi ban nhap goc quay(0-360): ";
        do
        {
            cin >> goc;
        } while (goc < 0 || goc > 360);
        A.Quay(goc);
        B.Quay(goc);
        C.Quay(goc);
    }
};

int main()
{

    return 0;
}