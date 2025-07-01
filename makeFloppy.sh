dd if=/dev/zero of=zubinlinux.img bs=512 count=2880
mkfs.vfat zubinlinux.img

LOOP=$(sudo losetup -f --show zubinlinux.img)

sudo syslinux --install $LOOP

sudo mkdir -p /mnt/floppy
sudo mount $LOOP /mnt/floppy

sudo cp linux/arch/x86/boot/bzImage /mnt/floppy/bzImage
sudo cp initrd /mnt/floppy/initrd
sudo cp syslinux.cfg /mnt/floppy/syslinux.cfg

sudo umount /mnt/floppy
sudo rmdir /mnt/floppy
sudo losetup -d $LOOP