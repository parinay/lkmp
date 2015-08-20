#include <stdio.h>
#include <stddef.h>

// Alignment requirements
// (typical 32 bit machine)
//
// char     1 byte
// short int  2 bytes
// int     4 bytes
// double    8 bytes
//
// structure A
typedef struct structa_tag
{
	char    c;
	short int  s;
} structa_t;

// structure B
typedef struct structb_tag
{
	short int  s;
	char    c;
	int     i;
} structb_t;

// structure C
typedef struct structc_tag
{
	char    c;
	double   d;
	int	 s;
} structc_t;
typedef struct structcp_tag
{
		char c;
		double d;
		int s;
}__attribute__((packed)) structcp_t;

// structure D
typedef struct structd_tag
{
	double   d;
	int	 s;
	char    c;
} structd_t;

int main()
{
	structa_t a_t;
	structb_t b_t;
	structc_t c_t;
	structcp_t cp_t;
	structd_t d_t;

	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(short int) = %lu\n", sizeof(short int));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(double) = %lu\n", sizeof(double));

	printf("\n\n");
	printf("sizeof(structa_t(char, short int)- 3) = %lu\n", sizeof(structa_t));
	printf("Addrss of - char %p short int %p\n", &a_t.c, &a_t.s);
	printf("offset of structa_t.c: %lu\n", (offsetof(structa_t,c)));
	printf("offset of structa_t.s: %lu\n", (offsetof(structa_t,s)));

	printf("\n\n");
	printf("sizeof(structb_t(short int, char, int)- 7) = %lu\n", sizeof(structb_t));
	printf("Addrss of - short int %p char %p int %p\n", &b_t.s, &b_t.c,
	       &b_t.i);
	printf("offset of structb_t.s: %lu\n", offsetof(structb_t,s));
	printf("offset of structb_t.c: %lu\n", offsetof(structb_t,c));
	printf("offset of structb_t.i: %lu\n", offsetof(structb_t,i));

	printf("\n\n");
	printf("sizeof(structc_t(char, double, int)- 13) = %lu\n", sizeof(structc_t));
	printf("Addrss of - char %p, double %p short int %p\n", &c_t.c, &c_t.d,
	       &c_t.s);
	printf("offset of structc_t.c: %lu\n", offsetof(structc_t,
								 c));
	printf("offset of structc_t.d: %lu\n", offsetof(structc_t,
								 d));
	printf("offset of structc_t.s: %lu\n", offsetof(structc_t,
								 s));

	printf("\n\n");
	printf("sizeof(structd_t(double, int , char)- 13) = %lu\n", sizeof(structd_t));
	printf("Addrss of - double %p short int %p char %p\n", &d_t.d, &d_t.s,
	       &d_t.c);
	printf("offset of structd_t.d: %lu\n", offsetof(structd_t,d));
	printf("offset of structd_t.s: %lu\n", offsetof(structd_t,s));
	printf("offset of structd_t.c: %lu\n", offsetof(structd_t,c));

	printf("\n\n");
	printf("packed with __attribute__((packed)) struct_name\n");
	printf("sizeof(structcp_t(char, double, int)- 13) = %lu\n",
	       sizeof(structcp_t));
	printf("Addrss of - char %p, double %p short int %p\n", &cp_t.c,
	       &cp_t.d,&cp_t.s);
	printf("offset of structcp_t.c: %lu\n", offsetof(structcp_t, c));
	printf("offset of structcp_t.d: %lu\n", offsetof(structcp_t, d));
	printf("offset of structcp_t.s: %lu\n", offsetof(structcp_t, s));
return 0;
}
