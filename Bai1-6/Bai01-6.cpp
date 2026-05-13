#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Date
{
public:
    int d, m, y;
    friend istream &operator>>(istream &in, Date &dt)
    {
        cout << "\nMoi ban nhap ngay sinh: ";
        in >> dt.d;
        cout << "Moi ban nhap thang sinh: ";
        in >> dt.m;
        cout << "Moi ban nhap nam sinh: ";
        in >> dt.y;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Date &dt)
    {
        out << dt.d << "/" << dt.m << "/" << dt.y << endl;
        return out;
    }
    bool operator<(const Date &other) // so sanh tuoi
    {
        if (y != other.y)
            return y < other.y;
        if (m != other.m)
            return m < other.m;
        return d < other.d;
    }
};
class cNhanVien
{
protected:
    string HoTen;
    Date NgaySinh;
    double Salary;

public:
    virtual void Nhap()
    {
        cout << "Moi ban nhap ho ten: ";
        getline(cin >> ws, HoTen);
        cout << "Moi ban nhap ngay thang nam sinh(dd/mm/yy) ";
        cin >> NgaySinh;
    }
    virtual void Xuat()
    {
        cout << "Ho ten: " << HoTen << " | Ngay sinh: " << NgaySinh;
    }
    virtual void CaculateSalary() = 0;

    virtual double GetSalary()
    {
        return Salary;
    }
    virtual int GetLoai() = 0;
    Date GetNgaySinh()
    {
        return NgaySinh;
    }
    string GetHoTen()
    {
        return HoTen;
    }
    virtual ~cNhanVien() {}
};

class cNhanVienSanXuat : public cNhanVien
{
    double BaseSalary;
    int SoSanPham;

public:
    void Nhap() override
    {
        cNhanVien::Nhap();
        cout << "Moi ban nhap luong can ban(tram ngan dong): ";
        cin >> BaseSalary;
        cout << "Moi ban nhap so luong san pham: ";
        cin >> SoSanPham;
    }
    void CaculateSalary() override
    {
        Salary = BaseSalary + SoSanPham * 5;
    }
    void Xuat() override
    {
        cNhanVien::Xuat();

        cout << " | Loai: Nhan vien san Xuat  | Luong: " << Salary << " VND" << endl;
    }
    int GetLoai() override
    {

        return 1;
    }
};

class cNhanVienVanPhong : public cNhanVien
{
    int SoNgayLam;

public:
    void Nhap() override
    {
        cNhanVien::Nhap();
        cout << "Moi ban nhap so ngay lam viec: ";
        cin >> SoNgayLam;
    }

    void CaculateSalary() override
    {
        Salary = SoNgayLam * 100;
    }

    void Xuat() override
    {
        cNhanVien::Xuat();
        cout << " | Loai: Nhan vien van phong | Luong: " << Salary << " VND" << endl;
    }
    int GetLoai() override
    {
        return 2;
    }
};
int main()
{
    vector<cNhanVien *> ds;
    int n;
    cout << "---CHUONG TRINH QUAN LY NHAN VIEN---" << endl;
    cout << "Nhap so luong nhan vien: ";
    while (!(cin >> n) || n <= 0)
    {
        cout << "So luong khong hop le. Vui long nhap lai: ";
        cin.clear();
    }

    for (int i = 0; i < n; i++)
    {
        int loai;
        cNhanVien *nv = nullptr;
        cout << "\n Nhap thong tin nhan vien thu " << i + 1 << endl;

        do
        {
            cout << "---Vui long chon loai nhan vien---";
            cout << "\n1.Nhan Vien San Xuat";
            cout << "\n2.Nhan Vien Van Phong" << endl;
            cin >> loai;
            if (loai != 1 && loai != 2)
            {
                cout << "!Lua chon khong hop le.Vui long chon lai.\n";
            }
        } while (loai != 1 && loai != 2);
        if (loai == 1)
        {
            nv = new cNhanVienSanXuat();
        }
        else
        {
            nv = new cNhanVienVanPhong();
        }
        nv->Nhap();
        nv->CaculateSalary();
        ds.push_back(nv);
        cout << "->Da them nhan vien: " << nv->GetHoTen() << " thanh cong!" << endl;
    }
    cout << "--DANH SACH NHAN VIEN CONG TY---" << endl;
    double SumSalary = 0;
    for (auto *nv : ds)
    {
        nv->Xuat();
        SumSalary += nv->GetSalary();
    }

    cout << "-> Tong Luong CONG TY phai tra la: " << fixed << setprecision(3) << SumSalary << " VND" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    cout << "\n____THONG KE_____" << endl;

    cNhanVien *NVSXmin = nullptr;
    cNhanVien *NVVPOld = nullptr;

    for (auto nv : ds)
    {
        if (nv->GetLoai() == 1)
        {
            if (NVSXmin == nullptr || nv->GetSalary() < NVSXmin->GetSalary())
                NVSXmin = nv;
        }
        if (nv->GetLoai() == 2)
        {
            if (NVVPOld == nullptr || nv->GetNgaySinh() < NVVPOld->GetNgaySinh())
                NVVPOld = nv;
        }
    }
    if (NVSXmin)
        cout << " --Nhan vein San Xuat luong thap nhat: " << NVSXmin->GetHoTen() << " (" << NVSXmin->GetSalary() << " VND)" << endl;
    else
        cout << " --Khong co nhan vien san Xuat." << endl;

    if (NVVPOld)
        cout << " --Nhan vien van phong tuoi cao nhat: " << NVVPOld->GetHoTen() << " || Sinh ngay: " << NVVPOld->GetNgaySinh() << endl;
    else
        cout << " -- Khong co nhan vien van phong." << endl;

    for (auto nv : ds)
        delete nv;
    ds.clear();

    return 0;
}