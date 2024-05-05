KERNEL_DIR=/home/lmnb/f1c100s/linux-nano-5.2-tf

obj-m := ns2009.o


all:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) modules

.PHONY:clean
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) clean

