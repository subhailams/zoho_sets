//1.Paranthesis
/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
  static class stack  
    { 
        int top=-1; 
        char items[] = new char[100]; 
  
        void push(char x)  
        { 
            if (top == 99)  
            { 
                System.out.println("Stack full"); 
            }  
            else 
            { 
                items[++top] = x; 
            } 
        } 
  
        char pop()  
        { 
            if (top == -1)  
            { 
                System.out.println("Underflow error"); 
                return '\0'; 
            }  
            else 
            { 
                char element = items[top]; 
                top--; 
                return element; 
            } 
        } 
  
        boolean isEmpty()  
        { 
            return (top == -1) ? true : false; 
        } 
    } 
      
    /* Returns true if character1 and character2 
       are matching left and right Parenthesis */
    static boolean isMatchingPair(char character1, char character2) 
    { 
       if (character1 == '(' && character2 == ')') 
         return true; 
       else if (character1 == '{' && character2 == '}') 
         return true; 
       else if (character1 == '[' && character2 == ']') 
         return true; 
       else
         return false; 
    } 
      
    /* Return true if expression has balanced  
       Parenthesis */
    static boolean areParenthesisBalanced(char exp[]) 
    { 
       /* Declare an empty character stack */
       stack st=new stack(); 
       
       /* Traverse the given expression to  
          check matching parenthesis */
       for(int i=0;i<exp.length;i++) 
       { 
            
          /*If the exp[i] is a starting  
            parenthesis then push it*/
          if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') 
            st.push(exp[i]); 
       
          /* If exp[i] is an ending parenthesis  
             then pop from stack and check if the  
             popped parenthesis is a matching pair*/
          if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') 
          { 
                   
              /* If we see an ending parenthesis without  
                 a pair then return false*/
             if (st.isEmpty()) 
               { 
                   return false; 
               }  
       
             /* Pop the top element from stack, if  
                it is not a pair parenthesis of character  
                then there is a mismatch. This happens for  
                expressions like {(}) */
             else if ( !isMatchingPair(st.pop(), exp[i]) ) 
               { 
                   return false; 
               } 
          } 
            
       } 
          
       /* If there is something left in expression  
          then there is a starting parenthesis without  
          a closing parenthesis */
        
       if (st.isEmpty()) 
         return true; /*balanced*/
       else
         {   /*not balanced*/
             return false; 
         }  
    }  
	public static void main (String[] args) {
		//code
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();s.nextLine();
		for(int i=0;i<n;i++){
        String st=s.nextLine();
        char[] exp =st.toCharArray();
          if (areParenthesisBalanced(exp)) 
            System.out.println("balanced "); 
          else
            System.out.println("not balanced ");  
	 }
	    
	}
}
//2.Number System Find n’th number in a number system with only 3 and 4

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    string arr[n+1];
    arr[0]="";
    int size=1,arrelem=1;
    
    while(size <= n){
        
        for(int i=0; i<arrelem && (size+i)<=n ; i++){
            arr[size+i]="3" + arr[size-arrelem+i];
        }
        
        for(int i=0; i<arrelem && (size+arrelem)<=n ; i++){
            arr[size+arrelem+i]="4" + arr[size-arrelem+i];
        }
        
        
        arrelem=arrelem*2;
        size=size+arrelem;
    }
    cout<<arr[n]<<" ";
    
    
    
    
  return 0;
}

// 3. expression evaluation

#include <iostream>
#include <stdlib.h>
#include<stack>
#include<string.h>
using namespace std;


int prece(char op){ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*'||op == '/') 
    return 2; 
    return 0; 
} 
  
int applyop(int a, int b, char op){ 
  switch(op){ 
    case '+': return a + b; 
    case '-': return a - b; 
    case '*': return a * b; 
    case '/': return a / b; 
  } 
}
int main()
{
    char expr[1000];
    scanf("%[^\n]s",expr);
    stack<int> values;
    stack<char> ops;
    for(int i=0;i<strlen(expr);i++){
        if(expr[i]==' ')continue;
        
        else if( expr[i]=='(' ){
            ops.push(expr[i]);
        }
        else if(isdigit(expr[i])){
            int val=0;
            while(i<strlen(expr) && isdigit(expr[i])){

                val = (val*10) + (expr[i]-'0');
                i++;
            }
            values.push(val);
            //cout<<val;
        }
        
        else if(expr[i]==')'){
            
            while(!ops.empty() && ops.top()!='('){
                
            int val2=values.top();
            values.pop();
            int val1=values.top();
            values.pop();
            
            char op = ops.top();
            ops.pop();
            
            values.push(applyop(val1, val2, op));
            
            }
            ops.top();
        }
        
        else{
            
            while(!ops.empty() && prece(ops.top())>=prece(expr[i])){
                int val2=values.top();
            values.pop();
            int val1=values.top();
            values.pop();
            
            char op = ops.top();
            ops.pop();
            
            values.push(applyop(val1, val2, op));
                
            }
            ops.push(expr[i]);
        }
    }

        while(!ops.empty()){
            int val2=values.top();
            values.pop();
            int val1=values.top();
            values.pop();
            
            char op = ops.top();
            ops.pop();
            
            values.push(applyop(val1, val2, op));
        }
            
     cout<<values.top();
    
  return 0;
}