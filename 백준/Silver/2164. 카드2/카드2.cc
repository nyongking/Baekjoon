#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    list<int> Numbers;

    for (int i = 1; i <= N; ++i)
        Numbers.push_back(i);

    while (1 < Numbers.size())
    {
        Numbers.pop_front();

        if (1 >= Numbers.size())
            break;

        int Top = Numbers.front();

        Numbers.pop_front();

        Numbers.push_back(Top);
    }

    cout << Numbers.front();

    return 0;
}
