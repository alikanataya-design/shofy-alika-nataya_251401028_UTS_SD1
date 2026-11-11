#include <iostream>
#include <string>
using namespace std;

#define MAX 100
int main() {
    char stack[MAX];
    int top = -1;
    string kata, balik = "";
    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        top++;
        stack[top] = kata[i];
    }
    while (top >= 0) {
        balik += stack[top];
        top--;
    }
    cout << "Pengecekan:" << endl;
    cout << "Kata dibalik: " << balik << endl;

    if (kata == balik) {
        cout << "Kesimpulan: KATA INI ADALAH PALINDROM";
    } else {
        cout << "Kesimpulan: BUKAN PALINDROM";
    }
    cout << endl;

    return 0;
}
