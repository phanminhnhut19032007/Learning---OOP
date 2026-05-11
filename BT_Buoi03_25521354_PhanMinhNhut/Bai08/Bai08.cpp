#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

using namespace std;

class cNhanVienVP
{
private:
    string MaNV;
    string HoTen;
    string ngaySinh;
    float Luong;

public:
    cNhanVienVP()
    {
        MaNV = HoTen = ngaySinh = "";
        Luong = 0.0;
    }
    void SetMaNV(string ma)
    {
        MaNV = ma;
    }
    string GetMaNV()
    {
        return MaNV;
    }

    void SetHoTen(string ten)
    {
        HoTen = ten;
    }
    string GetHoTen()
    {
        return HoTen;
    }

    void SetNgaySinh(string ns)
    {
        ngaySinh = ns;
    }
    string GetNgaySinh()
    {
        return ngaySinh;
    }

    void SetLuong(float l)
    {
        Luong = l;
    }
    float GetLuong()
    {
        return Luong;
    }
    int GetNamSinh()
    {
        int len = ngaySinh.length();
        if (len >= 4)
        {
            string strNam = ngaySinh.substr(len - 4);
            return atoi(strNam.c_str());
        }
        return 9999;
    }

    void Nhap()
    {
        cout << "Nhap Ma nhan vien: ";
        getline(cin >> ws, MaNV);
        cout << "Nhap Ho ten: ";
        getline(cin, HoTen);
        cout << "Nhap Ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        cout << "Nhap Luong: ";
        cin >> Luong;
    }

    void Xuat()
    {
        cout << "Ma NV: " << setw(8) << left << MaNV
             << " | Ten: " << setw(20) << left << HoTen
             << " | Ngay sinh: " << setw(12) << left << ngaySinh
             << " | Luong: " << fixed << setprecision(2) << Luong << "\n";
    }
};

class cListNhanVienVP
{
private:
    int n;
    cNhanVienVP *DanhSach;

public:
    cListNhanVienVP()
    {
        n = 0;
        DanhSach = NULL;
    }

    ~cListNhanVienVP()
    {
        if (DanhSach != NULL)
        {
            delete[] DanhSach;
            DanhSach = NULL;
        }
    }
    bool IsEmpty()
    {
        return n <= 0 || DanhSach == NULL;
    }
    void NhapDanhSach()
    {
        cout << "Nhap so Luong nhan vien n: ";
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (DanhSach != NULL)
            delete[] DanhSach;
        DanhSach = new cNhanVienVP[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Nhap thong tin nhan vien thu " << i + 1 << "\n";
            DanhSach[i].Nhap();
        }
        cout << "Da nhap xong danh sach!\n";
    }

    void XuatDanhSach()
    {
        if (IsEmpty())
            return;
        cout << "\n--- DANH SACH NHAN VIEN VAN PHONG ---\n";
        for (int i = 0; i < n; i++)
        {
            DanhSach[i].Xuat();
        }
    }
    void NhanVienLuongCaoNhat()
    {
        if (IsEmpty())
            return;
        float maxLuong = DanhSach[0].GetLuong();
        for (int i = 1; i < n; i++)
        {
            if (DanhSach[i].GetLuong() > maxLuong)
            {
                maxLuong = DanhSach[i].GetLuong();
            }
        }

        cout << "\n NHAN VIEN CO Luong CAO NHAT (" << maxLuong << ") ---\n";
        for (int i = 0; i < n; i++)
        {
            if (DanhSach[i].GetLuong() == maxLuong)
            {
                DanhSach[i].Xuat();
            }
        }
    }
    void TinhTongLuong()
    {
        if (IsEmpty())
            return;
        float tong = 0;
        for (int i = 0; i < n; i++)
        {
            tong += DanhSach[i].GetLuong();
        }
        cout << "\nTong Luong cong ty phai tra la: " << fixed << setprecision(2) << tong << "\n";
    }
    void NhanVienTuoiCaoNhat()
    {
        if (IsEmpty())
            return;
        int minNamSinh = DanhSach[0].GetNamSinh();
        for (int i = 1; i < n; i++)
        {
            int namSinhHienTai = DanhSach[i].GetNamSinh();
            if (namSinhHienTai < minNamSinh)
            {
                minNamSinh = namSinhHienTai;
            }
        }

        cout << "\nNHAN VIEN CO TUOI CAO NHAT (Sinh nam: " << minNamSinh << ") ---\n";
        for (int i = 0; i < n; i++)
        {
            if (DanhSach[i].GetNamSinh() == minNamSinh)
            {
                DanhSach[i].Xuat();
            }
        }
    }
    void SapXepTangDanTheoLuong()
    {
        if (IsEmpty())
            return;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (DanhSach[i].GetLuong() > DanhSach[j].GetLuong())
                {
                    swap(DanhSach[i], DanhSach[j]);
                }
            }
        }
        cout << "\nDa sap xep danh sach TANG DAN theo Luong!\n";
    }
};

int main()
{
    cListNhanVienVP list;
    int Choice;

    do
    {
        cout << "\n================ MENU QUAN LY NHAN VIEN ================" << endl;
        cout << "1. Nhap danh sach n nhan vien van phong" << endl;
        cout << "2. Xuat danh sach nhan vien" << endl;
        cout << "3. Cho biet nhan vien co Luong cao nhat" << endl;
        cout << "4. Tinh tong Luong cong ty phai tra" << endl;
        cout << "5. Cho biet nhan vien nao co tuoi cao nhat" << endl;
        cout << "6. Sap xep danh sach tang dan theo Luong" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "========================================================" << endl;
        cout << "Moi ban nhap lua chon: ";

        if (!(cin >> Choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (list.IsEmpty() && Choice >= 2 && Choice <= 6)
        {
            cout << "Danh sach dang rong. Vui long chon 1 de nhap danh sach truoc!\n";
            continue;
        }

        switch (Choice)
        {
        case 1:
            list.NhapDanhSach();
            break;
        case 2:
            list.XuatDanhSach();
            break;
        case 3:
            list.NhanVienLuongCaoNhat();
            break;
        case 4:
            list.TinhTongLuong();
            break;
        case 5:
            list.NhanVienTuoiCaoNhat();
            break;
        case 6:
            list.SapXepTangDanTheoLuong();
            list.XuatDanhSach();
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh!\n";
            break;
        default:
            cout << "Lua chon sai! Vui long nhap lai.\n";
            break;
        }
    } while (Choice != 0);

    return 0;
}