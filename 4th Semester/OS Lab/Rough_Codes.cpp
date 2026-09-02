///*
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0; // SHARED global--all threads read and write this!

void *printp1(void *parm) {
for (int i = 0; i < 5; i++) {
counter++; // DANGER: multiple threads doing this at the same time!
printf("thread %d counter %d\n", *(int*)parm, counter);
}
return NULL;
}

int main() {
int a = 1, b = 2, c = 3;
pthread_t t1, t2, t3;

pthread_create(&t1, 0, printp1, (void*)&a);
pthread_create(&t2, 0, printp1, (void*)&b);
pthread_create(&t3, 0, printp1, (void*)&c);

pthread_join(t1, 0);
pthread_join(t2, 0);
pthread_join(t3, 0);

printf("Final counter: %d (expected 15)\n", counter);
return 0;
}
//*/






















































