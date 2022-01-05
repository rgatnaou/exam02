#include<unistd.h>
int main(int ac ,char **cv)
{
	if (ac == 3)
	{
		int tab[256]={0};
		char *s1=cv[1];
		char *s2=cv[2];
		while(*s2)
		{
			tab[(int)*s2] = 1;
			s2++;
		}
		while(*s1)
		{
			if(tab[(int)*s1] == 1)
			{
				write(1,s1,1);
				tab[(int)*s1] = 0;
			}
			s1++;
		}
	}
	write(1,"\n",1);
}
