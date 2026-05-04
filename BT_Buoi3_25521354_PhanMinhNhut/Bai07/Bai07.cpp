#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

class cNhanVienVP {
private:
    string MaNV;
    string HoTen;
    string ngaySinh;
    float Luong;

public:
    cNhanVienVP() {
        MaNV = "";
        HoTen = "";
        ngaySinh = "";
        Luong = 0;
    }

    void SetMaNV(string ma) 
    { 
        MaNV = ma; 
    }

    string GetMaNV() {
         return MaNV; 
        }
    void SetTenNV(string ten) 
    {
         HoTen = ten; 
        }
    string GetHoTen() 
    { 
        return HoTen;
     }
    void SetNgaySinh(string ns) { 
        ngaySinh = ns; 
    }
    string GetNgay() 
    {
         return ngaySinh; 
        }
    void SetLuong(float l) 
    { 
        Luong = l; 
    }
    float GetLuong() { 
        return Luong; 
    }
    int LayNamSinh() {
        int doDai = ngaySinh.length();
        if (doDai >= 4) {
            string chuoiNam = ngaySinh.substr(doDai - 4); 
            return atoi(chuoiNam.c_str()); 
        }
        return 9999; 
    }

    void Nhap() {
        cout << "Nhap Ma nhan vien: ";
        getline(cin >> ws, MaNV); 
        cout << "Nhap Ho ten: ";
        getline(cin, HoTen);
        cout << "Nhap Ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        cout << "Nhap Luong: ";
        cin >> Luong;
    }

    void Xuat() {
        cout << "Ma NV: " << MaNV 
             << " | Ten: " << HoTen 
             << " | Ngay sinh: " << ngaySinh 
             << " | Luong: " << Luong << endl;
    }
};

class cDanhSachNhanVienVP {
private:
    int n;
    cNhanVienVP* danhSach;

public:
    cDanhSachNhanVienVP() {
        n = 0;
        danhSach = NULL;
    }

    ~cDanhSachNhanVienVP() {
        if (danhSach != NULL) {
            delete[] danhSach;
        }
    }

    void NhapDanhSach() {
        cout << "Nhap so Luong nhan vien van phong: ";
        cin >> n;
        cin.ignore();
        if (danhSach != NULL) delete[] danhSach;
        danhSach = new cNhanVienVP[n];

        for (int i = 0; i < n; i++) {
            cout << " Nhap thong tin nhan vien thu " << i + 1 << "\n";
            danhSach[i].Nhap();
        }
    }

    void XuatDanhSach() {
        if (n == 0) return;
        cout << "\n--- DANH SACH NHAN VIEN VAN PHONG ---\n";
        for (int i = 0; i < n; i++) {
            danhSach[i].Xuat();
        }
    }


    void NhanVienLuongCaoNhat() {
        if (n == 0) return;
        
        float maxLuong = danhSach[0].GetLuong();
        
    
        for (int i = 1; i < n; i++) {
            if (danhSach[i].GetLuong() > maxLuong) {
                maxLuong = danhSach[i].GetLuong();
            }
        }

        cout << "\n--- NHAN VIEN CO Luong CAO NHAT (" << maxLuong << ") ---\n";
        for (int i = 0; i < n; i++) {
            if (danhSach[i].GetLuong() == maxLuong) {
                danhSach[i].Xuat();
            }
        }
    }



    void TinhTongLuong() {
        if (n == 0) return;
        float tong = 0;
        for (int i = 0; i < n; i++) {
            tong += danhSach[i].GetLuong();
        }
        cout << "\n=> Tong Luong cong ty phai tra la: " << tong << "\n";
    }

   


    void NhanVienTuoiCaoNhat() {
        if (n == 0) return;
        
        int minNamSinh = danhSach[0].LayNamSinh();
        
        for (int i = 1; i < n; i++) {
            if (danhSach[i].LayNamSinh() < minNamSinh) {
                minNamSinh = danhSach[i].LayNamSinh();
            }
        }

        cout << "\nNHAN VIEN TUOI CAO NHAT (Sinh nam: " << minNamSinh << ") ---\n";
        for (int i = 0; i < n; i++) {
            if (danhSach[i].LayNamSinh() == minNamSinh) {
                danhSach[i].Xuat();
            }
        }
    }
    void SapXepTangDanTheoLuong() {
        if (n == 0) return;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (danhSach[i].GetLuong() > danhSach[j].GetLuong()) {
                    cNhanVienVP tam = danhSach[i];
                    danhSach[i] = danhSach[j];
                    danhSach[j] = tam;
                }
            }
        }
        cout << "\nDa sap xep danh sach TANG DAN theo Luong!\n";
    }
};
int main() {
    cDanhSachNhanVienVP ds;
    int chon;

    do {
        cout << "\n============= MENU =============" << endl;
        cout << "1. Nhap danh sach nhan vien VP" << endl;
        cout << "2. Xuat danh sach nhan vien" << endl;
        cout << "3. Nhan vien co Luong cao nhat" << endl;
        cout << "4. Tong Luong cong ty phai tra" << endl;
        cout << "5. Nhan vien co tuoi cao nhat" << endl;
        cout << "6. Sap xep tang dan theo Luong" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;

        switch (chon) {
            case 1: ds.NhapDanhSach(); break;
            case 2: ds.XuatDanhSach(); break;
            case 3: ds.NhanVienLuongCaoNhat(); break;
            case 4: ds.TinhTongLuong(); break;
            case 5: ds.NhanVienTuoiCaoNhat(); break;
            case 6: 
                ds.SapXepTangDanTheoLuong(); 
                ds.XuatDanhSach(); 
                break;
            case 0: cout << "Ket thuc chuong trinh!\n"; break;
            default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (chon != 0);

    return 0;
}