#include <iostream>
#include <set>
#include <vector>

using namespace std;

void PrintSet(const set<string>& s) {
  cout << "Size = " << s.size() << endl;
  for (auto x : s) {
    cout << x << endl;
  }
}

set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}

int main () {
    int q;
    cin >> q;

    set<string> s;

    for (q; q>0; --q)
    {
        string word;
        cin >> word;

        s.insert(word);
    }

    cout << s.size();
  return 0;
}
