#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "asynchronous.h"

void test() async {
	int i = 3;

	sleep(i);
	printf("After sleeping for %i seconds\n", i);
}

void test2(int i, void (*callback)(int)) {
	sleep(i);
	printf("After sleeping for %i seconds.\n", i);
	i++;
	callback(i);
}

void test_callback(int i) {
	sleep(1);
	printf("Callback : %i\n", i);
}

int main() {
	int i = 3;
	test();
	puts("During thread");
	pthread_exit(0);
}