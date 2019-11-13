#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int helper)
{
    if(n == 1)
    {
        cout << "Move top ring from peg " << from << " to " << to << endl;
        return;
    }

    hanoi(n-1, from, helper, to);
    hanoi(1, from, to, helper);
    hanoi(n-1, helper, to, from);

}

int main()
{
    int n;
    cin >> n;

    hanoi(n, 1, 3, 2);
}