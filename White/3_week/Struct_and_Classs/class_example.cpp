#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Route {
    // Публичная секция
    public:
    string GetSource() {return source; }
    string GetDestination() {return destination;}
    int GetLenght() {return lenght; }

    // Приватная секция
    private: 
        string source;
        string destination;
        int lenght;
};

int main()
{
    Route route;

    route.GetSource() = "Moscow";

    return 0;
}