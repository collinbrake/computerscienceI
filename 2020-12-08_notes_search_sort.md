# Notes - Search and Sort Algorithms

Notes taken for CS1 final, 12/05/2020.

## Search Algorithms

### Linear Search

The number of operations completed in a worst case scenario (where the search key isn't in the list) is 3n + 3, and the computational complexity is O(n).

```pseudocode
def linearSearch(list, value) {
    i = 0
    n = len(list)
    while (i < n) {
        if (list[i] == value) {
            return i
        }
        ++i
    }
    return -1
}
```



### Binary Search

This search method requires a sorted list, but has a computational complexity of O(log_2(n)).

```pseudocode
def binarySearch(list, value) {
	i = 0
	j = len(list)
	
	while(i <= j) {
		mid = (i + j)/2
		
		if (list[mid] == value) {
			return mid
		}
		else if (list[mid] > value) {
			j = mid - 1
		}
		else {
			i = mid + 1
		}
	}
	return -1
}
```



## Sort Algorithms

### Bubble Sort

In this algorithm, we have a nested loop structure that sorts pairs within the array, swapping when the first element is greater than the second. It loops until no more swaps are made. This has the effect of moving values through the array iteration by iteration, like bubbles rising to the surface of a liquid.

```pseudocode
def bubbleSort(list) {
	n = len(list)
	do {
		swap = false
		for (i = 0; i < n; ++i) {
			if (list[i] > list[i + 1]) {
				tmp = list[i]
				list[i] = list[i + 1]
				list[i + 1] = tmp
				swap = true
			}
		}
	} while (swap)
}
```



### Selection Sort

Simply search for the smallest element and place it at the beginning. Search for second smallest and place at 2nd position. Repeat....

```pseudocode
def selectionSort(list) {
	n = len(list)
	
	for (startScan = 0; startScan < n-1; ++startScan) {
		minIndex = startScan
		minValue = list[startScan]
		for (i = startScan + 1; i < n; ++i) {
			if (list[i] < minValue) {
				minValue = list[i]
				minIndex = i
			}
		}
		list[minIndex] = array[startScan]
		list[startScan] = minValue
	}
}
```







