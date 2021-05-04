#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A, B, C, x, x1, x2, D;
    cin >> A >> B >> C;

    // Считаем дискриминант
    D = pow(B, 2) - (4 * A * C);

    // Смотрим на условия и находим корни, выводим их, если они есть

    // Bx + C = 0
    if (A == 0 && B != 0 && C != 0) { 
        x = (-C) / B;
        cout << x;

    // Ax^2 + C = 0
    } else if (B == 0 && A != 0 && C != 0) {

        // Если оба отрицательных, то просто делим друг на друга
        if (isnan(sqrt(A)) && isnan(sqrt(C))) {
            x1 = sqrt(C/A);
            x2 = -x1;
            cout << x1 << " " << x2;

        // Если отрицательный только один, то добавляем минус
        } else if ( isnan(sqrt(A)) || isnan(sqrt(C)) ) {
            x1 = sqrt(-C/A);
            x2 = -x1;
            cout << x1 << " " << x2;
        }

    // Ax^2 + Bx = 0
    } else if (C == 0 && A !=0 && B != 0) { 
        x1 = 0;
        x2 = (-B) / A;
        cout << x1 << " " << x2;

    // Ax^2 + Bx + C = 0
    } else if (A != 0 && B != 0 && C != 0){ 

        if (D > 0) {
            x1 = (-B + sqrt(D)) / (2 * A);
            x2 = (-B - sqrt(D)) / (2 * A);
            cout << x1 << " " << x2;

        } else if (D == 0) {
            x = (-B) / (2 * A);
            cout << x;
        }
    }
    return 0;
}