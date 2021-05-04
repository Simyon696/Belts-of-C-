#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void PrintResult(const vector<double>& v) {
    // Выводим количество значений
    cout << v.size() << endl;
    // Выводим значения в одну строку через запятую
    for (auto i : v) {
        cout << i << " ";
    }
}

double est_mean(vector<double>& nums, int n) {
    double sum = 0;

    // Находим сумму
    for (double n: nums) {
        sum += n;
    }
    // Находим среднее значение
    double mean = sum / n;
    return mean;
}

int main() {
    int n;
    cin >> n;

    // Создаем вектор
    vector<double> nums(n);

    // Добавляем (вводим) значения температуры
    for (double& num: nums) {
        cin >> num;
    }

    // Рассчитываем среднее по температуре
    double mean = est_mean(nums, n);

    // Массив для сохранения верных значений
    vector<double> right;
    // Сравним значения и поместим в список
    for (int i = 0; i <= n; i++) {
        if (nums[i] > mean)
            right.push_back(i);
    }

    PrintResult(right);
    return 0;
}