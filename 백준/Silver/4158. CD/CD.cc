#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        int N, M, Input;
        int Answer = 0;
        vector<int> CDs;

        cin >> N >> M;

        if (0 == N && 0 == M)
            break;

        for (int i = 0; i < N; ++i)
        {
            cin >> Input;
            CDs.push_back(Input);
        }

        for (int j = 0; j < M; ++j)
        {
            cin >> Input;

            // 이분 탐색
            // 0 ~ N-1
            int Start = 0;
            int End = N - 1;

            while (Start <= End) 
            {
                int Index = (Start + End) / 2;

                // 찾음
                if (CDs[Index] == Input)
                {
                    ++Answer;
                    break;
                }

                // 큰 숫자 ->
                else if (CDs[Index] < Input)
                {
                    Start = Index + 1;
                    if (N <= Start)
                        break;
                }

                // 작은 숫자 ->
                else
                {
                    End = Index - 1;
                    if (0 > End)
                        break;
                }
            }
        }

        cout << Answer << '\n';
    }


    return 0;
}
