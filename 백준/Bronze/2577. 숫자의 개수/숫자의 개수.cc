#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    int Calc;
    int Count[10] = { 0,0,0,0,0,0,0,0,0,0 };

    cin >> A >> B >> C;
    Calc = A * B * C;

    while (0 != Calc)
    {
        ++Count[Calc % 10];

        Calc /= 10;
    }

    for (int i = 0; i < 10; ++i)
        cout << Count[i] << '\n';
   
    return 0;
}
