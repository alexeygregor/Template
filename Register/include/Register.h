#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
namespace id {};

struct Key
{
    Key(string _key);
};

struct Val
{
    Val(string _val);
};

struct Register
{
    string key;
    string val;

    Register(Key _Key);
    Register(Val _Kal);
};

bool extract1(vector<vector<Register>>& vec, string input, int i);

void extract2(vector<vector<Register>>& vec, string input, int i);

void find(vector<vector<Register>>& vec);

void add(vector<vector<Register>>& vec);

void remove(vector<vector<Register>>& vec);

void print(vector<vector<Register>>& vec);