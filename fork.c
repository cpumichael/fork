#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
    pid_t kid;

    FILE *f = fopen("afile", "w");
    if (f == NULL) {
        /* XXX note that this will not print w/o newline, why???
           fprintf(stderr, "%s: %s", argv[0], strerror(errno));
         */
        fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
        exit(1);
    }
    
    kid = fork();
    if (kid == 0) {
        sleep(1); // This is weak, do NOT do this, only example.
        fprintf(f, "I am the kid!!!\n");
        exit(0);
    } else {
        fprintf(f, "I am the parent!!!\n");
    }

    sleep(2); // This is weak, do NOT do this, only example.
    fprintf(stdout, "Done!\n");
    return 0;
}

/* vim: cindent sw=4 ts=4 et showmatch
 */

