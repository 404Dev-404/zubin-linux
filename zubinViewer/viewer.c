#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define IMG_PATH "/usr/share/zubin.bgr"
// video format is 800x600x24

int main() {
    int fb = open("/dev/fb0", O_WRONLY);
    if (fb < 0) {
        perror("Couldn't open /dev/fb0");
        return 1;
    }

    FILE *zubin = fopen(IMG_PATH, "rb");
    if (!zubin) {
        perror("Couldn't open /usr/share/zubin.bgr");
    }

    char buf[4096];
    ssize_t nread;
    while ((nread = fread(buf, 1, sizeof(buf), zubin)) > 0) {
        ssize_t written = write(fb, buf, nread);
        if (written != nread) {
            perror("write fb0");
            break;
        }
    }

    fclose(zubin);
    close(fb);
    while (1) pause();

    return 0;
}