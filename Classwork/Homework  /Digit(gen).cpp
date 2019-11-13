#include <fstream>

int main()
{
    std::ofstream out("number.txt");

    for(int i = 1; i <= 1000000; ++i)
        out<<i;

    out.close();
}