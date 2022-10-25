#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algorithms.h"



void print_list(int* list, int len, int with_newline){
	printf("print list:\n");
	char fmtstr[10];
	
	if(with_newline){
		strcpy(fmtstr, "%15i\n");
	} else {
		strcpy(fmtstr, "%i ");
	}
	
	for(int i = 0; i < len; i++){
		printf(fmtstr, list[i]);
	}
	printf("\n");
}



int test_sorted_list(int* list, int len){
	
	int has_errors = 0;
	
	for(int i = 0; i < len - 1; i++){
		if(list[i] > list[i+1]){
			has_errors++;
		}
	}
		
	return has_errors;
}



int main() {
	
	//implemented: quick sort algorithm
	
	
	//       			sort small list	
	
	int test_list[10] = {485, 1789, 690, 735, 1056, 1698, 199, 790, 1303, 541};
	
	printf("sort small list - ");
	print_list(test_list, 10, 1);
	quick_sort(test_list, 10);
	print_list(test_list, 10, 1);
	
	
	
	
	
	//					sort a big list and test result
	
	
	//create a big list with random numbers
	time_t t;
	srand((unsigned) time(&t));
	
	int megabyte = 50;
	printf("construct big random list of %i MB\n", megabyte);
	
	int numb_rand_numbers = megabyte * 1024 * 1024 / sizeof(int);
	int* big_test_list = (int*) malloc( sizeof(int) * numb_rand_numbers);
	
	for(int i = 0; i < numb_rand_numbers; i++) {
		big_test_list[i] = rand();
	}
	
	//sort the list
	printf("sort a big list\n");	
	quick_sort(big_test_list, numb_rand_numbers);
	print_list(big_test_list, numb_rand_numbers, 1);
	
	
	//test the result
	if(test_sorted_list(big_test_list, numb_rand_numbers)){
		printf("TEST: ERROR - list isn't sorted in correct order\n");
	} else {
		printf("TEST: list is sorted in correct order\n");
	}
	
	
	free(big_test_list);
	
	
	return 0;
}
