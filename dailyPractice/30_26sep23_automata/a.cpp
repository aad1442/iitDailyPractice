#include <iostream>
#include <stdlib.h>

using namespace std;

bool isLanguage(string word, int p, int q)
{
    int n;
    int l0 = 0;
    while (1)
    {
        if (word[l0] == "0")
        {
            l0++;
        }
        else
        {
            break;
        }
    }
    int len = word.size();
    n = l0 / p;

    int l1 = 0;
    while (1)
    {
        if (word[l0] == "1")
        {
            l0++;
            l1++;
        }
    }

    if (q * n == l1)
    {
        return 1;
    }
    return 0;
}

void LanguageCheck(int p, int q)
{
    int n = 3 + rand() % 7;
    string w, wx, wy, wz, wp, x, y, z;
    int xl, yl, zl;
    w = wx = wy = wz = wp = x = y = z = "";
    for (int i = 0; i < p; i++)
    {
        w += "0";
    }
    for (int i = 0; i < q; i++)
    {
        w += "1";
    }
    // rand() % (ub - lb + 1)) + lb
    yl = (rand() % (n - 1 + 1)) + 1;
    xl = n - yl;
    zl = w.size() - xl - yl;

    int i, j, k;
    i = j = k = 0;
    for (i = 0; i < xl; i++)
    {
        wx[i] += w[i];
    }
    for (i, j; j < yl; i++, j++)
    {
        wy[j] += w[i];
    }
    for (i, k; k < zl; i++, k++)
    {
        wy[k] += w[i];
    }

    for (int i = 0; i < 100; i++)
    {
        wp = wx;
        for (int j = 0; j < i; j++)
        {
            wp += wy;
        }
        wp += wz;
    }
}

int main()
{
    string input;
    int p, q;

    cout << "Enter in this format,i. 0^n 1^n
            ii.0 ^
        n 1 ^ 2n "<< endl<< " Enter a the string : ";

    if (input == "0^n1^n")
    {
        p = q = 1;
    }
    else
    {
        p = 1;
        q = 2;
    }

    LanguageCheck(p, q);
}