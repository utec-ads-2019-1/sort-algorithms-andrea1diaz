#include "tester.h"

void integersBubble(void *elements, int first, int second) {
  int *array = (int*) elements;

  if (array[first] > array[second]) {
    swap(array[first], array[second]);
  }
}

void integersSelect(void *elements, int i, int min) {
  int *array = (int*) elements;
  int tmp;

  if (min != i) {
    tmp = array[i];
    array[i] = array[min];
    array[min] = tmp;
  }


}

void integersInsert(void *elements, int i, int j) {
  int *array = (int*) elements;
  int key = array[i];
  while (0 <= j && key < array[j]) {
    array[j + 1] = array[j];
    j = j - 1;
  }
  array[j + 1] = key;
}

void integersShell(void *elements, int i, int gap) {
  int *array = (int*) elements;
  int temp = array[i];

  for (int j = i; gap <= j && temp < array[j - gap]; j -= gap) {
    array[j] = array[j - gap];
  }
  array[j] = temp;
}

void integersQuick(void *elements, int i, int j) {
  int *array = (int*) elements;
  int pivot = array[ (i + j) / 2];


}

void integersMerge(void *elements, int i, int j) {

}


Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        case selectsort: return new SelectSort(array, size);
        case insertsort: return new InsertSort(array, size);
        case shellsort: return new ShellSort(array, size);
        case quicksort: return new QuickSort(array, size);
        // case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integersBubble;
        case selectsort: return &integersSelect;
        case insertsort: return &integersInsert;
        case shellsort: return &integersShell;
        case quicksort: return &integersQuick;
        // case mergesort: return &integersMerge;
        default: throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    int temp[size];

    // Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort, quicksort, mergesort };
    Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}
