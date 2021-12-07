#include <iostream>
#include<windows.h>
using namespace std;

void load();
string ROT13(string teks, int a, int b);
string enkripsiAffine(string teks, int a, int b);
string dekripsiAffine(string teks, int a, int b);

int main()
{
    string teks;
    int a, b;
    char option;
    cout << "Masukkan plaintext : ";
    getline(cin >> ws, teks);
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;

    cout << endl << endl << endl;
    system("color 07");
    load();
    cout << endl << endl << endl;

    cout << "------------------ Encrypted ------------------" << endl << endl;
    cout << "First, we use ROT13 method\n";
    teks = ROT13(teks, a, b);
    cout << "Encrypted of ROT 13 : " << teks;

    cout << "\n\nNext, we use Affine method for double encrypted";
    teks = enkripsiAffine(teks, a, b);
    cout << "\nEncrypted of Affine : " << teks;
    cout << "\nSo, The Chiperteks\t: " << teks << endl;

    cout << "\n\nare you ready for the Decrypted? (Y/N)\n";
    cin >> option;

    if(option == 'Y' || option == 'y'){
    cout << endl << endl << endl;
    system("color 07");
    load();
    cout << endl << endl << endl;

    cout << "\n\n------------------ Decrypted ------------------" << endl << endl;
    cout << "ROT13 method\n";
    teks = ROT13(teks, a, b);
    cout << "Decrypted of ROT 13 : " << teks;

    cout << "\n\nAffine method";
    teks = dekripsiAffine(teks, a, b);
    cout << "\nDecrypted of Affine : " << teks;
    cout << "\nSo, The Plainteks\t: " << teks << endl;
    } else{
        cout << "\nOkey, see you in the good time!\n";
    }
}

void load()
{
    char a = 219;
    cout << "Loading..."<< endl;
    for(int r =1; r<=20; r++)
    {
        for(int q=0; q<=10000000; q++);
        cout << a;
    }
}

string ROT13(string teks, int a, int b)
{
    string hasil = "";

    for (int i = 0; i < teks.length(); i++)
    {
        if (int(teks[i]) == 32)
        {
            hasil += char(int(teks[i]));
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
            hasil += char(int(teks[i]));
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
            hasil += char(int(teks[i]));
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