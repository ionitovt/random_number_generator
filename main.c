#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	unsigned int n;
	int *Masiv;
}Set;
Set* func(int);
int *random_generator(int);
void print(Set *);
unsigned find_element(Set*, int);


int main(){
	srand(time(0));
	Set *A, *B;
	func(rand() % 20);
	return 0;
}

Set* func(int N){
	Set *PSet;
	PSet = (Set*)malloc(sizeof(Set));
	PSet->Masiv = random_generator(N);
	PSet->n = N;
	print(PSet);
	return PSet;
}

int *random_generator(int num){
	int *Masiv, i;
	srand(time(0));
	Masiv = (int*)malloc(sizeof(int)*num);
	for (i = 0; i < num; i++){
		Masiv[i] = rand() % 100;
	}
	return Masiv;
}

void print(Set *set){
	int i;
	for (i = 0; i < set->n; i++){
		printf("%d ", set->Masiv[i]);
	}
}

Set* intersection(Set* A, Set* B){
	Set *C;
	C = func(0);
	int i;
	for (i = 0, C->n = 0; i < B->n; i++){
		if (find_element(A, B->Masiv[i])){
			C->n++;
			C->Masiv[C->n] = (unsigned*)realloc(C->Masiv, sizeof(unsigned)*C->n);
			C->Masiv[C->n] = B->Masiv[i];
		}
	}
}

unsigned find_element(Set* set, int element){
	int i;
	for (i = 0; i < set->n; i++){
		if (element == set->Masiv[i]) return 1;
	}
	return 0;
}
