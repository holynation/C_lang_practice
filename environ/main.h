#ifndef __MAIN__
#define __MAIN__

char *_getenv(const char *name);
char *locate_path(const char *name);
char *combine_path(const char sep, const char *path1, const char *path2);
int file_exist(const char *path);
char *_strdup(const char *str);

#endif