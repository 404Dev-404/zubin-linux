musl-gcc -static -Os init.c -o init
strip --strip-all init
cp init ../initramfs/init
