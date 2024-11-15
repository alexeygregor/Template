#include "Shop.h"

int main()
{
    string article, cnt;
    int count = 0;
    bool input = true;
    map<string, int> warez;
    map<string, int> basket;
    map<string, int>::iterator it;

    cout << "Enter the article:" << endl;
    while(input)
    {
        cin >> article;
        if(article == "end")
        {
            input = false;
            continue;
        }

        cin >> cnt;
        try
        {
            count = stoi(cnt);
        }
        catch(exception) {}

        try
        {
            valid(article, count);
            warez.insert(pair<string, int> (article, count));
        }
        catch(const invalid_argument& e)
        {
            cerr << "Invalid argument supplied: " << e.what() << endl;
        }
    }

    input = true;
    cout << "Enter the article:" << endl;
    while(input)
    {
        cin >> article;
        if(article == "end")
        {
            input = false;
            continue;
        }

        cin >> cnt;
        try
        {
            count = stoi(cnt);
        }
        catch(exception)
        {
            cerr << "Invalid argument supplied: count" << endl;
            continue;
        }

        try
        {
            valid(article, count);
            store(warez, article, count);
            basket.insert(pair<string, int> (article, count));
        }
        catch(const invalid_argument& e)
        {
            cerr << "Invalid argument supplied: " << e.what() << endl;
        }
        catch(const runtime_error& e)
        {
            cerr << "Runtime error: " << e.what() << endl;
        }
    }

    resume(warez, basket);
}