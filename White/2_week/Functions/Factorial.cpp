#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Factorial(int x) {
    vector<int> nums = {};
    int result = 1;
    // Если нужно найти факториал нуля, то тогда ответ 1
    if (x < 0)
        return 1;
    // Если же отличное от нуля, то создаем массив всех цифр (или чисел) 
    // от 1 до этого числа
    else {
        for (int i = 1; i <= x; ++i) {
            nums.push_back(i);
        }
        // Перемножаем все значения массива - reduce() если в Python
        for (int i : nums) {
            result *= i;
        }
        return result;
    }
}

int main() {
    int x;
    cin >> x;
    cout << Factorial(x);
    return 0;
}