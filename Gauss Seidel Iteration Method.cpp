/***   Gauss Seidel Iteration Method   ***/


/***   Algorithm:

        (i)      Arrange given system of linear equations in diagonally dominant form.
        (ii)     Read tolerable error (e)
        (iii)    Convert the first equation in terms of first variable, second equation
                 in terms of second variable and so on.
        (iv)     Set initial guesses for x0,  y0, z0 and so on.
        (v)      Substitute value of y0, z0 ... from step 5 in first equation obtained
                 from step 3 to calculate new value of x1. Use x1, z0, u0 .... in second
                 equation obtained from step 3 to caluclate new value of y1. Similarly,
                 use x1, y1, u0... to find new z1 and so on.
        (vi)     If| x0 - x1| > e and | y0 - y1| > e and | z0 - z1|  > e
                 and so on then goto step 8.
        (vii)    Set x0=x1, y0=y1, z0=z1 and so on and goto step 5.
        (viii)   Print value of x1, y1, z1 and so on

***/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db double

/* Example solving:
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
/* Defining function */
#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

void solution()
{
    db x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
    int step=1;

    cout<< setprecision(6)<< fixed;

    /* Reading tolerable error */
    cout<<"Enter tolerable error: ";
    cin>>e;

    cout<< endl<<"Count\tx\t\ty\t\tz"<< endl;

    do
    {
        /* Calculation */
        x1 = f1(x0,y0,z0);
        y1 = f2(x1,y0,z0);
        z1 = f3(x1,y1,z0);

        cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;

        /* Error */
        e1 = fabs(x0-x1);
        e2 = fabs(y0-y1);
        e3 = fabs(z0-z1);

        step++;

        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;

    }
    while(e1>e && e2>e && e3>e);

    cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
}

int main()
{
    solution();
    return 0;
}
