#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 0;
int main(int argc, char *argv[]) {
x = 100;

int rc = fork();
if(rc < 0 ){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if(rc == 0){
printf("hello \n");
}
else{
int status;
waitpid(rc, &status, 0);
printf("goodbye");
}
return 0;
}
