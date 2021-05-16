#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Person
{
private:
    vector<string> FindNamesHistory(int year, const map<int, string> &names) const
    {
        vector<string> result;

        // смотрим на все имена списка
        for (const auto &name : names)
        {
            // Пока год меньше установленного и такого имени еще не было в последовательности
            // find(result.begin(), result.end(), name.second) == result.end()
            if (name.first <= year && (result.empty() || result.back() != name.second))
            {
                result.push_back(name.second);
            }
        }

        return result;
    }

    string BuildFullName(const string &name, const string &last_name) const
    {
        if (name.empty() && last_name.empty())
            return "Incognito";
        if (!name.empty() && !last_name.empty())
            return name + " " + last_name;
        else
            return (name.empty()) ? last_name + " with unknown first name"
                                  : name + " with unknown last name";
    }

    string BuildJoinedName(vector<string> names) const
    {
        // Если имен нет, значит ворачиваем пустой список
        if (names.empty())
        {
            return "";
        }

        // Если имена есть, то разворачиваем список
        std::reverse(names.begin(), names.end());

        // Первое имя без скобок
        string chain = names[0];

        // Формируем предшествующие имена
        for (int i = 1; i < names.size(); i++)
        {
            if (i == 1)
                chain += " (";
            else
                chain += ", ";
            chain += names[i];
        }

        // Если было два имени или больше
        // (Нынешнее и прошлое, значит мы открывали скобки и их необходимо закрыть)
        if (names.size() > 1)
            chain += ")";

        return chain;
    }

public:
    Person(const string &name, const string &last_name, int year)
    {
        birthday = year;
        ChangeFirstName(birthday, name);
        ChangeLastName(birthday, last_name);
    }
    // Функции для пополнения списков
    void ChangeFirstName(int year, const string &name)
    {
        if (year >= birthday) first_names[year] = name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
        if (year >= birthday) last_names[year] = last_name;
    }

    string GetFullName(int year) const
    {
        // if (birthday != 0 && year < birthday)
        //     return "No person";

        if (year < birthday)
            return "No person";

        const vector<string> names_history = FindNamesHistory(year, first_names);
        const vector<string> last_names_history = FindNamesHistory(year, last_names);

        string name, last_name;

        if (!names_history.empty())
            name = names_history.back();
        if (!last_names_history.empty())
            last_name = last_names_history.back();

        return BuildFullName(name, last_name);
    }

    string GetFullNameWithHistory(int year) const
    {

        if (year < birthday)
            return "No person";

        const string name = BuildJoinedName(FindNamesHistory(year, first_names));
        const string last_name = BuildJoinedName(FindNamesHistory(year, last_names));

        return BuildFullName(name, last_name);
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;

    int birthday = 0;
};

int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960})
    {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967})
    {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}