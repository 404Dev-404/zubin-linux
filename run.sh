qemu-system-x86_64 -kernel ./linux/arch/x86/boot/bzImage \
                   -initrd ./initrd                      \
                   -append "vga=0x315 console=ttyS0,115200" \
		   -serial stdio
