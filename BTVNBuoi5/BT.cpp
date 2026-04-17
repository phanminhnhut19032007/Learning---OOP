#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class DaThuc
{
private:
    int n; // Bac da thuc
    double *HeSo;

public:
    DaThuc()
    {
        n = 0;
        HeSo = new double[1];
        HeSo[1] = 0;
    }
    DaThuc(int bac)
    {
        n = bac;
        HeSo = new double[n + 1];
        for (int i = 0; i <= n; i++)
        {
            HeSo[i] = 0;
        }
    }
    DaThuc(const DaThuc &other)
    {
        n = other.n;
        HeSo = new double[n + 1];
        for (int i = 0; i <= n; i++)
        {
            HeSo[i] = other.HeSo[i];
        }
    }
    DaThuc &operator=(DaThuc &other)
    {
        if (this != &other)
        {
            delete[] HeSo;
            n = other.n;
            HeSo = new double[n + 1];
            for (int i = 0; i <= n; i++)
            {
                HeSo[i] = other.HeSo[i];
            }
        }
    }
    double TinhGiaTriBieuThuc(double x);
    friend istream &operator>>(istream &is, DaThuc &a)
    {
        cout << "Nhap bac cua da thu: ";
        is >> a.n;

        a.HeSo = new double[a.n + 1];
        cout << "Nhap cac he so: " << endl;
        for (int i = a.n; i >= 0; i--)
        {
            cout << "Nhap he so x^" << i << " : ";
            is >> a.HeSo[i];
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, DaThuc a)
    {
        if (a.HeSo[0] == 0 && a.n == 0)
        {
            os << "0";
            return os;
        }
        for (int i = a.n; i >= 0; i--)
        {
            if (a.HeSo[i] != 0)
            {
                if (i < a.n && a.HeSo[i] > 0)
                {
                    os << "+";
                }
                os << a.HeSo[i];
                if (i > 0)
                {
                    os << "x^" << i << " ";
                }
            }
        }
        return os;
    }
    DaThuc operator+(DaThuc &other)
    {
        int bac = max(this->n, other.n);
        DaThuc result(bac);
        for (int i = 0; i <= bac; i++)
        {
            double hs1 = (i <= this->n) ? this->HeSo[i] : 0;
            double hs2 = (i <= other.n) ? other.HeSo[i] : 0;
            result.HeSo[i] = hs1 + hs2;
        }
        return result;
    }
    DaThuc operator-(DaThuc &other)
    {
        int bac = max(this->n, other.n);
        DaThuc result(bac);
        for (int i = 0; i <= bac; i++)
        {
            double hs1 = (i <= this->n) ? this->HeSo[i] : 0;
            double hs2 = (i <= other.n) ? other.HeSo[i] : 0;
            result.HeSo[i] = hs1 - hs2;
        }
        return result;
    }
    ~DaThuc()
    {
        delete[] HeSo;
    }
};
double DaThuc::TinhGiaTriBieuThuc(double x)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
    {
        result += HeSo[i] * pow(x, i);
    }
    return result;
}

int main()
{
    DaThuc P, Q;
    cout << "\nNhap da thuc P(x): " << endl;
    cin >> P;
    cout << "\nNhap da thuc Q(x): " << endl;
    cin >> Q;
    cout << "\nDa thuc P(x) = " << P << endl;
    cout << "\nDa thuc Q(x) = " << Q << endl;
    DaThuc Tong = P + Q;
    DaThuc Hieu = P - Q;
    cout << "\nP(x)+Q(x) = " << Tong << endl;
    cout << "\nP(x)-Q(x) = " << Hieu << endl;
    double x;
    cout << "\nNhap gia tri de tinh P(x): ";
    cin >> x;
    cout << "P(" << x << ") = " << P.TinhGiaTriBieuThuc(x) << endl;
    return 0;
}