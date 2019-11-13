#include <iostream>
using namespace std;

void printReverse(int n)
{
    if(n == 0)
        return;

    int num;
    cin >> num;

    printReverse(n - 1);
    cout << num << " ";

}

int main()
{
    int n;
    cin >> n;

    printReverse(n);
}
