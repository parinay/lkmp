#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel List Implementation");
MODULE_AUTHOR("Zorba");

/*
 * User defined structure to be implemented using kernel
 * list.
 */
struct mNode {
	int data;
	/* kernel's List structre.
	 * Embed this inside the list node.
	 */
	struct list_head list;
};

struct mNode mList;

int init_module()
{
	struct mNode *mNodeNew; /* node for creating the new list elements */
	struct mNode *mNodeP; /* node for traversling the list elements */

	unsigned int i;

	printk(KERN_INFO "Initialize kernel module");

	/* Initialize the structre.*/
	INIT_LIST_HEAD(&mList.list);

	for(i=0; i<5; i++) {
		mNodeNew = kmalloc(sizeof(*mNodeNew), GFP_KERNEL);
		mNodeNew->data = i;
		/* list head mNodeNew */
		INIT_LIST_HEAD(&mNodeNew->list);

		/* add node to the tail of list */
		list_add_tail(&(mNodeNew->list), &(mList.list));
	}

	printk(KERN_INFO "traversing the list using list_for_each()n");

	list_for_each_entry(mNodeP, &mList.list, list) {

		printk(KERN_INFO "Data: %d", mNodeP->data);
	}
	printk(KERN_INFO "n");

	return 0;
}


void cleanup_module()
{
	struct mNode *mnode;
	struct mNode *tmp;

	printk(KERN_INFO "kernel module unloaded.n");
	printk(KERN_INFO "deleting the list using list_for_each_entry_safe()n");

	list_for_each_entry_safe(mnode, tmp, &mList.list, list) {
		list_del(&mnode->list);
		kfree(mnode);
	}
}
