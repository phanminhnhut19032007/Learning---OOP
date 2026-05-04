#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll TimUCLN(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool LaSoNguyenTo(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

class PhanSo
{
private:
    ll tu, mau; 
public:
    PhanSo(ll t = 0, ll m = 1)
    {
        tu = t;
        mau = (m == 0) ? 1 : m;
        RutGon();
    }

    void RutGon()
    {
        ll ucln = TimUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }

    void Nhap()
    {
        cout << "   Nhap tu so: ";
        cin >> tu;
        do
        {
            cout << "   Nhap mau so (khac 0): ";
            cin >> mau;
            if (mau == 0)
                cout << "   Mau phai khac 0! Nhap lai.\n";
        } while (mau == 0);
        RutGon();
    }

    void Xuat() const
    {
        if (mau == 1)
            cout << tu;
        else
            cout << tu << "/" << mau;
    }
    ll GetTu() const { 
        return tu; 
    }
    ll GetMau() const {
         return mau; 
        }
    bool operator<(const PhanSo &khac) const
    {
        return (ll)this->tu * khac.mau < (ll)khac.tu * this->mau;
    }

    bool operator>(const PhanSo &khac) const
    {
        return khac < *this;
    }

    PhanSo cong(PhanSo khac) const
    {
        ll tuMoi = (ll)tu * khac.mau + (ll)khac.tu * mau;
        ll mauMoi = (ll)mau * khac.mau;
        return PhanSo(tuMoi, mauMoi);
    }
};

class cDSPhanSo
{
private:
    vector<PhanSo> ds;

public:
    void NhapDS()
    {
        int n;
        cout << "Nhap so luong phan so: ";
        cin >> n;
        ds.clear();
        for (int i = 0; i < n; i++)
        {
            PhanSo ps;
            cout << "Phan so thu " << i + 1 << ":\n";
            ps.Nhap();
            ds.push_back(ps);
        }
    }

    void XuatDS() const
    {
        if (ds.empty())
        {
            cout << "Danh sach trong!\n";
            return;
        }
        for (size_t i = 0; i < ds.size(); i++)
        {
            ds[i].Xuat();
            if (i < ds.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }

    PhanSo TinhTong() const
    {
        PhanSo tong(0, 1);
        for ( auto &ps : ds)
            tong = tong.cong(ps);
        return tong;
    }

    PhanSo TimMax() const
    {
        return *max_element(ds.begin(), ds.end());
    }

    PhanSo TimMin() const
    {
        return *min_element(ds.begin(), ds.end());
    }

    void TimPhanSoTuNguyenToMax() const
    {
        ll maxNT = -1;
        int index = -1;
        for (int i = 0; i < (int)ds.size(); i++)
        {
            if (LaSoNguyenTo(ds[i].GetTu()))
            {
                if (index == -1 || ds[i].GetTu() > maxNT)
                {
                    maxNT = ds[i].GetTu();
                    index = i;
                }
            }
        }
        if (index != -1)
        {
            cout << "Phan so co tu la SNT lon nhat (" << maxNT << "): ";
            ds[index].Xuat();
            cout << endl;
        }
        else
        {
            cout << "Khong co phan so nao co tu la so nguyen to.\n";
        }
    }

    void SapXepTang()
    {
        sort(ds.begin(), ds.end());
    }

    void SapXepGiam()
    {
        sort(ds.begin(), ds.end(), greater<PhanSo>());
    }

    bool IsEmpty() const { return ds.empty(); }
};

int main()
{
    cDSPhanSo danhSach;
    int luaChon;

    do
    {
        cout << "\n================ MENU QUAN LY PHAN SO ================\n";
        cout << "1. Nhap danh sach phan so\n";
        cout << "2. Xuat danh sach phan so\n";
        cout << "3. Tinh tong cac phan so\n";
        cout << "4. Tim phan so Lon nhat & Nho nhat\n";
        cout << "5. Tim phan so co tu la so nguyen to lon nhat\n";
        cout << "6. Sap xep danh sach tang dan\n";
        cout << "7. Sap xep danh sach giam dan\n";
        cout << "8. Thoat chuong trinh\n";
        cout << "Lua chon cua ban (1-8): ";
        cin >> luaChon;

        if (luaChon >= 2 && luaChon <= 7 && danhSach.IsEmpty())
        {
            cout << "Vui long nhap danh sach truoc (Chon 1)!\n";
            continue;
        }

        switch (luaChon)
        {
        case 1:
            danhSach.NhapDS();
            break;
        case 2:
            cout << "Danh sach: ";
            danhSach.XuatDS();
            break;
        case 3:
            cout << "Tong cac phan so: ";
            danhSach.TinhTong().Xuat();
            cout << endl;
            break;
        case 4:
            cout << "Max: ";
            danhSach.TimMax().Xuat();
            cout << " | Min: ";
            danhSach.TimMin().Xuat();
            cout << endl;
            break;
        case 5:
            danhSach.TimPhanSoTuNguyenToMax();
            break;
        case 6:
            danhSach.SapXepTang();
            cout << "Da sap xep tang: ";
            danhSach.XuatDS();
            break;
        case 7:
            danhSach.SapXepGiam();
            cout << "Da sap xep giam: ";
            danhSach.XuatDS();
            break;
        case 8:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 8);

    return 0;
}