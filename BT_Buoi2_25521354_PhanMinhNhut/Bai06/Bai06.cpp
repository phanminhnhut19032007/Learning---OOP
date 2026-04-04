#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *str;
    int len;

public:
    String()
    {
        len = 0;
        str = new char[1]{'\0'};
    }

    String(const char *s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    String(const String &other)
    {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    ~String()
    {
        delete[] str;
    }
    int ChieuDaiChuoi()
    {
        return len;
    }

    String NoiChuoi(String s2)
    {
        char *tam = new char[len + s2.len + 1];
        strcpy(tam, str);
        strcat(tam, s2.str);

        String kq(tam);
        delete[] tam;
        return kq;
    }

    void DaoChuoi()
    {
        for (int i = 0; i < len / 2; i++)
        {
            swap(str[i], str[len - 1 - i]);
        }
    }

    void InHoa()
    {
        for (int i = 0; i < len; i++)
            str[i] = toupper(str[i]);
    }

    void InThuong()
    {
        for (int i = 0; i < len; i++)
            str[i] = tolower(str[i]);
    }

    void nhap()
    {
        char tam[1000];
        cin.getline(tam, 1000);

        delete[] str;
        len = strlen(tam);
        str = new char[len + 1];
        strcpy(str, tam);
    }

    void xuat()
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
    s3.xuat();
    cout << "\n";
    s1.DaoChuoi();
    cout << "3. Dao chuoi s1: ";
    s1.xuat();
    cout << "\n";
    s1.InHoa();
    cout << "4. In hoa s1: ";
    s1.xuat();
    cout << "\n";
    s1.InThuong();
    cout << "5. In thuong s1: ";
    s1.xuat();
    cout << "\n";

    return 0;
}