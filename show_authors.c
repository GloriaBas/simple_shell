#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
const char *authors = "Obenewa and Gloria";
int fd = 1;
write(fd, authors, strlen(authors));
return 0;
}
