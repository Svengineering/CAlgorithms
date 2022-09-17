#include <stdlib.h>
#include <string.h>
#include "algorithms.h"

//listA - list to be sorted
//listB - will contain sorted list result at end of recursion step
//len 	- length of both lists
//
void pivot_sort_rec(int* listA, int* listB, int len){
	if(len <= 1){
		return;
	}
	//printf("piv_sort_rec ");
	//print_list(test_list, 10, 0);//###
	//print_list(test_listB, 10, 0);//###
	//printf("listA ");
	//print_list(listA, 2,0); //#####
	
	//choose first list element as pivot element
	int pivot_el = listA[0];
	
	int cnt1, cnt2;
	cnt1 = 0;		//starting at begin of listB
	cnt2 = 0;	//starting at end of listB
	
	//sort by pivot element
	for(int i = 1; i < len; i++){
		if(listA[i] <= pivot_el){
			listB[cnt1] = listA[i];
			cnt1++;
		} else {
			listB[len - 1 - cnt2] = listA[i];
			cnt2++;
		}
	}
	
	listB[cnt1] = pivot_el; //sort pivot element as last element into first sublist
	
	if(cnt2 == 0){ //if is second sublist is empty, make it contain at least the pivot element
		cnt1--;
		cnt2++;
	}
	
	//recursion step
	pivot_sort_rec(listB, listA, cnt1 + 1);
	pivot_sort_rec( (listB + cnt1 + 1), (listA + cnt1 + 1), cnt2);
	
	//insert sorted results back into listA
	memcpy((void*) listA, (void*) listB, (cnt1 + 1) * sizeof(int));
	
	memcpy((void*) (listA + cnt1 + 1), (void*) (listB + cnt1 + 1), cnt2 * sizeof(int));
	
	//printf("\tback copy to listA "); //###
    //print_list(listA, len, 0);    //##
	
	return;
}


// pivot sort implementation
//
// wrapper function for recursive pivot sort func
//
// function uses only len*sizeof(int) memory internally
//
void pivot_sort(int* list, int len){
	int* list_mall = (int *) malloc( sizeof(int) * len);
	if(list_mall == NULL){
		exit(0);
	}
	
	pivot_sort_rec(list, list_mall, len);
	
	free((void *)list_mall);
	return;
}
