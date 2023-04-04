/***   Gauss Elimination Method   ***/


/***   Algorithm:

       (i)      Create Augmented Matrix from the equations.
       (ii)     Make all the elements zero below the main diagonal.
       (iii)    Apply Back Substitution Method
       (iv)     Find the values of the coefficients

***/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db double

void solution()
{
    cout<< setprecision(3)<< fixed;

    /* 1. Reading number of unknowns */
    cout<<"Enter number of unknowns: ";

    int n;
    cin >> n;

    db a[n][n + 1], x[n], ratio;

    /* 2. Reading Augmented Matrix */
    cout<<"Enter Coefficients of Augmented Matrix: "<< endl;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n + 1; j++)
        {
            cout<<"a["<< i<<"]"<< j<<"]= ";
            cin >> a[i][j];
        }
    }

    /* Applying Gauss Elimination */
    for(int i = 1; i <= n - 1; i++)
    {
        if(a[i][i] == 0.0)
        {
            cout << "Mathematical Error!";
            exit(0);
        }
        for(int j = i + 1; j <= n; j++)
        {
            ratio = a[j][i] / a[i][i];

            for(int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    /* Obtaining Solution by Back Substitution Method */
    x[n] = a[n][n + 1] / a[n][n];

    for(int i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];

        for(int j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    /* Displaying Solution */
    cout << endl << "Solution: " << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << "x["<< i<<"] = " << x[i] << endl;
    }
}

int main()
{
    solution();
    return 0;
}
