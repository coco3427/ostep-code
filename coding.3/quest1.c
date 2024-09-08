#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x = 0;
int main(int argc, char *argv[]) {
x = 100;

int rc = fork();
if(rc < 0 ){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if(rc == 0){
printf("child x = %d \n", x);
x++;
printf("child x2 = %d \n", x);
}
else{
printf("parent x = %d \n", x);
x--;
printf("parent x = %d \n", x);
}
return 0;
}

