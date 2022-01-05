#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>
#define TAB "0123456789abcdef"
int ft_putchar(char c)
{
	return(write(1,&c,1));
}

int putnb(long long nb,int base)
{
	int ret = 0;
	if(nb < 0)
	{
		ret += ft_putchar('-');
		nb *= -1;
	}
	if(nb >= base)
		ret +=putnb(nb/base,base);
	ret +=ft_putchar(TAB[nb%base]);
	return (ret);
}

int putstr(char *s)
{
	int ret =0;
	if(!*s)
		return(write(1,"(null)",6));
	while(*s)
	{
		ret += ft_putchar(*s++);
	}
	return(ret);
}

int print(char *s,va_list arg)
{
	int ret;
	while(*s)
	{
		if(*s == '%')
		{
			s++;
			if(*s == 'd' )
				ret += putnb((long long)va_arg(arg,int),10);
			else if(*s == 'x' )
				ret += putnb((long long)va_arg(arg,unsigned int),16);
			else if(*s == 's' )
				ret += putstr(va_arg(arg,char *));
		}
		else
			ret += write(1,s,1);
		s++;
	}
	return(ret);
}
int ft_printf(char *s,...)
{
	int ret;
	va_list arg;
	va_start(arg, s);
	ret = 0;
	ret +=print(s,arg);
	va_end(arg);
	return(ret);

}

#include<limits.h>
#include<stdio.h>
int main()
{
    int f, s;
    f = ft_printf("%s %d %d %x\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX);
    s =    printf("%s %d %d %x\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX);
    printf("%d | %d\n", f, s);
}
