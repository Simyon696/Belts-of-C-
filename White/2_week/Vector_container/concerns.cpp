#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 
    Так как мы работаем с памятью, поэтому используем указатель
       тоесть указываем с каким фрагментом памяти мы работаем, без копирования переменной
*/
void add(vector<vector<string>>& tasks_gen,
string task, int day) {
    tasks_gen[day].push_back(task);
}

/*
     Здесь используем const, потому что мы только считываем данные
*/
void dump(const vector<vector<string>>& tasks,
int day) {

    // Выводим количество задач в этот день
    cout << tasks[day].size() << " ";

    // Выводим сами задачи черех пробел
    for (string task: tasks[day]) {
        cout << task << " ";
    }
    cout << endl;
}
/* 
    Передаем список задач, номер текущего месяца и список
           месяцов, чтобы определить количество дней в новом расписании.

           Ко всему обращаемся с указателями для изменения наших данных 
           в глобальном пространстве (global).
*/
void next(vector<vector<string>>& tasks_gen,
        int& current_month,
        const vector<int>& months)
{   
    // Увеличиваем счетчик месяца на 1 (берем следующий месяц)
    ++current_month;

    //если текущий месяц стал > 11(т.е. 12) то начинаем год с начала
    if (current_month > 11) current_month = 0;

    
    // Создадим отдельную переменную количества дней в этом месяце
    // так как мы ее еще часто будем использовать, дабы не забивать память
    int new_month_days = months[current_month];
    size_t old_size = tasks_gen.size();

    // Создаем шаблон расписания на новый месяц
    vector<vector<string>> new_month = tasks_gen;

    tasks_gen.resize(new_month_days);

    // Переменная последнего дня нового месяца
    const int last = new_month_days - 1;
    // Если дней в новом месяце меньше чем в предыдущем, то
    if (new_month_days < old_size)
    {
        // С каждых последующих дней после конца нового месяца сжимаем их в последний
        for (new_month_days; new_month_days < old_size; ++new_month_days)
        {
            tasks_gen[last].insert(end(tasks_gen[last]), begin(new_month[new_month_days]), end(new_month[new_month_days]));
        }
    }

}

void preparing(vector<string>& commands,
vector<int>& days,
vector<string>& tasks,
int q) 
{
    // Сохраним все вводы данных
    for ( int i=0; i<q; ++i ) {
        string command, task;
        int day;
        cin >> command;

        commands.push_back(command);
        if (command != "NEXT") 
        {
            cin >> day;
            days.push_back(day);

            if (command == "ADD")
            {
                cin >> task;
                tasks.push_back(task);
            }
            else
            {
                tasks.push_back("empty");
            }
        }
        else
        {
            days.push_back(0);
            tasks.push_back("");
        }
    }
}

int main() {
    int q, day;
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> q;

    int current_month = 0;
    vector<string> commands;
    vector<int> days;
    vector<string> tasks;

    // Создаем массив массивов в количестве дней нынешнего месяца
    vector<vector<string>> tasks_gen(months[current_month]);

    // Сохраним весь вывод в отдельные списки,
    // по которым потом будем итерироваться
    preparing(commands, days, tasks, q);

    for (int i = 0; i < q; ++i) {
        // Считываем команду и принимаем решение какому сотруднику дать задание
        // Сотрудник выполняет работу - каждая функция - сотрудник

        if (commands[i] == "ADD")
        {
            // Считываем наше задание на этоот день
            string current_task = tasks[i];

            // -1, так как в обычной жизни n-ый день будет n-нным,
            // а в информатике n-1 - ым.
            int current_day = days[i] - 1;
            add(tasks_gen, current_task, current_day);
        }
        if (commands[i] == "DUMP")
        {
            int current_day = days[i] - 1;
            dump(tasks_gen, current_day);
        }
        if (commands[i] == "NEXT")
        {
            next(tasks_gen, current_month, months);
        }
    }
    return 0;
}