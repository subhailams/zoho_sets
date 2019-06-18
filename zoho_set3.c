
    
/* 2. Write a program to sort the elements in odd positions in descending order and elements in ascending order
Eg 1: Input : 13,2 4,15,12,10,5
      Output: 13,2,12,10,5,15,4
Eg 2: Input : 1,2,3,4,5,6,7,8,9
      Output: 9,2,7,4,5,6,3,8,1 
*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n,i,j;
	printf("Array size : ");
	scanf("%d",&n);

    int a[n];
	printf("Enter Elements : ");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++)
		{
			if(i%2)
			{
				if(a[i]>a[j])
					{int t=a[i];a[i]=a[j];a[j]=t;}
			}
			else
			{
				if(a[i]<a[j])
					{int t=a[i];a[i]=a[j];a[j]=t;}
			}
		}
	}
	printf("Array elements  : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
        printf("\n");
	return 0;
}    

// 3. Naive algorithm for Pattern Searching

void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "
                 << i << endl; 
    } 

    // KMP ALGORITHM
    / Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
//4.Reverse words in string using recursion

// C program to reverse a string using recursion 
#include <stdio.h> 

char rev[10000];
int k=0;
/* Function to print reverse of the passed string */
void reverse(char *str) 
{ 
if (*str) 
{ 
	reverse(str+1); 
	rev[k++]=*str;
} 
}
void reve(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin; 
        *begin++ = *end; 
        *end-- = temp; 
    } 
}
void reverseWords(char* s) 
{ 
    char* word_begin = s; 
    char* temp = s; /* temp is for word boundry */
  
    /*STEP 1 of the above algorithm */
    while (*temp) { 
        temp++; 
        if (*temp == '\0') { 
            reve(word_begin, temp - 1); 
        } 
        else if (*temp == ' ') { 
            reve(word_begin, temp - 1); 
            word_begin = temp + 1; 
        } 
    } /* End of while */
  
    /*STEP 2 of the above algorithm */
    //reve(s, temp - 1); 
} 
  

/* Driver program to test above function */
int main() 
{ 
char a[] = "Geeks for Geeks all"; 
reverse(a); 
reverseWords(rev);
printf("%s",rev);
return 0; 
} 
