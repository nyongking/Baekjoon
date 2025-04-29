#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string Input;
    stack<char> PS;
    stack<pair<int, int>> AccScores; // 축적된 점수를 두는 스택

    cin >> Input;

    // ([](([][])()))([])
    // 순서
    // 3(2단) 3(4단) 3(4단) 2(3단) 2(3단) 2(2단) 2(1단)

    for (int i = 0; i < Input.size(); ++i)
    {
        char Now = Input[i];

        if ('(' == Now || '[' == Now)
            PS.push(Now);

        // 짝 판정
        else if (')' == Now || ']' == Now)
        {
            // 실패
            if (PS.empty())
            {
                cout << 0;
                return 0;
            }

            char Prev = PS.top();
            if (('(' == Prev && ']' == Now) || ('[' == Prev && ')' == Now))
            {
                cout << 0;
                return 0;
            }

            int Score = 0;
            if (']' == Now)
                Score = 3;
            else
                Score = 2;

            // 점수 계산
            if (AccScores.empty())
            {
                AccScores.push(make_pair((int)PS.size(), Score));
            }
            else
            {
                pair<int, int> Pair = AccScores.top();

                // 단계가 같을 경우 -> 점수 더하기
                if (Pair.first == PS.size())
                {
                    Score = Pair.second + Score;

                    AccScores.pop();
                    AccScores.push(make_pair((int)(PS.size()), Score));
                }

                // 더 높은 단계 -> push
                else if (Pair.first < PS.size())
                {
                    AccScores.push(make_pair((int)PS.size(), Score));
                }

                // 더 낮은 단계 -> pop 점수 곱해서 push
                else if (Pair.first > PS.size())
                {
                    Score = Score * Pair.second;
                    AccScores.pop();

                    if (false == AccScores.empty())
                    {
                        pair<int, int> NextPair = AccScores.top();

                        // 그 다음 stack의 단계와 같다 -> 점수 더하기
                        if (NextPair.first == PS.size())
                        {
                            Score = NextPair.second + Score;

                            AccScores.pop();
                        }
                    }                 

                    AccScores.push(make_pair((int)PS.size(), Score));
                }
            }

            PS.pop();
        }     
    }

    if (false == PS.empty())
    {
        cout << 0;
        return 0;
    }


    cout << AccScores.top().second;

    return 0;
}
