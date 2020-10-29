#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;

	list<int> lst;
	for(int i = 0; i < n; ++i)
	{
		int el;
		cin >> el;
		lst.push_back(el);
	}

	auto first = find(lst.begin(), lst.end(), 0);
	if(first != lst.end())
	{
		auto second = find(next(first), lst.end(), 0);
		if(second != lst.end())
			lst.erase(second); 
	}

	for(const auto &el : lst)
		cout << el << " ";
}