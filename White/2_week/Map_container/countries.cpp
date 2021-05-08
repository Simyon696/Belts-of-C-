#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void change_capital(map<string, string>& thesaurus)
{
    string country, new_capital;
    cin >> country >> new_capital;

    // Если у нас была такая страна
    if (thesaurus.count(country) != 0)
    {
        // Если такая столица уже была
        if (thesaurus[country] == new_capital)
        {
            cout << "Country " << country << " hasn't changed its capital" << endl; 
        }
        // Если была другая столица, то
        else
        {
            // Считываем старую столицу
            string old_capital = thesaurus[country];
            // Заменяем столицу
            thesaurus[country] = new_capital;
            // Выводим предложение
            cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
        }
    }
    // Если у нас не было такой страны, то пишем это:
    else 
    {
        thesaurus[country] = new_capital;
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    }
    
}

void rename(map<string, string>& thesaurus)
{
    string old_country_name, new_country_name;
    cin >> old_country_name >> new_country_name;

    // Если названия совпадают, то ничего не делаем
    if (old_country_name == new_country_name || thesaurus.count(old_country_name) == 0 || thesaurus.count(new_country_name) == 1)
    {
        cout << "Incorrect rename, skip" << endl;
    }
    // Если не совпадают, то
    else
    {   
        // Текст
        cout << "Country " << old_country_name << " with capital " << thesaurus[old_country_name] << " has been renamed to " << new_country_name << endl;
        // Создаем новый ключ и удаляем старый
        thesaurus[new_country_name] = thesaurus[old_country_name];
        thesaurus.erase(old_country_name);
    }
}

void about(map<string, string>& thesaurus)
{
    string country;
    cin >> country;

    // Если такая страна существует в справочнике
    if (thesaurus.count(country) != 0)
    {
        cout << "Country " << country << " has capital " << thesaurus[country] << endl;
    }
    // Если страны не имеется в данных
    else
    {
        cout << "Country " << country << " doesn't exist" << endl;
    }
}

void dump(map<string, string>& thesaurus)
{
    // Если пока не было добавлено ни одной страны
    if (thesaurus.size() == 0)
    {
        cout << "There are no countries in the world" << endl;
    }
    // Если уже есть, то выводим на печать
    else
    {
        for (auto& item : thesaurus)
        {
            cout << item.first << "/" << item.second << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int q;
    cin >> q;

    map<string, string> thesaurus;

    for (int i = 0; i<q; ++i)
    {
        string command;
        cin >> command;
        if (command != "DUMP")
        {
            if (command == "CHANGE_CAPITAL")
            {
                change_capital(thesaurus);
            }
            if (command == "RENAME")
            {
                rename(thesaurus);
            }
            if (command == "ABOUT")
            {
                about(thesaurus);
            }
        }
        else
        {
            dump(thesaurus);
        }
    }

    return 0;
}