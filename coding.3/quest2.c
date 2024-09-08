#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 0;
int main(int argc, char *argv[]) {
x = 100;
FILE *fptr;
fptr = fopen("quest2TEXT.txt", "w");

int rc = fork();
if(rc < 0 ){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if(rc == 0){
printf("child x = %d \n", x);
x++;
printf("child x2 = %d \n", x);
fprintf(fptr,"a");
fprintf(fptr,"b");
fprintf(fptr,"c");
fprintf(fptr,"d");
fprintf(fptr,"e \n");
}
else{
printf("parent x = %d \n", x);
x--;
printf("parent x = %d \n", x);
fprintf(fptr,"1");
fprintf(fptr,"2");
fprintf(fptr,"3");
fprintf(fptr,"4");
fprintf(fptr,"5");
}
return 0;
}

