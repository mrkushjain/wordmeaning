#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define FNAME "defs.txt"
#define LINELEN 1000
#define DEFPARTS 2
void output(char defs[][LINELEN])
{
	printf("\n\r<tr><td class='heading'>%s</td><td class='defination'>%s</td></tr>",defs[0],defs[1]);
}
void test(char *fname)
{
	FILE* infile = fopen(fname,"r");
	char line[LINELEN];
	char defs[DEFPARTS][LINELEN];
	while(fgets(line,LINELEN,infile ))
	{
	     int j,endj,len=strlen(line);
	     for(j=len-1;!(j<0||isalpha(line[j]));j--);
	     endj=j+1;
	     line[endj]=NULL;
	     for(j;j>=0 && (line[j]!=' ' && line[j]!='\t');j--);
	     strcpy(defs[0],line+j+1);
	     for(j=j-1;!(j<0||isalnum(line[j]));j--);
	     endj=j+1;
	     line[endj]=NULL;

	     strcpy(defs[1],line);
	     output(defs);


	}
}
void driver()
{
	test(FNAME);
}
int main()
{
	driver();
	return 0;
}