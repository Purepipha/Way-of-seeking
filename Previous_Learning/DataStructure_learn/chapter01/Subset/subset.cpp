#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    vector<int> State{55, 34, 31, 27, 21, 21, 20, 17, 15, 15, 15, 13, 12,
                      11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 8, 8,
                      7, 7, 7, 7, 6, 6, 6, 5, 5, 5, 5, 5, 4,
                      4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3};
    int sum = 0;
    for (auto X : State)
    {
        sum += X;
    }
    cout << sum << endl; //FIXME complete the function of subset
    return 0;

}