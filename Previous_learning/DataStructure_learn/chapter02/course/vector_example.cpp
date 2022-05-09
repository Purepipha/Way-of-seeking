// vector_example -- using STL vector
#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    vector<int> v;
    vector<int> s(32,63);   // {63,63,...63},sum = 2016
    s.insert(s.begin() + 2, 2017);  // {63,63,2017,63,...,63}
    s.erase(s.end() - 30, s.end()); // {63,63,2017}
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << endl;
    return 0;
}