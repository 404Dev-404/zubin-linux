find . ! -name 'build.sh' -print0 | cpio --null --create --verbose --format=newc | gzip --best > ../initrd
