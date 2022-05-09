#include <iostream>
#include <vector>
int main()
{
    using namespace std;
    cout << "Enter a integer: ";
    int n;
    cin >> n;
    vector<int> hailstone;
    hailstone.push_back(n);
    int length = 1;
    while (n > 1)
    {
        length++;
        n = n % 2 == 0 ? n / 2 : 3*n + 1;
        hailstone.push_back(n);
    }
    cout << "The Hailstone(" << hailstone[0] << ") length is  " << length << std::endl;
    cout << "Hailsstone(" << hailstone[0] << ") = "
         << "{";
    for (auto X : hailstone)
    {
        if (X == hailstone[length - 1])
            cout << X;
        else
            cout << X << ", ";
    }
    cout << "}" << endl;
    return 0;
}