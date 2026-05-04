#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
class Diem
{
private:
    double x, y;

public:
    Diem(double xx = 0, double yy = 0) : x(xx), y(yy) {}
    double GetX()
    {
        return this->x;
    }
    double GetY()
    {
        return this->y;
    }

    void NhapDiem()
    {
        cout << "Nhap toa do x: ";
        cin >> this->x;
        cout << "Nhap toa do y: ";
        cin >> this->y;
    }
    void XuatDiem()
    {
        cout << "(" << this->x << ", " << this->y << ")";
    }
    double TinhDoDaiCanh(Diem other)
    {
        return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
    }
    void TinhTien(double dx, double dy)
    {
        this->x += dx;
        this->y += dy;
    }
    void PhongTo(double k)
    {
        this->x *= k;
        this->y *= k;
    }
    void ThuNho(double l)
    {
        this->x /= l;
        this->y /= l;
    }
    void Quay(double goc)
    {
        double xmoi = this->x * cos(goc / 180 * PI) - this->y * sin(goc / 180 * PI);
        double ymoi = this->x * sin(goc / 180 * PI) + this->y * cos(goc / 180 * PI);
        this->x = xmoi;
        this->y = ymoi;
    }
};

class cDaGiac
{
private:
    int n;
    Diem *dinh;

public:
    cDaGiac()
    {
        n = 0;
        dinh = nullptr;
    }

    ~cDaGiac()
    {
        if (dinh != nullptr)
        {
            delete[] dinh;
        }
    }

    void NhapDaGiac()
    {
        do
        {
            cout << "Nhap so luong dinh cua da giac (n >= 3): ";
            cin >> n;
            if (n < 3)
                cout << "Da giac phai co it nhat 3 dinh. Vui long nhap lai!\n";
        } while (n < 3);

        if (dinh != nullptr)
            delete[] dinh;
        dinh = new Diem[n];

        for (int i = 0; i < n; i++)
        {
            cout << " Nhap dinh thu " << i + 1 << " ---\n";
            dinh[i].NhapDiem();
        }
    }

    void XuatDaGiac()
    {
        if (n == 0 || dinh == nullptr)
        {
            cout << "Da giac rong!\n";
            return;
        }
        cout << "Toa do cac dinh cua da giac la:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Dinh " << i + 1 << ": ";
            dinh[i].XuatDiem();
            cout << "\n";
        }
    }

    double TinhChuVi()
    {
        if (n < 3)
            return 0;
        double chuvi = 0;
        for (int i = 0; i < n; i++)
        {

            int next = (i + 1) % n;
            chuvi += dinh[i].TinhDoDaiCanh(dinh[next]);
        }
        return chuvi;
    }

    double TinhDienTich()
    {
        if (n < 3)
            return 0;
        double dientich = 0;
        for (int i = 0; i < n; i++)
        {
            int next = (i + 1) % n;
            dientich += (dinh[i].GetX() * dinh[next].GetY() - dinh[next].GetX() * dinh[i].GetY());
        }
        return abs(dientich) / 2.0;
    }

    void TinhTienDaGiac()
    {
        double dx, dy;
        cout << "Nhap toa do tinh tien x (dx): ";
        cin >> dx;
        cout << "Nhap toa do tinh tien y (dy): ";
        cin >> dy;
        for (int i = 0; i < n; i++)
        {
            dinh[i].TinhTien(dx, dy);
        }
        cout << "-> Da tinh tien da giac thanh cong.\n";
    }

    void PhongToDaGiac()
    {
        double k;
        cout << "Nhap he so muon phong to: ";
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            dinh[i].PhongTo(k);
        }
        cout << "-> Da phong to da giac thanh cong.\n";
    }

    void ThuNhoDaGiac()
    {
        double l;
        do
        {
            cout << "Nhap he so muon thu nho (khac 0): ";
            cin >> l;
        } while (l == 0);

        for (int i = 0; i < n; i++)
        {
            dinh[i].ThuNho(l);
        }
        cout << "-> Da thu nho da giac thanh cong.\n";
    }

    void QuayDaGiac()
    {
        double goc;
        cout << "Nhap goc quay (0-360 do): ";
        cin >> goc;
        for (int i = 0; i < n; i++)
        {
            dinh[i].Quay(goc);
        }
        cout << "-> Da quay da giac thanh cong.\n";
    }

    bool KiemTraDaNhap()
    {
        return n >= 3 && dinh != nullptr;
    }
};

int main()
{
    cDaGiac dg;
    int luaChon;

    do
    {
        cout << "\n================= MENU QUAN LY DA GIAC =================" << endl;
        cout << "1. Nhap toa do cac dinh cua da giac" << endl;
        cout << "2. Xuat toa do cac dinh da giac" << endl;
        cout << "3. Tinh chu vi da giac" << endl;
        cout << "4. Tinh dien tich da giac" << endl;
        cout << "5. Tinh tien da giac" << endl;
        cout << "6. Phong to da giac" << endl;
        cout << "7. Thu nho da giac" << endl;
        cout << "8. Quay da giac" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "========================================================" << endl;
        cout << "Moi ban nhap lua chon: ";
        cin >> luaChon;
        if (!dg.KiemTraDaNhap() && luaChon >= 2 && luaChon <= 8)
        {
            cout << "Vui long nhap da giac (Chuc nang 1) truoc khi thuc hien!\n";
            continue;
        }

        switch (luaChon)
        {
        case 1:
            dg.NhapDaGiac();
            break;
        case 2:
            dg.XuatDaGiac();
            break;
        case 3:
            cout << "Chu vi da giac la: " << dg.TinhChuVi() << endl;
            break;
        case 4:
            cout << "Dien tich da giac la: " << dg.TinhDienTich() << endl;
            break;
        case 5:
            dg.TinhTienDaGiac();
            break;
        case 6:
            dg.PhongToDaGiac();
            break;
        case 7:
            dg.ThuNhoDaGiac();
            break;
        case 8:
            dg.QuayDaGiac();
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
            break;
        }
    } while (luaChon != 0);

    return 0;
}