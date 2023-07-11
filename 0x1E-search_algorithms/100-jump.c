#include "search_algos.h"

/**
 * jump_search - performs jump search
 * @array: the integer array
 * @size: its size
 * @value: value to search for
 *
 * Return: the index found or -1
 */
def jump_search(arr,x):
 n=len(arr)
	step+= int(math.sqrt(n))
	if prev>=n:
	return -1
while arr[prev] < x:
	prev += 1
	if prev == min(step,n):
	return -1
if arr[prev] ==x:
 return prev
return -1 
		
