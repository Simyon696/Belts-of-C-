#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Вкладываем наш вектор в функцию
vector<int> Reversed(const vector<int>& v) {
    // Создаем список обратного порядка чисел возложенного
    vector<int> reverso = {};

    // Загоняем их в обратном порядке и возвращаем массив
    for (int i = v.size() - 1; i >= 0; --i) {
        reverso.push_back(v[i]);
    }
    return reverso;
}

int main() {
    return 0;
}