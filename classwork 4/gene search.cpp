#include <iostream>
#include <string>

int main() {
    std::string genome, gene;
    std::cin >> genome >> gene;


    int pos = 0;
    while (true) {
        size_t found = genome.find(gene, pos);
        if (found == std::string::npos)
            break;

        std::cout << found << " ";
        pos = found + 1;

    }
}