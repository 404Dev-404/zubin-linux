# build linux
cd linux || exit
make -j10
cd ..

# build init
cd zubInit || exit
./build.sh
cd ..

# build viewer
cd zubinViewer || exit
./build.sh
cd ..

# build initrd
cd initramfs || exit
./build.sh
cd ..
