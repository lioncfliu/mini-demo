#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

    if (argc < 2) {
        fprintf(stderr, "usage: %s <cmd>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char output[1024+1];
    FILE *pp = popen(argv[1], "r");
    if (NULL == pp) {
        perror("popen error");
        exit(EXIT_FAILURE);
    }
    
    int nread = fread(output, 1, 1024, pp);
    int status = pclose(pp);
    if (status < 0) {
        perror("pclose error");
        exit(EXIT_FAILURE);
    }
    output[nread] = 0;
    if (WIFEXITED(status))  {
        printf("status: %d\n%s", WEXITSTATUS(status), output);
    } 
    return 0;

}
