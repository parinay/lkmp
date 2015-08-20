#include <stdio.h>
#include <stddef.h>
// from lwn.net
typedef unsigned int uint32_t;

typedef struct obj_1
{
	uint32_t   a, b;
	char       c;
	char       filler[3];
	uint32_t*  p1;
	char**     p2;
	char**     p3;
} obj_1;

typedef struct obj_2
{
	uint32_t   a, b;
	char       c;
	uint32_t*  p1;
	char**     p2;
	char**     p3;
} obj_2;

int main()
{
	printf("struct obj_1 {\n");
	printf("\t uint32_t   a, b;\n\tchar       c;\n\tchar\t"
	       "filler[3];\n\tuint32_t*  p1;\n\tchar**     p2;\n\tchar**"
	       "p3;\n\t} obj_1;\n");
	printf("offset of obj_1.a:       %lu bytes\n", offsetof(obj_1, a));
	printf("offset of obj_1.b:       %lu bytes\n", offsetof(obj_1, b));
	printf("offset of obj_1.c:       %lu bytes\n", offsetof(obj_1, c));
	printf("offset of obj_1.filler:  %lu bytes\n", offsetof(obj_1, filler));
	printf("offset of obj_1.p1:      %lu bytes\n", offsetof(obj_1, p1));
	printf("offset of obj_1.p2:      %lu bytes\n", offsetof(obj_1, p2));
	printf("offset of obj_1.p3:      %lu bytes\n", offsetof(obj_1, p3));
        putchar('\n');

	printf("\t struct obj_2 {\n\tuint32_t   a, b;\n\tchar       c;\n\t"
	       "uint32_t*  p1;\n\tchar** p2;\n\tchar**"
	       "p3;\n\t} obj_1;\n");
	printf("offset of obj_2.a:       %lu bytes\n", offsetof(obj_2, a));
        printf("offset of obj_2.b:	 %lu bytes\n", offsetof(obj_2, b));
	printf("offset of obj_2.c:	 %lu bytes\n", offsetof(obj_2, c));
	printf("offset of obj_2.p1:	 %lu bytes\n", offsetof(obj_2, p1));
	printf("offset of obj_2.p2:	 %lu bytes\n", offsetof(obj_2, p2));
        printf("offset of obj_2.p3:	 %lu bytes\n", offsetof(obj_2, p3));
	putchar('\n');
	
	printf("sizeof(int)=%lu bytes\n", sizeof(int));
	printf("sizeof(long)=%lu bytes\n", sizeof(long));
        printf("sizeof(void*)=%lu bytes\n", sizeof(void*));

	return 0;
}
