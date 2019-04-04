#include "tester.h"

void integersBubble(void *elements, int first, int second) {
  if
}

Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        // case selectsort: return new SelectSort(array, size);
        // case insertsort: return new InsertSort(array, size);
        // case shellsort: return new ShellSort(array, size);
        // case quicksort: return new QuickSort(array, size);
        // case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

Sort* Tester::getCompare(Algorithm sort) {
  switch (sort) {
    case bubblesort: return &integersBubble;
    default: throw invalid_argument("Not a valid compare")
  }
}

void Tester::integerSorts(int *array, size_t size, void (*compare)(void*, int, int)) {
    Sort* sort;
    int temp[size];

    // Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort, quicksort, mergesort };
    Algorithm algorithm[] = { bubblesort};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}
