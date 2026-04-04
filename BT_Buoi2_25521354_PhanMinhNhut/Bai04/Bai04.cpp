#include <iostream>
#include <iomanip>

using namespace std;

class ThoiGian
{
private:
    int gio, phut, giay;
    void ChuanHoa()
    {
        if (giay >= 60)
        {
            phut += giay / 60;
            giay %= 60;
        }
        else if (giay < 0)
        {
            phut -= (abs(giay) / 60 + 1);
            giay = 60 - (abs(giay) % 60);
            if (giay == 60)
            {
                giay = 0;
                phut++;
            }
        }

        if (phut >= 60)
        {
            gio += phut / 60;
            phut %= 60;
        }
        else if (phut < 0)
        {
            gio -= (abs(phut) / 60 + 1);
            phut = 60 - (abs(phut) % 60);
            if (phut == 60)
            {
                phut = 0;
                gio++;
            }
        }
        gio %= 24;
        if (gio < 0)
            gio += 24;
    }

public:
    ThoiGian(int h = 0, int m = 0, int s = 0) : gio(h), phut(m), giay(s)
    {
        ChuanHoa();
    }

    void NhapThongTin()
    {
        cout << "Nhap gio: ";
        cin >> this->gio;
        cout << "Nhap phut: ";
        cin >> this->phut;
        cout << "Nhap giay: ";
        cin >> this->giay;
        ChuanHoa();
    }

    void XuatThongTin()
    {
        cout << setfill('0') << setw(2) << gio << ":"
             << setw(2) << phut << ":"
             << setw(2) << giay << endl;
    }

    int GetGio()
    {
        return gio;
    }
    int GetPhut()
    {
        return phut;
    }
    int GetGiay()
    {
        return giay;
    }

    void SetGio(int h)
    {
        gio = h;
        ChuanHoa();
    }
    void SetPhut(int m)
    {
        phut = m;
        ChuanHoa();
    }
    void SetGiay(int s)
    {
        giay = s;
        ChuanHoa();
    }

    void TangGiay(int s = 1)
    {
        giay += s;
        ChuanHoa();
    }
    void GiamGiay(int s = 1)
    {
        giay -= s;
        ChuanHoa();
    }
    void TangPhut(int m)
    {
        phut += m;
        ChuanHoa();
    }
    void GiamPhut(int m)
    {
        phut -= m;
        ChuanHoa();
    }
    void TangGio(int h)
    {
        gio += h;
        ChuanHoa();
    }
    void GiamGio(int h)
    {
        gio += h;
        ChuanHoa();
    }
};

int main()
{

    ThoiGian t1(23, 59, 50);
    cout << "Thoi gian ban dau t1: ";
    t1.XuatThongTin();

    cout << "Tang t1 them 15 giay: ";
    t1.TangGiay(15);
    t1.XuatThongTin();

    ThoiGian t2;
    cout << "\nNhap thoi gian cho t2:\n";
    t2.NhapThongTin();
    cout << "Thoi gian t2 vua nhap: ";
    t2.XuatThongTin();
    cout << endl;
    cout << "Vui long chon thanh phan muon thay doi " << endl;
    cout << "1.Tang Giay" << endl;
    cout << "2.Giam Giay" << endl;
    cout << "3.Tang Phut" << endl;
    cout << "4.Giam Phut" << endl;
    cout << "5.Tang Gio" << endl;
    cout << "6.Giam Gio" << endl;
    int k;
    cin >> k;
    switch (k)
    {
    case 1:
    {
        int s;
        cout << "Moi ban nhap giay muon tang them:";
        cin >> s;
        t2.TangGiay(s);
        cout << "Gio,phut,giay sau khi update la: ";
        t2.XuatThongTin();
        break;
    }
    case 2:
    {
        int s;
        cout << "Moi ban nhap giay muon giam bot:";
        cin >> s;
        t2.GiamGiay(s);
        cout << "Gio,phut,giay sau khi update la: ";
        t2.XuatThongTin();
        break;
    }
    case 3:
    {
        int m;
        cout << "Moi ban nhap phut muon tang them: ";
        cin >> m;
        t2.TangPhut(m);
        cout << "Gio,phut,giay sau khi update la: ";
        t2.XuatThongTin();
        break;
    }
    case 4:
    {
        int m;
        cout << "Moi ban nhap phut muon giam bot: ";
        cin >> m;
        t2.GiamPhut(m);
        cout << "Gio,phut,giay sau khi update la: ";
        t2.XuatThongTin();
        break;
    }
    case 5:
    {
        int h;
        cout << "Moi ban nhap so gio muon tang them: ";
        cin >> h;
        t2.TangGio(h);
        cout << "Gio,phut,giay sau khi update la: ";
        t2.XuatThongTin();
        break;
    }
    case 6:
    {
        int h;
        cout << "Moi ban nhap so gio muon giam bot: ";
        cin >> h;
        t2.GiamGio(h);
        cout << "Gio,phut,giay sau khi update la: ";
        t2.XuatThongTin();
        break;
    }
    }

    return 0;
}