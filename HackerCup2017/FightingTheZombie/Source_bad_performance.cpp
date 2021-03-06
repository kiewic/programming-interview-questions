#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <cstdio>

struct DiceResult
{
    double good;
    double bad;
};

int minimumDamage;
int adjustedDamage = 20;
double bestProbability;
int X; // roll X times
int Y; // a Y-sided dice

DiceResult rollDice(int index, double sum)
{
    DiceResult result;
    result.good = 0;
    result.bad = 0;

    if (index >= X)
    {
        return result;
    }

    double min = sum + (X - index) * 1;
    double max = sum + (X - index) * Y;

    if (max < adjustedDamage)
    {
        // all are bad
        result.bad += std::pow(Y, X - index);
        return result;
    }

    if (min >= adjustedDamage)
    {
        // all are good
        result.good += std::pow(Y, X - index);
        return result;
    }

    for (int y = 1; y <= Y; y++)
    {
        if (index == X - 1)
        {
            if (sum + y < adjustedDamage)
            {
                result.bad++;
            }
            else
            {
                result.good++;
            }
        }
        else
        {
            DiceResult loopResult = rollDice(index + 1, sum + y);
            result.good += loopResult.good;
            result.bad += loopResult.bad;
        }
    }

    return result;
}

double calculateProbability()
{
    DiceResult result = rollDice(0, 0);
    double total = result.good + result.bad;
    double probability = result.good / total;
    return probability;
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
            double loopProbability = calculateProbability();
            if (loopProbability > bestProbability)
            {
                bestProbability = loopProbability;
            }
        }

        printf("Case #%d: %f\n", i, bestProbability);
    }
    return 0;
}

