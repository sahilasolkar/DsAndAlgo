/*
AUTHOR : SAHIL.A
PROGRAM: POSTFIX EVALUATION
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 7th NOV 2021
*/
// DS DEVELOPERv

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2107_stack.h"
int main(){
char str[50];
eleType x,y,z;
eleType choice,i=0;
float val;
stackType s = createStack();
printf("Enter the Expression\n");
scanf("%s",str);
        
while(str[i]!='\0'){
	if((str[i]>='0')&&(str[i]<='9')){
		z=str[i]-'0';
		push(z,&s);
	}
	else{
		x=pop(&s);
		y=pop(&s);				
		switch(str[i]){
		case '+' : val=x+y; break;
		case '-' : val=y-x; break;
		case '*' : val=x*y; break;
		case '/' : val=y/x; break;
	}
	push(val,&s);
	}
	i++;
	}
	val=pop(&s);
	printf("\nANSWER = %.2f \n",val);
destroyStack(&s);
return 0;
}