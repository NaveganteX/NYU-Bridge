#include <iostream>
using namespace std;

/*
 * Linear Search:
 * search() runtime is big-O of f(n) where n is the size of the input array.
 * The worst case runtime (big-O) is when it iterates through each element in
 * the input array (array_size).
 *
 * If f(n) = theta(number of iterations) then we notice the WORST case (big-O) is
 * the number of times the for loop iterates. The search() algorithm iterates, at maximum,
 * the number of elements (n) in the input array (array_size) so we can say that the big-O is
 * n times. Therefore, f(n) = theta(n), i.e. it runs in linear time.
 *
 * Thus, the general search algorithm search() is a linear search algorithm.
 */

int search(const int *arr, int array_size, int value) {
    for (int i = 0; i < array_size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

/*
 * Binary Search:
 * The sortedSearch() algorithm (aka Binary Search) divides the input array in half and compares the value to
 * the middle number. Based on whether the value is larger or smaller than the middle value,
 * it readjusts the array to the half that contains the number and redivides the pertinent half in half again.
 * This continues until the value is found or until there is no more array to divide.
 *
 * Because we are dividing the array in half after each iteration until the value is found, we can say
 * for each iteration the size of the searching range is 1 / (2^(k-1)).
 *
 * e.g. :
 * iteration number (n) --> size of searching range:
 * 1 --> n/1 == n/2^0
 * 2 --> n/2 == n/2^1
 * 3 --> n/4 == n/2^2
 * 4 --> n/8 == n/2^3
 * .
 * .
 * k --> n/2^(k-1)
 * Ultimately the size of the searching range will reach 1 (again this is for WORST case analysis) because we keep
 * iterating until the low range crosses over the high range (i.e. the size of the searching range is 1). The iteration
 * number that corresponds to a search range size of 1 is our runtime.
 *
 * If we know that when the size of the searching range == 1 is the worst case then
 * we can set n/2^(k-1)  = 1 and solve for k:
 * n/2^(k-1) = 1
 * n = 2^(k-1)
 * log_base_2 (n) = log_base_2 (2^(k-1))
 * log_base_2 (n) = (k-1) * log_base_2 * (2) //this is a log rule
 * log_base-2 (n) = (k-1) * 1 //this is a log rule
 * log_base_2 (n) + 1 = k //order of scale the +1 is insignificant so we drop it (asymptotic analysis)
 * => k = log_base_2 (n)
 *
 * Therefore if f(n) = log_base_2 (n)
 */

int sortedSearch(const int *sorted_arr, int array_size, int value) {
    int low, high, mid, index;
    bool found = false;

    low = 0;
    high = array_size - 1;

    while ((found == false) && (low <= high)) {
        mid = (low + high) / 2;
        if (value == sorted_arr[mid]) {
            index = mid;
            found = true;
        } else if (value < sorted_arr[mid]) {
            high = mid - 1;
        } else { // i.e. when value > sorted_arr[mid]r
            low = mid + 1;
        }
    }

    if (found == true) {
        return index;
    } else {
        return -1;
    }
}

/*
 * Linear vs Logarithmic:
 * For a small n (small input array) the difference between an algorithm that runs
 * in linear vs logarithmic is negligible. However, for large arrays the difference becomes drastic.
 *
 * Linear <--> Log
 * n = 2 (2^1) < --> n = log_base_2 (2^1) == 1 //2 vs. 1 is not too large a difference
 * n = 4 (2^2) <--> n = log_base_2 (2^2) == 2 //4 vs. 2 is again insignificant
 * n = 8 (2^3) <--> n = log_base_2 (2^3) == 3 //8 vs. 3 is still insignificant
 * .
 * .
 * .
 * n = 1024 (2^10) <--> n = log_base_2 (2^10) == 10 //1024 vs. 10; linear time is becoming untenable while log time is still low
 * n = 4,294,967,296 (2^32) <--> n = log_base_2 (2^32) == 32 //4,294,967,296 vs. 32 clearly favors log
 *
 * This is why log_base_2 algorithms like Binary Search are better than linear algorithms like Linear Search for large inputs
 */
int main() {
    int array_size, value, index_of_value;
    int arr[10] = {13, 12, 53, 4, 15, 86, 7, 28, 29, 31};
    array_size = 10;
    value = 7;
    index_of_value = search(arr, array_size, value);
    cout << value << " is found at index " << index_of_value << endl;

    int sortedArr[10] = {14, 25, 32, 48, 58, 66, 75, 83, 94, 140};
    array_size = 10;
    value = 94;
    index_of_value = sortedSearch(sortedArr, array_size, value);
    cout << value << " is found at index " << index_of_value << endl;

    return 0;
}
