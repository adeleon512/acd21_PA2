/*
 * De_Leon_Adam_PA2.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Adam C. De Leon
 *      NetID: acd21
 *      Class: CS 2308
 *      Section: 1
 *      Roster number: 6
 *      Program description: This program loads an array with random numbers
 *      then searches for that number by performing a combination of
 *      linear searches, binary searches, bubble sorts, and selection sorts,
 *      implemented by calling functions; all while timing each of these
 *      operations.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

const int SIZE = 10000;        // size declared for array storage.
const int INQUIRED_VALUE = 1523;  // value to be found in array.

int LinearSearch(int[], int, int);            // Prototypes for functions
int BinarySearch(const int[], int, int);

void BubbleSort(int[], int);

int minIndex(int[], int, int);

void SelectionSort(int[], int);

int main() {
    clock_t start_time1, end_time1;        // variables for clock times
    clock_t start_time2, end_time2;
    clock_t start_time3, end_time3;
    clock_t start_time4, end_time4;
    clock_t start_time5, end_time5;
    clock_t start_time6, end_time6;

    double elapsedtime1;    //Variables for elapsed times, index numbers, and
    double elapsedtime2;    //array copies.
    double elapsedtime3;
    double elapsedtime4;
    double elapsedtime5;
    double elapsedtime6;
    int values[SIZE];
    int temp1[SIZE];
    int temp2[SIZE];
    int temp3[SIZE];
    int place1;
    int place2;
    int place3;
    int place4;
    int place5;
    int place6;

    //Load array with random numbers and copy to temp arrays
    for (int i = 0; i < SIZE; i++) {
        values[i] = rand() % SIZE + 1;
        temp1[i] = values[i];
        temp2[i] = values[i];
        temp3[i] = values[i];
    }

    //Run first linear search and display message.
    start_time1 = clock();
    place1 = LinearSearch(values, SIZE, INQUIRED_VALUE);
    cout << "After first linear search with no sorting the inquired value was "
            "found in index: " << place1;
    end_time1 = clock();
    cout << endl;
    elapsedtime1 = start_time1 - end_time1 / CLOCKS_PER_SEC;
    cout << "The time taken to perform this operation was:" << " "
         << elapsedtime1 << endl;

    //Run first binary search with out sorting and display message.
    start_time2 = clock();
    place2 = BinarySearch(values, SIZE, INQUIRED_VALUE);
    cout << "After first binary search with no sorting the inquired value was"
            " found in index: " << place2;
    cout << endl;
    cout << "inquired value was: " << INQUIRED_VALUE;
    end_time2 = clock();
    cout << endl;

    //If statement for values that are not in the array, and display message.
    if (place2 == -1) {
        cout << "The value was not found in the first binary search "
                "because the array has not been sorted yet. Therefore, the"
                " algorithm could not locate the inquired value.";
    }
    elapsedtime2 = start_time2 - end_time2 / CLOCKS_PER_SEC;
    cout << "The time taken to perform this operation was: "
         << elapsedtime2 << endl;

    //Bubble sort, linear search, and display message.
    start_time3 = clock();
    BubbleSort(values, SIZE);
    place3 = LinearSearch(values, SIZE, INQUIRED_VALUE);
    cout << "After a bubble sort and a linear search found the inquired value "
            "in index: " << place3;
    end_time3 = clock();
    cout << endl;
    elapsedtime3 = start_time3 - end_time3 / CLOCKS_PER_SEC;
    cout << "The time taken to perform this operation was: " << elapsedtime3;
    cout << endl;

    //Bubble sort, binary search, and display message.
    start_time4 = clock();
    BubbleSort(temp1, SIZE);
    place4 = BinarySearch(temp1, SIZE, INQUIRED_VALUE);
    cout << "After a bubble sort and a binary search the inquired value was "
            "found in index: " << place4;
    end_time4 = clock();
    cout << endl;

    //If statement for a value not found.
    if (place4 == -1) {
        cout << "The number " << INQUIRED_VALUE << "was not found.";
    }
    elapsedtime4 = start_time4 - end_time4 / CLOCKS_PER_SEC;
    cout << "The time taken to perform this operation was: " << elapsedtime4;
    cout << endl;

    //Selection sort, linear search, and display message.
    start_time5 = clock();
    SelectionSort(temp2, SIZE);
    place5 = LinearSearch(temp2, SIZE, INQUIRED_VALUE);
    cout << "After a selection sort and a linear search the inquired value was"
            " found in index: " << place5;
    end_time5 = clock();
    cout << endl;
    elapsedtime5 = start_time5 - end_time5 / CLOCKS_PER_SEC;
    cout << "The time taken to perform this operation was: " << elapsedtime5;
    cout << endl;

    //Selection sort, binary search, and display message.
    start_time6 = clock();
    SelectionSort(temp3, SIZE);
    place6 = BinarySearch(temp3, SIZE, INQUIRED_VALUE);
    cout << "After a selection sort and a binary search the inquired value was"
            " found in index: " << place6;
    end_time6 = clock();
    cout << endl;

    //If statement for a value not found
    if (place6 == -1) {
        cout << "The number " << INQUIRED_VALUE << "was not found.";
    }
    elapsedtime6 = start_time6 - end_time6 / CLOCKS_PER_SEC;
    cout << "The time taken to perform this operation was: " << elapsedtime6;

    return 0;
}

/*****************************************************************************
 * BubbleSort - This function compares the first two elements in an array. If
 * the first is bigger, they exchange places (swap). Then it compares the
 * second and third elements in the array. If the second is bigger, they
 * exchange places. This method of operation is repeated until the last two
 * elements of the array are compared and no more swaps are necessary.
 */
void BubbleSort(int values[], int SIZE) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < (SIZE - 1); i++) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

/*****************************************************************************
 * MinIndex - This function determines which index in the array contains the
 * minimum value.
 */
int minIndex(int values[], int SIZE, int start) {
    int minIndex = start;
    for (int i = start + 1; i < SIZE; i++)
        if (values[i] < values[minIndex])
            minIndex = i;
    return minIndex;
}

/*****************************************************************************
 * SelectionSwap - This function calls on the MinIndex function to locate
 * which element holds the smallest value. Then it swaps this value with the
 * value that is stored in element number 0. Then it locates the array index
 * that holds the next smallest value and swaps it with the value in element
 * number 1. It continues this process until all the elements are arranged in
 * order.
 */
void SelectionSort(int values[], int SIZE) {
    int min;
    for (int index = 0; index < (SIZE - 1); index++) {
        min = minIndex(values, SIZE, index);
        swap(values[min], values[index]);
    }
}

/*****************************************************************************
 * LinearSearch - This functions searches the array element by element until
 * it locates the specified element, moving in a sequential incremental order.
 */
int LinearSearch(int values[], int SIZE, int value) {
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < SIZE && !found) {
        if (values[index] == value) {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

/*****************************************************************************
 * BinarySearch - Finds a specified element in the array by determining the
 * end points and the mid point of an array then proceeds to progress through
 * the algorithm to find the specified element.
 */
int BinarySearch(const int values[], int SIZE, int value) {
    int first = 0;
    int last = SIZE - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (values[middle] == value) {
            found = true;
            position = middle;
        } else if (values[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
