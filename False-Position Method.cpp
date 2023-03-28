/***   False-Position Method   ***/


/***   Algorithm:

       (i)      Choose two real numbers a and b such that f(a) * f(b) < 0
       (ii)     Define root, c = ((a * f(b)) - (b * f(a))) / (f(b) - f(a))
       (iii)    Find f(c) , if f(c) == zero then c is the root
       (iv)     If f(a) * f(c) < 0 then set
                                        b = c
                                    else
                                        a = c

        Repeat this process until there is any same value of c in the iteration.
        That will be the root.

        Setting values for a and b:

                Also we need to set the values of a and b in such way that,
                if f(a) is negative then f(b) must be positive and vice versa.

***/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db double

#define f(x) x*x*x - 2*x - 5


void solution()
{
    cout << "Choose the value of a : ";
    double a;
    cin >> a;
    cout << "Choose the value of b : ";
    double b;
    cin >> b;

    double f_a = f(a);
    double f_b = f(b);

    if(f_a * f_b > 0)
    {
        cout << "\nThe value of a or b is not valid" << endl;
    }
    else
    {

        double c = ((a * f_b) - (b * f_a)) / (f_b - f_a);
        double f_c = f(c);
        printf("\n\ta\tb\tf(a)\tf(b)\tc\tf(c)\n");

        while(fabs(f(c)) > 0.001)
        {
            printf("\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",a,b,f_a,f_b,c,f_c);
            if(f_a * f_c < 0)
            {
                b = c;
                f_b = f(b);
            }
            else
            {
                a = c;
                f_a = f(a);
            }
            c = (a + b) / 2;
            f_c = f(c);

        }
        printf("\n\tThe root is = %.2lf\n",c);
    }
}

int main()
{
    solution();
    return 0;
}
