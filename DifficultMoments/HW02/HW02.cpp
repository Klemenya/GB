#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h"
#include <fstream>
#include <string>




template <typename T>
void Swap(T** Left, T** Right)
{
    T* temp = *Left;
    *Left = *Right;
    *Right = temp;
}

template <typename T>
void vectorSort(std::vector <T>& v)
{
    std::sort(v.begin(), v.end(), [](T left, T right) {return *left < *right; });
}


class Book
{
    std::vector<std::string> vParagraph;

public:
    
    Book(std::ifstream& file)
    {
        if (!file.is_open())
        {
            std::cout << "Error open file !!!";
        }
        else
        {
            int cntParagraph = 0;
            int cntVowels = 0;
            std::string vowels = "EYUIOA";
            std::string paragraph;

            while (std::getline(file, paragraph))
            {
                vParagraph.push_back(paragraph);
            }

            /*---------------------------*/
            Timer timer("for - for");
            for (auto v : vParagraph)
            {                
                for (int i = 0; i < v.size() && v.size() >0; i++)
                {    
                    if (std::toupper(v[i]) == 'E' || std::toupper(v[i]) == 'Y' ||
                        std::toupper(v[i]) == 'U' || std::toupper(v[i]) == 'I' ||
                        std::toupper(v[i]) == 'O' || std::toupper(v[i]) == 'A')
                    {
                        ++cntVowels;
                        //std::cout << v[i];
                    };
                }
            }
            timer.print();

            /*---------------------------*/
            std::cout << "cntVowels = " << cntVowels << '\n';

            for (auto v : vParagraph)
            {
                cntParagraph++;
            }
                

            std::cout << "cntParagraph = " << cntParagraph << std::endl;
            //std::cout << vParagraph.at(28000);
            //std::cout << vParagraph.at(27000);

            

        }
    }


};




int main()
{
    /* ----------------------------------------------------------------------------------------------*/
    int a = 1;
    int b = 2;
    int* ptrA = &a;
    int* ptrB = &b;
    std::cout << "\n -------- Task 1 --------------\n";
    std::cout << "a = " << a << " [ " << &a << " ]" << "\tptrA = " << ptrA << " [ " << &ptrA << " ]";
    std::cout << "  ||  ";
    std::cout << "b = " << b << " [ " << &b << " ]" << "\tptrB = " << ptrB << " [ " << &ptrB << " ]";
    std::cout << std::endl;

    Swap(&ptrA, &ptrB);

    std::cout << "a = " << a << " [ " << &a << " ]" << "\tptrA = " << ptrA << " [ " << &ptrA << " ]";
    std::cout << "  ||  ";
    std::cout << "b = " << b << " [ " << &b << " ]" << "\tptrB = " << ptrB << " [ " << &ptrB << " ]";
    std::cout << std::endl;

    /* ----------------------------------------------------------------------------------------------*/

    std::cout << "\n -------- Task 2 --------------\n";
    std::vector<int*> myVector;
    for (int i = 0; i < 10; ++i)
        myVector.push_back(new int(rand() % 10));

    for (auto v : myVector)
        std::cout << v << ' ' << *v << '\n';

    vectorSort(myVector);
    std::cout << "-------- After sort --------------\n";

    for (auto v : myVector)
        std::cout << v << ' ' << *v << '\n';



    /*----------------------------------------------------------------*/

    std::cout << "\n -------- Task 3 (in progress ( --------------\n";
    std::ifstream file("War and peace.txt");
    Book book(file);

    //std::getchar();

}
