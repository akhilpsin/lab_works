#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	int i,flag,l;	
	char str[50],str1[50],ch;
	FILE *f1,*f2;
	f1=fopen("input.txt","r");
	
	while(fscanf(f1,"%s",&str)!=EOF)
	{

		flag=0;
		f2=fopen("keyword.txt","r");
		while(fscanf(f2,"%s",&str1)!=EOF)
		{		
			if(strcmp(str,str1)==0)
			{
				printf("%s Keyword\n",&str);		
				flag=1;
				break;
			}	
		}
		if(flag==1)
				continue;
		l=strlen(str);
		for(i=1;i<=l;++i)
		{
			ch=str[i];			
			switch(ch)
			{
				case 'a'...'z':
				case 'A'...'Z': 
					if(isalpha(ch)||isdigit(ch)){
						
						printf("%s identifier\n",&ch);
					}
				break;
				/*case '1'...'9': if(isdigit(ch)){	
						printf("%s Digit\n",&ch);
					}
				break;
				case '<':
				case '>':
				case '=': 	printf("%s Relational Operator",&ch);
				break;
				*/
				case '{':
				case '}':
				case '(':
				case ')':
				case ';':	printf("%s Symbols \n",&ch);
				break;
				default: printf("Error");

			}
		}
	fclose(f2);
	}
	fclose(f1);
	
}
