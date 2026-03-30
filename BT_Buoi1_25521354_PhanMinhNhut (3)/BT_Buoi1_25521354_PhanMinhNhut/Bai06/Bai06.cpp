#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

class HocSinh {
private:
    string name= "";
    double diemToan = 0.0;
    double diemVan = 0.0;
    double diemTrungBinh = 0.0;
public:
    void NhapThongTin();
    double DiemTrungBinh();
    void XuatHocSinh();
    double GetDiemTrungBinh();
};

void HocSinh::NhapThongTin() {
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, this->name);
    cout << "Nhap diem toan: ";
    cin >> this->diemToan;
    cout << "Nhap diem van: ";
    cin >> this->diemVan;
}

double HocSinh::DiemTrungBinh() {
    this->diemTrungBinh = (this->diemToan + this->diemVan) / 2;
    return this->diemTrungBinh;
}

void HocSinh::XuatHocSinh() {
    cout << "Ho va ten: " << this->name << endl;
    cout << "Diem toan: " << this->diemToan << endl;
    cout << "Diem van: " << this->diemVan << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2) << this->diemTrungBinh << endl;
}

double HocSinh::GetDiemTrungBinh() {
    return this->diemTrungBinh;
}

bool operator < (HocSinh a, HocSinh b) {
    return a.GetDiemTrungBinh() < b.GetDiemTrungBinh();
}

int main() {
    HocSinh danhsach[1000];
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":" << endl;
        danhsach[i].NhapThongTin();
        danhsach[i].DiemTrungBinh();
    }
    sort(danhsach, danhsach + n);
    cout << "Hoc sinh co diem trung binh cao nhat la: " << endl;
    danhsach[n - 1].XuatHocSinh();
    cout << "Hoc sinh co diem trung binh thap nhat la: " << endl;
    danhsach[0].XuatHocSinh();

    return 0;
}