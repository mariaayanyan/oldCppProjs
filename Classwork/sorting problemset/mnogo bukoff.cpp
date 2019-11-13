#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ifstream fin("gibberish.txt");
    vector<int> bucket(26);

    char cnt;
    while(fin >> cnt)
        ++bucket[cnt - 'a'];

    fin.close();

    for(int i = 0; i < 26; ++i)
    {
        cout << char('a' + i) << "- " << setw(10) << bucket[i] << endl;
    }

}