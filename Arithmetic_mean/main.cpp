#include <iostream>
#include <string>
using namespace std;

bool valid(string type, int size)
{
    if(size <= 0 || size > 100)
    {
        throw invalid_argument("size");
    }
    else if(type != "int" || type != "float" || type != "double")
    {
        throw invalid_argument("type");
    }
    return true;
}

template<typename T>
void arithmetic_mean(T array[], int size)
{
    int am = 0;
    for(int i = 0; i < size; ++i)
    {
        am += array[i];
    }
    am /= size;
    cout << "Arithmetic mean:\n" << am << endl;
}

template<typename T>
void input(T array[], int size)
{
    T value;
    cout << "Fill the array:" << endl;
    for(int i = 0; i < size; ++i)
    {
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            throw invalid_argument("value");
        }
        array[i] = value;
    }
    arithmetic_mean(array, size);
}

int main()
{
    string type;
    int size = 0;

    cout << "Enter array type:" << endl;
    cin >> type;
    cout << "Enter array size:" << endl;
    cin >> size;

    try
    {
        if(cin.fail())
        {
            cin.clear();
			cin.ignore(256, '\n');
            valid(type, size);
        }
        else if(type == "int")
        {
            int index1[size];
            input(index1, size);
        }
        else if(type == "float")
        {
            float index2[size];
            input(index2, size);
        }
        else if(type == "double")
        {
            double index3[size];
            input(index3, size);
        }
        else
        {
            valid(type, size);
        }
    }
    catch(invalid_argument& e)
    {
        cerr << "Invalid argument: " << e.what();
    }
}