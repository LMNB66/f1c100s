KERNEL_DIR=/home/lmnb/f1c100s/linux-nano-5.2-tf

obj-m := lora.o


all:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) modules

.PHONY:clean
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) clean

