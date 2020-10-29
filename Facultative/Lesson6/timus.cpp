#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<set<int> > students(n);
    string cmd;
    while (cin >> cmd)
    {
        if(cmd[0] == 's')
        {
            int num, prob;
            cin >> num >> prob;
            students[num - 1].insert(prob);
        }
        else
        {
            int a, b;
            char dummy;
            cin >> a >> dummy >> b;
            
            vector<int> diff;
            set_difference(students[a-1].begin(), students[a-1].end(), 
            students[b-1].begin(), students[b-1].end(), back_inserter(diff));

            if(diff.empty())
            {
                cout << "There are no problems which student " << a << " has solved but " << b << " hasn’t.\n";
                continue;
            }
            if(diff.size() == 1)
            {
                cout << "There is 1 problem which student " << a << " has solved but " << b << " hasn’t: ";
            }
            else
            {
                cout << "There are " << diff.size() << " problems which student " << a << " has solved but " << b << " hasn’t: ";
            }
            
            for(auto el : diff)
            {
                cout << el << " ";
            }
            cout << endl;
            
        }
        
    }
    
    
}