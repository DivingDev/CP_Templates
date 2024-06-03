#include <bits/stdc++.h>
using namespace std;

// T.C. = O(nlogn)

vector<int> divisors[1000010];
void listOfDivisors()
{
    for (int i = 1; i <= 1e6; i++)          // let say i = 8
    {
        for (int j = i; j <= 1e6; j += i)
        {
            divisors[j].push_back(i);       // divisors[8] - {8}, divisors[16] - {8} ....
        }
    }
}