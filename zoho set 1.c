1.
/*Print the word with odd letters as

P         M
 R      A
   O  R
     G
  O    R
 R       A
P          M 
*/
#include<stdio.h>
#include <stdlib.h>

int main()
{
char a[1000];
scanf("%s",a);
int n;
for(n=0;a[n];n++);
int s=0,t=n-1,r=(n/2);
for(int i=0;i<n;i++){
    if(i==r){
        s=r;
        t=r;
    }
    for(int j=0;j<n;j++){
        if(j==s)printf("%c",a[i]);
        if(j==t && s!=t)printf("%c",a[n-i-1]);
        else printf(" ");
    }
    printf("\n");
    s++;t--;
    
}

}
/*2.	Given a set of numbers like <10, 36, 54,89,12> we want to find sum of weights based on the following conditions
    1. 5 if a perfect square
    2. 4 if multiple of 4 and divisible by 6
    3. 3 if even number

And sort the numbers based on the weight and print it as follows

<10,its_weight>,<36,its weight><89,its weight>
*/
import java.util.*;

public class SortWeights {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner s=new Scanner(System.in);
		System.out.print("Enter n");
		n=s.nextInt();
		int[] a=new int[n+1],ws=new int[n+1];
		for(int i=0;i<n;i++){
			a[i]=s.nextInt();
			ws[i]=getweight(a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(ws[i]<ws[j]){
					int t=ws[i];
					ws[i]=ws[j];
					ws[j]=t;
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		for(int i=0;i<n;i++){
			System.out.print(a[i]+":"+ws[i]+" ");
		}
	}
	private static int getweight(int i) {
		// TODO Auto-generated method stub
		int root=(int)Math.sqrt(i),weight=0;
		if(root*root == i){
			weight+=5;
		}
		if(i%4==0 && i%6==0){
			weight+=4;
		}
		if(i%2==0){
			weight+=3;
		}
			
		return weight;
	}

}



/*3.	Save the string “WELCOMETOZOHOCORPORATION” in a two dimensional array and search for substring like “too” in the two dimensional string both from left to right and from top to bottom.

w	e	L	C	O
M	E	T	O	Z
O	H	O	C	O
R	P	O	R	A
T	I	O	n	  
And print the start and ending index as

Start index : <1,2>

End index: <3, 2>
*/

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int sqt(float);
int main()
{
char a[100][100],s[100],s1[100];
scanf("%s",s);
int k=0,rc=0,len=0,i=0,j=0,c=0;
for(len=0;s[len];len++);
if(len=sqt(len)*sqt(len)){
	rc=sqt(len)+1;
}
else{
	rc=sqt(len);
}
for(int i=0,ins=0;i<rc;i++){
	for(int j=0;j<rc && s[ins];j++){
		a[i][j]=s[ins++];
		printf("%c",a[i][j]);
	}
	printf("\n");
}
scanf("%s",s1);
for(i=0;i<rc;i++)
  for(j=0;j<rc;j++)
    if(a[i][j]==s1[0])
    {  for(k=j,c=0;a[i][k]==s1[c] && s1[c]!='\0';k++,c++);
       if(s1[c]=='\0'){
          printf("\nStart index : <%d ,%d>   End index: <%d, %d>\n",i,j,i,k-1);}
    }
//find substring in coloumns
for(i=0;i<rc;i++)
  for(j=0;j<rc;j++)
    if(a[j][i]==s1[0])
    { 
      for(k=j,c=0;a[k][i]==s1[c] && s1[c]!='\0';k++,c++);
       if(s1[c]=='\0'){
         printf("\nStart index : <%d ,%d>   End index: <%d, %d>\n",j,i,k-1,i);}
    }          

}
int sqt(float n){
	    float x = n; 
        float y = 1; 
        float e = 0.00001; /* e decides the accuracy level*/
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
        } 
        return x; 
}
5. /*  Given a two dimensional array of string like
  <”luke”, “shaw”>
  <”wayne”, “rooney”>
  <”rooney”, “ronaldo”>
  <”shaw”, “rooney”> 
Where the first string is “child”, second string is “Father”. 
And given “ronaldo” we have to find his no of grandchildren Here “ronaldo” has 2 grandchildren.
 So our output should be 2. */
#include<stdlib.h>
#include<stdio.h>
int main(void)
{
char *str,***a;
str=malloc(50);
int n,i,j,c=0;
//enter th number of pair of strings
printf("Enter the number of pair : ");
scanf("%d",&n);
//create 3d array dynamically using malloc
a=malloc(sizeof(char*)*n);     //allocate n character pointer spaces and store addres in a
for(i=0;i<n;i++)                 
{ a[i]=malloc(sizeof(char*)*2); // store 2 chara pointer spaces to every previously allocated n spaces 
  for(j=0;j<2;j++)
     a[i][j]=malloc(sizeof(char)*50); // allocate 50 bytes to previously allocated 2 char pointer spaces
}
//enter the list of strings
printf("Enter the strings : ");
for(i=0;i<n;i++)
{
  for(j=0;j<2;j++)
   scanf(" %s",a[i][j]);
}
//print length of strings
printf("The Array is : \n");
for(i=0;i<n;i++)
{
  printf("<");
  for(j=0;j<2;j++)
   printf("%-10s ",a[i][j]);
  printf(">\n");
}
//enter the grangfather name 
printf("Enter the string : ");
scanf("%s",str);

printf("Grandchildren of %s :  ",str);
for(i=0;i<n;i++)
  if(strcmp(a[i][1],str)==0)             //Locate grandfather in the list
      for(j=0;j<n;j++)                   // Find son of the grandfather
         if(strcmp(a[j][1],a[i][0])==0)  //find grandchildren
          {  printf("%s ",a[j][0]); 
             c++;                        //increment count for every grandchildren   
          }
printf("\nNumber of grandchildren  :  %d\n",c);
free(a);
free(str);
return 0;
}         
