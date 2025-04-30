#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        bool Result = false;
        int N;
        int HouseX, HouseY;
        int ConcertX, ConcertY;
        
        vector<pair<int, int>> Convenients;
        list<pair<int, int>>   Dests;

        cin >> N;
        vector<bool>           Visited(N, false);
        
        cin >> HouseX >> HouseY;


        for (int i = 0; i < N; ++i)
        {
            int ConvenientX, ConvenientY;
            cin >> ConvenientX >> ConvenientY;

            Convenients.push_back(make_pair(ConvenientX, ConvenientY));
        }

        cin >> ConcertX >> ConcertY;

        // 집 -> (편의점 거치기 ->) 페스티벌
        Dests.push_back(make_pair(HouseX, HouseY));

        while (false == Dests.empty())
        {
            pair<int, int> Now = Dests.front();
            
            int Distance = abs(Now.first - ConcertX) + abs(Now.second - ConcertY);

            if (1000 >= Distance)
            {
                Result = true;
                break;
            }

            for (int i = 0; i < N; ++i)
            {
                if (Visited[i])
                    continue;

                Distance = abs(Now.first - Convenients[i].first) + abs(Now.second - Convenients[i].second);

                if (1000 < Distance)
                    continue;

                Dests.push_back(Convenients[i]);
                Visited[i] = true;
            }

            Dests.pop_front();
        }

        if (Result)
            cout << "happy\n";
        else
            cout << "sad\n";

       
    }


    return 0;
}
