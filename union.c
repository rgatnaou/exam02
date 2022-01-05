#include<unistd.h>

int main(int ac ,char **av)
{
	if(ac ==3)
	{
		int tab[256]= {0};
		char *s1=av[1];
		char *s2=av[2];
		while(*s1)
		{
			if(!tab[(int)*s1])
			{
				write(1,s1,1);
				tab[(int)*s1] = 1;
			}
			s1++;
		}
		while(*s2)
		{
			if(!tab[(int)*s2])
			{
				write(1,s2,1);
				tab[(int)*s2] = 1;
			}
			s2++;
		}
	}
	write(1,"\n",1);
}
