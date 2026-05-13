#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class cCacChuyenXe {
protected:
    string HoTenTaiXe, MaSoChuyen;
    int SoXe;
    double DoanhThu;
public:
    cCacChuyenXe()
   {
    HoTenTaiXe=MaSoChuyen="";
    SoXe=0;
    DoanhThu=0.00;
   }
    virtual void Nhap() {
        cout << "Moi ban nhap ho ten tai xe: ";
        getline(cin, HoTenTaiXe);
        cout << "Moi ban nhap ma so chuyen xe: ";
        getline(cin, MaSoChuyen);
        cout << "Moi ban nhap so xe: ";
        cin >> SoXe;
        cout << "Moi ban nhap doanh thu (trieu dong): ";
        cin >> DoanhThu;
    }

    virtual void Xuat() {
        cout << "Tai xe: " << HoTenTaiXe << " | Ma so: " << MaSoChuyen << " | So xe: " << SoXe
            << " | Doanh thu: " << DoanhThu << "trieu VND";
    }

    double GetDoanhThu() {
        return DoanhThu;
    }

    virtual ~cCacChuyenXe() {}
};

class cChuyenXeNoiThanh : public cCacChuyenXe {
private:
    int SoTuyen;
    double SoKm;
public:
    void Nhap() override {
        cCacChuyenXe::Nhap();
        cout << "Moi ban nhap so tuyen: ";
        cin >> SoTuyen;
        cout << "Moi ban nhap so kilomet di duoc: ";
        cin >> SoKm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    void Xuat() override {
        cCacChuyenXe::Xuat();
        cout << " | So Tuyen: " << SoTuyen << " | So km: " << SoKm << endl;
    }
};

class cChuyenXeNgoaiThanh : public cCacChuyenXe {
private:
    int SoNgayDi;
    string DiemDen;
   
public:
    void Nhap() override {
        cCacChuyenXe::Nhap();
        cout << "Moi ban nhap so ngay di duoc: ";
        cin >> SoNgayDi;
        cin.ignore(); 
        cout << "Moi ban nhap Diem den: ";
        getline(cin, DiemDen);
    }

    void Xuat() override {
        cCacChuyenXe::Xuat();
        cout << " | So ngay di: " << SoNgayDi << " | Diem den: " << DiemDen << endl;
    }

};

int main() {
    vector<cCacChuyenXe*> danhsach;
    int n;

    cout << "---CHUONG TRINH QUAN LY CAC CHUYEN XE---" << endl;
    cout << "Nhap so luong chuyen xe: ";
    while (!(cin >> n) || n <= 0) {
        cout << "So luong khong hop le. Vui long nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; i++) {
        cCacChuyenXe* chuyenxe = nullptr; 
        int loaichuyen;
        
        cout << "\n--- Moi ban nhap chuyen xe thu " << i + 1 << " ---";
        do {
            cout << "\n1. Chuyen Xe Noi Thanh";
            cout << "\n2. Chuyen Xe Ngoai Thanh";
            cout <<"\n";
            cin >> loaichuyen;
            if (loaichuyen != 1 && loaichuyen != 2)
                cout << "Ban da chon sai. Vui long chon lai!";
        } while (loaichuyen != 1 && loaichuyen != 2);

        cin.ignore(); 

        if (loaichuyen == 1) chuyenxe = new cChuyenXeNoiThanh();
        else chuyenxe = new cChuyenXeNgoaiThanh();

        chuyenxe->Nhap();
        danhsach.push_back(chuyenxe);
        cout << "---> DA THEM THANH CONG" << endl;
    }

    cout << "\n--------- DANH SACH CAC CHUYEN XE ---------\n";
    double TongDoanhThu = 0;
    for (auto* x : danhsach) {
        x->Xuat();
        TongDoanhThu += x->GetDoanhThu();
    }

    cout << "\n_______ THONG KE DOANH THU ______\n";
    cout << TongDoanhThu << " trieu VND" << endl;

    for (auto x : danhsach) delete x;
    danhsach.clear();

    return 0;
}