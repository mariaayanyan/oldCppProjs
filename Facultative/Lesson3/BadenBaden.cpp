 #include <iostream>
 #include <string>
 #include <algorithm>
 using namespace std;
 int main()
 {
    string s;
    cin >> s;

    cout << (equal(s.begin(), s.begin()+s.size()/2, s.begin() + s.size()/2) ? "Yes" : "No") << endl;

 }