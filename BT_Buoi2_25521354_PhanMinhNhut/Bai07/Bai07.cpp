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
    void NhapThongTin();

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
};
bool KiemTraGia(double gia)
{
    if (gia < 0)
        return false;

    return true;
}
bool KiemTraXyLanh(int xylanh)
{
    if (xylanh < 0)
        return false;
    return true;
}
void Vehicle::NhapThongTin()
{
    cout << "Moi ban nhap ten chu xe :";
    getline(cin, this->ChuXe);
    cout << "Moi ban nhap loai xe: ";
    getline(cin, this->Loai);
    cout << "Moi ban nhap gia : ";
    cin >> this->Gia;
    cout << "Moi ban nhap dung tich xylanh:";
    cin >> this->DungTich;
}

int main()
{
    Vehicle xe1;
    Vehicle xe2("Nguyen Van B", "Future", 39.5, 125);
    Vehicle xe3;
    cout << "Nhap thong tin xe 3" << endl;
    xe3.NhapThongTin();
    if (KiemTraGia(xe3.GetGia()))
        cout << "Ban da nhap gia xe 3 sai,vui long nhap lai: ";
    if (KiemTraXyLanh(xe3.GetXyLanh()))
    {
        cout << "Ban da nhap xy lanh xe 3 sai,vui long nhap lai: ";
    }

    cout << "Bang ke khia thong tin chi tiet va ";

    return 0;
}