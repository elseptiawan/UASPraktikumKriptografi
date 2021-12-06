#include <iostream>
using namespace std;

string ROT13(string teks, int a, int b);
string enkripsiAffine(string teks, int a, int b);
string dekripsiAffine(string teks, int a, int b);

int main()
{
    string teks;
    int a, b;
    cout << "Masukkan plaintext : ";
    getline(cin >> ws, teks);
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;
    teks = ROT13(teks, a, b);
    teks = enkripsiAffine(teks, a, b);
    cout << "Chiperteks\t: " << teks << endl;
    teks = ROT13(teks, a, b);
    teks = dekripsiAffine(teks, a, b);
    cout << "Plainteks\t: " << teks;
}

string ROT13(string teks, int a, int b)
{
    string hasil = "";

    for (int i = 0; i < teks.length(); i++)
    {
        if (int(teks[i]) == 32)
        {
            hasil += char(int((teks[i] - 32)) % 26 + 32);
        }
        else
        {
            if (isupper(teks[i]))
            {
                hasil += char(int((teks[i] - 65) + 13) % 26 + 65);
            }
            else
            {
                hasil += char(int((teks[i] - 97) + 13) % 26 + 97);
            }
        }
    }
    return hasil;
}

string enkripsiAffine(string teks, int a, int b)
{
    string hasil = "";

    for (int i = 0; i < teks.length(); i++)
    {
        if (int(teks[i]) == 32)
        {
            hasil += char(int((teks[i] - 32)) % 26 + 32);
        }
        else
        {
            if (isupper(teks[i]))
            {
                hasil += char(int(a * (teks[i] - 65) + b) % 26 + 65);
            }
            else
            {
                hasil += char(int(a * (teks[i] - 97) + b) % 26 + 97);
            }
        }
    }
    return hasil;
}

string dekripsiAffine(string teks, int a, int b)
{
    string hasil = "";
    int invers_mod_a;
    for (int i = 0; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
        {
            invers_mod_a = i;
            break;
        }
    }

    for (int i = 0; i < teks.length(); i++)
    {
        if (int(teks[i]) == 32)
        {
            hasil += char(int((teks[i] - 32)) % 26 + 32);
        }
        else
        {
            if (isupper(teks[i]))
            {
                hasil += char(int(invers_mod_a * ((teks[i] - 65) - b) + (26 * invers_mod_a)) % 26 + 65);
            }
            else
            {
                hasil += char(int(invers_mod_a * ((teks[i] - 97) - b) + (26 * invers_mod_a)) % 26 + 97);
            }
        }
    }
    return hasil;
}