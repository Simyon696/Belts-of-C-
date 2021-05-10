#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;

    vector<int> v;

    for (int i = 0; i < q ; ++i)
    {
        int num;
        cin >> num;
        // Пополняем вектор
        v.push_back(num);
    }

    sort(v.begin(),v.end(),[](int a, int b){ return abs(a) < abs(b);});

    for (const int& num : v)
    {
        cout << num << " ";
    }
    return 0;
}