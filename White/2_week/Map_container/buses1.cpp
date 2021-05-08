#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void new_bus(map<string, vector<string>>& bus_list, vector<string>& steps)
{
    string bus;
    int stop_count;
    cin >> bus >> stop_count;
    steps.push_back(bus);
    // Создадим вектор из остановок
    for (int i = 0; i < stop_count; ++i)
    {
        // Считываем остановку
        string stop;
        cin >> stop;
        // Пополняем список остановок для автобуса
        bus_list[bus].push_back(stop);
    }
}

/* 
Будем использовать функцию в двух режимах, когда у нас уже есть определенная остановка
   о которой мы хотим что-то узнать и когда ее нет
*/
void buses_for_stop(const map<string, vector<string>>& bus_list,
const string stop, const string bus, vector<string>& buses,
const vector<string>& steps)
{
    // Если мы не передали никакую остановку, то значит ее необходимо считать с косноли
    if (stop == "" & bus == "")
    {
        string stop;
        cin >> stop;

        for (auto& temp_bus : bus_list)
        {
            // https://ru.cppreference.com/w/cpp/algorithm/binary_search
            // if (binary_search(stops.begin(), stops.end(), stop))
            // {
            //     buses.push_back(bus);
            // }
            for (const string& temp_stop: temp_bus.second) 
            {
                if (temp_stop == stop) buses.push_back(temp_bus.first); 
            }
        }
        //  Если после проверки такой остановки не оказалось, то выводим это
        if (buses.size() == 0)
        {
            cout << "No stop" << endl;
        }
        // Если остановка все же нашлась, то
        else
        {
            for (auto& step : steps)
            {
                for (const string& bus: buses)
                {
                    if (step == bus) cout << bus << " ";
                }
            }
            cout << endl;
        }
    }
    // 2 МОДУЛЬ
    // Если мы передали остановку, то нам нужно узнать какие автобусы
    // останавливаются на ней
    else
    {
        for (auto& temp_bus : bus_list)
        {
            // https://ru.cppreference.com/w/cpp/algorithm/binary_search
            if (temp_bus.first != bus)
            {
                for (const string& temp_stop : temp_bus.second)
                {
                    if (temp_stop == stop) buses.push_back(temp_bus.first);
                }
            }

        }
        // Из списка удаляем наш автобус (https://en.wikipedia.org/wiki/Erase–remove_idiom)
        // buses.erase(std::remove(buses.begin(), buses.end(), bus), buses.end());
    }

}

void stops_for_bus(map<string, vector<string>>& bus_list, 
const vector<string>& steps)
{
    string bus;
    cin >> bus;
    
    // Если такого автобуса нет, то так и пишем
    if (bus_list.count(bus) == 0) cout << "No bus" << endl;
    // Если же есть, начинаем выполнять функцию
    else 
    {
        // Берем список остановок автобуса
        vector<string> stops = bus_list[bus];

        // Для каждой остановки узнаем другие автобусы
        for (const string& stop: stops)
        {
            // В начачле для каждой остановки очищаем список автобусов
            vector<string> buses;

            // Запускаем 2 МОДУЛЬ нашей функции
            buses_for_stop(bus_list, stop, bus, buses, steps);

            // Если никакой другой автобус не проезжает через эту останвоку
            // значит у нас будет пустой список
            if (buses.size() == 0) cout << "Stop " << stop << ": " "no interchange " << endl;
            // Делаем вывод для каждой останвоки если автобусы есть
            else 
            {
                cout << "Stop " << stop << ": ";
                for (auto& step : steps)
                    // Устанавливаю последовательность вывода
                    for (const string& bus : buses)
                    {
                        if (bus == step) cout << bus << " ";
                    }
                // Переходим на следующую остановку
                cout << endl;
            }

        }
    }
}

void all_buses(map<string, vector<string>>& bus_list)
{
    // Если автобусов нет
    if (bus_list.size() == 0) cout << "No buses" << endl;

    // Если они уже есть
    else 
    {
        for (const auto& temp_bus : bus_list)
        {
            cout << "Bus " << temp_bus.first << ": ";
            for (const string& stop : temp_bus.second)
            {
                cout << stop << " ";
            }
            cout << endl;
        }
    }

}

int main() 
{
    int q;
    cin >> q;
    // Нужен для сохранения последовательности new_bus
    vector<string> steps;

    map<string, vector<string>> bus_list;

    for (int i = 0; i < q; ++i)
    {
        string command;
        cin >> command;
        if (command != "ALL_BUSES")
        {
            if (command == "NEW_BUS")
            {
                new_bus(bus_list, steps);
            }
            if (command == "BUSES_FOR_STOP")
            {
                vector<string> buses;
                buses_for_stop(bus_list, "", "", buses, steps);
            }
            if (command == "STOPS_FOR_BUS")
            {
                stops_for_bus(bus_list, steps);
            }
        }
        else
        {
            all_buses(bus_list);
        }
    }

    return 0;
}