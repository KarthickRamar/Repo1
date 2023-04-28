/*The POSIX Semaphore API in C++ provides the following functions:

sem_init: This function initializes a semaphore. Its signature is:
*/
#include <semaphore.h>

int sem_init(sem_t *sem, int pshared, unsigned int value);
/*
Here, sem is a pointer to the semaphore that needs to be initialized, pshared is a flag that indicates whether the semaphore is shared between processes, and value is the initial value of the semaphore.
*/
//=================================================================================================================
/*sem_destroy: This function destroys a semaphore. Its signature is:*/

int sem_destroy(sem_t *sem);

/*Here, sem is a pointer to the semaphore that needs to be destroyed.*/

//================================================================================================================
/*sem_wait: This function waits on a semaphore. Its signature is:*/

int sem_wait(sem_t *sem);

/*Here, sem is a pointer to the semaphore that needs to be waited on.*/

//================================================================================================================

/*sem_trywait: This function waits on a semaphore, but it returns immediately if the semaphore cannot be acquired. Its signature is:*/

int sem_trywait(sem_t *sem);

/*Here, sem is a pointer to the semaphore that needs to be waited on.*/

//================================================================================================================

/*sem_timedwait: This function waits on a semaphore for a specified amount of time. Its signature is:*/

int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);

/*Here, sem is a pointer to the semaphore that needs to be waited on, and abs_timeout is a pointer to a timespec structure that specifies the absolute time until which the function will wait for the semaphore.*/

//================================================================================================================

/*sem_post: This function releases a semaphore. Its signature is:*/

int sem_post(sem_t *sem);

/*Here, sem is a pointer to the semaphore that needs to be released.*/

//================================================================================================================

/*sem_getvalue: This function retrieves the current value of a semaphore. Its signature is:*/

int sem_getvalue(sem_t *sem, int *sval);

/*
Here, sem is a pointer to the semaphore whose value needs to be retrieved, and sval is a pointer to an integer where the value will be stored.

All of these functions return 0 on success and -1 on failure. In case of failure, the errno variable is set to indicate the error.
*/