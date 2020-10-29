#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct FloweringPlant
{
    string Genus, Species;
    int FlowerDiameterCm, Height;
};

int main()
{
    int n;
    cin >> n;

    vector<FloweringPlant> FloweringPlants(n), BeautifulFlowers;

    for(auto &el : FloweringPlants)
        cin >> el.Genus >> el.Species >> el.FlowerDiameterCm >> el.Height;

    copy_if(FloweringPlants.begin(), FloweringPlants.end(), back_inserter(BeautifulFlowers),
    [](const FloweringPlant& pl){return pl.FlowerDiameterCm > 10;});

    sort(BeautifulFlowers.begin(), BeautifulFlowers.end(),
    [](const FloweringPlant& a, const FloweringPlant& b){return a.Genus < b.Genus;});

    BeautifulFlowers.erase(unique(BeautifulFlowers.begin(), BeautifulFlowers.end(), 
    [](const FloweringPlant& a, const FloweringPlant& b){return a.Genus == b.Genus;}),BeautifulFlowers.end());

    for(auto &el : BeautifulFlowers)
        cout << el.Genus << " ";
    cout << endl;

    auto it = max_element(FloweringPlants.begin(), FloweringPlants.end(),
    [](const FloweringPlant& a, const FloweringPlant& b){return a.Height < b.Height;});

    //cout << it->Genus << " " << it->Species << endl;

    vector<FloweringPlant> FloweringPlantsCorrected(n);
    replace_copy_if(FloweringPlants.begin(), FloweringPlants.end(), FloweringPlantsCorrected.begin(),
    [](const FloweringPlant& pl){return pl.FlowerDiameterCm > 100;}, FloweringPlant{"Error", "Error", -1, -1});
    
    // for(auto &el : FloweringPlantsCorrected)
    //     cout << el.Genus << " " << el.Species << " " << el.FlowerDiameterCm << " " << el.Height << endl;
    // cout << endl;


}

// 6
// G1 S1 12 2134
// G1 S1 111 2134
// G2 S2 1 123
// G2 S3 123 32
// G2 S3 123 234
// G3 S4 1 213