#include "Register.h"

int main()
{
    cout << "Register" << endl;
    vector<vector<Register>> vec;
    vec.push_back({(Key) "39", (Val) "19.9"});
    vec.push_back({(Key) "20.12", (Val) "poiuyt"});
    vec.push_back({(Key) "qwerty", (Val) "26"});
    int i = 0;
    while(i != -1)
    {
        string input, command;
        cin >> command;

        if(command == "search")
        {
            search(vec);
        }
        else if(command == "add")
        {
            add(vec);
        }
        else if(command == "print")
        {
            print(vec);
        }
        else if(command == "end")
        {
            i = -1;
        }
        else
        {
            cerr << "Input error" << endl;
        }
    }
}