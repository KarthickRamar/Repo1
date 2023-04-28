/*
Semaphore is a synchronization primitive that allows multiple processes or threads to access a shared resource in a mutually exclusive manner. It maintains a counter that is used to control the access to the shared resource.

A semaphore has two basic operations:

Wait() - Decrements the counter. If the counter is zero, the process/thread that invokes Wait() is blocked until the counter becomes positive.

Signal() - Increments the counter. If there are blocked processes/threads waiting for the semaphore, one of them is unblocked.

A semaphore can be used to control access to a shared resource by having each process/thread perform a Wait() operation before accessing the resource and a Signal() operation after it has finished accessing the resource. This ensures that only one process/thread can access the resource at a time.
*/
//==================================================================================================================
/*
Here are some commonly used semaphore functions in C++:

sem_init(): This function initializes a semaphore. It takes three arguments: a pointer to the semaphore, a flag indicating whether the semaphore should be shared between processes or only between threads, and an initial value for the semaphore.

sem_wait(): This function decrements the value of a semaphore. If the semaphore value is currently 0, the function will block until the semaphore becomes available.

sem_post(): This function increments the value of a semaphore, making it available for other threads or processes to use.

sem_destroy(): This function destroys a semaphore that was previously created with sem_init(), freeing any associated resources.
*/
//==================================================================================================================
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <semaphore.h>

// Create a semaphore with an initial value of 1
sem_t sem;

void threadFunction(int threadId) {
  // Wait for the semaphore
  sem_wait(&sem);

  // Access the shared resource
  std::cout << "Thread " << threadId << " is accessing the shared resource" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  // Release the semaphore
  sem_post(&sem);
}

int main() {
  // Initialize the semaphore with an initial value of 1
  sem_init(&sem, 0, 1);

  // Create two threads
  std::thread thread1(threadFunction, 1);
  std::thread thread2(threadFunction, 2);

  // Wait for the threads to finish
  thread1.join();
  thread2.join();

  // Destroy the semaphore
  sem_destroy(&sem);

  return 0;
}
