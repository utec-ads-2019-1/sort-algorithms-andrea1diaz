#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {
    public:
        InsertSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
          int key;
          for (int i = 1; i < size; ++i) {
            int j = i - 1;
            compare(elements, i, j);
          }
        }

        inline string name() { return "InsertSort"; }
};

#endif
