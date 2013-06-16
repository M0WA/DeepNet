/**
 *
 * @file Semaphore.cpp
 * @author Moritz Wagner
 * @date 16.06.2013
 *
 */

#include "Semaphore.h"

namespace threading {

Semaphore::Semaphore(const size_t& maxCount) {
	sem_init(&sem, 0, maxCount);
}

Semaphore::~Semaphore() {
	sem_destroy(&sem);
}

void Semaphore::Lock(){
	sem_wait(&sem);
}

void Semaphore::Unlock(){
	sem_post(&sem);
}

}
