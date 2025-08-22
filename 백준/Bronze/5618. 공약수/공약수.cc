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

    int n;
    cin >> n;

    int Number1;
    cin >> Number1;

    int gcd = 1;
    for (int i = 1; i < n; ++i)
    {
        int Number2;
        cin >> Number2;

        while (true)
        {
            if (Number1 < Number2)
                swap(Number1, Number2);

            int Remain = Number1 % Number2;

            if (0 == Remain)
            {
                gcd = Number2;
                break;
            }

            Number1 = Number2;
            Number2 = Remain;
        }

        Number1 = gcd;
    }

    vector<int> cds;

    for (int i = 1; i * i <= gcd; ++i)
    {
        if (0 == gcd % i)
        {
            int div = gcd / i;
            if (div != i)
                cds.push_back(i);
            cds.push_back(div);
        }
    }

    sort(cds.begin(), cds.end());

    for (int cd : cds)
        cout << cd << '\n';

    return 0;
}