#include <stdio.h>
#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })

/* Parent structre , this will be embbeded in  test2*/
struct test1 {
	int a;
};

/* test2 struct has a member from test1 z */
struct test2 {
	int b;
	int c;
	struct test1 z;
};

int main(void)
{
	/* Initialize test2 objects */
	struct test2 *testobj;
	testobj = malloc(sizeof(struct test2));

	if (testobj == NULL)
		printf("Error: malloc failed\n");

	testobj->b = 10;
	testobj->c = 20;
	testobj->z.a = 0;

	/* Create test1 object and initialize */
	struct test1 *testobj1 = &testobj->z;

	/*
	 * container_of(pointer to parent struct, parent struct,
	 * embeded object of stuct.
	 * testobj2 is extracted from testobj1, embbeded  struct test
	 * and its object member z.
	 */
	/* container_of(pointer, type, member) */

	struct test2 *testobj2 = container_of(testobj1, struct test2, z);

	printf("testobj2->b = %d\n", testobj2->b);
	printf("testobj2->c = %d\n", testobj2->c);

	return 0;
}
