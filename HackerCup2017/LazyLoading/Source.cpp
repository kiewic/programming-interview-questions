#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <algorithm>

int length;
int items[101];
int table[101][101];

int recu(int index, int left)
{
    if (left == 0)
    {
        return 0;
    }

    if (index >= length) {
        return 0; // It does not matter if there are left items, they can be added to any existing bag.
    }

    // Calculate needed items if item[index] is at the top of the bag.
    int needed = (50 + items[index] - 1) / items[index];

    if (left >= needed)
    {
        return std::max(
            table[index + 1][left - needed] + 1,
            table[index + 1][left]);
    }

    return table[index + 1][left];
}

int solveDay()
{
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &items[i]);
    }

    for (int index = length; index >= 0; index--)
    {
        for (int left = 0; left <= length; left++)
        {
            table[index][left] = recu(index, left);
        }
    }

    //// Only for debugging purposes.
    //for (int index = 0; index < length; index++)
    //{
    //    for (int left = 0; left <= length; left++)
    //    {
    //        printf("%2d ", table[index][left]);
    //    }
    //    printf("\n");
    //}

    return table[0][length];
}

int main()
{
    int days;
    scanf("%d", &days);

    for (int i = 1; i <= days; i++)
    {
        auto result = 1;
        printf("Case #%d: %d\n", i, solveDay());
    }

    return 0;
}
