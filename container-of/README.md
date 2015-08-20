Linux kernel circular linked lists and container_of macro


Linux kernel circular linked lists and use of container_of macro
to understand, how to extract the data payload while moving through
the list.

list_entry(struct list_head *ptr, type_of_struct, field_name);

Where 
	ptr is a pointer to the struct list_head being used,
	type_of_struct is the type of the structure containing the ptr, &
	field_name is the name of the list field within the structure

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
*/
#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

More:
	http://isis.poly.edu/kulesh/stuff/src/klist/
	http://www.makelinux.net/ldd3/chp-11-sect-5

	http://www.kroah.com/log/linux/container_of.html
	"http://crashcourse.ca/introduction-linux-kernel-programming/\
	intermission-lets-talk-about-linked-lists-and-containerof-free"
