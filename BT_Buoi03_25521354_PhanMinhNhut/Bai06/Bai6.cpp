#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

class cCandidate
{
private:
    string Ma;
    string Ten;
    string NgaySinh;
    float DiemToan, DiemVan, DiemAnh;


public:
    cCandidate()
    {
        Ma = Ten = NgaySinh = "";
        DiemToan = DiemVan = DiemAnh = 0;
    }



    void Nhap()
    {

        cout << "Nhap Ma thi sinh: ";
        cin >> ws;
        getline(cin, Ma);
        cout << "Nhap Ten thi sinh: ";
        getline(cin, Ten);
        cout << "Nhap ngay thang nam sinh : ";
        getline(cin, NgaySinh);
        cout << "Nhap diem Toan: ";
        cin >> DiemToan;
        cout << "Nhap diem Van: ";
        cin >> DiemVan;
        cout << "Nhap diem Anh: ";
        cin >> DiemAnh;
    }



    float TinhTongDiem()
    {
        return DiemToan + DiemVan + DiemAnh;
    }



    void Xuat()
    {
        cout << "Ma: " << Ma
             << " | Ten: " << Ten
             << " | Ngay sinh: " << NgaySinh
             << " | Toan: " << DiemToan
             << " | Van: " << DiemVan
             << " | Anh: " << DiemAnh
             << " | Tong diem: " << TinhTongDiem() << "\n";
    }
};

class cListCandidate
{
private:
    int n;
    cCandidate *DanhSach;

public:
    cListCandidate()
    {
        n = 0;
        DanhSach = NULL;
    }
    ~cListCandidate()
    {
        if (DanhSach != NULL)
        {
            delete[] DanhSach;
        }
    }

    void NhapDanhSach()
    {
        cout << "Nhap so luong thi sinh n: ";
        cin >> n;
        if (DanhSach != NULL)
            delete[] DanhSach;
        DanhSach = new cCandidate[n];
        for (int i = 0; i < n; i++)
        {
            cout << " Nhap thong tin thi sinh thu " << i + 1 << " ---\n";
            DanhSach[i].Nhap();
        }
        cout << "Da nhap xong danh sach thi sinh!\n";
    }



    void XuatDanhSach()
    {
        if (n == 0 || DanhSach == NULL)
            return;

        cout << "\nDANH SACH TAT CA THI SINH:\n";
        for (int i = 0; i < n; i++)
        {
            DanhSach[i].Xuat();
        }
    }

    void XuatThiSinhLonHon15()
    {
        bool CoThiSinh = false;

        cout << "\nDANH SACH THI SINH CO TONG DIEM > 15:\n";
        for (int i = 0; i < n; i++)
        {
            if (DanhSach[i].TinhTongDiem() > 15.0)
            {
                DanhSach[i].Xuat();
                CoThiSinh = true;
            }
        }
        if (!CoThiSinh)
            cout << "Khong co thi sinh nao thoa man!\n";
    }

    void TimThiSinhDiemCaoNhat()
    {
        if (n == 0)
            return;
        float MaxDiem = DanhSach[0].TinhTongDiem();
        for (int i = 1; i < n; i++)
        {
            if (DanhSach[i].TinhTongDiem() > MaxDiem)
            {
                MaxDiem = DanhSach[i].TinhTongDiem();
            }
        }

        cout << "\nTHI SINH CO TONG DIEM CAO NHAT (" << MaxDiem << " diem) ---\n";
        for (int i = 0; i < n; i++)
        {
            if (abs(DanhSach[i].TinhTongDiem() - MaxDiem) < 1e-4)
            {
                DanhSach[i].Xuat();
            }
        }
    }

    void SapXepGiamDan()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (DanhSach[i].TinhTongDiem() < DanhSach[j].TinhTongDiem())
                {
                    swap(DanhSach[i], DanhSach[j]);
                }
            }
        }
        cout << "Da sap xep danh sach thi sinh GIAM DAN theo tong diem.\n";
    }

    bool IsEmpty()
    {
        return n == 0 || DanhSach == NULL;

    }
};

int main()
{
    cListCandidate list;
    int luaChon;
    

    do
    {
        cout << "\n================ MENU QUAN LY THI SINH ================" << endl;
        cout << "1. Nhap danh sach n thi sinh" << endl;
        cout << "2. Xuat toan bo danh sach thi sinh" << endl;
        cout << "3. Xuat cac thi sinh co tong diem > 15" << endl;
        cout << "4. Tim thi sinh co tong diem cao nhat" << endl;
        cout << "5. Sap xep thi sinh giam dan theo tong diem" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "=======================================================" << endl;
        cout << "Moi ban nhap lua chon: ";
        cin >> luaChon;

        if (list.IsEmpty() && luaChon >= 2 && luaChon <= 5)
        {
            cout << "Danh sach dang rong. Vui long chon 1 de nhap danh sach!\n";
            continue;
        }

        switch (luaChon)
        {
        case 1:
            list.NhapDanhSach();
            break;
        case 2:
            list.XuatDanhSach();
            break;
        case 3:
            list.XuatThiSinhLonHon15();
            break;
        case 4:
            list.TimThiSinhDiemCaoNhat();
            break;
        case 5:
            list.SapXepGiamDan();
            list.XuatDanhSach();
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!\n";
            break;
        }
    } while (luaChon != 0);

    return 0;
}
