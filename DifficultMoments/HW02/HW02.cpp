#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Timer.h"








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

/*----------------------------------------------------------------------------------------*/
class Book
{
    std::vector<char>lettersBooks = {};
    std::vector<char>vowels = { 'E','Y','U','I','O','A' };
    int countLettersBook = 0;
    int countVowelsLetters = 0;


public:
    Book(std::ifstream& file)
    {
        if (!file.is_open())
        {
            std::cout << "Error opening file !" << std::endl;
        }
        else
        {
            while (!file.eof())
            {
                std::string temp;
                char ch = file.get();
                lettersBooks.push_back(ch);
            }
        }
    }

    void GetCountLetter()
    {
        for (auto c : lettersBooks)
        {
            if( (c >64 && c<123) && (c < 91 || c > 96) )
            {
                ++countLettersBook;
            }

        }
        std::cout << "In this book " << countLettersBook << " latin letters  --> ";
    }

    void ForFor()
    {
        for (auto l : lettersBooks)
        {
            for (auto v : vowels)
            {
                if (toupper(l) == v)
                {
                    ++countVowelsLetters;
                }
            }
        }
        PrintRes(countVowelsLetters);
    }

    void CountifFor()
    {
        for (auto v : vowels)
        {
            countVowelsLetters += std::count_if(lettersBooks.begin(), lettersBooks.end(),
                [=](auto l) {return (toupper(l) == v); });
        }
        PrintRes(countVowelsLetters);
    }

    void ForFind()
    {
        for (auto l : lettersBooks)
        {
            if (std::find(vowels.begin(), vowels.end(), toupper(l)) != vowels.end())
            {
                ++countVowelsLetters;
            }
        }
        PrintRes(countVowelsLetters);
    }

    void CountifFind()
    {
        countVowelsLetters = std::count_if(lettersBooks.begin(), lettersBooks.end(),
            [=](char c) {if (std::find(vowels.begin(), vowels.end(), toupper(c)) != vowels.end()) { return true; }return false; });
        PrintRes(countVowelsLetters);
    }

    void PrintRes(int x)
    {
        std::cout << "In this book " << x << " vowels letters --> ";
        countVowelsLetters = 0;
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
        std::cout << v << ' ' << *v << std::endl;

    vectorSort(myVector);
    std::cout << "-------- After sort --------------\n";

    for (auto v : myVector)
        std::cout << v << ' ' << *v << std::endl;

    /* ----------------------------------------------------------------------------------------------*/

    std::cout << "\n -------- Task 3 (--------------\n";
    std::ifstream file("War and peace.txt");
    Book book(file);

    Timer timer("Get all letters");
    book.GetCountLetter();
    timer.print();

    timer.start("For For        ");
    book.ForFor();
    timer.print();

    timer.start("Count_if For   ");
    book.CountifFor();
    timer.print();

    timer.start("Find For       ");
    book.ForFind();
    timer.print();

    timer.start("Count_if Find  ");
    book.CountifFind();
    timer.print();
}
