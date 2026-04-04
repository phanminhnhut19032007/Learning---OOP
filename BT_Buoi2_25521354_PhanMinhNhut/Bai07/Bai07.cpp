#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Vehicle
{
private:
    string ChuXe;
    string Loai;
    double Gia;
    int DungTich;

public:
    Vehicle()
    {
        this->ChuXe = "Nguyen Van A";
        this->Loai = "Wave alpla";
        this->Gia = 18.5;
        this->DungTich = 110;
    }
    Vehicle(string name, string kieu, double gia, int Dungtich)
    {
        this->ChuXe = name;
        this->Loai = kieu;
        this->Gia = gia;
        this->DungTich = Dungtich;
    }
    void NhapThongTin()
    {

        cout << "Moi ban nhap ten chu xe :";
        getline(cin, this->ChuXe);
        cout << "Moi ban nhap loai xe: ";
        getline(cin, this->Loai);
        cout << "Moi ban nhap gia xe(trieu dong):";
        cin >> this->Gia;
        cout << "Moi ban nhap dung tich cua xe:";
        cin >> this->DungTich;
    }
    void NhapGia()
    {
        do
        {
            cout << "Nhap gia xe:";
            cin >> this->Gia;
        } while (this->Gia < 0);
    }
    void NhapXyLanh()
    {
        do
        {
            cout << "Nhap dung tich xe:";
            cin >> this->DungTich;
        } while (this->DungTich < 0);
    }
    int GetXyLanh()
    {
        return this->DungTich;
    }
    double GetGia()
    {
        return this->Gia;
    }
    double TinhThue()
    {
        double thue;
        if (this->DungTich < 100)
            thue = this->Gia / 100;
        else if (100 <= this->DungTich < 200)
            thue = this->Gia * 3 / 100;
        else
            thue = this->Gia * 5 / 100;

        return thue;
    }

    void XuatThongTin(double thue)
    {
        cout << "Ten cua chu xe la: ";
        cout << this->ChuXe << endl;
        cout << "Loai xe: ";
        cout << this->Loai << endl;
        cout << "Gia xe: ";
        cout << this->Gia << " trieu dong" << endl;
        cout << "Dung tich xe: ";
        cout << this->DungTich << " cc" << endl;
        cout << "Tien thue truoc ba: ";
        cout << thue << " trieu dong" << endl;
    }
};
bool KiemTraGia(double gia)
{
    return gia > 0;
}

bool KiemTraXyLanh(int xylanh)
{

    return xylanh > 0;
}

int main()
{
    Vehicle xe1;
    Vehicle xe2("Nguyen Van B", "Future", 39.5, 125);
    Vehicle xe3;
    cout << "Nhap thong tin xe 3" << endl;
    xe3.NhapThongTin();
    cout << endl;
    if (KiemTraGia(xe3.GetGia()) == false)
    {
        cout << "Thong tin khong hop le!" << endl;
        cout << "Ban da nhap gia xe 3 sai,vui long nhap lai: " << endl;
        xe3.NhapGia();
    }
    if (KiemTraXyLanh(xe3.GetXyLanh()) == false)
    {
        cout << "Thong tin khong hop le!" << endl;
        cout << "Ban da nhap dung tich xe 3 sai,vui long nhap lai: " << endl;
        xe3.NhapXyLanh();
    }

    cout << "\nBang ke khia thong tin chi tiet va tien thue truoc ba" << endl;
    cout << "\nThong tin chi tiet va thue truoc ba cua xe 1 " << endl;
    xe1.XuatThongTin(xe1.TinhThue());
    cout << "\nThong tin chi tiet va thue truoc ba cua xe 2 " << endl;
    xe2.XuatThongTin(xe2.TinhThue());
    cout << "\nThong tin chi tiet va thue truoc ba cua xe 3 " << endl;
    xe3.XuatThongTin(xe3.TinhThue());

    return 0;
}