#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void add (map<string, set<string>>& words)
{
    // Считываем слова
    string word1, word2;
    cin >> word1 >> word2;

    // Словарь со множеством синонимов для каждого слова
    words[word1].insert(word2);
    words[word2].insert(word1);
}

void check (map<string, set<string>>& words)
{
    string word1, word2;
    cin >> word1 >> word2;

    // Если со словом с таким ключом у нас есть второй синоним, то пишем YES
    if (words[word1].count(word2)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void count (map<string, set<string>>& words)
{
    string word;
    cin >> word;

    // Выводим количество синонимов из их множества для данного слова
    cout << words[word].size() << endl;
}

int main()
{
    int q;
    cin >> q;

    map<string, set<string>> words;

    for (int i = 0; i<q; i++)
    {
        string command;
        cin >> command;

        if (command == "ADD")
        {
            add(words);
        }
        else if (command == "COUNT")
        {
            count(words);
        }
        else
        {
            check(words);
        }
    }
    return 0;
}