#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <algorithm>

char screen[101][101];

double getRadio(double x, double y)
{
    double r = std::sqrt(std::pow(x - 50, 2) + std::pow(y - 50, 2));
    return r;
}

double getAngle(double x, double y)
{
    double xs = x - 50;
    double ys = y - 50;
    double m = (xs) / (ys);

    double atan = std::atan(m) * 180.0 / 3.141592653589793;
    double angle = 400.0; // error
    if (ys == 0 && xs > 0)
    {
        angle = 90;
    }
    else if (ys < 0 && xs == 0)
    {
        angle = 180;
    }
    else if ((m < 0 && xs > 0) || (atan > 0))
    {
        if ((ys > 0 && xs > 0))
        {
            angle = atan;
        }
        else
        {
            angle = 180 + atan;
        }
    }
    else
    {
        angle = 360 + atan;
    }
    return angle;
}

double getPercent(double x, double y) {
    double p = getAngle(x, y) / 360.0;
    return p;
}

bool test(int p, int x, int y)
{
    if (getRadio(x, y) > 50 || getPercent(x, y) > p / 100.0)
    {
        return true;
    }

    return false;
}

char pythagoras(int x, int y)
{
    if (test(99, y, x))
    {
        return '.';
    }
    return 'O';
}

void printScreen()
{
    // Only for debugging purposes.
    for (int i = 100; i >= 0; i--)
    {
        for (int j = 0; j <= 100; j++)
        {
            screen[i][j] = pythagoras(i, j);
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //printScreen();

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int p = 13, x = 55, y = 55;
        scanf("%d %d %d", &p, &x, &y);

        if (test(p, x, y))
        {
            printf("Case #%d: white\n", i);
        }
        else
        {
            printf("Case #%d: black\n", i);
        }
    }

    return 0;
}
