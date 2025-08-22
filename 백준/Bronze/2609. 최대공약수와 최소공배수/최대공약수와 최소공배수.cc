#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B;
    cin >> A >> B;
       
    int AOrig = A, BOrig = B;
    int gcd = 1;
    while (true)
    {
        if (A < B)
            swap(A, B);

        int Remain = A % B;

        if (0 == Remain)
        {
            gcd = B;
            break;
        }

        A = B;
        B = Remain;
    }

    A = AOrig;
    B = BOrig;

    int lcm = (A * B) / gcd;

    cout << gcd << '\n' << lcm;


    return 0;
}