#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> IsPrime(2001, true);

bool IsFirstOdd = true;
int N;
vector<int> Odd;
vector<int> Even;
vector<vector<int>> PrimePairGraph;

void Prime()
{
    for (int i = 2; i * i <= 2000; ++i)
    {
        if (false == IsPrime[i])
            continue;
        for (int j = i * 2; j <= 2000; j += i)
            IsPrime[j] = false;
    }
}

bool dfs(int Now, vector<bool>& Visit, vector<int>& Match)
{
    if (Visit[Now])
        return false;
    Visit[Now] = true;

    for (int Target : PrimePairGraph[Now])
    {
        if (-1 == Match[Target] || dfs(Match[Target], Visit, Match))
        {
            Match[Target] = Now;
            return true;
        }
    }

    return false;
}

bool BiMatch(int FirstTarget)
{
    vector<int> Match(N / 2, -1);
    Match[FirstTarget] = 0;

    for (int i = 1; i < N / 2; ++i)
    {
        vector<bool> Visit(N / 2, false);
        Visit[0] = true;
        
        if (false == dfs(i, Visit, Match))
            return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Prime();

    cin >> N;

    int First = 0;
    {
        cin >> First;

        if (0 == First % 2)
        {
            Even.push_back(First);
            IsFirstOdd = false;
        }
        else
        {
            Odd.push_back(First);
            IsFirstOdd = true;
        }
    }

    for (int i = 1; i < N; ++i)
    {
        int Input;
        cin >> Input;

        if (0 == Input % 2)
            Even.push_back(Input);
        else
            Odd.push_back(Input);
    }

    if (Even.size() != Odd.size())
    {
        cout << -1;
        return 0;
    }

    PrimePairGraph.resize(N / 2);

    for (int i = 0; i < N / 2; ++i)
    {
        for (int j = 0; j < N / 2; ++j)
        {
            if (IsPrime[Even[i] + Odd[j]])
            {
                if (IsFirstOdd)
                    PrimePairGraph[j].push_back(i);
                else
                    PrimePairGraph[i].push_back(j);
            }
        }
    }

    vector<int> Answers;

    for (size_t i = 0; i < PrimePairGraph[0].size(); ++i)
    {
        if (BiMatch(PrimePairGraph[0][i]))
        {
            if (IsFirstOdd)
                Answers.push_back(Even[PrimePairGraph[0][i]]);
            else
                Answers.push_back(Odd[PrimePairGraph[0][i]]);
        }
    }


    sort(Answers.begin(), Answers.end());

    if (0 == Answers.size())
        cout << -1;

    else
    {
        for (size_t i = 0; i < Answers.size(); ++i)
        {
            if (0 < i)
                cout << ' ';
            cout << Answers[i];
        }
    }

    
    return 0;
}