/*
Semaphore is a synchronization primitive that allows multiple processes or threads to access a shared resource in a mutually exclusive manner. It maintains a counter that is used to control the access to the shared resource.

A semaphore has two basic operations:

Wait() - Decrements the counter. If the counter is zero, the process/thread that invokes Wait() is blocked until the counter becomes positive.

Signal() - Increments the counter. If there are blocked processes/threads waiting for the semaphore, one of them is unblocked.

A semaphore can be used to control access to a shared resource by having each process/thread perform a Wait() operation before accessing the resource and a Signal() operation after it has finished accessing the resource. This ensures that only one process/thread can access the resource at a time.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <semaphore.h>

std::mutex mtx;
std::condition_variable cv;
sem_t sem;

void worker(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Worker " << id << " waiting..." << std::endl;
    if (sem_trywait(&sem)) { // wait for semaphore
        std::cout << "Worker " << id << " started!" << std::endl;
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        lock.lock();
        sem_post(&sem); // release semaphore
        std::cout << "Worker " << id << " finished!" << std::endl;
        cv.notify_one(); // notify main thread
    } else {
         lock.unlock();
    }
}

int main() {
    sem_init(&sem, 0, 2); // initialize semaphore with value 2
    std::thread workers[5];
    for (int i = 0; i < 5; i++) {
        workers[i] = std::thread(worker, i);
    }
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return sem_getvalue(&sem, NULL) == 0; }); // wait for semaphore to be available
    lock.unlock();
    std::cout << "Starting all workers..." << std::endl;
    sem_post(&sem); // release semaphore twice
    sem_post(&sem);
    for (int i = 0; i < 5; i++) {
        workers[i].join();
    }
    sem_destroy(&sem); // destroy semaphore
    return 0;
}
