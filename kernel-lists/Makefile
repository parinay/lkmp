obj-m += mykList.o

all:
	make -C /lib/modules/4.17.14-202.fc28.x86_64/build M=$(PWD) modules

clean:
	make -C /lib/modules/4.17.14-202.fc28.x86_64/build M=$(PWD) clean
