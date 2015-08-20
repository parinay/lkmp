#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define MAX 10

struct my_list {
	struct list_head list;
	int data;
};

int main(int argc, char *argv[])
{
	struct my_list mlist;
	struct my_list *temp;
	int count;


	INIT_LIST_HEAD(&mlist.list);

	for(count=0; count<MAX;count++) {
		temp = (struct my_list *)malloc(sizeof(struct my_list));
		printf("Enter the data:");
		scanf("%d",&temp->data);
		list_add(&(temp->list), &(mlist.list));
	}
	printf("\n");
	list_for_each_entry(temp, &mlist.list, list)
		printf("data: %d\n", temp->data);
	printf("\n");
	return 0;
}
