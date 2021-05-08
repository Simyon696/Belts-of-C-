#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main()
{
    int q, counter;
    cin >> q;

    counter = 0;
    map<vector<string>, int> dict;
    
    for (int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;
        vector<string> v;

        for (int j = 0; j < n; j++)
        {
            string word;
            cin >> word;
            // i выступает в роли индекса
            v.push_back(word);
        }
        if (dict.count(v)) cout << "Already exists for " << dict[v] << endl;
        else{
            ++counter;
            dict[v] = counter;
            cout << "New bus " << counter << endl;
        }
    }
    return 0;
}