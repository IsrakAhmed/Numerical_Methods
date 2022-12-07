

/***   Bisection Method   ***/


/***   Algorithm:

       (i)      Choose two real numbers a and b such that f(a) * f(b) < 0
       (ii)     Define root, c = (a + b) / 2
       (iii)    Find f(c)
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



#include<stdio.h>
#include<math.h>

float f(float x){

    /** the equation is x^3 - 2x - 5 **/

    float result = pow(x,3) - (2.0 * x) - 5.0;
    result = floor(10000*result)/10000.0;
    return result;
}

int isSame(float *valuesOfc,float c,int size){

    int i;

    float key = c;

    int count = 0;

    for(i = 0; i < size; i++){
        if(valuesOfc[i] == key){
            count = 1;
            break;
        }
    }

    if(count)           return 1;
    else                return 0;
}

int main(){

    float a,b,c;
    float fOfa,fOfb,fOfc;
    float valuesOfc[30];

    printf("Enter the value of a:   ");
    scanf("%f",&a);

    a = floor(10000*a)/10000.0;

    printf("Enter the value of b:   ");
    scanf("%f",&b);

    b = floor(10000*b)/10000.0;

    printf("\n\n\ta\tb\tf(a)\tf(b)\tc\tf(c)\n\n");

    int i = 0;

    while(1){

        printf("\t%.4f",a);
        printf("\t%.4f",b);

        fOfa = f(a);
        printf("\t%.4f",fOfa);

        fOfb = f(b);
        printf("\t%.4f",fOfb);

        c = (a + b) / 2.0;
        c = floor(10000*c)/10000.0;
        printf("\t%.4f",c);

        fOfc = f(c);
        printf("\t%.4f\n",fOfc);

        if(isSame(valuesOfc,c,i)){

            printf("\n\tRoot is %.4f\n",c);
            break;
        }

        else{
            valuesOfc[i] = c;
            i++;
        }

        if((fOfa * fOfc) < 0){
            b = c;
        }
        else{
            a = c;
        }
    }

    return 0;
}
