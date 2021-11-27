#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h"
#include <fstream>
#include <any>




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

/*----------------------------------------------------------------------------------------*/
bool findFirstWay(unsigned char h)
{
    h = toupper(h);
    if (h == 'A' || h == 'E' || h == 'I' || h == 'O' || h == 'U')
    {
        return true;
    }
    return false;
}

int  firstWay(std::vector<unsigned char>& vec)
{

    return count_if(vec.begin(), vec.end(), findFirstWay);
}

bool findFirstWay1(unsigned char h)
{
    std::string s = "AEIOU";
    h = toupper(h);
    for (auto s1 : s)
    {
        if (h == s1)
            return true;
    }
    return false;
}

int  firstWay1(std::vector<unsigned char>& vec)
{

    return count_if(vec.begin(), vec.end(), findFirstWay1);
}

int  firstWay2(std::vector<unsigned char>& vec)
{
    int count = 0;
    std::string s = "AEIOU";
    for (auto& c : vec)
    {

        c = toupper(c);
        for (auto s1 : s)
        {
            if (c == s1)
            {
                count++;
                break;
            }

        }
    }
    return count;
}
/*-----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------*/
class Book
{
private:

    std::vector<std::string> allwords;


public:


    Book(std::ifstream& file)
    {
        if (!file.is_open())
        {
            std::cout << "Error open file !!!";
        }
        else
        {
            while (!file.eof())
            {
                std::string temp;
                file >> temp;
                allwords.push_back(temp);
            }

            std::string  searchSymbols = "AEIOUY";
            int counter = 0;


            Timer timer("Count_if - For");
            for (auto words : allwords)
            {
                counter += std::count_if(words.begin(), words.end(),
                    [&searchSymbols](char symbol)
                    {
                        for (char sS : searchSymbols)
                            if ((char)toupper(symbol) == sS)
                            {
                                return true;
                            }
                        return false;
                    });
            }
            
            timer.print();
            std::cout << counter << std::endl;


            counter = 0;
            timer.start("   For   - For");
            for (auto words : allwords)
            {
                for (auto letter : words)
                {
                    for (char sS : searchSymbols)
                    {
                        if ((char)toupper(letter) == sS)
                        {
                            counter++;
                        }
                    }
                }
            }
            timer.print();
            std::cout << counter << std::endl;
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

;   Swap(&ptrA, &ptrB);

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
