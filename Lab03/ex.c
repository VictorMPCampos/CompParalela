#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int ShmID;
	pid_t pid;
	int *ShmPTR;
	int valor = 1;

	ShmID = shmget(IPC_PRIVATE, 1*sizeof(int), IPC_CREAT | 0666);
	if (ShmID < 0) {
          printf("shmget error\n");
          exit(1);
	}
	ShmPTR  = (int*) shmat(ShmID, NULL, 0);
	ShmPTR[0] = (valor);
	printf("Processo pai vizualiza valor = %d\n", ShmPTR[0]);
	pid = fork();
	if (pid < 0){
		printf("fork error\n");
		exit(1);
	}
	else if (pid == 0){
		printf("Processo filho adicionando 3 ao valor\n");
		ShmPTR[0] += 3;
		exit(0);
	}
	else
		wait(NULL);
	printf("Processo pai multiplicando o valor por 4\n");
	ShmPTR[0] = ShmPTR[0]*4;
	printf("Valor final visto pelo processo pai = %d\n", ShmPTR[0]);
	shmctl(ShmID, IPC_RMID, NULL);
	return 0;
}
