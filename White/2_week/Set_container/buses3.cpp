#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


int main()
{
    int q, index;
    cin >> q;
    index = 0;

    // Основной словарь
    map<set<string>, int > dict;
    
    for (int i = 0; i < q; ++i) 
    {
        // Количество остановок
        int n;
        cin >> n;

        set<string> temp;

        // Пополняем список остановок 
        for (int i = 0; i < n; i++)
        {
            string stop;
            cin >> stop;

            temp.insert(stop);
        }
        // Если в словаре есть такой индекс остановок, то
        if (dict.count(temp)) cout << "Already exists for " << dict[temp] << endl;
        // Если такого не было
        else
        {
            dict[temp] = ++index;
            cout << "New bus " << index << endl;
        }
    }
    return 0;
}