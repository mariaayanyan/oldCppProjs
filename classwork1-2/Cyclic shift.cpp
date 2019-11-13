#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int>a(n),b(n);

    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    for(int i = 0; i < n; ++i)
        std::cin >> b[i];

    bool is_a_shift = false;

    for(int start = 0; start < n && !is_a_shift; ++start)
    {
        is_a_shift = true;
        for(int i = 0; i < n && is_a_shift; ++i)
            if(a[i] != b[(start+i)%n])
                is_a_shift=false;
    }

    std::cout << (is_a_shift ? "Yes" : "No");

}