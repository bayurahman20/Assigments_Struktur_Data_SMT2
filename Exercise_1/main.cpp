/*
 * Nama Kelompok :
 * 1. Amanda A Gunawan 01085210007
 * 2. Evri Bagas Saputro 01085210008
 * 3. Erwiyono Yusuf 01085210013
 * 4. Bayu Rahman Adinata 01085210005
 * */

#include <iostream>

using namespace std;

void initEgg(int [5][10], int, int[2]);

int buyEgg(int [5][10], int, int, int[2]);

void viewEgg(int [5][10], int[2]);

int countEgg(int data[5][10]);


int main() {
    int data[5][10], choose, rack = -1, buyValue, arrTop[2];
    arrTop[0] = -1;
    arrTop[1] = -1;

    do {
        do {
            cout << "Menu" << endl;
            cout << "1. Inisialisasi Telur" << endl;
            cout << "2. Lihat Rak Telur" << endl;
            cout << "3. Beli Telur" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih menu (1 - 4): ";
            cin >> choose;
        } while (choose < 1 || choose > 4);

        if (choose == 1) {
            initEgg(data, rack, arrTop);
            cout << "Inisialisasi Telur Berhasil" << endl;
            system("pause");
            cout << endl;
        } else if (choose == 2) {
            viewEgg(data, arrTop);
            cout << endl;
            system("pause");
            cout << endl;
        } else if (choose == 3) {
            cout << "Beli Telur berapa butir Mas : ";
            cin >> buyValue;
            rack = buyEgg(data, rack, buyValue, arrTop);
            cout << endl;
            system("pause");
            cout << endl;
        }
        system("cls");
    } while (choose != 4);

    system("pause");

    return 0;
}

void initEgg(int data[5][10], int top, int arrTop[2]) {
    for (int i = 0; i < 5; ++i) {
        arrTop[1] = -1;
        for (int j = 0; j < 10; ++j) {
            data[i][j] = 0;
            arrTop[1] += 1;
        }
        arrTop[0] += 1;
    }
}

int buyEgg(int data[5][10], int top, int cnt, int arrTop[2]) {

    int lastEgg = countEgg(data), cntTemp = cnt;

    if (lastEgg < cntTemp) {
        cout << "Telur Abis boss";
    } else {
        for (int i = 5; cnt > 0 && i > 0; --i)  {

            if ((i-1) <= arrTop[0]){
                for (int j = 10; cnt > 0 &&  j > 0; --j) {
                    if ((j-1) <= arrTop[1]){
                        data[i-1][j-1] = -1;
                        arrTop[1] -= 1;
                        --cnt;
                    }
                }
            }
            if (arrTop[1] == -1) {
                arrTop[0] -= 1;
                if (arrTop[0] > -1) {
                    arrTop[1] = 9;
                }
            }
        }
        cout << cntTemp << " Telur Berhasil terbeli" << endl;
    }
    return cntTemp;
}

void viewEgg(int data[5][10], int arrTop[2]) {
    for (int i = 5; i > 0; --i) {
        for (int j = 10; j > 0; --j) {
            if (data[i-1][j-1] == -1) {
                cout << " ";
            } else {
                cout << data[i-1][j-1];
            }
        }
        cout << endl;
    }
}

int countEgg(int data[5][10]) {
    int counter = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (data[i][j] == 0) {
                counter++;
            }
        }
    }

    return counter;
}
