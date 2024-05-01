#include <iostream>
using namespace std;
int main()
{
    int angka;

    lompat:

    do
    {
        cout << "Masukkan angka dari -100 sampai 100 :";
        cin >> angka; 
    }   while (angka < - 100 ||  angka > 100);
    
    cout << "angka anda adalah "<< angka << endl;
    

}