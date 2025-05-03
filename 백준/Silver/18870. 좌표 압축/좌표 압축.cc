#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Inputs;
    vector<int> Outputs;

    int N;
    cin >> N;

    Inputs.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Inputs[i];
    }

    Outputs = Inputs;

    sort(Outputs.begin(), Outputs.end());
    Outputs.erase(unique(Outputs.begin(), Outputs.end()), Outputs.end());

    for (int Input : Inputs)
    {
        auto iter = lower_bound(Outputs.begin(), Outputs.end(), Input);
        cout << distance(Outputs.begin(), iter) << ' ';
    }



    return 0;
}
