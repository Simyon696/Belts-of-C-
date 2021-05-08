#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Функция для определения аннаграм
map<char, int> BuildCharCounters(const string& word)
{
    map<char, int> counter;

    for (char c: word)
    {
        ++counter[c];
    }
    return counter;
}

int main() 
{
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        string word1, word2;
        cin >> word1 >> word2;

        if (BuildCharCounters(word1) != BuildCharCounters(word2))  cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}