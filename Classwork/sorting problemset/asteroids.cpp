#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>

void sort(std::vector<double> &v, std::vector<std::tuple<int, int, int>> &coord)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i] > v[j])
            {
                std::swap(v[i], v[j]);
                std::swap(coord[i], coord[j]);
            }
}
double dist(int x, int y, int z)
{
    return sqrt(x*x + y*y + z*z);
}
int main()
{
    int x, y, z;
    std::ifstream fin("AsteroidsDatabase.txt");
    std::vector<double> ast;
    std::vector<std::tuple<int, int, int>> coord;

    while(fin >> x >> y >> z)
    {
        ast.push_back(dist(x, y, z));
        coord.emplace_back(x, y, z);
    }

    fin.close();

    sort(ast, coord);

    std::ofstream fout("AsteroidsSortedByDanger.txt");

    for(auto el : coord)
    {
        int x, y, z;
        std::tie(x, y, z) = el;
        fout << x << " " << y << " " << z << '\n';
    }

    fout.close();
}