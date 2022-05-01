#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int n;	// n is the power of expression
// char expression[20][20];
// coffStore[20][2];
// varStore[20][5];


int fact(int num);
int nCr(int r);
void expand(char a[], char b[]);
void distribute_power(char term[], int term_power);
// void printMiddleTerms(int mt1, int mt2);
// void printNthTerm(int nthTerm);
// void finalstep();


int main(void)
{
    char x[5], y[5];
	
	// input
    printf("First term: ");
	scanf("%s", &x);
    printf("Second term: ");
	scanf("%s", &y);
    printf("Power: ");
	scanf("%d", &n);

	// printf("(%s + %s)^%d\n\n= ", x,y,n);
	// printf("How to expand?\n");
	// char choice;
	// // if choice is invalid, re-prompt the user
	// here:
	// printf(" a. All\n m. Middle term(s)\n n. nth term\n");
	// scanf("%c",&choice);

	// conditions
	// if(choice == 'a')
	// 	expand();
	// else if(choice == 'n'){
	// 	printNthTerm();
	// }
	// else if(choice == 'n'){
	// 	printMiddleTerms( n/2, (n/2)+1 );;
	// }
	// else{
	// 	printf("INVALID CHOICE")
	// 	goto here;
	// }
	
	printf("-----------------------------------------------------------------------\n");
	printf("(%s + %s)^%d\n\n= ", x,y,n);
    
    expand(x,y);
	// finalstep();
}

void expand(char a[], char b[])
{
	// step 1
	for (int i=0; i<=n; i++)
	{
		printf("%dC%d (%s)^%d (%s)^%d", n,i,a,n-i,b,i);
		if(i != n)
			printf("  +  ");
	}
	printf("\n\n= ");

	// step2
	for (int i=0; i<=n; i++)
	{
		printf("%d ", nCr(i));
		distribute_power(a,n-i);
		distribute_power(b,i);
		if(i != n)
			printf(" +  ");
	}
	printf("\n\n= ");

}

int nCr(int r)
{
	return fact(n) / ( fact(n-r)*fact(r) );
}

int fact(int num)
 {
 	if(num<=0)
 	    return 1;
 	else
 	    return num*fact(num-1);
 }
 

void distribute_power(char term[], int term_power)
{
	if (term_power == 0)
			return;
	if (term_power == 1){
			printf("%s ",term);
			return;
		}

	for (int i=0; i<strlen(term); i++)
    {
		if(isalnum(term[i]))
			continue;
		else if(isalpha(term[i])){
			printf("%c^%d", term[i],term_power);
			// varStore
			// for (int j=0; j<2; j++)
			// 	varStore[i][j] = 
		}
        else{
            char temp[2];           // 1 byte for the char of term[i] and 1 for \0
            temp[0] = term[i];
			
			int coff = (int)pow( atoi(temp),term_power );
            printf("%d", coff);
			// coffStore
			// for (int j=0; j<2; j++)
			// 	coffStore[i][j] = coff;
            // // printf("%d",pow(atoi(temp),n) );
        }
    }printf(" ");
}

// void printMiddleTerms(int mt1, int mt2)
// {

// }
// void printNthTerm(int nthTerm)
// {
	
// }

// void finalStep()
// {
// 	// step3
// 	for (int i=0; i<=n; i++)
// 	{
// 		printf("%d", nCr(i)*)
// 		if(i != n)
// 			printf(" +  ");
// 	}
// }