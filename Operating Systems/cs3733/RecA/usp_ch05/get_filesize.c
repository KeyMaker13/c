#include <sys/stat.h>

int get_filesize(char *path) {
   struct stat statbuf;

   if (stat(path, &statbuf) == -1){
      perror("Failed to get file status");
	return -1;
	}
   else{
//      printf("%s last accessed at %s", path, ctime(&statbuf.st_atime));
	}
	return (int) (statbuf.st_size);
}
