#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string to_lower(string s)
{
    for (auto& c : s)
        c = tolower(c);
    return s;
}

int main()
{
    int q;
    cin >> q;

    vector<string> v;

    for (int i = 0; i < q ; ++i)
    {
        string input;
        cin >> input;
        // Пополняем вектор
        v.push_back(input);
    }

    sort(v.begin(), v.end(), [](string a, string b)
    {
        return to_lower(a) < to_lower(b);
    });

    for (const string& s : v)
    {
        cout << s << " ";
    }
    return 0;
}