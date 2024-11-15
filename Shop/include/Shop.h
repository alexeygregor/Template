#pragma once
#include <iostream>
#include <string>
#include <map>
#include <exception>
using namespace std;

void valid(string& article, int& count);

void store(map<string, int>& warez, string& article, int& count);

void resume(map<string, int> warez, map<string, int> basket);
