#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int Answer = 1;

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        Answer *= i;
    }

    cout << Answer;

    return 0;
}
