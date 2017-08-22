#include <stdio.h>
#include <string.h>

struct person
{
	const char* fn;
	const char* ln;
	size_t id;
};

typedef struct
{	
	char dd;
	char mm;
	char yy;
}date;

typedef struct//es mejor este metodo si no son constantes
{	
	char fn[32];
	char ln[32];
	size_t id;
}person2;

void init_person(person2 * x, const char* fn, const char* ln, size_t id)
{
	strcpy((*x).fn, fn);
	strcpy(x->ln, ln);
	(*x).id = id;

}

void print_person(const person2* p)
{
	puts(p->fn);
	size_t tamfn = strlen((*p).fn);
	//puts(strlen(*p).fn);
	puts(p->ln);
	printf("%u\n", (*p).id);
	printf("%u\n", tamfn);
}
int main()
{
	struct person p;
	date d;
	person2 a;
	init_person(&a,"juan","perez",658);//
	print_person(&a);
	char* palabra = "pedro";
	//size_t tamfn = strlen(palabra);
	//printf("%u\n", tamfn);
	puts(palabra);
	char ** pa = &palabra;
	*pa = "josee";
	puts(palabra);
	/*char q[] = "juan";
	p.fn = q;
	p.ln = "valdez";
	p.id = 3678901;
	q[0] = 'I';
	q[1] = 'v';
	puts(p.fn);*/

	/*struct person p2;
	{
		char s[] = "hola";
		p2.fn = s;			
	}
	{
		char z[] = "jonas";
	}
	puts(p2.fn);*/

	return 0;
}