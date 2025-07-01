musl-gcc -static -Os viewer.c -o viewer
strip --strip-all viewer
cp viewer ../initramfs/bin/viewer

# making da image!!
magick zubin.png -resize 800x600 \
                 -background black \
                 -gravity center \
                 -extent 800x600 \
                 -depth 8 \
                 -channel RGB -separate \
                 -swap 0,2 \
                 -combine \
                 rgb:zubin.bgr
cp zubin.bgr ../initramfs/usr/share/zubin.bgr