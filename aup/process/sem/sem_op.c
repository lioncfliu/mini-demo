#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>


#define FILENAME "/dev/null"

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int sem_set(int sem_id) 
{
    union semun sem_u;
    sem_u.val = 1;
    
    if (semctl(sem_id, 0, SETVAL, sem_u)) 
        return -1;
    else  
        return 0;
}


int sem_p(int sem_id) 
{
    struct sembuf sem_b[1] ;
    sem_b[0].sem_num = 0;
    sem_b[0].sem_op = -1;
    sem_b[0].sem_flg = SEM_UNDO;
    if (semop(sem_id, sem_b, 1))
        return -1; 
    else 
        return 0;
}


int sem_v(int sem_id) 
{
    struct sembuf sem_b[1];
    sem_b[0].sem_num = 0;
    sem_b[0].sem_op = 1;
    sem_b[0].sem_flg = SEM_UNDO;
    
    if (semop(sem_id, sem_b, 1)) 
        return -1;
    else 
        return 0;
}

int sem_del(int sem_id) 
{
    if (semctl(sem_id, 0, IPC_RMID) == -1) 
        return -1;
    else 
        return 0;
}


int main(int argc, char* argv[]) 
{
    key_t  shm_key = ftok(FILENAME, 0);
    if (shm_key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }


    int shm_size = getpagesize();
    int shm_id = shmget(shm_key, shm_size, 0644 | IPC_CREAT);
    

    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    

    char *data = (char *)shmat(shm_id, NULL, 0);
    if (data == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    
    memset(data, 0, shm_size);
    key_t sem_key = shm_key;
    int sem_id = semget(sem_key, 1, 0644 | IPC_CREAT);
    if (sem_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }
    
    if (sem_set(sem_id) == -1 ) {
        perror("semset");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0) {
        if (sem_p(sem_id) == -1) {
            perror("sem_p");
            exit(EXIT_FAILURE);
        }

        printf("parent_proc(%d) writing now ... \n", getpid());
        int i = 0;
        for (i = 0; i < 3; i++) {
            sprintf(data + 5*i, "www%d ", i);
            sleep(1);
        }
        printf("parent_proc(%d) writing complete ... \n", getpid());
        
        if (sem_v(sem_id) == -1) {
            perror("sem_v");
            exit(EXIT_FAILURE);
        }
        if (shmdt(data) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
        if (sem_del(sem_id) == -1) {
            perror("shm_del");
            exit(EXIT_FAILURE);
        }
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    } else if (pid == 0) {
        usleep(3);
        printf("child_proc(%d) waiting to read ...\n", getpid());
        if (sem_p(sem_id) == -1) {
            perror("sem_p");
            exit(EXIT_FAILURE);
        }
        printf("child_proc(%d) read data: %s \n", getpid(), data);
        if (sem_v(sem_id) == -1) {
            perror("sem_v");
            exit(EXIT_FAILURE);
        }
        if (shmdt(data) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
