#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <cstdio>

int minimumDamage;
int adjustedDamage = 20;
double bestProbability;
int X; // roll X times
int Y; // a Y-sided dice

// f(D, K)
// D: number of dice
// K: damage
double matrix[21][20001];

double f(int D, int K)
{
    if (K <= 0)
    {
        return 1;
    }

    if (K > 0 && D == 0)
    {
        return 0;
    }

    if (adjustedDamage > X * Y)
    {
        return 0;
    }

    double sum = 0;
    for (int y = 1; y <= Y; y++)
    {
        if ((K - y) <= 0)
        {
            sum += 1;
        }
        else if ((K - y) > 0 && (D - 1) == 0)
        {
            sum += 0;
        }
        else if (adjustedDamage > X * Y)
        {
            sum += 0;
        }
        else
        {
            sum += matrix[D - 1][K - y];
        }
    }

    return (1.0 / (double)Y) * sum;
}

double getProbability(int D, int K)
{
    // We can always do at least zero damage.
    if (K <= 0)
    {
        return 1;
    }

    for (int d = 0; d <= D; d++)
    {
        for (int k = 0; k <= K; k++)
        {
            matrix[d][k] = f(d, k);
        }
    }

    return matrix[D][K];
}

void parseSpell(char* spell)
{
    char sign;
    int Z;
    int matches = sscanf(spell, "%dd%d%c%d", &X, &Y, &sign, &Z);

    if (matches == 4)
    {
        if (sign == '-')
        {
            adjustedDamage = minimumDamage + Z;
        }
        else
        {
            adjustedDamage = minimumDamage - Z;
        }
    }
    else
    {
        adjustedDamage = minimumDamage;
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        int spells;
        scanf("%d %d", &minimumDamage, &spells);

        bestProbability = 0;
        char spell[20];
        for (int j = 0; j < spells; j++)
        {
            scanf("%s", spell);
            parseSpell(spell);
            double loopProbability = getProbability(X, adjustedDamage);
            if (loopProbability > bestProbability)
            {
                bestProbability = loopProbability;
            }
        }

        printf("Case #%d: %f\n", i, bestProbability);
    }
    return 0;
}

