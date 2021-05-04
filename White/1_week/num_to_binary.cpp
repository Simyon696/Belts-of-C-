#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse_list (const vector<int> &v1) {
    vector<int> v2;
    size_t i = v1.size();
    while (i > 0)
        v2.push_back(v1[--i]);
    return v2;
    }


int main() {
    int n;
    cin >> n;
    vector<int> code = {};

    while (n > 0) {
        code.push_back((n % 2));
        n /= 2;
    }
    
    code = reverse_list(code);
    for (int c: code) {
        cout << c;
    }
    return 0;
}