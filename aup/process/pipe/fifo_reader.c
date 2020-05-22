#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        fprintf(stderr, "usage: %s <fifo_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int fifo = open(argv[1], O_RDONLY);
    if (fifo < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    FILE *outstream = fopen(argv[2], "wb");
    if (! outstream) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    char buf[BUFSIZ];
    int nbuf;
    while((nbuf = read(fifo, buf, BUFSIZ)) > 0) {
        fwrite(buf, nbuf, 1, outstream);

    }
    
    close(fifo);
    fclose(outstream);
    
    return 0;
}
