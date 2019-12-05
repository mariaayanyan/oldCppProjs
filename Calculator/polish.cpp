#include <bits/stdc++.h>

#define ll long long
#define a_number(a) (a>='0' && a<='9')
using namespace std;

template<class T>
int check_mod(T a, T b) { return (a % b) ? 1 : 0; }

int pr(char c) {
    if (c == '+' || c == '-')
        return 0;
    if (c == '*' || c == '/')
        return 1;
    if (c == '(')
        return 2;
    if (c == '!')
        return 3;

    cout << "Unrecognized operation!\n";
    exit(-1);
}

bool priority(char a, char b) {
    return pr(a) > pr(b);
}

string RPN(string s) {
    string ans;
    int len = (int) s.length();
    vector<char> stack;

    for (int i = 0; i < len; i++) {
        if ((a_number(s[i]))) {
            while (a_number(s[i]) && i < len)
                ans.push_back(s[i++]);

            ans.push_back(',');
            i--;
            continue;
        }


        if (s[i] == ')') {

            while (stack.back() != '(') {
                ans.push_back(stack.back());
                ans.push_back(',');
                stack.pop_back();
            }

            stack.pop_back();
            continue;

        }


        if (s[i] == '(' || stack.empty() || priority(stack.back(), s[i])) {
            stack.push_back(s[i]);
            continue;
        }

        ans.push_back(stack.back());
        ans.push_back(',');
        stack.pop_back();
        stack.push_back(s[i]);


    }
    while (!stack.empty()) {
        ans.push_back(stack.back());
        ans.push_back(',');
        stack.pop_back();
    }
    if (ans[ans.length() - 1] == ',')ans.pop_back();


    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto t1 = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, rpn;
    cin >> s;
    rpn = RPN(s);
    cout << rpn << endl;

    vector<string> res;
    vector<char> stack;
    int len = (int) rpn.length();

    for (int i = 0; i < len; i++) {
        if (rpn[i] == ',')continue;

        if (a_number(rpn[i])) {
            string temp = "";
            while (a_number(rpn[i]) && i < len)
                temp += rpn[i++];

            res.push_back(temp);
            continue;

        }

        double a = atof(res[res.size() - 2].c_str());
        double b = atof(res[res.size() - 1].c_str());
        res.pop_back();
        res.pop_back();

        if (rpn[i] == '+') {
            res.push_back(to_string(a + b));
            continue;
        }

        if (rpn[i] == '-') {
            res.push_back(to_string(a - b));
            continue;
        }

        if (rpn[i] == '*') {
            res.push_back(to_string(a * b));
            continue;
        }

        res.push_back(to_string(a / b));


    }
    cout << res[0] << endl;


#ifdef LOCAL
    auto t2 = chrono::high_resolution_clock::now();
    cerr << "Running time " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
#endif
    return 0;
}