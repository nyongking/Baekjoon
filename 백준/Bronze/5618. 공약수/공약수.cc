#include <iostream>
using namespace std;

#include <set>
#include <algorithm>
// 소인수 분해 -> 약수 -> 공약수 -> 최대 공약수

// 둘 사이의 최대공약수 구하기
int GreatestCommonDivisor(int A, int B)
{
    int MinNum = min(A, B);
    
    if (0 == A % MinNum && 0 == B % MinNum)
        return MinNum;

    for (int i = MinNum / 2 + 1; i > 0; --i)
    {
        if (0 == A % i && 0 == B % i)
            return i;
    }

    return 1;
}

// 최대 공약수 -> 약수 구하기
void PrintCommons(int Input)
{
    set<int> Divs;

    int Start = 1;
    do
    {
        if (0 == Input % Start)
        {
            Divs.insert(Start);
            Divs.insert(Input / Start);
        }

        ++Start;
    } while (Start <= Input / 2);

    for (auto& div : Divs)
    {
        cout << div << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int Input[3] = {};
    int Answer = 1;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Input[i];
    }

    Answer = Input[0];

    for (int i = 0; i < N - 1; ++i)
    {
        Answer = GreatestCommonDivisor(Answer, Input[i + 1]);
    }

    if (1 == Answer)
        cout << 1;
    else
        PrintCommons(Answer);

    return 0;
}
