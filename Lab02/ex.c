#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
   int i, num, j;
   int status, pid, pip[2];
   char buffer[20];

   printf("Enter the number: ");
   scanf("%d", &num);

   j = num;
   i = 1;

   status = pipe(pip);
   if (status == -1){
        perror("Trouble");
        exit(1);
   }

   sprintf(buffer, "%d", i);
   write(pip[1], buffer, sizeof(buffer));

   for (i = 1; j > 1; j = j - 1) {
        pid = fork();
        if (pid == 0){
            read(pip[0], buffer, sizeof(buffer));
            sscanf(buffer, "%d", &i);
            i = i * j;
            sprintf(buffer, "%d", i);
            write(pip[1], buffer, sizeof(buffer));
            close(pip[0]);
            close(pip[1]);
            exit(0);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("fork");
            exit(1);
        }
   }

   read(pip[0], buffer, sizeof(buffer));
   sscanf(buffer, "%d", &i);

   printf("The factorial of %d is %d\n", num, i);

   close(pip[0]);
   close(pip[1]);

   return 0;
}
