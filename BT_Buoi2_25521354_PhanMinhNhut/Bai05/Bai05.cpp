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
    int SoNgayTrongTuan(int m, int y)
    {
        switch (m)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return LaNamNhuan(y) ? 29 : 28;
        default:
            return 31;
        }
    }
    bool LaNamNhuan(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    DateOfWeek(int d = 1, int m = 1, int y = 2024) : ngay(d), thang(m), nam(y) {}

    void NhapNgayThangNam();
    void NgayTrongTuan();
    int GetNgay();
    int GetThang();
    int GetNam();
    void SetNgay(int d);
    void SetThang(int m);
    void SetNam(int y);
    void TangNgay(int d);
    void GiamNgay(int d);
    void TangThang(int m);
    void GiamThang(int m);
    void TangNam(int y);
    void GiamNam(int y);
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
void DateOfWeek::SetNgay(int d)
{
    this->ngay = d;
}
void DateOfWeek::SetThang(int m)
{
    this->thang = m;
}
void DateOfWeek::SetNam(int y)
{
    this->nam = y;
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

void DateOfWeek::TangNgay(int d)
{
    this->ngay += d;
    while (this->ngay > SoNgayTrongTuan(this->thang, this->nam))
    {
        this->ngay -= SoNgayTrongTuan(this->thang, this->nam);
        this->thang++;
        if (this->thang > 12)
        {
            this->thang = 1;
            this->nam++;
        }
    }
}

void DateOfWeek::GiamNgay(int d)
{
    this->ngay -= d;
    while (this->ngay < 1)
    {
        this->thang--;
        if (this->thang < 1)
        {
            this->thang = 12;
            this->nam--;
        }
        this->ngay += SoNgayTrongTuan(this->thang, this->nam);
    }
}

void DateOfWeek::TangThang(int m)
{
    this->thang += m;
    while (this->thang > 12)
    {
        this->thang -= 12;
        this->nam++;
    }
    int maxD = SoNgayTrongTuan(this->thang, this->nam);
    if (this->ngay > maxD)
        this->ngay = maxD;
}

void DateOfWeek::GiamThang(int m)
{
    this->thang -= m;
    while (this->thang < 1)
    {
        this->thang += 12;
        this->nam--;
    }
    int maxD = SoNgayTrongTuan(this->thang, this->nam);
    if (this->ngay > maxD)
        this->ngay = maxD;
}

void DateOfWeek::TangNam(int y)
{
    this->nam += y;
    int maxD = SoNgayTrongTuan(this->thang, this->nam);
    if (this->ngay > maxD)
        this->ngay = maxD;
}
void DateOfWeek::GiamNam(int y)
{
    this->nam -= y;
    int maxD = SoNgayTrongTuan(this->thang, this->nam);
    if (this->ngay > maxD)
        this->ngay = maxD;
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
        do
        {
            cout << "Nhap lai ngay thang nam: " << endl;
            date.NhapNgayThangNam();
        } while (!KiemTraNgayThangNamHopLe(date.GetNgay(), date.GetThang(), date.GetNam()));
        date.NgayTrongTuan();
    }
    cout << "--Vui long chon thanh phan muon thay doi-- " << endl;
    cout << "1.Tang Ngay" << endl;
    cout << "2.Giam Ngay" << endl;
    cout << "3.Tang Thang" << endl;
    cout << "4.Giam Thang" << endl;
    cout << "5.Tang Nam" << endl;
    cout << "6.Giam Nam" << endl;
    int k;
    cin >> k;
    switch (k)
    {
    case 1:
    {
        int k;
        cout << "Nhap ngay muon tang them: ";
        cin >> k;

        date.TangNgay(k);
        break;
    }
    case 2:
    {
        int k;
        cout << "Nhap ngay muon giam bot: ";
        cin >> k;
        date.GiamNgay(k);
        break;
    }
    case 3:
    {
        int k;
        cout << "Nhap thang muon tang them: ";
        cin >> k;
        date.TangThang(k);
        break;
    }
    case 4:
    {
        int k;
        cout << "Nhap thang muon giam bot: ";
        cin >> k;
        date.GiamThang(k);
        break;
    }
    case 5:
    {
        int k;
        cout << "Nhap nam muon tang them: ";
        cin >> k;
        date.TangNam(k);
        break;
    }
    case 6:
    {
        int k;
        cout << "Nhap nam muon giam bot: ";
        cin >> k;
        date.GiamNam(k);

        break;
    }
    }
    cout << "Ngay sau khi thay doi la: " << date.GetNgay() << "/" << date.GetThang() << "/" << date.GetNam() << endl;

    date.NgayTrongTuan();
    return 0;
}
