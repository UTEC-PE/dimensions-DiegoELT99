#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
             
    private:
        T* data;
        int dataSize;
        int dimensions;
        int* dimensionSizes;
        Operation op;

    public:
        Vector() : data(nullptr) {};
             
        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes)
        {
            this -> dataSize = 1; //Inicialmente el data size es 1.
            for (int i = 0; i < dimensions; ++i)
                this -> dataSize *= dimensionSizes[i];
            this -> data = new T[this -> dataSize];
        }
             
        void set(T datum, int* coordinates)
        {
            int position = op(coordinates, this -> dimensionSizes, this -> dimensions);
            this -> data[position] = datum;
        };
             
        T get(int* coordinates)
        {
            int position = op(coordinates, this -> dimensionSizes, this -> dimensions);
            return this -> data[position];
        };

        ~Vector()
        {
            delete[] data;
        }
};

#endif
