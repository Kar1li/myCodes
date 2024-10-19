#include <stdio.h>


//#include <string.h>
//#include <stdlib.h>
//#include <math.h>





/*
#define max 10
#define MAX 100
*/

/*

char * core(char * input)
{
    int i = 0, sign = 1, frac = 0;

    double sum = 0, product = 1, num = 0;

    char ch = input[0], prev = 't';

    for (  ;  ; i++, ch = input[i])
    {
        switch (ch)
        {
            case '.':
                frac = 1;
                break;


            case 'a':

                if (frac) {
                    num += 6 / pow(10, frac++);
                }
                else
                num = num * 10 + 6;
                break;

            case 'b':

                if (frac) {
                    num += 7 / pow(10, frac++);
                }
                else
                num = num * 10 + 7;
                break;

            case 'c':

                if (frac) {
                    num += 1 / pow(10, frac++);
                }
                else
                num = num * 10 + 1;
                break;

            case 'd':

                if (frac) {
                    num += 2 / pow(10, frac++);
                }
                else
                num = num * 10 + 2;
                break;

            case 'e':

                if (frac) {
                    num += 3 / pow(10, frac++);
                }
                else
                num = num * 10 + 3;
                break;

            case 'f':

                if (frac) {
                    num += 4 / pow(10, frac++);
                }
                else
                num = num * 10 + 4;
                break;

            case 'g':

                if (frac) {
                    num += 5 / pow(10, frac++);
                }
                else
                num = num * 10 + 5;
                break;

            case 'o':

                if (frac) {
                    ++frac;
                }
                else
                num = num * 10;
                break;
            
            case 's':

                if (frac) {
                    num += 8 / pow(10, frac++);
                }
                else
                num = num * 10 + 8;
                break;

            case 'q':

                if (frac) {
                    num += 9 / pow(10, frac++);
                }
                else
                num = num * 10 + 9;
                break;
        
            default:

                frac = 0;

                switch (prev)
                {
                case 't':
                case 'x':
                    product *= num;
                    num = 0;
                    break;
                
                case '/':
                    product /= num;
                    num = 0;
                    break;

                case '-':
                    product *= -num;
                    num = 0;
                    break;


                default:
                    break;
                }

            
                prev = ch;

                switch (ch)
                {
                case '\0':
                case '-':
                case 't':
                    sum += product;
                    product = 1;
                    break;

                default:
                    break;
                }
                
                break;
        }

        if (ch == '\0') break;
    }
}


*/

/*
char * cal(char * expression)
{
    

    char Q[max][MAX];

    for ( );
    //break expression into parts
    //transform/cal some parts
    //concata back

    char newExp[MAX] = "";

    for (int i = 0; i < max; ++i)
    {
        strcat(newExp, Q[i]);
    }



    //apply core    
    return core(newExp);
}
*/


int main()
{
    char input[100];
    scanf("%s", input);

    while (input[0] != 'p')
    {
        int i = 0, sign = 1, frac = 0;

        double sum = 0, product = 1, num = 0;

        char ch = input[0], prev = 't';

        for (  ;  ; i++, ch = input[i])
        {
            switch (ch)
            {
                case '.':
                    frac = 1;
                    break;


                case 'a':
                    /* code */
                    if (frac) {
                        num += 6 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 6;
                    break;

                case 'b':
                    /* code */
                    if (frac) {
                        num += 7 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 7;
                    break;

                case 'c':
                    /* code */
                    if (frac) {
                        num += 1 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 1;
                    break;

                case 'd':
                    /* code */
                    if (frac) {
                        num += 2 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 2;
                    break;

                case 'e':
                    /* code */
                    if (frac) {
                        num += 3 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 3;
                    break;

                case 'f':
                    /* code */
                    if (frac) {
                        num += 4 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 4;
                    break;

                case 'g':
                    /* code */
                    if (frac) {
                        num += 5 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 5;
                    break;

                case 'o':
                    /* code */
                    if (frac) {
                        ++frac;
                    }
                    else
                    num = num * 10;
                    break;
                
                case 's':
                    /* code */
                    if (frac) {
                        num += 8 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 8;
                    break;

                case 'q':
                    /* code */
                    if (frac) {
                        num += 9 / pow(10, frac++);
                    }
                    else
                    num = num * 10 + 9;
                    break;
            
                default:

                    frac = 0;

                    switch (prev)
                    {
                    case 't':
                    case 'x':
                        product *= num;
                        num = 0;
                        break;
                    
                    case '/':
                        product /= num;
                        num = 0;
                        break;

                    case '-':
                        product *= -num;
                        num = 0;
                        break;


                    default:
                        break;
                    }

                
                    prev = ch;

                    switch (ch)
                    {
                    case '\0':
                    case '-':
                    case 't':
                        sum += product;
                        product = 1;
                        break;

                    default:
                        break;
                    }
                    
                    break;
            }

            if (ch == '\0') break;

        }

        printf("%.3lf\n\n", sum);




        scanf("%s", input);
    }
}