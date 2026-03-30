#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
class PhanSo
{
private:
	int tu;
	int mau;
public:
	void NhapPhanSo();
	void SetTu(int tu);
	void SetMau(int mau);
	int GetTu();
	int GetMau();

};

void PhanSo::NhapPhanSo()
{
	cout << "Nhap tu so: ";
	cin >> this->tu;
	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> this->mau;
	} while (this->mau == 0);
}

PhanSo operator + (PhanSo a, PhanSo b)
{
	PhanSo c;
	c.SetTu(a.GetTu() * b.GetMau() + b.GetTu() * a.GetMau());
	c.SetMau(a.GetMau() * b.GetMau());
	return c;

}

PhanSo operator - (PhanSo a, PhanSo b)
{
	PhanSo c;
	c.SetTu(a.GetTu() * b.GetMau() - b.GetTu() * a.GetMau());
	c.SetMau(a.GetMau() * b.GetMau());
	return c;
}

PhanSo operator * (PhanSo a, PhanSo b)
{
	PhanSo c;
	c.SetTu(a.GetTu() * b.GetTu());
	c.SetMau(a.GetMau() * b.GetMau());
	return c;
}

PhanSo operator / (PhanSo a, PhanSo b)
{
	PhanSo c;
	c.SetTu(a.GetTu() * b.GetMau());
	c.SetMau(a.GetMau() * b.GetTu());
	return c;
}

int PhanSo::GetTu()
{
	return this->tu;
}

int PhanSo::GetMau()
{
	return this->mau;
}

void PhanSo::SetTu(int tu)
{
	this->tu = tu;
}

void PhanSo::SetMau(int mau)
{
	this->mau = mau;
}

int main()
{
	PhanSo a, b, c;
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