#include <iostream>
#include <string>
#include <map>

using namespace std;

string GetValue(const map<int, string> &names, int year)
{
    string result;

    for (const auto &name : names)
    {
        // Пока год меньше установленного, обновляем переменную
        if (year >= name.first)
            result = name.second;
        else
            break;
    }
    return result;
}

class Person
{
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name)
    {
        last_names[year] = last_name;
    }

    string GetFullName(int year)
    {
        // Получаем значения
        const string name = GetValue(first_names, year);
        const string last_name = GetValue(last_names, year);

        if (name.empty() && last_name.empty())
            return "Incognito";

        if (!name.empty() && !last_name.empty())
            return name + " " + last_name;
        else
            return (name.empty()) ? last_name + " with unknown first name" : name + " with unknown last name";
    }

private:
    // Создаем два словаря для работы
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
    // Person person;

    // person.ChangeFirstName(1965, "Polina");
    // person.ChangeLastName(1967, "Sergeeva");
    // for (int year : {1900, 1965, 1990})
    // {
    //     cout << person.GetFullName(year) << endl;
    // }

    // person.ChangeFirstName(1970, "Appolinaria");
    // for (int year : {1969, 1970})
    // {
    //     cout << person.GetFullName(year) << endl;
    // }

    // person.ChangeLastName(1968, "Volkova");
    // for (int year : {1969, 1970})
    // {
    //     cout << person.GetFullName(year) << endl;
    // }

    return 0;
}