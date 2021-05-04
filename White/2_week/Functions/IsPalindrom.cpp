#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string word) {
    // Узнаем длину слова
    int len = word.length();
    // Сравниваем слово с самим собой, только с разных концов
    // https://nicknixer.ru/programmirovanie/palindrom-proverit-yavlyaetsya-li-slovo-stroka-chislo-palindromom-na-c/
    for (int i = 0; i < len/2; ++i) {
        if(word[i] != word[len-i-1]) {
            return false;
        }
    } return true;
}


int main() {
    string word;
    cin >> word;

    cout << IsPalindrom(word);
    return 0;
}