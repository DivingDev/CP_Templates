#include <bits/stdc++.h>
using namespace std;
// multi source sortest paths
// O(N^3)
void FloydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(matrix[i][k] < 1e8 && matrix[k][j] < 1e8)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}