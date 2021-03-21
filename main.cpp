#include <iostream>
#include <iomanip>
#include<stdio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <cmath>

using namespace std;
bool Sprawdzenie(int);
void Generowanie();
int Nwd(int, int);
int OdwrMod(int, int);
void ZakodujRSA();
int Modpot(int, int, int);
double long p, q, z, n, e, d;




int main()
{
    int wybor;


    do
    {
        cout << endl;
        cout << "-------------------------------------------" << endl;
    cout << "System szyfrowania danych RSA" << endl << endl;
    cout << "1 - Generowanie kluczy" << endl;
    cout << "2 - Kodowanie" << endl;
    cout << "3 - Koniec" << endl << endl;
        cout << "Wybierz opcje: ";
            cin  >> wybor;
            cout << endl;

    switch (wybor)
    {
      case 1 : Generowanie();
      break;
      case 2 : ZakodujRSA();
      break;
      case 3 : exit(0);

    }

  } while(wybor != 0);







}
// GENEROWANIE KLUCZY

void Generowanie()
{
     do
    {

        srand((unsigned)time(NULL));
        p = rand()%998+2;
        q = rand()%998+2;

     if ((Sprawdzenie(p)) && (Sprawdzenie(q)))
     {
         cout << "Liczba p wynosi: " <<p << endl;
         cout << "Liczba q wynosi: " <<q << endl << endl;

         n   = p * q;

         z = (p - 1) * (q - 1);


        for(e = 3; Nwd(e,z) != 1; e += 2);
            d = OdwrMod(e,z);

         cout << "KLUCZ PUBLICZNY" << endl << endl;
            cout << "Wykladnik e wynosi: " << e << endl;
            cout << "Modul n wynosi: " << n << endl << endl;;
         cout << "KLUCZ PRYWATNY" << endl << endl;
            cout << "Wykladnik d wynosi: " << d << endl;
             system("cls");

     }
     else
     {
         do
         {
             cout << "Losuje liczbe pierwsza... " << endl;
            system("cls");
             srand((unsigned)time(NULL));
             p = rand()%998+2;
             q = rand()%998+2;

             if ((Sprawdzenie(p)) && (Sprawdzenie(q)))
            {
         cout << "Liczba p wynosi: " <<p << endl;
         cout << "Liczba q wynosi: " <<q << endl << endl;

                n   = p * q;
                z = (p - 1) * (q - 1);

            for(e = 3; Nwd(e,z) != 1; e += 2)
            d = OdwrMod(e,z);



            cout << "KLUCZ PUBLICZNY" << endl << endl;
            cout << "Wykladnik e wynosi: " << e << endl;
            cout << "Modul n wynosi: " << n << endl << endl;;
            cout << "KLUCZ PRYWATNY" << endl << endl;
            cout << "Wykladnik d wynosi: " << d << endl;

             break;

            }

         }while(true);



    }
    } while (p == q);





}

// SPRAWDZENIE CZY LICZBA JEST PIERWSZA //

    bool Sprawdzenie(int a)
    {
        if (a <= 1) return false;
            for (unsigned int i = 2; i <= sqrt(a); i++)
            {
                if (!(a%i))
                    return false;
            }

    return true;
    }

// OBLICZANIE NWD z wykorzystaniem algorytmu Euklidesa

    int Nwd(int a, int b)
    {

            while(a != b)
            {
                if (a > b)
                    a = a - b;
                else
                    b = b - a;
            }
            return a;
    }



// OBLICZANIE ODWROTNOSCI MODULO z wykorzystaniem rozszerzonego algorytmu Euklidesa//

    int OdwrMod(int a, int n)
  {
   int a0, n0, p0, p1, q, r, t;

  p0 = 0; p1 = 1; a0 = a; n0 = n;
  q  = n0 / a0;
  r  = n0 % a0;
  while(r > 0)
  {
    t = p0 - q * p1;
    if(t >= 0)
      t = t % n;
    else
      t = n - ((-t) % n);
    p0 = p1; p1 = t;
    n0 = a0; a0 = r;
    q  = n0 / a0;
    r  = n0 % a0;
  }
  return p1;
}

// OBLICZANIE MODULO POTEGI //

int Modpot(int a, int w, int n)
{
  int pot,wyn,q;

  pot = a; wyn = 1;
  for(q = w; q > 0; q /= 2)
  {
    if(q % 2)
    wyn = (wyn * pot) % n;
    pot = (pot * pot) % n;
  }
  return wyn;
}



// KODOWANIE DANYCH

void ZakodujRSA()
{
  int e,n,t;

     cout << "KODOWANIE RSA" << endl << endl;
     cout <<     "Podaj wykladnik e: ";
           cin  >> e;
     cout << endl;
     cout << "Podaj modul n: ";
           cin  >> n;
     cout << endl;
     cout <<    "Podaj kod RSA: ";
           cin  >> t;
     cout << endl;


    cout << "Wynik kodowania: " << Modpot(t,e,n) << endl;

    Sleep(3000);
    system("cls");

    getchar();



}







