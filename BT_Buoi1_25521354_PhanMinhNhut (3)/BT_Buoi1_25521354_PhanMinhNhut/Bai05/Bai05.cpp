#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class HocSinh
{
private:
    string name = "";
    double diemToan = 0.0;
    double diemVan = 0.0;
    double diemTrungBinh = 0.0;
public:
    void NhapThongTin();
    double TinhDiemTrungBinh();
    void XuatThongTin();
};

void HocSinh::NhapThongTin()
{
    cout << "Nhap ho va ten hoc sinh: ";
    getline(cin, this->name);
    cout << "Nhap diem toan: ";
    cin >> this->diemToan;
    cout << "Nhap diem van: ";
    cin >> this->diemVan;
}

double HocSinh::TinhDiemTrungBinh()
{
    this->diemTrungBinh = (this->diemToan + this->diemVan) / 2;
    return diemTrungBinh;
}

void HocSinh::XuatThongTin()
{
    cout << "Ho va ten: " << this->name << endl;
    cout << "Diem toan: " << this->diemToan << endl;
    cout << "Diem van: " << this->diemVan << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2) << this->diemTrungBinh << endl;
}

int main() {
    HocSinh hocsinh;
    hocsinh.NhapThongTin();
    hocsinh.TinhDiemTrungBinh();
    hocsinh.XuatThongTin();

}