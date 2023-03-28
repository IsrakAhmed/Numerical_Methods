/***   Newton-Raphson Method   ***/


/***   Algorithm:

       (i)      Choose two real numbers a and b such that f(a) * f(b) < 0
       (ii)     Assume xn = a or xn = b
       (iii)    Define root, xn1 = xn - (f(xn) / f'(xn))
       (iv)     Find f(xn) , if f(xn) == zero then xn1 is the root
       (v)      Set xn = xn1


        Repeat this process until f(xn) becomes zero.
        Then xn1 will be the root.

        Setting values for a and b:

                Also we need to set the values of a and b in such way that,
                if f(a) is negative then f(b) must be positive and vice versa.

***/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db double

#define f(x) x*x*x - 2*x - 5
#define df(x) 3*x*x - 2     // let df(x) as f'(xn)


void solution()
{
    cout << "The value of a is 2 and b is 3\n";
    double a = 2;
    double b = 3;

    double f_a = f(a);
    double f_b = f(b);

    if(f_a * f_b > 0)
    {
        cout << "\nThe value of a or b is not valid" << endl;
    }
    else
    {
        double xn = a;
        double f_xn = f(xn);
        double df_xn = df(xn);
        double xn1 = xn - (f_xn / df_xn);

        printf("\n\txn\tf(xn)\tf'(xn)\txn+1\n");

        while(fabs(f(xn)) > 0.001)
        {
            printf("\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",xn,f_xn,df_xn,xn1);
            xn = xn1;
            f_xn = f(xn);
            df_xn = df(xn);
            xn1 = xn - (f_xn / df_xn);
        }
        printf("\n\tThe root is = %.2lf\n",xn1);
    }
}

int main()
{
    solution();
    return 0;
}
