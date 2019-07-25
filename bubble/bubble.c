#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


void bubble(int *seq, int length){
    for(int i = length; i > 0; i--){
        for(int j = 0; j < i; j++)
	    if(seq[j] > seq[j + 1]){
	        int tmp = seq[j];
		seq[j] = seq[j + 1];
		seq[j + 1] = tmp;
	    }
    }
}

void print_seq(int *seq, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", seq[i]);
    printf("\n");
}

int main(){
    int seq[SIZE];
    for(int i = 0; i < SIZE; i++)
        seq[i] = rand() % 10 + 1; 
    int size = (int) (sizeof(seq)/sizeof(int));
    print_seq(seq, size);
    bubble(seq, size);
    print_seq(seq, size);
    return 0;
}
