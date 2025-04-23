#include <iostream>
using namespace std;

#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int Score = 0;
        int Prev = 1;
        string Input;

        cin >> Input;
        
        for (int i = 0; i < Input.size(); ++i)
        {
            if ('O' == Input[i])
            {
                Score += Prev++;
            }
            else
            {
                Prev = 1;
            }
        }

        cout << Score << '\n';
    }

    return 0;
}
