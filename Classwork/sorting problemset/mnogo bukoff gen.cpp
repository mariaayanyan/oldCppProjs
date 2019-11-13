#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    ofstream fout("gibberish.txt");

    for(int i = 0; i < 100000000; ++i)
    {
        char gen = 'a' + rand()%26;
        fout << gen;
    }

    fout.close();
}
