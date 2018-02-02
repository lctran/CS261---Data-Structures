/* Name: Laura Tran
Class: CS 261 Data Structures (Winter 2018)
Date: 29 JAN 2018
Description: a2 part 3, use stack to check balanced equations */

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	printf("STRING INPUT = %s\n", s);
    if(s==NULL) return 1;

    DynArr* tempList=newDynArr(8);
    TYPE ch, topTempList;

    do{
        ch=nextChar(s);
        //if starting with a closing bracket, automatically unbalanced
        if((ch==')'||ch=='}'||ch==']') && isEmptyDynArr(tempList)){
            deleteDynArr(tempList);
            return 0; // not balanced
        }

        //left parenthesis, push onto stack
        if(ch=='('||ch=='{'||ch=='[')
            pushDynArr(tempList, ch);

        //finding right parenthesis
        printf("   Current Character = %c\n", ch);
        printf("        tempList TOP = %c\n", topTempList);

        if(!isEmptyDynArr(tempList))
            topTempList=topDynArr(tempList);

        if((ch==')' && topTempList=='(') || (ch=='}' && topTempList=='{') || (ch==']' && topTempList=='[')){
            if(isEmptyDynArr(tempList))
                return 0;

            popDynArr(tempList);
        }

        printf("Updated tempList TOP = %c\n\n", topTempList);

    } while(ch!='\0');

    //Check if cycled through input, but no closing bracket found
    if(isEmptyDynArr(tempList)){
        deleteDynArr(tempList);
        return 1;
    }
    else{
        deleteDynArr(tempList);
        return 0;
    }
}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

