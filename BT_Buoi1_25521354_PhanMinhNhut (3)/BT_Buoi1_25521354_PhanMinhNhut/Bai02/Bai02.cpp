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
	bool Greater(PhanSo b);

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
bool PhanSo::Greater(PhanSo another)
{
	return (tu * another.mau > another.tu * mau);
}




int main()
{
	PhanSo a, b;
	cout << "Nhap phan so a: " << endl;
	a.NhapPhanSo();
	cout << "Nhap phan so b: " << endl;
	b.NhapPhanSo();
	if (a.Greater(b))
		cout << "Phan so a lon hon phan so b" << endl;
	else if (b.Greater(a))
		cout << "Phan so b lon hon phan so a" << endl;
	else
		cout << "Phan so a va Phan so b bang nhau" << endl;

	return 0;
}