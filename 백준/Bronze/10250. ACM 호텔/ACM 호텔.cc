#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int H, W, N;
    int Floor, Number;

    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> H >> W >> N;

        Floor = N % H;
        Number = N / H + 1;

        if (0 == Floor)
        {
            Floor = H;
            Number -= 1;
        }
        cout << Floor * 100 + Number << '\n';
    }

    return 0;
}
