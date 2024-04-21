#include <iostream>
#include <random>
#include <string>

using namespace std;

string newNumber() {
    random_device rd;  
    mt19937 gen(rd()); 

 
    uniform_int_distribution<int> dis(0, 999);
    int num = dis(gen);
    string result = to_string(num);
    while (result.length() < 3) {
        result = "0" + result;
    }
    return result;
}

void info() {
    cout << "      Tutturulan Hane Sayısı    Kazanç" << endl;
    cout << "                 3              Bahis x 10" << endl;
    cout << "                 2              Bahis x 5" << endl;
    cout << "                 1              Kayıp veya Kazanç Yok" << endl;
    cout << "                 0              Bahis x 2 Kayıp" << endl << endl << endl;

}

int main() {
    setlocale(LC_ALL, "Turkish");
    int maxcoin = 1000;
    int coin;

    while (true) {
        int menu;
        string input;
        string number = newNumber();

        cout << "Bakiye sorgulamak için 1'i  " << endl;
        cout << "Ruleti döndürmek için 2'yi" << endl;
        cout << "Kazanç / kayıp hakkında bilgi almak için 3'ü" << endl;
        cout << "Oyundan çıkmak için 4'ü tuşlayın" << endl;
        cout << endl << "Seçiminiz:";

        cin >> menu;


        if (menu == 1)
        {
            cout << "Bakiyeniz: " << maxcoin << endl << endl;
            continue;
        } // Bakiye sorgulama
        if (menu == 2)
        {
            // Oyun başlangıcı
            cout << endl << endl <<"Lutfen girmek istediğiniz miktari girin: ";
            cin >> coin;
            if (maxcoin - coin < 0) {
                cout << "Kullanılabilecek bakiye: "<< maxcoin << endl;
                break;
            // Bakiye bittiyse döngüyü sonlandır
            }

            cout << "Lutfen 3 basamaklı bir sayi giriniz: ";
            cin >> input;

            // Ruletin sonucu
            cout << endl << "Ruletin sonucu: " << number;

            // Sayıların aynı olma durumu
            bool a = (input[0] == number[0]);
            bool b = (input[1] == number[1]);
            bool c = (input[2] == number[2]);

            // Durumlara göre kazanç
            if (a && b && c) {
                coin *= 10;
            }
            else if (a && b) {
                coin *= 5;
            }
            else if (a && c) {
                coin *= 5;
            }
            else if (b && c) {
                coin *= 5;
            }
            else if (a || b || c == true)
            {
                coin *= 0;
            }
            else {
                coin = coin * -2;
            }

            maxcoin += coin;
            if (maxcoin < 0)
            {
                cout <<endl << "Bakiyeniz bitti." << endl;
                break;
            }
            else
            {
                cout << endl << "Yeni bakiyeniz: " << maxcoin << endl << endl<< endl;
                continue;
            }
        } // Oyun
        if (menu == 3)
        {
            info();
            continue;
        } // Bilgi
        if (menu == 4)
        {
            cout << "Bakiyeniz: " << maxcoin << endl << endl;
            break;
        }//Çıkış
        else
        {
            cout << "Lutfen gecerli bir islem giriniz." << endl;
            continue;
        }

        return 0;
    }
        }
