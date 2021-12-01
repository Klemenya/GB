#include <iostream>
#include <list>
#include <vector>


void PrintList(const std::list <double>& _list)
{
    for (auto l : _list)
    {
        std::cout << l << ' ';
    }
    std::cout << std::endl;
}

void PushBackAverage(std::list <double>& _list)
{
    double sum = 0;

    size_t lSize = _list.size();

    //   for (auto l : _list)                                  // Так проще
    //   {
    //       sum += l;
    //   }

    for (size_t i = 0; i < lSize; ++i)                      // Так интереснее
    {
        sum += (*next(_list.begin(), i));                   // т.е. значение следующего в списке от начала (смещение на i элемен)
    }

    _list.push_back(sum / lSize);
}

/*----------------------------------------------------------------------*/

class Matrix
{
private:

    int size_;
    std::vector<std::vector<int>> matrix_;

public:

    Matrix(int size, std::vector<int> values)
    {
        size_ = size;
        matrix_.resize(size);
        for (int i = 0; i < size; ++i)
        {
            int offset = i * size, counter = 0;
            while (counter < size)
            {
                matrix_[i].push_back(values[offset]);
                ++offset;
                ++counter;
            }
        }
    }

    std::vector <std::vector<int>> GetMinor(int line, int row)
    {
        std::vector <std::vector<int>> copiedMatrix(2);
        int lineOffset = 0;
        for (int i = 0; i < size_ - 1; ++i)
        {
            if (i == line)
            {
                lineOffset = 1;
            }
            int rowOffset = 0;
            for (int j = 0; j < size_ - 1; ++j)
            {
                if (j == row)
                {
                    rowOffset = 1;
                }
                copiedMatrix.at(i).push_back(matrix_[i + lineOffset][j + rowOffset]);
            }
        }
        return copiedMatrix;
    }

    std::vector<std::vector<int>> GetMatrix() const
    {
        return matrix_;
    }

    int Determinant(int size, std::vector<std::vector<int>>& matrix)
    {
        std::vector<std::vector<int>> tmpMatrix;
        int sign = 1;
        int decrementedSize = size - 1;
        int result = 0;

        if (size == 1)
        {
            return matrix[0][0];
        }
        else if (size == 2)
        {
            return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                tmpMatrix = GetMinor(i, 0);
                result += sign * matrix[i][0] * Determinant(decrementedSize, tmpMatrix);
                sign = -sign;
            }
        }
        return result;
    }

    void PrintMatrix()
    {
        for (auto line : matrix_)
        {
            for (auto value : line)
            {
                std::cout << "[ " << value  << " ]" << "  ";
            }
            std::cout << std::endl;
        }
    }

    void PrintMatrix(std::vector<std::vector<int>>& matrix)
    {
        for (auto line : matrix)
        {
            for (auto value : line)
            {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};

/*----------------------------------------------------------------------*/

class Iterator
{
    std::vector <int>& m_vector;
    int* m_begin;
    int* m_end;
public:
    Iterator(std::vector<int>& i_vector) : m_vector(i_vector)
    {
        m_begin = m_vector.empty() ? 0 : &m_vector.front();
        m_end = m_begin + m_vector.size();
    }

    int* begin()
    {
        return m_begin;
    }

    int* end()
    {
        return m_end;
    }


};


int main()
{
    /*Написать функцию, добавляющую в конец списка вещественных чисел элемент,
      значение которого равно среднему арифметическому всех его элементов.    */

    std::cout << "\n\n---------- Task 1 ------------\n\n";
    std::list <double> myList = { 5.2, 3.0, 0.0, -18, 16.5, 4, 3.2, -20, 8, -8, -14.3 };

    PrintList(myList);
    PushBackAverage(myList);
    PrintList(myList);
    
    /*----------------------------------------------------------------------*/

    /*Создать класс, представляющий матрицу. Реализовать в нем метод, 
      вычисляющий определитель матрицы. Для простоты решения разрешаю 
      реализовать метод только для 1,2,3-размерной матриц            */

    std::cout << "\n\n---------- Task 2 ------------\n\n";
    std::vector<int> iMatrix = { 2, 4, 3, 5, 7, 8, 6, 9, 1 }; // Determinant = 51

    Matrix matrixThree(3, iMatrix);
    matrixThree.PrintMatrix();
    auto initialIntMatrix = matrixThree.GetMatrix();
    std::cout << "Determinant: " << matrixThree.Determinant(3, initialIntMatrix) << "\n\n";


    iMatrix = { 2, 4, 9, 1 }; // Determinant = 51

    Matrix matrixTwo(2, iMatrix);
    matrixTwo.PrintMatrix();
    initialIntMatrix = matrixTwo.GetMatrix();
    std::cout << "Determinant: " << matrixTwo.Determinant(2, initialIntMatrix) << "\n\n";
    

    /*----------------------------------------------------------------------*/

    /*Реализовать собственный класс итератора, с помощью которого можно будет
      проитерироваться по диапазону целых чисел в цикле for-range-based.     */

    std::cout << "\n\n---------- Task 3 ------------\n\n";






}
