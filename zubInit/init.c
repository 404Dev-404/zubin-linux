#include <sys/mount.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	puts("ZubInit: natural ketchup idk man");
	
	puts("ZubInit: mounting /dev");
	if (mount("devtmpfs", "/dev", "devtmpfs", 0, NULL) != 0) {
		perror("ZubInit: failed to mount /dev");
		return 1;
	}
	puts("ZubInit: mounted /dev!");

	// I'm not really sure if /proc is necessary, but I'm leaving the code here anyways.
	/*
	puts("ZubInit: mounting /proc");
	if (mount("proc", "/proc", "proc", 0, NULL) != 0) {
		perror("ZubInit: failed to mount /proc");
		return 1;
	}
	puts("ZubInit: mounted /proc!");
	*/

	puts("ZubInit: mounting /sys");
	if (mount("sysfs", "/sys", "sysfs", 0, NULL) != 0) {
		perror("ZubInit: failed to mount /sys");
		return 1;
	}
	puts("ZubInit: mounted /sys!");
	
	puts("ZubInit: Jumping to /bin/viewer!");

	char *argv[] = { "/bin/viewer", NULL };
	execv("/bin/viewer", argv);
	perror("ZubInit: failed to exec viewer");
	_exit(1);

	return 0;
}
