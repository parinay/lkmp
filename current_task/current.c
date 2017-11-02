#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/errno.h>   /* error codes */
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

void device_exit(void);
int device_init(void);

module_init(device_init);
module_exit(device_exit);

int device_init(void)
{
	struct task_struct *task = current;
	printk(KERN_NOTICE "current process: %s, PID: %d, TGID:%d", \
	       task->comm, task->pid, task->tgid);
	do {
		task = task->parent;
		printk(KERN_NOTICE "parent process: %s, PID:%d, TGID:%d", \
		       task->comm, task->pid, task->tgid);
	} while(task->pid != 0);

	printk(KERN_NOTICE "Current processor: %d", task->on_cpu);

	return 0;
}

void device_exit(void)
{
	printk(KERN_NOTICE "assignment: existing module");
}
