#include <iostream>
#include <vector>
using namespace std;
template<class T>
void insert_into_vector(vector<T>& v, int pos, const T& elem)
{
    int size = v.size();
    v.resize(size + 1);

    for(int i = size; i > pos; --i)
        v[i] = v[i-1];

    v[pos] = elem;
}

template<class T>
void erase_from_vector(vector<T>& v, int pos)
{
    for(int i = pos; i < (int)v.size() - 1; ++i)
        v[i] = v[i+1];
    v.resize(v.size() - 1);
}


template<class T>
void print(const vector<T> &v)
{
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    insert_into_vector(v, 2, 7);
    cout << v.size() << endl; //5

    print(v); // 1 2 7 3 4

    erase_from_vector(v, 1);
    cout << v.size() << endl; //4

    print(v); // 1 7 3 4
}