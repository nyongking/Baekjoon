#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string S;

    cin >> N >> M;
    cin >> S;

    string Find = "I";

    for (int i = 0; i < N; ++i)
        Find += "OI";

    size_t Offset = 0;
    int Answer = 0;
    while (Offset != string::npos)
    {
        Offset = S.find(Find, Offset);

        if (Offset != string::npos)
        {
            ++Offset;
            ++Answer;
        }
        else
            break;
    }

    cout << Answer;


    
    return 0;
}
