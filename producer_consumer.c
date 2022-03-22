#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/moduleparam.h> // included to use module_param macro
#include <linux/sched.h>	

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jacqueline Dworaczyk");
MODULE_DESCRIPTION("Those dogs are barkin");

int uid = 0, buffer_size = 0, num_producers = 0, num_consumers = 0;
module_param(uid, int, 0);
MODULE_PARM_DESC(uid, "User ID obtained from id -u command (positive integer).");
module_param(buffer_size, int, 0);
MODULE_PARM_DESC(buffer_size, "Size of the buffer that holds the user's process information.");
module_param(num_producers, int, 0);
MODULE_PARM_DESC(num_producers, "Number of producer threads.");
module_param(num_consumers, int, 0);
MODULE_PARM_DESC(num_consumers, "Number of consumer threads.");

static int __init producer_consumer(void) {
	printk(KERN_INFO "uid = %d\n", uid);
	
	struct task_struct* p;
	size_t process_counter = 0;
	for_each_process(p) {
		pid_t task_pid = task->pid;
		int task_uid = task->cred->uid.val;

		printk(KERN_INFO "task pid: %d\n", pid);
		printk(KERN_INFO "task uid: %d\n", uid);

		++process_counter;
	}

	return 0;
}

static void __exit producer_consumer_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
    uid = NULL;
}

module_init(producer_consumer);
module_exit(producer_consumer_cleanup);
