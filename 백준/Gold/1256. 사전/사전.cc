#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Combination

F((N, M), K) = ?

'aaz' 'aza' 'zaa' 2, 1
'azz' 'zaz' 'zza' 1, 2

'aazz' 'azaz' 'azza' 'zaaz' 'zaza' 'zzaa' 2, 2

3, 2 = a + (2, 2) + z + (3, 1) ?


'aazz' 'azaz' 'azza' 'zaaz' 'zaza' 'zzaa' 2, 2
'aaaz' 'aaza' 'azaa' 'zaaa'

aaazz aazaz aazza azaaz azaza azzaa zaaaz zaaza zazaa zzaaa 3, 2


=> K > N+M-1 Comb N-1
    F((N, M), K) = 'z' + F((N, M - 1), K - N+M-1 Comb N-1)
   else
    F((N, M), K) = 'a' + F((N - 1, M), K)

    K = 1 -> 'a' * N + 'z' * M
    N = 0 -> 'z' * M

*/

vector<vector<int64_t>> Combinations;

//  조합 찾기
int64_t GetCombinations(int N, int R)
{
    if (0 == Combinations[N][R])
    {
        if (N == R)
            Combinations[N][R] = 1;

        else if (N == 1)
            Combinations[N][R] = 1;

        else if (R == 1)
            Combinations[N][R] = N;

        else if (R == 0)
            Combinations[N][R] = 1;

        else
            Combinations[N][R] = GetCombinations(N - 1, R - 1) + GetCombinations(N - 1, R);

        if (1'000'000'000 < Combinations[N][R])
            Combinations[N][R] = 1'000'000'001;
    }

    return Combinations[N][R];
}

// 문자열 완성하기
void GetString(int N, int M, int K, string& OutString)
{
    if (K > GetCombinations(N + M, N))
    {
        OutString = "-1";
        return;
    }

    else if (1 == K)
    {
        string Addstring;

        for (int i = 0; i < N; ++i)
            Addstring += 'a';
        for (int i = 0; i < M; ++i)
            Addstring += 'z';

        OutString = OutString + Addstring;
    }

    else if (0 == N)
    {
        string Addstring;

        for (int i = 0; i < M; ++i)
            Addstring += 'z';
        
        OutString = OutString + Addstring;
    }

    else if (K > GetCombinations(N + M - 1, N - 1))
    {
        GetString(N, M - 1, K - GetCombinations(N + M - 1, N - 1), OutString);
        OutString = 'z' + OutString;
    }

    else
    {
        GetString(N - 1, M, K, OutString);
        OutString = 'a' + OutString;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string Answer;
    int N, M, K;
    cin >> N >> M >> K;

    Combinations.resize(N + M + 1, vector<int64_t>(N + M + 1, 0));

    GetString(N, M, K, Answer);

    cout << Answer;

    return 0;
}
