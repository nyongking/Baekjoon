#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> LessPQ;  // 내림차순 (작은 숫자들)
    priority_queue<int, vector<int>, greater<int>> GreaterPQ; // 오름차순 (큰 숫자들);
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int Input; 
        cin >> Input;

        // PQ가 비어있을 때
        if (GreaterPQ.empty())
        {
            // 첫번째
            if (LessPQ.empty())
            {
                LessPQ.push(Input);
                cout << Input << '\n';
            }
            // 두번째
            else
            {
                int LessTop = LessPQ.top();
                
                // 
                if (LessTop > Input)
                {
                    LessPQ.pop();
                    LessPQ.push(Input);
                    GreaterPQ.push(LessTop);

                    cout << Input << '\n';
                }
                else
                {
                    GreaterPQ.push(Input);

                    cout << LessTop << '\n';
                }
            }
        }

        //
        else
        {
            int LessTop = LessPQ.top();
            int GreaterTop = GreaterPQ.top();                      

            // 홀수번 -> 가운데 숫자 부르기
            if (0 != i % 2)
            {      
                // 비교
                // Input이 작은 숫자에 해당
                if (Input <= LessTop)
                {
                    LessPQ.pop();
                    LessPQ.push(Input);
                    GreaterPQ.push(LessTop);
                }
                // Input이 큰 숫자에 해당
                else if (Input >= GreaterTop)
                {
                    GreaterPQ.pop();
                    GreaterPQ.push(Input);
                    LessPQ.push(GreaterTop);
                }
                // Input이 중간 숫자에 해당 -> LessPQ에 넣기
                else if (LessTop < Input && Input < GreaterTop)
                {
                    LessPQ.push(Input);
                }

                // 숫자 부르기
                if (GreaterPQ.size() > LessPQ.size())
                    cout << GreaterPQ.top() << '\n';
                else
                    cout << LessPQ.top() << '\n';
            }
            // 짝수번 -> 가운데 숫자 중 작은 숫자 부르기
            else
            {
                // 비교
                // Input이 작은 숫자에 해당
                if (Input <= LessTop)
                {
                    if (LessPQ.size() > GreaterPQ.size())
                    {
                        LessPQ.pop();
                        GreaterPQ.push(LessTop);
                    }
                    LessPQ.push(Input);
                }
                // Input이 큰 숫자에 해당
                else if (Input >= GreaterTop)
                {
                    if (GreaterPQ.size() > LessPQ.size())
                    {
                        GreaterPQ.pop();
                        LessPQ.push(GreaterTop);
                    }
                    GreaterPQ.push(Input);
                }
                // Input이 중간 숫자에 해당 -> LessPQ에 넣기
                else if (LessTop < Input && Input < GreaterTop)
                {
                    if (GreaterPQ.size() > LessPQ.size())
                        LessPQ.push(Input);                    
                    else
                        GreaterPQ.push(Input);
                }

                cout << LessPQ.top() << '\n';
            }
        }

    }


    return 0;
}
