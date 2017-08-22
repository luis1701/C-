#include <stdio.h>
#include <string.h>

void populate(char** m)
{
	m[0] = "enero";
	m[1] = "febrero";
	m[2] = "marzo";
	m[3] = "abril";
}

void show(char** m, int n)
{
	for (int i = 0; i < n; ++i)
	{
		puts(m[i]);
	}
}

int ff(int n , const char** s)
{
	if(n<0) return 0;
	if(n%2)
		*s = "impar";
	else
		*s = "par";
	return 1;
}

void print(const void* n, int type)
{
	switch(type)
	{
		case 0:
			printf("%d\n", *(int*)n);
			break;
		case 1:
			printf("%f\n", *(double*)n);
			break;
	}
}

void print_a(int* p, int f, int c)
{
	for (int i = 0; i < f; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			printf("%d ", *(p+(i*c)+j));
		}
		puts("");
	}

}
int main()
{
	/*char aux[20];
	char* meses[4];
	populate(meses);
	show(meses, 4);*/
	
	/*const char *q = "hola";
	int r = ff(3 , &q);
	if(r)
		puts(q);*/

	int f = 25;
	int* pf = &f;
	void* qf = &f;
	printf("%d\n", *pf);
	printf("%d\n", *(int*)qf);

	/*int p = 1234;
	double q = 3.1415926;
	print(&p, 0);
	print(&q, 1);*/

	/*int s [2][2];
	s[0][0] = 2;
	s[0][1] = 8; 
	s[1][0] = 2; 
	int* m = (int*) s;
	*(m+(1*2)+1) = 123; 
	print_a(m,2,2);*/ 


	return 0;
}