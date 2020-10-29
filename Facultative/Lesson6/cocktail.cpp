#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;

    set<string> bar;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        bar.insert(str);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        string event;
        cin >> event;

        if(event.front() == 'R')
        {
            string drink;
            cin >> drink;
            bar.erase(drink);
        }
        else if(event.front() == 'D')
        {
            string drink;
            cin >> drink;
            bar.insert(drink);
        }
        else
        {
            int num;
            cin >> num;

            bool ok = true; 
            while(num--)
            {
                string ing;
                cin >> ing;
                ok *= bar.find(ing) != bar.end();
            }

            cout << "Cocktail " << (ok ? "can " : "cannot ") << "be made\n";
        }
    }       
  
}