#include "Register.h"

namespace id
{
    string inKey;
    string inVal;
};

Key::Key(string _key)
{
    id::inKey = _key;
}

Val::Val(string _val)
{
    id::inVal = _val;
}

Register::Register(Key)
{
    key = id::inKey;
}
Register::Register(Val)
{
    val = id::inVal;
}

bool extract1(vector<vector<Register>>& vec, string input, int i)
{
    bool valid = true;
    string str1, str2;
    (valid)
    {
        try
        {
            int ch = stoi(vec[i][0].key);
            str1 = to_string(ch);
            str2 = vec[i][0].key;
            if(input == str1.substr(0, input.length()))
            {
                cout << "[" << i << "] " << str2  << " (int)" << endl;
                valid = false;
                return true;
            }
        }
        catch (exception) {}
    }
    (valid)
    {
        try
        {
            double ch = stod(vec[i][0].key);
            str1 = to_string(ch);
            str2 = vec[i][0].key;
            if(input == str1.substr(0, input.length()))
            {
                cout << "[" << i << "] " << str2 << " (double)" << endl;
                valid = false;
                return true;
            }
        }
        catch (exception) {}
    }
    (valid)
    {
        try
        {
            str1  = vec[i][0].key;
            if (input == str1.substr(0, input.length()))
            {
                cout << "[" << i << "] " << str1 << " (string)" << endl;
                valid = false;
                return true;
            }
        }
        catch (exception) {}
    }
    return false;
}

void extract2(vector<vector<Register>>& vec, string input, int i)
{
    bool valid = true;
    string str1, str2;
    (valid)
    {
        try
        {
            int ch = stoi(vec[i][1].val);
            str1 = to_string(ch);
            str2 = vec[i][1].val;
            if(str2 == str1.substr(0, str2.length()))
            {
                cout << "[_] " << str2 << " (int)" << endl;
                valid = false;
            }
        }
        catch (exception) {}
    }
    (valid)
    {
        try
        {
            double ch = stod(vec[i][1].val);
            str1 = to_string(ch);
            str2 = vec[i][1].val;
            if(str2 == str1.substr(0, str2.length()))
            {
                cout << "[_] " << str2 << " (double)" << endl;
                valid = false;
            }
        }
        catch (exception) {}
    }
    (valid)
    {
        try
        {
            str1  = vec[i][1].val;
            cout << "[_] " << str1 << " (string)" << endl;
            valid = false;
        }
        catch (exception) {}
    }
}

void find(vector<vector<Register>>& vec)
{
    string input;
    cin >> input;
    bool ch = false;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(extract1(vec, input, i))
        {
            extract2(vec, input, i);
            ch = true;
        }
    }
    if(!ch)
        cerr << "[.] Invalid key" << endl;
}

void add(vector<vector<Register>>& vec)
{
    string str1, str2;
    cin >> str1 >> str2;
    vec.push_back({(Key) str1, (Val) str2});
}

void remove(vector<vector<Register>>& vec)
{
	bool ch = false;
    string input;
    cin >> input;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(input == vec[i][0].key)
		{
            vec.erase(vec.begin( ) + i);
			ch = true;
		}
	}
	if(!ch)
		cerr << "[.] Invalid key" << endl;
}

void print(vector<vector<Register>>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        extract1(vec, vec[i][0].key, i);
        extract2(vec, vec[i][1].val, i);
    }
}
