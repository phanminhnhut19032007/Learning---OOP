#include <bits/stdc++.h>
using namespace std;

class cArray
{
private:
    int n; // so phan tu
    int *arr;

public:
    cArray()
    {
        this->n = 0;
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
    void NhapSoLuongPhanTu()
    {
        cin >> this->n;
    }
    void NhapMang()
    {
        arr = new int[n];
        for (int i = 0; i < this->n; i++)
        {
            int x;
            cout << "Moi ban nhap phan tu thu " << i << ": ";
            cin >> x;
            arr[i] = x;
        }
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
    bool KiemTraTangDan(int a, int b)
    {
        return a < b;
    }

    ~cArray()
    {
        delete[] arr;
    }
};

int main()
{

    return 0;
}