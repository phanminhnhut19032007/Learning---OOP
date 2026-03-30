#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
class cPhanSo
{
private:
  int tu;
  int mau;

public:
  cPhanSo();
  void NhapPhanSo();
  void SetTu(int tu);
  void SetMau(int mau);
  int GetTu();
  int GetMau();
};
cPhanSo::cPhanSo()
{
  this->tu = 1;
  this->mau = 1;
}

void cPhanSo::NhapPhanSo()
{
  cout << "Nhap tu so: ";
  cin >> this->tu;
  do
  {
    cout << "Nhap mau so (khac 0): ";
    cin >> this->mau;
  } while (this->mau == 0);
}

cPhanSo operator+(cPhanSo a, cPhanSo b)
{
  cPhanSo c;
  c.SetTu(a.GetTu() * b.GetMau() + b.GetTu() * a.GetMau());
  c.SetMau(a.GetMau() * b.GetMau());
  return c;
}

cPhanSo operator-(cPhanSo a, cPhanSo b)
{
  cPhanSo c;
  c.SetTu(a.GetTu() * b.GetMau() - b.GetTu() * a.GetMau());
  c.SetMau(a.GetMau() * b.GetMau());
  return c;
}

cPhanSo operator*(cPhanSo a, cPhanSo b)
{
  cPhanSo c;
  c.SetTu(a.GetTu() * b.GetTu());
  c.SetMau(a.GetMau() * b.GetMau());
  return c;
}

cPhanSo operator/(cPhanSo a, cPhanSo b)
{
  cPhanSo c;
  c.SetTu(a.GetTu() * b.GetMau());
  c.SetMau(a.GetMau() * b.GetTu());
  return c;
}

int cPhanSo::GetTu()
{
  return this->tu;
}

int cPhanSo::GetMau()
{
  return this->mau;
}

void cPhanSo::SetTu(int tu)
{
  this->tu = tu;
}

void cPhanSo::SetMau(int mau)
{
  this->mau = mau;
}

int main()
{
  cPhanSo a, b, c;
  cout << "Nhap phan so a " << endl;
  a.NhapPhanSo();
  cout << "Nhap phan so b " << endl;
  b.NhapPhanSo();
  c = a + b;
  cout << "Tong hai phan so la: " << endl;
  cout << c.GetTu() << "/" << c.GetMau() << endl;
  c = a - b;
  cout << "Hieu hai phan so la: " << endl;
  cout << c.GetTu() << "/" << c.GetMau() << endl;
  c = a * b;
  cout << "Tich hai phan so la: " << endl;
  cout << c.GetTu() << "/" << c.GetMau() << endl;
  cout << "Thuong hai phan so la: " << endl;
  cout << (a / b).GetTu() << "/" << (a / b).GetMau() << endl;

  return 0;
}