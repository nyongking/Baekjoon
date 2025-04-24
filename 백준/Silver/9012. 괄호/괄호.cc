#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string Input;
        cin >> Input;

        stack<char> Parenthesis;
        for (int j = 0; j < Input.size(); ++j)
        {
            char Now = Input[j];
            // Stack이 비었을 경우 -> Push
            if (Parenthesis.empty())
            {
                Parenthesis.push(Now);
            }
            // 비어있지 않을 경우 -> 쌍 비교
            else
            {
                char Prev = Parenthesis.top();

                if (Prev == '(' && Now == ')')
                {
                    Parenthesis.pop();
                }

                else
                    Parenthesis.push(Now);
            }
        }

        if (Parenthesis.empty())
            cout << "YES\n";
        else
            cout << "NO\n";

    }


    return 0;
}
