#include <bits/stdc++.h>
using namespace std;

struct node
{
    vector<int>next;
    bool leaf = false;

    node()
    {
        next.resize(26, -1);
    }
};

vector<node>trie(1);

void add_string(string const& s)
{
    int v = 0;
    for(char ch : s)
    {
        int ind = ch - 'a';
        if(trie[v].next[ind] == -1)
        {
            trie[v].next[ind] = trie.size()-1;
            trie.emplace_back();
        }

        v = trie[v].next[ind];
    }

    trie[v].leaf = true;
}

void traverse(int &ans, int cur_node = 0, int cur_ans = 0)
{
    cur_ans += trie[cur_node].leaf;
    ans = max(ans, cur_ans);

    for(int i = 0; i < 26; ++i)
        if(trie[cur_node].next[i] != -1 && trie[cur_node].next[i] != trie.size())
        {
            traverse(ans, cur_node, cur_ans);
        }

    --cur_ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string>v(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        add_string(v[i]);
    }

    int ans = 0;
    traverse(ans);

    cout << ans << endl;

}