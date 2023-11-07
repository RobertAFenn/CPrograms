#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
  int fd;
  fd = open("file", O_WRONLY | O_CREAT | O_TRUNC,
            S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);

  if (fd == -1) {
    printf("Error");
  }

  return 0;
}