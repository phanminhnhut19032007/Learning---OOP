#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
class cSoPhuc
{
private:
    int thuc;
    int ao;

public:
    cSoPhuc();
    void NhapSoPhuc();
    void SetThuc(int thuc);
    void SetAo(int ao);
    int GetThuc();
    int GetAo();
    void XuatSoPhuc();
};
cSoPhuc::cSoPhuc()
{
    this->thuc = 1;
    this->ao = 1;
}

void cSoPhuc::NhapSoPhuc()
{
    cout << "Nhap phan thuc:";
    cin >> thuc;
    cout << "Nhap phan ao:";
    cin >> ao;
}

cSoPhuc operator+(cSoPhuc a, cSoPhuc b)
{
    cSoPhuc c;
    c.SetThuc(a.GetThuc() + b.GetThuc());
    c.SetAo(a.GetAo() + b.GetAo());
    return c;
}

cSoPhuc operator-(cSoPhuc a, cSoPhuc b)
{
    cSoPhuc c;
    c.SetThuc(a.GetThuc() - b.GetThuc());
    c.SetAo(a.GetAo() - b.GetAo());
    return c;
}

cSoPhuc operator*(cSoPhuc a, cSoPhuc b)
{
    cSoPhuc c;
    c.SetThuc(a.GetThuc() * b.GetThuc() - a.GetAo() * b.GetAo());
    c.SetAo(a.GetThuc() * b.GetAo() + a.GetAo() * b.GetThuc());
    return c;
}

cSoPhuc operator/(cSoPhuc a, cSoPhuc b)
{
    cSoPhuc c;
    c.SetThuc((a.GetThuc() * b.GetThuc() + a.GetAo() * b.GetAo()) / (b.GetThuc() * b.GetThuc() + b.GetAo() * b.GetAo()));
    c.SetAo((a.GetAo() * b.GetThuc() - b.GetAo() * a.GetThuc()) / (b.GetThuc() * b.GetThuc() + b.GetAo() * b.GetAo()));
    return c;
}

int cSoPhuc::GetThuc()
{
    return this->thuc;
}

int cSoPhuc::GetAo()
{
    return this->ao;
}

void cSoPhuc::SetThuc(int thuc)
{
    this->thuc = thuc;
}

void cSoPhuc::SetAo(int ao)
{
    this->ao = ao;
}
void cSoPhuc::XuatSoPhuc()
{
    cout << "(" << this->thuc << ", " << this->ao << ")";
}
int main()
{
    cSoPhuc a, b, c;
    cout << "Nhap so phuc a " << endl;
    a.NhapSoPhuc();
    cout << "Nhap so phuc b " << endl;
    b.NhapSoPhuc();
    c = a + b;
    cout << "\nTong hai so phuc la: " << endl;
    c.XuatSoPhuc();
    c = a - b;
    cout << "\nHieu hai so phuc la: " << endl;
    c.XuatSoPhuc();
    c = a * b;
    cout << "\nTich hai phan so la: " << endl;
    c.XuatSoPhuc();
    c = a / b;
    cout << "\nThuong hai phan so la: " << endl;
    c.XuatSoPhuc();

    return 0;
}