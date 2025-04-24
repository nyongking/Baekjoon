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
    Numbers.push_back(N);
    
    int Now = N - 1;
    // 첫번째 카드를 뒤로 N번 넘기고, Top 카드가 N번째 카드
    // 역순 : Top 카드가 N번째, Back 카드를 N번 앞으로
    while (0 < Now)
    {
        Numbers.push_front(Now);

        int Turn = Now;

        while (0 < Turn)
        {
            int Back = Numbers.back();

            Numbers.pop_back();
            Numbers.push_front(Back);

            --Turn;
        }

        --Now;
    }

    while (false == Numbers.empty())
    {
        cout << Numbers.front() << ' ';
        Numbers.pop_front();
    }
    return 0;
}
