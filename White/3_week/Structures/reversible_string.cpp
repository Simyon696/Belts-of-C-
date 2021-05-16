#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString
{
    public:
        ReversibleString() {}
        ReversibleString(const string& s){
            text = s;
        }

        string ToString() const {
            return text;
        }

        void Reverse(){
            reverse(text.begin(), text.end());
        }
    private:
        string text = "";
};

int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    return 0;
}