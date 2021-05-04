#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция, что была в прошлом задании
bool IsPalindrom(string word) {
    size_t len = word.length();
    for (int i = 0; i < word.size() / 2; ++i) {
        if (word[i] != word[word.size() - i - 1]) {
                return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {

    // Создаем массив для сохранения нужных нам результатов
    vector<string> right = {};

    // Проверяем каждое слово
    for (string word: words)
    {
        // Если удовлетворяет условию длины и слово - палиндром, то добавляем
        // в противном случая ничего не делаем
        if (word.size() >= minLength && IsPalindrom(word))
        {
                right.push_back(word);
        }
    }
    return right;
}
    


int main() {

    // Для проверки
    vector<string> words = {"abacaba", "aba"};
    vector<string> lst = PalindromFilter(words, 2);
    
    // for (string word: lst) {
    //     cout << word << ",";
    // }
    return 0;
}