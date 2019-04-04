#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {
    public:
        SelectSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
          int min;
          int *array = (int*) elements;
            for (int i = 0; i < size - 1; ++i) {
              min = i;
              for (int j = i + 1; j < size; ++j) {
                if (array[j] < array[min]) {
                  min = j;
                }
              }
              compare(elements, i, min);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif
