#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <algorithm>

#define MAX_COST 300090001

int N; // number of days
int M; // number of pies on each day
int C[302][302];

int recu(int currentDay, int takenPies)
{
    if (currentDay > N)
    {
        return 0;
    }

    if (takenPies >= N)
    {
        return 0;
    }

    int min = MAX_COST;

    // We can take zero pies this day, only if wa have
    // taken more pies with anticipation.
    if (takenPies >= currentDay)
    {
        min = recu(currentDay + 1, takenPies);
    }

    int piesTotalToday = 0;
    for (int m = 1; m <= M && takenPies + m <= N; m++)
    {
        piesTotalToday += C[currentDay][m];
        int temp = recu(currentDay + 1, takenPies + m) + piesTotalToday + (int)std::pow(m, 2);
        if (temp < min)
        {
            min = temp;
        }
    }

    return min;
}

int solveSpree()
{
    scanf("%d %d", &N, &M);
    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            scanf("%d", &C[n][m]);
        }

        // Sort pie prices on each day.
        std::sort(C[n] + 1, C[n] + M + 1);
    }

    return recu(1, 0);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        printf("Case #%d: %d\n", t, solveSpree());
    }

}
