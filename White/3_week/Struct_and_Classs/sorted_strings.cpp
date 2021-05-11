#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string to_lower(string s)
{ 
    for (auto& c : s)
    c = tolower(c);
    return s;
}

class SortedStrings {
    public:
        void AddString(const string& s) {
            strings_row.push_back(s);
        }

    vector<string> GetSortedStrings() {
        // sort(strings_row.begin(), strings_row.end(), [] (string a, string b)
        // {
        //     return to_lower(a) < to_lower(b);
        // });
        sort(strings_row.begin(), strings_row.end());
        return strings_row;
    }

    private:
        vector<string> strings_row;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
    SortedStrings strings;
  
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
  
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    return 0;
}