#include <iostream>
#include <list>


void PrintList(std::list <double> _list)
{
    for (auto l : _list)
    {
        std::cout << l << ' ';
    }
    std::cout << std::endl;
}

void PushBackAverage ( std::list <double> &_list)
{
    double sum = 0;
    size_t lSize = _list.size();
    for (size_t i = 0; i < lSize; ++i)
    {
        sum += ( *next(_list.begin(), i));
    }
    _list.push_back(sum / lSize);
    PrintList(_list);
}


int main()
{
    /*Написать функцию, добавляющую в конец списка вещественных чисел элемент,
      значение которого равно среднему арифметическому всех его элементов.*/

    std::list <double> myList = { 5.2, 3.0, 0.0, -18, 16.5, 4, 3.2, -20, 8, -8, -14.3 };
    
    PrintList(myList);
    PushBackAverage(myList);
    PrintList(myList);
    

}
