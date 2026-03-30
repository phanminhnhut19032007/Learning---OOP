#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
class NgayThangNam
{
private:
	int ngay;
	int thang;
	int nam;
public:
	void NhapNgayThangNam();
	void KiemtraNgayThangNam();
	void XuatNgayKeTiep();
	int GetNgay();
	int GetThang();
	int GetNam();
};

int NgayThangNam::GetNgay()
{
	return this->ngay;
}

int NgayThangNam::GetThang()
{
	return this->thang;
}

int NgayThangNam::GetNam()
{
	return this->nam;
}

void NgayThangNam::NhapNgayThangNam()
{
	cout << "Nhap ngay: ";
	cin >> this->ngay;
	cout << "Nhap thang: ";
	cin >> this->thang;
	cout << "Nhap nam: ";
	cin >> this->nam;
}

bool NamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
		return true;
	else
		return false;
}

void NgayThangNam::KiemtraNgayThangNam()
{
	cout << "Kiem tra ngay thang nam " << endl;
	if (this->nam < 0)
	{
		cout << "Nam khong hop le!" << endl;
	}
	else
	{
		cout << "Nam hop le!" << endl;
	}

	if (this->thang > 12 || this->thang < 1)
		cout << "Thang khong hop le!" << endl;
	else
		cout << "Thang hop le!" << endl;
	switch (this->thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (this->ngay > 31 || this->ngay < 1)
			cout << "Ngay khong hop le!" << endl;
		else
			cout << "Ngay hop le!" << endl;
		break;
	case 4: case 6: case 9: case 11:
		if (this->ngay > 30 || this->ngay < 1)
			cout << "Ngay khong hop le!" << endl;
		else
			cout << "Ngay hop le!" << endl;
		break;
	case 2:
		if (NamNhuan(this->nam))
		{
			if (this->ngay > 29 || this->ngay < 1)
				cout << "Ngay khong hop le!" << endl;
			else
				cout << "Ngay hop le!" << endl;
			break;
		}
		else
		{
			if (this->ngay > 28 || this->ngay < 1)
				cout << "Ngay khong hop le!" << endl;
			else
				cout << "Ngay hop le!" << endl;
			break;
		}
	}
}


bool KiemTraNgayThangNamHopLe(int ngay, int thang, int nam)
{
	if (nam < 0)
		return false;
	if (thang > 12 || thang < 1)
		return false;
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (ngay > 31 || ngay < 1)
			return false;
		else
			return true;
	case 4: case 6: case 9: case 11:
		if (ngay > 30 || ngay < 1)
			return false;
		else
			return true;
	case 2:
		if (NamNhuan(nam))
		{
			if (ngay > 29 || ngay < 1)
				return false;
			else
				return true;
		}
		else
		{
			if (ngay > 28 || ngay < 1)
				return false;
			else
				return true;
		}
	default:
		return false;
	}
}

void NgayThangNam::XuatNgayKeTiep()
{
	int ngayketiep = this->ngay + 1;
	int thangketiep = this->thang;
	int namketiep = this->nam;
	switch (this->thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10:
		if (ngayketiep > 31)
		{
			ngayketiep = 1;
			thangketiep++;
		}
		break;
	case 4:  case 6: case 9: case 11:
		if (ngayketiep > 30)
		{
			ngayketiep = 1;
			thangketiep++;
		}
		break;
	case 12:
		if (ngayketiep > 31)
		{
			ngayketiep = 1;
			thangketiep = 1;
			namketiep++;
		}
		break;
	case 2:
		if (NamNhuan(this->nam))
		{
			if (ngayketiep > 29)
			{
				ngayketiep = 1;
				thangketiep++;
			}
		}
		else
		{
			if (ngayketiep > 28)
			{
				ngayketiep = 1;
				thangketiep++;
			}
		}
		break;

	}
	cout << "Ngay ke tiep la: " << ngayketiep << "/" << thangketiep << "/" << namketiep << endl;

}

int main()
{
	NgayThangNam date;
	date.NhapNgayThangNam();
	date.KiemtraNgayThangNam();
	if (KiemTraNgayThangNamHopLe(date.GetNgay(), date.GetThang(), date.GetNam()))
		date.XuatNgayKeTiep();
	else
		cout << "Ngay hoac thang hoac nam khong hop le, khong the tinh ngay ke tiep!" << endl;

	return 0;
}




