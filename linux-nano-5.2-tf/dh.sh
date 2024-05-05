lsblk | grep sdb
sudo mount /dev/sdb1 /mnt
#sudo rm -rf /mnt/*
sudo cp arch/arm/boot/zImage /mnt/
sudo cp ./arch/arm/boot/dts/suniv-f1c100s-licheepi-nano.dtb /mnt/
sync
sudo umount /dev/sdb1
echo ok!
