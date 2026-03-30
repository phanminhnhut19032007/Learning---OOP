#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
class DateOfWeek
{
private:
    int ngay;
    int thang;
    int nam;

public:
    void NhapNgayThangNam();
    void NgayTrongTuan();
    int GetNgay();
    int GetThang();
    int GetNam();
};

int DateOfWeek::GetNgay()
{
    return this->ngay;
}

int DateOfWeek::GetThang()
{
    return this->thang;
}

int DateOfWeek::GetNam()
{
    return this->nam;
}

void DateOfWeek::NhapNgayThangNam()
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

bool KiemTraNgayThangNamHopLe(int ngay, int thang, int nam)
{
    if (nam < 0)
        return false;
    if (thang > 12 || thang < 1)
        return false;
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (ngay > 31 || ngay < 1)
            return false;
        else
            return true;
    case 4:
    case 6:
    case 9:
    case 11:
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

void DateOfWeek::NgayTrongTuan()
{
    // Sử dụng công thức Zeller để tính thu trong tuần
    int d = this->ngay;
    int m = this->thang;
    int y = this->nam;
    if (m == 1 || m == 2)
    {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    string Thu[] = {"Thu Bay", "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau"};
    cout << "Ngay " << this->ngay << "/" << this->thang << "/" << this->nam << " la: " << Thu[h] << endl;
}

int main()
{
    DateOfWeek date;
    date.NhapNgayThangNam();
    if (KiemTraNgayThangNamHopLe(date.GetNgay(), date.GetThang(), date.GetNam()))
    {
        date.NgayTrongTuan();
    }
    else
    {
        cout << "Ban nhap sai,vui long nhap lai!" << endl;
    }

    return 0;
}
