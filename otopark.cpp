#include <iostream>
#include <conio.h>
using namespace std;
void AnaMenu();
class otopark
{
private:
    int buyukarackapasite;
    int kucukarackapasite;
    int buyukaracsayisi;
    int kucukaracsayisi;

public:
    otopark(int buyukarackapasite, int kucukarackapasite);
    int Kkontrol(int kucukarackontrol);
    int Kkontrol2(int kucukarackontrol);
    int Bkontrol(int buyukarackontrol);
    int Bkontrol2(int buyukarackontrol);
    void kucukaracgirisfonk(int karacgiris);
    void kucukaraccikisfonk(int karaccikis);
    void buyukaracgirisfonk(int baracgiris);
    void buyukaraccikisfonk(int baraccikis);
    void print();
};

otopark::otopark(int buyukarackapasite, int kucukarackapasite)
{
    this->buyukarackapasite = buyukarackapasite;
    this->kucukarackapasite = kucukarackapasite;
    this->buyukaracsayisi = buyukarackapasite;
    this->kucukaracsayisi = kucukarackapasite;
}
void otopark::kucukaracgirisfonk(int karacgiris)
{
    kucukaracsayisi -= karacgiris;
    cout << "Islem basariyla tamamlandi" << endl;
    getch();
}
void otopark::kucukaraccikisfonk(int karaccikis)
{
   kucukaracsayisi += karaccikis;
    cout << "Islem basariyla tamamlandi" << endl;
    getch();
}
void otopark::buyukaracgirisfonk(int baracgiris)
{
    buyukaracsayisi -= baracgiris;
    cout << "Islem basariyla tamamlandi" << endl;
    getch();
}
void otopark::buyukaraccikisfonk(int baraccikis)
{
    buyukaracsayisi += baraccikis;
    cout << "Islem basariyla tamamlandi" << endl;
    getch();
}
void otopark::print()
{
    cout << "Otoparktaki kucuk araclar icin bos yer sayisi: " << kucukaracsayisi << endl;
    cout << "Otoparktaki buyuk araclar icin bos yer sayisi: " << buyukaracsayisi << endl;
    getch();
}
int otopark::Kkontrol(int kucukarackontrol)
{
    if (kucukaracsayisi < kucukarackontrol)
        return 1;

    else
        return 0;
}
int otopark::Kkontrol2(int kucukarackontrol)
{
    int arac;
    arac=kucukarackontrol+kucukaracsayisi;
    if (kucukarackapasite < arac)
        return 1;
    else
        return 0;
    
}
int otopark::Bkontrol(int buyukarackontrol)
{
    if (buyukaracsayisi < buyukarackontrol)
        return 1;
    else
        return 0;
}
int otopark::Bkontrol2(int buyukarackontrol)
{
      int arac;
    arac=buyukarackontrol+buyukaracsayisi;
    if (buyukarackapasite < arac)
        return 1;
    else
        return 0;
}
int main()
{
    int *girilen = new int;
    int *girilenarac = new int;
    int *girilenkarac = new int;
    int *girilenbarac = new int;
    cout << "Olusturacaginiz otopark icin kucuk ve buyuk arac sayisi giriniz:" << endl;
    cout << "Kucuk arac sayisi: " << endl;
    cin >> *girilenkarac;
    cout << "Buyuk arac sayisi: " << endl;
    cin >> *girilenbarac;
    otopark Kayseri(*girilenbarac, *girilenkarac);
    do
    {
        AnaMenu();
        cin >> *girilen;
        switch (*girilen)
        {
        case 1:
            system("cls");
            cout << "Arac sayisini giriniz: " << endl;
            cin >> *girilenarac;
            if (Kayseri.Kkontrol(*girilenarac))
            {
                cout << "Yeterli yer yok!!!" << endl;
                getch();
                break;
            }
            Kayseri.kucukaracgirisfonk(*girilenarac);
            break;
        case 2:
            system("cls");
            cout << "Arac sayisini giriniz: " << endl;
            cin >> *girilenarac;
            if (Kayseri.Bkontrol(*girilenarac))
            {
                cout << "Yeterli yer yok!!!" << endl;
                getch();
                break;
            }
            Kayseri.buyukaracgirisfonk(*girilenarac);
            break;
        case 3:
            system("cls");
            cout << "Arac sayisini giriniz: " << endl;
            cin >> *girilenarac;
            if (Kayseri.Kkontrol2(*girilenarac))
            {
                cout << "Otoparkta bu sayida kucuk arac yok" << endl;

                getch();
                break;
            }
            Kayseri.kucukaraccikisfonk(*girilenarac);
            break;
        case 4:
            system("cls");
            cout << "Arac sayisini giriniz: " << endl;
            cin >> *girilenarac;
            if (Kayseri.Bkontrol2(*girilenarac))
            {
                cout << "Otoparkta bu sayida buyuk arac yok" << endl;
                getch();
                break;
            }
            Kayseri.buyukaraccikisfonk(*girilenarac);
            break;
        case 5:
            system("cls");
            Kayseri.print();

            break;
        case 0:
            break;
        default:
            system("cls");
            cout << "Dogru sayi giriniz." << endl;
            getch();
            break;
        }
    } while (0 < *girilen);
    delete girilen;
    delete girilenarac;
    delete girilenbarac;
    delete girilenkarac;
    cout<<"Made by FURKAN KOCA"<< endl;
}

void AnaMenu()
{
    system("cls");
    cout << "1-)Kucuk arac girisi" << endl;
    cout << "2-)Buyuk arac girisi" << endl;
    cout << "3-)Kucuk arac cikisi" << endl;
    cout << "4-)Buyuk arac cikisi" << endl;
    cout << "5-)Otoparktaki arac sayisi" << endl;
    cout << "0-)Sistemden cikis" << endl;
}
