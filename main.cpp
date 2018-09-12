#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions)
    {
        int total = 0;
        int temp = 1;
        for (int i = 0; i < dimensions; ++i)
        {
            total += coordinates[i] * temp;
            temp *= sizes[i];
        }
        return total;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    int tuple2[] = {2, 3, 5};
    int tuple[] = {0, 0, 0};

    Vector <Integer> vector(3, tuple2);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++) {
                *tuple = k;
                *(tuple + 1) = j;
                *(tuple + 2) = i;

                vector.set(i + j + k, tuple);
            }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++) {
                *tuple = k;
                *(tuple + 1) = j;
                *(tuple + 2) = i;
                cout << "{" << *tuple << ", " << *(tuple + 1) << ", " << *(tuple + 2) << "} = ";

                cout << vector.get(tuple) << endl;
            }

    system("pause");
    return EXIT_SUCCESS;
}