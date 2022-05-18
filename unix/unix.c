#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void _print(long n);

int main(int argc, char **argv) /* *argv[] => **argv */
{
   	FILE *stream;
   	char *line = NULL;
   	size_t len = 0;
   	ssize_t nread;
   	int line_count = 0;

   	if (argc != 2) {
    	fprintf(stderr, "Usage: %s <file>\n", argv[0]);
       	exit(EXIT_FAILURE);
   	}

   	stream = fopen(argv[1], "r");
   	if (stream == NULL) {
       perror("fopen");
       exit(EXIT_FAILURE);
    }

    /* Get the first line of the file. */
    nread = getline(&line, &len, stream);

   	while (nread != -1) {
   		/* incrememt the line number */
       	line_count++;

       	/* show the line details */
       	printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", line_count,
        nread, len, line);

        /* get the next line */
        nread = getline(&line, &len, stream);
    	/*fwrite(line, nread, 1, stdout);*/
   	}

   	free(line);
   	line = NULL;
   	fclose(stream);
   	exit(EXIT_SUCCESS);
}

void _print(long n)
{
    /* If number is smaller than 0, put a - sign */
    /* and change number to positive */
    if (n < 0) {
        putchar('-');
        n = -n;
    }
 
    /* Remove the last digit and recur */
    if (n/10)
        _print(n/10);
 
    /* Print the last digit */
    putchar(n%10 + '0');
}