#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *str;
    int Len;

public:
    String()
    {
        Len = 0;
        str = new char[1]{'\0'};
    }

    String(const char *s)
    {
        Len = strlen(s);
        str = new char[Len + 1];
        strcpy(str, s);
    }

    String(const String &other)
    {
        Len = other.Len;
        str = new char[Len + 1];
        strcpy(str, other.str);
    }
    ~String()
    {
        delete[] str;
    }
    int ChieuDaiChuoi()
    {
        return Len;
    }

    String NoiChuoi(String s2)
    {
        char *tam = new char[Len + s2.Len + 1];
        strcpy(tam, str);
        strcat(tam, s2.str);

        String kq(tam);
        delete[] tam;
        return kq;
    }

    void DaoChuoi()
    {
        for (int i = 0; i < Len / 2; i++)
        {
            swap(str[i], str[Len - 1 - i]);
        }
    }

    void InHoa()
    {
        for (int i = 0; i < Len; i++)
            str[i] = toupper(str[i]);
    }

    void InThuong()
    {
        for (int i = 0; i < Len; i++)
            str[i] = tolower(str[i]);
    }

    void nhap()
    {
        char tam[1000];
        cin.getline(tam, 1000);

        delete[] str;
        Len = strlen(tam);
        str = new char[Len + 1];
        strcpy(str, tam);
    }

    void XuatChuoi()
    {
        cout << str;
    }
};

int main()
{
    String s1;
    cout << "Nhap chuoi s1: ";
    s1.nhap();

    String s2(" - OOP C++");

    cout << "1. Chieu dai s1: " << s1.ChieuDaiChuoi() << "\n";
    String s3 = s1.NoiChuoi(s2);
    cout << "2. Noi voi s2: ";
    s3.XuatChuoi();
    cout << "\n";
    s1.DaoChuoi();
    cout << "3. Dao chuoi s1: ";
    s1.XuatChuoi();
    cout << "\n";
    s1.InHoa();
    cout << "4. In hoa s1: ";
    s1.XuatChuoi();
    cout << "\n";
    s1.InThuong();
    cout << "5. In thuong s1: ";
    s1.XuatChuoi();
    cout << "\n";

    return 0;
}