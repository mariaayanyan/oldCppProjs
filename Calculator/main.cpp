#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char c)
{
    if(c == '+' || c == '-')
        return 0;
    if(c == '*' || c == '/')
        return 1;
    if(c == '(')
        return 2;
    if(c == '!')
        return 3;

    cout << "Unrecognized operation!\n";
    exit(-1);
}

int factorial(int n)
{
    int ans = 1;
    for(int i = 2; i <= n; ++i)
        ans *= i;
    return ans;
}

void performOperation(stack<int> &num, stack<char> &oper)
{
    if(num.empty())
    {
        cout << "Invalid expression!\n";
        exit(-1);
    }

    int b = num.top(); num.pop();
    char op = oper.top(); oper.pop();
    if(op == '!')
    {
        num.push(factorial(b));
        return;
    }

    if(num.empty())
    {
        cout << "Invalid expression!\n";
        exit(-1);
    }

    int a = num.top(); num.pop();

    if(op == '+')
        num.push(a+b);
    else if(op == '-')
        num.push(a-b);
    else if(op == '*')
        num.push(a*b);
    else if(op == '/')
        num.push(a/b);
    else
    {
        cout << "Couldn't perform operation\n";
        exit(-1);
    }

}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    stack<int> num;
    stack<char> oper;

    char c;
    while(cin >> c)
    {
        if(isdigit(c))
        {
            cin.putback(c);
            int n; cin >> n;
            num.push(n);
            continue;
        }

        if(c == '(')
        {
            oper.push(c);
            continue;
        }

        if(c == ')')
        {
            while(!oper.empty() && oper.top() != '(')
                performOperation(num, oper);

            if(oper.empty())
            {
                cout << "Invalid expression!\n";
                exit(-1);
            }

            oper.pop();
            continue;
        }

        if(oper.empty() || priority(oper.top()) < priority(c))
        {
            oper.push(c);
            continue;
        }

        while(!oper.empty() && priority(c) <= priority(oper.top()) && oper.top() != '(')
        {
            performOperation(num, oper);
        }
        oper.push(c);
    }

    while(!oper.empty())
        performOperation(num, oper);

    if(num.size() != 1)
    {
        cout << "Invalid expression!\n";
        exit(-1);
    }

    cout << num.top() << endl;

}