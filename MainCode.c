#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
//decleraton of variables
char *len() {
    int cnt = 0;
    char *line = (char*) malloc(sizeof(char) * 1);
    line[0] = '\0';
    char newchar;
    while (scanf("%c", &newchar) == 1 && newchar != '\n') {
        char *newarr = (char*) malloc(sizeof(char) * (cnt+1+1));
        int i;
        for ( i = 0; i < cnt; ++i)
            newarr[i] = line[i];
        newarr[cnt] = newchar;
        newarr[cnt+1] = '\0';
        free(line);
        line = newarr;
        ++cnt;
    }
 return line;
}


// function for sum
void sum(char *a,char *b){

	int l1=strlen(a);
	int l2=strlen(b);
	int max;
	int i;
	if(l2>l1)
	{

		max=strlen(b);

	}
	else{
		max=strlen(a);

	}
	int *n1=(int* )malloc(sizeof(int )*max);
	int *n2=(int* )malloc(sizeof(int )*max);
	for(i=0;i<=max;i++)
	{
		n1[i]=0;
		n2[i]=0;
	}
	int *sum=(int* )malloc(sizeof(int )*max);

	for(i=0;i<l1;i++)
	{
		n1[i]=a[l1-i-1]-'0';

	}

	for(i=0;i<l2;i++)
	{
		n2[i]=b[l2-i-1]-'0';

	}

     int k;
     int c=0;
     for(k=0;k<max;k++)
{
      sum[k]=(n1[k]+n2[k]+c)%10;
	if((n1[k]+n2[k]+c)>=10)
	{
		c=1;
	}
	else{
		c=0;
	}

         }
        sum[max]=c;


     int j=0;
     printf("\n");
     printf("The answer of addittion is:\n");

for(j=max;j>=0;j--)
{

	printf("%d",sum[j]);
}
free(n1);
free(n2);
free(sum);
}

//upto this addition processs.


//ssubstraction function
char *substraction(char *a,char *b){

	int l1=strlen(a);
	int l2=strlen(b);

	int max;
	int tt;

	int i;
	if(l2>l1)
	{

		max=strlen(b);

	}
	else{
		max=strlen(a);

	}
	int check=0;
		for(tt=0;tt<max;tt++)
		{
			if(l1>l2)
			{
				check=1;
				break;
			}
		else if (l1==l2 && a[tt]>b[tt])
		{
			check=1;
			break;
		}
		else
		{
			check=0;
		}
		}


	int *n1=(int* )malloc(sizeof(int )*max);
	int *n2=(int* )malloc(sizeof(int )*max);
	for(i=0;i<=max;i++)
	{
		n1[i]=0;
		n2[i]=0;
	}
char *substraction=(char* )malloc(sizeof(char )*max);

	for(i=0;i<l1;i++)
	{
		n1[i]=a[l1-i-1]-'0';

	}

	for(i=0;i<l2;i++)
	{
		n2[i]=b[l2-i-1]-'0';

	}

int k;
int l=0;
int ll;
for(k=0;k<max;k++)
{
	if(check==1)
{
 ll=	l+n1[k]-n2[k];}
else
{
	 ll=	l-n1[k]+n2[k];
}
if(ll<0)
{
	ll=ll+10;
	l=-1;
	substraction[k]=ll;
}
else
{
	substraction[k]=ll;
	l=0;
}



}
substraction[max]=0;


int j=0;
printf("\n");

if(check==0)
{
printf("-");
}
char *sep=(char*)malloc(sizeof(char)*(max+1));
for(j=max-1;j>=0;j--)
{

	printf("%d",substraction[j]);
	sep[j]=substraction[j]+'0';
}
sep[j]='\0';
return   sep;
free(n1);
free(n2);
}
//substraction upto this


//mutilplication

char  * multiply(char* a,char* b) {
	int max =strlen(a)*strlen(b);
     char *mul=(char*) malloc(sizeof(char)*(max));
    char *c=(char*) malloc(sizeof(char)*(max));
    char *temp=(char*) malloc(sizeof(char)*(max));


    int  la,lb;
    int i,j,k=0,x=0,y;
     int r=0;
     int sum = 0;
    la=strlen(a)-1;
        lb=strlen(b)-1;

        for(i=0;i<=la;i++){
                a[i] = a[i] - 48;
        }

        for(i=0;i<=lb;i++){
                b[i] = b[i] - 48;
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }

    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    printf("%s",mul);
    return mul;
free(c);
free(temp);
}

