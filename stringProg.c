#include <stdio.h>
#include <string.h>

#define TXT  1024
#define WORD   30

// globals
char c[WORD]={0};
char c2[WORD] = {0};
char c3[WORD] = {0};
char c4[WORD] = {0};
char m[TXT] = {0};

int Anagram(char* m,char* c)
{
	int j=0;
	for(int i=0;c[i]!='\0';i++)
	{
		if(m[j]==' ')
		{
			i=-1;
			j++;
			continue;
		}
		if(c[i]==m[j])
		{
			c[i]=' ';
			for(int k=0;c[k]!='\0';k++)
			{
				if(c[k]!=' ')
					break;
				if (c[k+1]=='\0')
				{
					return j;
				}
				
			}
			j++;
			i=-1;

		}
		else if (c[i+1]=='\0'||m[j]=='~')
		{
			return -1;
		}
	}
    return -1;
}


void get_word( )
{
	for (int i = 0; i < WORD; i++)
	{
		c[i] = getchar(); //(" %c", &c[i]);
		if((c[i]=='\n') || (c[i]=='\t') || (c[i]==' '))
		{
			c[i]='\0';
			break;
		}   
	}
}

void get_txt( )
{
	for (int i = 0; i < TXT; i++)
	{
		m[i] = getchar(); //scanf(" %c", &c[i]);
		if(m[i]=='~')
			break;
	}
}

int main() 
{
	int g=0,g2=0,a=0,num=0;

    get_word(  );
    get_txt(  );

    // strcpy(c,"aba");
    // strcpy(m, "aabzyzz a#  abaab~");
	strcpy(c4,c);


    	// printf("c = %s\n", c);
	// printf("m = %s\n", m);
	
   //char m[]="I'mbebe be ,y,vvyvy bringing home my baby bumble ,bee Won't my Mommy be so proud of me I'm bringing home my baby bumble bee-OUCH!! It stung me!!~";
printf("Gematria Sequences: ");
for(int i=0;c[i]!='\0';i++)
{
    g+=c[i]-'a'+1;
}
//printf("%d", g);
for(int i=0; m[i]!='~'; i++)
{
for(int j=i; m[j]!='~'; j++)
{
	if(m[j]>='A' && m[j]<='Z')
		g2+=m[j]-('A'-1);
	if(m[j]>='a' && m[j]<='z')
		g2+=m[j]-('a'-1);
	if(g2==0)
		break;
	if(g==g2)
	{
		if(a!=0)
			printf("~");
		for(a=i;a<=j;a++)
		{
			printf("%c", m[a]);
		}
		
		g2=0;
		break;
	}
	else if(g2>g)
	{
		g2=0;
		break;
	}
}
g2=0;
}
printf("\n");
printf("Atbash Sequences: ");
for(int i=0;c[i]!='\0';i++)
{
	if(c[i]>='a' && c[i]<='z')
   		c2[i]='z'-(c[i]-'a');
	if(c[i]>='A' && c[i]<='Z')
		c2[i]='Z'-(c[i]-'A');

}
int size = strlen(c);
for(int i=size;i>=0;i--)
{
	c3[size-i]=c2[i];
}
for(int i=0;m[i]!='~';i++)
{
	int x=i;
	int a=0;
	for(int j=0;c2[j]!='\0';j++)
	{
		if(m[x]=='~')
			break;
	
		if((m[x]==c2[j]))
		{
			x++;
			a++;
		}
		else if((m[x]<'a' || c[x]>'z') && (m[x]<'A' || m[x]>'Z')&&a!=0)
			{
				x++;
				j--;
			}
		else
			break;
		if(j==size)
		{
			if(num!=0)
				printf("~");
			for(int k=i;k<x;k++)
			{
				printf("%c", m[k]);
			}
			num++;
		}
	}
	if(strcmp(c2,c3)!=0)
	{
		x=i;
		a=0;
		for(int j=0;c3[j]!='\0';j++)
		{
			if(m[x]=='~')
				break;
		
			if((m[x]==c3[j]))
			{
				x++;
				a++;
			}
			else if((m[x]<'a' || c[x]>'z') && (m[x]<'A' || m[x]>'Z')&&a!=0)
				{
					x++;
					j--;
				}
			else
				break;
			if(j==size)
			{
				if(num!=0)
					printf("~");
				for(int k=i;k<x;k++)
				{
					printf("%c", m[k]);
				}
				num++;
			}
		}
	}

}
printf("\n");
printf("Anagram Sequences: ");
int d=0;
for(int i=0;m[i]!='~';i++)
{	
	if(m[i]==' ')
		continue;
	int x=Anagram(m+i,c4);
	strcpy(c4,c);
	if(x!=-1)
	{
        if(d!=0)
          printf("~");
		for(int j=i;j<=x+i;j++)
			{
				printf("%c", m[j]);//aba
			}
		d++;
	}
}

		
}
