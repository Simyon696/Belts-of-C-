#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string a ,b ,c;
    cin >> a >> b >> c;
    vector<string> lst = {a, b, c};
    string min = lst[0];
    int N = 3;
    for (int i = 1; i < N; i++) {
        if(min > lst[i]) min = lst[i];
    }
    cout << min;
    return 0;
}