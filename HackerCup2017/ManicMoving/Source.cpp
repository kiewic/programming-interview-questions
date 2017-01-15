#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <algorithm>

#define INFINITE_GAS 100001

int N; // towns
int M; // roads
int K; // families
int dist[102][102];
int families[5002][2];

int convertDist(int a)
{
    if (a >= INFINITE_GAS)
    {
        return -1;
    }
    return a;
}

int sumInfs(int a, int b)
{
    if (a == -1 || b == -1)
    {
        return -1;
    }
    return a + b;
}

int memo[5002][4][102];

//             1-5000            0-2           1-100
int recu(int nextFamily, int truckLoad, int prevTown)
{
    int x, y;
    if (nextFamily > K && truckLoad == 0)
    {
        // We are done.
        return 0;
    }

    if (nextFamily <= K && truckLoad == 0)
    {
        // We must pick next family.
        x = sumInfs(convertDist(dist[prevTown][families[nextFamily][0]]), memo[nextFamily + 1][truckLoad + 1][families[nextFamily][0]]);
        return x;
    }

    if ((nextFamily > K && truckLoad > 0) || truckLoad == 2)
    {
        // We must deliver a load.
        x = sumInfs(convertDist(dist[prevTown][families[nextFamily - truckLoad][1]]), memo[nextFamily][truckLoad - 1][families[nextFamily - truckLoad][1]]);
        return x;
    }

    // We can load or deliver, whatever is the best.
    x = sumInfs(convertDist(dist[prevTown][families[nextFamily][0]]), memo[nextFamily + 1][truckLoad + 1][families[nextFamily][0]]);
    y = sumInfs(convertDist(dist[prevTown][families[nextFamily - truckLoad][1]]), memo[nextFamily][truckLoad - 1][families[nextFamily - truckLoad][1]]);
    return std::min(x, y);
}

void doFloydWarshall()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int solveDeliverySchedule()
{
    scanf("%d %d %d", &N, &M, &K);

    // Set-up Floyd-Warshall matrix
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dist[i][j] = (i == j ? 0 : INFINITE_GAS);
        }
    }

    for (int m = 1; m <= M; m++)
    {
        int A, B, G;
        scanf("%d %d %d", &A, &B, &G);
        dist[A][B] = (G < dist[A][B] ? G : dist[A][B]);
        dist[B][A] = (G < dist[B][A] ? G : dist[B][A]);
    }

    for (int k = 1; k <= K; k++)
    {
        scanf("%d %d", &families[k][0], &families[k][1]);
    }

    doFloydWarshall();

    // Dynamic programming
    for (int nextFamily = K + 1; nextFamily >= 1; nextFamily--)
    {
        for (int truckLoad = 0; truckLoad <= 2; truckLoad++)
        {
            for (int prevTown = 1; prevTown <= N; prevTown++)
            {
                memo[nextFamily][truckLoad][prevTown] = recu(nextFamily, truckLoad, prevTown);
            }
        }
    }

    return memo[1][0][1];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        printf("Case #%d: %d\n", t, solveDeliverySchedule());
    }
}
