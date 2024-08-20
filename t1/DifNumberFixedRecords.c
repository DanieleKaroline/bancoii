#include <stdio.h>

void gera(FILE *f)
{
	 char qt;
	 int num[10];
	 qt=5;
	 fwrite(&qt,sizeof(char),1,f);
	 // primeiro
	 qt=3;
	 fwrite(&qt,sizeof(char),1,f);
	 num[0]=10; num[1]=12;num[2]=14;
	 fwrite(num,sizeof(int),3,f);
	 // segundo
	 qt=2;
	 fwrite(&qt,sizeof(char),1,f);
	 num[0]=21; num[1]=46;
	 fwrite(num,sizeof(int),2,f);
	 // terceiro
	 qt=4;
	 fwrite(&qt,sizeof(char),1,f);
	 num[0]=17; num[1]=19;num[2]=23; num[3]=31;
	 fwrite(num,sizeof(int),4,f);
	 // quarto
	 qt=1;
	 fwrite(&qt,sizeof(char),1,f);
	 num[0]=44;
	 fwrite(num,sizeof(int),1,f);
	 // cinco
	 qt=4;
	 fwrite(&qt,sizeof(char),1,f);
	 num[0]=27; num[1]=11;num[2]=55; num[3]=33;
	 fwrite(num,sizeof(int),4,f);
}

void imprime(FILE *f)
{
	char qts,qtn,i,j;
	int num;
	fseek(f,0,SEEK_SET);
   	fread(&qts,sizeof(char),1,f);
   	for (i=0;i<qts;i++)
   	{
		fread(&qtn,sizeof(char),1,f);
		printf("\n");
		for (j=0;j<qtn;j++)
		{
			fread(&num,sizeof(int),1,f);
			printf("%d ",num);
		}
    }
}
	 
int main()
{
	 FILE *f;
	 f=fopen("seq.dat","w+");
	 gera(f);
	 imprime(f);
	 return 1;
}
	 
