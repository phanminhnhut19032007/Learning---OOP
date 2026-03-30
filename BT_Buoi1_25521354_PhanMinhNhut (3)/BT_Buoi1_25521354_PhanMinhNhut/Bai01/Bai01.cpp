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
	int UocChungLonNhat(int a, int b);
	void RutGonPhanSo();
};

void PhanSo::NhapPhanSo()
{
	cout << "Moi ban nhap phan so " << endl;
	cout << "Nhap tu so: ";
	cin >> this->tu;
	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> this->mau;
	} while (this->mau == 0);


}

int PhanSo::UocChungLonNhat(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;

}
void PhanSo::RutGonPhanSo()
{
	int temp = UocChungLonNhat(this->tu, this->mau);
	cout << "Phan so da rut gon: " << this->tu / temp << "/" << this->mau / temp << endl;


}

int main()
{
	PhanSo a;
	a.NhapPhanSo();
	a.RutGonPhanSo();
	return 0;
}