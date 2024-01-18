#include <stdio.h>
#include<string.h>
#define ASIZE 100 /*ARRAYES 1&2 SIZE IN CONFUSED PASCAL*/
#define MAX_LEN 100 /*MAX CHAR LENGTH*/
#define COLLATZ 1 /*FIRST FUNCTION REQUEST*/
#define VOWELS 2 /*SECOND FUNCTION REQUEST*/
#define PASCAL 3 /*THIRD FUNCTION REQUEST*/
#define EXIT 4 /*FOURTH FUNCTION REQUEST*/

/*THIS PRGORAM TAKE A REQUEST(1-4) FROM THE USER AND RETURN SPECIAL THINGS BASED VIA FUNCTIONS*/
void reverse_vowels(char type[], int length);/* FUNCTION STATEMENT */
void reverse_vowels_recursive(char type[], int x);
int collatz_max(int n);
int confused_pascal(int n);

int max=0; /*GLOBAL VARIABLE USED IN COLLATZ_MAX FUNCTION*/

int collatz_max(int n) /*FUNCTION REALIZATION*/
{
    int next=n; /*NEXT NUMBER IN THE SEQUANCE*/
    if (n == 1)
    {
        return 1;
    }
    if(max<next)
    {
        max=next; /*GIVING A VALUE TO THE MAX*/
    }
    if(n%2 == 0) /*EVEN NUMBER*/
    {
        next=n/2;
        collatz_max(next);
    }
    if(n%2!=0) /*ODD NUMBER*/
    {
        next=(3*n)+1;
    }
    if(max<next) /*CHECKING MAXIMUM*/
    {
        max=next;
        collatz_max(next);
    }
    return max;
}
int confused_pascal(int n) /*FUNCTION REALIZATION*/
{
    int array[ASIZE], array_2[ASIZE];
    int i, j, k, c, largest = 0;
    array[0] = 1;
    array_2[0] = 1;

    for(i=1; i<n; i++) /*INNER LOOP*/
    {
        for(j=1; j<=i; j++)
        {
            if (j==1 || i==1 || i==j) /*MAKING SURE THAT FIRST AND LAST VALUE OF THE ROW IS EQUAL TO THE NUMBER OF ROW*/
            {
                c = i;
                array[j] = c;
            }
            else
            {
                c = array_2[j-1] + array_2[j];
                array[j] = c;
            }
            if(largest < c) /*FINDING LARGEST NUMBER*/
            {
                largest = c;
            }
        }
        for (k=0; k<n; k++) /*CLEARING THE ORIGINAL ARRAY AND GIVING ALL THE VALUES TO ARRAY_2*/
        {
            array_2[k] = array[k];
        }
    }
    return largest; /*RETURNING THE LARGEST VALUE IN CONFUSED PASCAL ROW*/
}
void reverse_vowels(char type[],int length) /*FUNCTION REALIZATION REGULAR FUNCTION TO REVERSE THE VOWELS IN A STRING*/
{
    int i;
    for (i =length ; i>0 ; i--) /*REVERSE THE VOWELS IN THE STRING*/
    {
        if (type[i]== 'A' || type[i]=='E' || type[i]=='I' || type[i]=='O' || type[i]=='U' || type[i]=='a' || type[i]=='e' || type[i]=='i' || type[i]=='o' || type[i]=='u') /*VOWELS CHECK*/
        {
            printf("%c",type[i]);
        }
    }
    return;
}
void reverse_vowels_recursive(char type[], int x) /*FUNCTION REALIZATION RECURSIVE FUNCTIOM TO REVESE THE VOWELS IN A STRING*/
{
    if(x==0) /*BASE RECURSION CASE*/
    {
        return;
    }
    if (type[x]=='A' || type[x]=='E' || type[x]=='I' ||type[x]=='O' || type[x]=='U' || type[x]=='a' || type[x]=='e' || type[x]=='i' || type[x]=='o' || type[x]=='u')
    {
        printf("%c",type[x]);
    }
    x--; /*MOVING TO THE NEXT CHARACTER*/
    reverse_vowels_recursive(type, x); /*RECURSIVE CALL TO THE FUNCTION */
    return;
}
int main()
{
    int request, natural, length, line, highest;
    char type[MAX_LEN];
    while(1)
    {
        printf("Please Press a function number: 1- Collatz Max 2- Reversed Vowels 3- Confused Pascal Triangle 4- EXIT\n");
        scanf("%d",&request);
        if(request==COLLATZ) /*COLLATZ_MAX REQUEST*/
        {
            while(1) /*LOOP TO ENTER A NEW REQUEST EVERYTIME*/
            {
                printf("Enter a positive integer:\n");
                scanf("%d",&natural);
                max=0;
                if(natural<0) /*NEGATIVE NUMBER*/
                {
                    continue; /*ENTER A NEW NUMBER */
                }
                if(natural>0)
                {
                    printf("The max is %d\n",collatz_max(natural));
                    break; /*END THE LOOP*/
                }
            }
            continue; /*BACK TO THE LOOP TO ENTER A NEW REQUEST*/
        }
        if(request==VOWELS)
        {
            printf("Enter a string:"); /*READ THE STRING FROM THE USER*/
            scanf("%s",type);
            length = strlen(type); /*THE LENGTH OF THE ENTERED STRING*/
            printf("\nRECURSIVE METHOD - Reversed vowels are: ");
            reverse_vowels_recursive(type, length); /*SENDING TO THE RECURSIVE FUNCTION*/
            printf("\n");
            printf("REGULAR METHOD - Reversed vowels are: ");
            reverse_vowels(type,length); /*SENDING TO THE REGULAR FUNCTION*/
            printf("\n");
            continue;
        }
        if(request==PASCAL)
        {
            printf("Enter number of rows a confused pascal triangle:\n");
            scanf("%d",&line);
            line=line+1;
            highest=confused_pascal(line); /*CONFUSED PASCAL HIGHEST NUMBER IN THE ENTERED LINE*/
            printf("The largest value in confused pascal triangle of size %d, is %d\n",line-1,highest);
            continue;
        }
        if(request==EXIT)
        {
            return 0; /*PROGRAM ENDED*/
        }
    }
}
