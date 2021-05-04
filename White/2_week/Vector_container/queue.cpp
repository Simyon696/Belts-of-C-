#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main(){
    int Q, count=0;
    cin >> Q;
    vector<int> queue;
    string command;
    int number;
 
    while ( Q>0 ){
        cin >> command;

        // COME
        if ( command == "COME")
        {
            cin >> number;

            // Если количество больше 0
            if (number>=0)
            {
                // Пополняем на НЕ обеспокоенных (false)
                queue.resize(queue.size()+number, false);
            } 
            else 
            {
                // Если меньше, то убираем последнего number раз
                for (int i=0; i<-number; i++)
                {
                    queue.pop_back();
                }
            }
        }

        // WORRY
        if (command == "WORRY")
        {
            cin >> number;
            // If человек уже был ОБЕСПОКОЕН (true) - то у нас будет false и ничего не поменяется
            // If человек был СПОКОЕН (false) - то здесь будет True и условие выполнется, он станет ОБЕСПОКОЕННЫМ (true)
            if ( !queue[number] )
            {                
                queue[number] = true;
            }
        }

        // QUIET
        if (command == "QUIET")
        {
            cin >> number;
            // If человек уже был ОБЕСПОКОЕН (true) - то у нас будет true и мы его успокоем - условие выполнится
            // If человек был СПОКОЕН (false) - то условие не выполнится, так как он уже СПОКОЕН (false)
            if ( queue[number] )
            {   
                queue[number] = false;
            }
        }

        // WORRY_COUNT
        if (command == "WORRY_COUNT")
        {
            // Используем счетчик для обнаружения всех ОБЕСПОКОЕННЫХ (true)
            count=0;
            for ( auto el : queue )
            {
                if ( el )
                {
                    count++;
                }
            }
            cout << count << endl;
        }       
 
        Q--;
    }   
 
    return 0;
}