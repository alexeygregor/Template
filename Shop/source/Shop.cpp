#include "Shop.h"

void valid(string& article, int& count)
{
    if(article.length() > 50)
        throw invalid_argument("article");

    if(count <= 0 || count > 100)
        throw invalid_argument("count");
}

void store(map<string, int>& warez, string& article, int& count)
{
    map<string, int>::iterator it;
    bool ch = false;
    for(it = warez.begin(); it != warez.end(); ++it)
    {
        if(article == it->first)
        {
            ch = true;
            break;
        }
    }
    if(!ch)
        throw invalid_argument("article");

    ch = false;
    for(it = warez.begin(); it != warez.end(); ++it)
    {
        if(article == it->first)
        {
            if(count <= it->second)
            {
                it->second -= count;
                cout << "Remainder " << it->first << ": " << it->second << endl;
                ch = true;
                break;
            }
        }
    }
    if(!ch)
        throw invalid_argument("count");
}

void resume(map<string, int> warez, map<string, int> basket)
{
    map<string, int>::iterator it;

    cout << "Store: " << endl;
    for(it = warez.begin(); it != warez.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "Basket: " << endl;
    for(it = basket.begin(); it != basket.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
}