struct labeltab
{
	int adrs;
}entry[100];

int linecnt;


int findline(char *s)
{
	int num=0,i=0;
	while(s[i]!='\0'&&isdigit(s[i]))
	{
		num=num*10+(s[i]-'0');
		i++;
	}
	return num;
}