//mutilpication finished





bool compar(char *a,char * b)
{
if(strlen(a)<strlen(b))
{
	return 0;

	}
	else if(strlen(a)==strlen(b))
	{
		int i;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>b[i])
			{
				return 1;
				break;
			}
			else if(a[i]<b[i])
			{
				return 0;
				break;
			}
			else{

			}
		}
	}
	else
	{
		return 1;

	}



}






char *divi(char * n,char *d)

{



	char *result=(char* )malloc(sizeof(char )*strlen(n));
	char *res=(char* )malloc(sizeof(char )*strlen(n));
	char *rem=(char* )malloc(sizeof(char )*strlen(n));

	if( !compar(n,d) ) //gives zero when a<b;
	{
		char res[]="0";
		char *rem=(char* )malloc(sizeof(char )*strlen(n));
		strcpy(rem,n);
		printf("%s",res);

	}

	else if (d[0]=='0')
	{

		printf("\nERROR :Zero in denomirator gives ans that is no exist any definate values\n");
	}

	else
	{


		char *sep=(char* )malloc(sizeof(char )*(strlen(n)+1));
		int i;


		int ss=strlen(n)-strlen(d);

		for(i=0;i<strlen(d);i++)
		{
			sep[i]=n[i];
		}
		sep[i]='\0';
	if(!compar(sep,d))
	{
		sep[i]=n[i];
		ss=ss-1;
	}
	sep[i+1]='\0';


	char digg[]="987654321";
	char dig[1]="9";
	int j=0;
	int h=0;



	while(ss>0){
	j=0;
	while(compar(sep,multiply(dig,d)))
	{


		j=j+1;
		char digg[]="987654321";
    dig[0]=digg[j];
    dig[1]='\0';

	}

	char *tt=substraction(sep,multiply(d,dig));
	tt[ss+1]=n[ss+1];
	*sep=*tt;

	result[h]=digg[j];
	h++;

	ss=ss-1;
}
    result[h]='\0';

	printf("%s",result);

return result;
free(res);
free(rem);
free(sep);
}


//remainder function

}
void rem(char *n, char* d)
{


	char *rem=(char* )malloc(sizeof(char )*strlen(n));

	if( !compar(n,d) ) //gives  when a<b;
	{

		char rem[strlen(n)];
		strcpy(rem,n);
		printf("%s",rem);

	}

	else if (d[0]=='0')
	{

		printf("\nERROR :Zero in denomirator gives ans that is no exist any definate values\n");
	}
	else
	{

		rem=substraction(n,divi(n,d));
		printf("%s",rem);
	}
	free(rem);

}


// main programme
int main()
{
	int manuslec;
	do
	{

	printf("Enter the first no:\n");
	char *a = len();
	printf("Enter the second no:\n");
    char *b=len();

		printf(
		"which work you what to perform slect manu\n"
            "0. Addingtion of a and b\n"
            "1. substraction of a from b\n"
            "2. Mutilication of a and b\n"
            "3. Division  of a and b\n"
            "4. remainder  when a is bivided by b\n"
			);
        scanf("%d", &manuslec);
        switch(manuslec)
        {
        	case 0:
        	sum(a,b);
			free(a);
	        free(b);
        	break;
        	case 1:printf("the ans of substraction is :\n");
			char *sub=substraction(a,b);
        	free(a);
        	free(b);
        	free(sub);
        	break;
        	case 2:
			printf("The result of mutilplication is:");
			char *mul=multiply(a,b);

        	free(a);
        	free(b);
        	free(mul);
        	break;
        	case 3:
        	printf("The result of division is:");
        	char* result=divi(a,b);
        	free(a);
        	free(b);
        	free(result);
        	break;
        	case 4:
        	printf("The result of remainder is :");
        	rem(a,b);
        	free(a);
        	free(b);
        	break;
        	default:printf("Your choice is not fine:\n");
			break;

		}

		break;

	}
	while(manuslec);

	return 0;

	}
