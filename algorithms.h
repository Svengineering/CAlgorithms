#ifndef ALGORITHMS_MY_H_
#define ALGORITHMS_MY_H_


//listA - list to be sorted
//listB - will contain sorted list result at end of recursion step
//len 	- length of both lists
void quick_sort_rec(int* listA, int* listB, int len);

//wrapper function for recursive quick sort func
void quick_sort(int* list, int len);


#endif
