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
	PhanSo();
	void NhapPhanSo();
	void XuatPhanSo();
	int GetTu();
	int GetMau();

};

PhanSo::PhanSo()
{
	tu = 1;
	mau = 1;
}

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

void PhanSo::XuatPhanSo()
{
	cout << this->tu << "/" << this->mau << endl;
}

bool  XetTangDan(PhanSo a, PhanSo b)
{
	return (a.GetTu() * b.GetMau() < b.GetTu() * a.GetMau());
}

bool XetGiamDan(PhanSo a, PhanSo b)
{
	return (a.GetTu() * b.GetMau() > b.GetTu() * a.GetMau());
}

int PhanSo::GetTu()
{
	return this->tu;
}

int PhanSo::GetMau()
{
	return this->mau;
}

int main()
{
	int n;
	cout << "Nhap so luong phan so: ";
	cin >> n;
	PhanSo a[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan so thu " << i + 1 << ": " << endl;
		a[i].NhapPhanSo();
	}
	sort(a, a + n, XetTangDan);
	cout << "Phan so sau khi sap xep tang dan: " << endl;
	for (int i = 0; i < n; i++) // In ra các phân số sau khi sắp xếp tang dan
	{
		cout << "Phan so thu " << i + 1 << ": ";
		a[i].XuatPhanSo();
		cout << endl;
	}
	sort(a, a + n, XetGiamDan);
	cout << "Phan so sau khi sap xep giam dan: " << endl;
	for (int i = 0; i < n; i++) // In ra các phân số sau khi sắp xếp giam dan
	{
		cout << "Phan so thu " << i + 1 << ": ";
		a[i].XuatPhanSo();
		cout << endl;
	}

}