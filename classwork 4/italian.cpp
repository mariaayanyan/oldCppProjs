#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::string>ans;

    for(int i = 0; i < n; ++i)
    {
        std::string temp;
        std::cin >> temp;

        char last = temp[temp.length()-1];
        if(last == 'a' || last == 'o')
            ans.push_back(temp);
    }

    std::cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); ++i)
    {
        char last = ans[i][ans[i].length()-1];
        std::cout << ans[i] << " - " << (last == 'a' ? "f.\n" : "m.\n");

    }

}
