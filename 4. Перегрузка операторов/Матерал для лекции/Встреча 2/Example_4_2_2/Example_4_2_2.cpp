#include <iostream>

class DynArray
{
    int* arr;
    int size;
public:
    DynArray(int sizeP)
        : arr{ new int[sizeP] {} }, size{ sizeP }
    {
        std::cout << "DynArr constructed for " << size << " elements, for " << this << '\n';
    }
    DynArray() : DynArray(5) {}

    DynArray(const DynArray& object)
        : arr{ new int[object.size] }, size{ object.size }
    {

        for (int i{ 0 }; i < size; ++i)
        {
            arr[i] = object.arr[i];
        };

        std::cout << "DynArr copy constructed for " << size << " elements, for " << this << '\n';
    }

    DynArray& operator=(const DynArray& object)
    {
        // проверка на самоприсваивание

        if (!(this == &object))
        {
            /* проверяем на невозможность "переиспользовать"
            блок памяти, выделенный под имеющийся
            массив */
            if (size != object.size)
            {
                /* в случае невозможности "переиспользования"
                необходимо освободить память, УЖЕ
                занимаемую элементами текущего
                динамического массива */
                delete[] arr;
                /* выделяем новый блок памяти согласно
                размеру копируемого массива */
                arr = new int[object.size];
            }
            size = object.size;
            /* Следующим циклом копируем элементы
            из оригинального блока памяти во вновь
            выделенный */
            for (int i{ 0 }; i < size; ++i)
            {
                arr[i] = object.arr[i];
            }
        }
        std::cout << "DynArr copy assigned for "
            << size << " elements, for " << this
            << '\n';
        return *this;
    }


    int getElem(int idx) { return arr[idx]; }
    void setElem(int idx, int val) { arr[idx] = val; }
    void print();
    void randomize();
    ~DynArray()
    {
        std::cout << "Try to free memory from DynArray for " << arr << " pointer\n";
        delete[] arr;
        std::cout << "DynArr destructed for " << size << " elements, for " << this << '\n';
    }
};

void DynArray::print()
{
    for (int i{ 0 }; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void DynArray::randomize()
{
    for (int i{ 0 }; i < size; ++i)
    {
        arr[i] = rand() % 10;
    }
}

DynArray CreateRandomDynArray(int arrSize)
{
    DynArray arr{ arrSize };
    arr.randomize();
    return arr;
}

int main()
{
    DynArray ar0 = CreateRandomDynArray(10);
    DynArray ar1{ ar0 };

    //DynArray ar2{ CreateRandomDynArray(10) }; //RVO Return Value Optimization
    std::cout << "ar1 elements: ";
    ar1.print();
    return 0;
}