#include <bits/stdc++.h>
using namespace std;

class cArray
{
private:
    int n; 
    int *arr;
    bool KiemTraNguyenTo(int k)
    {
        if (k < 2) return false;
        for (int i = 2; i <= sqrt(k); i++)
        {
            if (k % i == 0) return false;
        }
        return true;
    }

public:
    cArray()
    {
        this->n = 0;
        this->arr = nullptr; 
    }

    cArray(int soluong)
    {
        this->n = soluong;
        arr = new int[n];
        for (int i = 0; i < this->n; i++)
        {
            arr[i] = 0;
        }
    }

    ~cArray()
    {
        if (arr != nullptr) {
            delete[] arr;
        }
    }
    void NhapMang()
    {
        cout << "Nhap so luong phan tu n: ";
        cin >> this->n;
        
        if (arr != nullptr) delete[] arr;
        arr = new int[n];

        for (int i = 0; i < this->n; i++)
        {
            cout << "Moi ban nhap phan tu thu " << i << ": ";
            cin >> arr[i];
        }
    }

    void TaoMangNgauNhien()
    {
        cout << "Nhap so luong phan tu n: ";
        cin >> this->n;
        
        if (arr != nullptr) delete[] arr;
        arr = new int[n];

        srand(time(0)); 
        for (int i = 0; i < this->n; i++)
        {
            arr[i] = rand() % 100; 
        }
        cout << "-> Da tao mang ngau nhien thanh cong!\n";
    }
    void XuatMang()
    {
        if (n == 0 || arr == nullptr) {
            cout << "Mang dang rong!\n";
            return;
        }
        cout << "Cac phan tu trong mang la: ";
        for (int i = 0; i < this->n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    int Count(int x)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                cnt++;
            }
        }
        return cnt;
    }
    bool KiemTraTangDan()
    {
        if (n <= 1) return true; 
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void TimLeNhoNhat()
    {
        int minLe = INT_MAX;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0 && arr[i] < minLe)
            {
                minLe = arr[i];
                found = true;
            }
        }
        
        if (found) cout << "Phan tu le nho nhat trong mang la: " << minLe << "\n";
        else cout << "Khong co so le nao trong mang!\n";
    }
    void TimNguyenToLonNhat()
    {
        int maxNT = INT_MIN;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (KiemTraNguyenTo(arr[i]))
            {
                if (!found || arr[i] > maxNT) {
                    maxNT = arr[i];
                    found = true;
                }
            }
        }

        if (found) cout << "So nguyen to lon nhat trong mang la: " << maxNT << "\n";
        else cout << "Khong co so nguyen to nao trong mang!\n";
    }
    void SapXepTangDan()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
        cout << " Da sap xep mang TANG DAN.\n";
    }
    void SapXepGiamDan()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
        cout << "-> Da sap xep mang GIAM DAN.\n";
    }

    bool IsEmpty() {
        return n == 0 || arr == nullptr;
    }
};

int main()
{
    cArray mang;
    int luaChon;

    do
    {
        cout << "\n================= MENU QUAN LY MANG =================" << endl;
        cout << "1. Tao mang ngau nhien" << endl;
        cout << "2. Nhap mang bang tay" << endl;
        cout << "3. Xuat cac phan tu mang" << endl;
        cout << "4. Dem so lan xuat hien cua gia tri X" << endl;
        cout << "5. Kiem tra mang co tang dan khong" << endl;
        cout << "6. Tim phan tu le nho nhat" << endl;
        cout << "7. Tim so nguyen to lon nhat" << endl;
        cout << "8. Sap xep mang tang dan" << endl;
        cout << "9. Sap xep mang giam dan" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "=========================================================" << endl;
        cout << "Moi ban nhap lua chon: ";
        cin >> luaChon;

        // Chặn người dùng gọi các hàm xử lý nếu mảng chưa được khởi tạo (ngoại trừ lựa chọn 0, 1, 2)
        if (mang.IsEmpty() && luaChon >= 3 && luaChon <= 9) {
            cout << "Mang dang rong! Vui long khoi tao mang (Chon 1 hoac 2) truoc.\n";
            continue;
        }
        switch (luaChon)
        {
        case 1:
            mang.TaoMangNgauNhien();
            break;
        case 2:
            mang.NhapMang();
            break;
        case 3:
            mang.XuatMang();
            break;
        case 4:
            int x;
            cout << "Nhap gia tri X can dem: ";
            cin >> x;
            cout << "-> So lan xuat hien cua " << x << " la: " << mang.Count(x) << " lan.\n";
            break;
        case 5:
            if (mang.KiemTraTangDan()) cout << " Mang hien tai DANG tang dan.\n";
            else cout << " Mang hien tai KHONG tang dan.\n";
            break;
        case 6:
            mang.TimLeNhoNhat();
            break;
        case 7:
            mang.TimNguyenToLonNhat();
            break;
        case 8:
            mang.SapXepTangDan();
            mang.XuatMang();
            break;
        case 9:
            mang.SapXepGiamDan();
            mang.XuatMang();
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh! Tam biet.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai tu 0 den 9!\n";
            break;
        }
    } while (luaChon != 0);

    return 0;
}