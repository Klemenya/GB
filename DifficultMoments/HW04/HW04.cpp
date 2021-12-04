#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
//#include <random>
#include <iomanip>

using namespace std;

/* Имеется отсортированный массив целых чисел. Необходимо разработать функцию 
  insert_sorted, которая принимает вектор и новое число и вставляет новое число 
  в определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась. 
  Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать 
  с любым контейнером, содержащим любой тип значения.                           */

void insert_sorted(std::vector<int>& vec, int value)
{
	auto it = upper_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}


template<class C, class T>
void insert_sorted(C& container, T value)
{
	auto it = upper_bound(container.begin(), container.end(), value);
	container.insert(it, value);
}

template<class C>
void printContainer(C& vec)
{
	
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		std::cout << "[" << *i << "]";
	}	
	std::cout << std::endl;
}


/*----------------------------------------------------------------------*/

/* Cгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий 
  собой значения аналогового сигнала. На основе этого массива чисел создайте 
  другой вектор целых чисел b, представляющий цифровой сигнал, в котором будут 
  откинуты дробные части чисел. Выведите получившиеся массивы чисел. Посчитайте 
  ошибку, которой обладает цифровой сигнал по сравнению с аналоговым по формуле
  (указана в методичке)

	N-1
	SUM =  POW ( (a[i]-b[i]) , 2 )
	i=0
*/

double getSignalError(std::vector<double> analogue, std::vector<int> digital)
{
	double result = 0.0;

	auto it = digital.begin();

	for_each(analogue.begin(), analogue.end(), 
		[&] (auto& val) { result += pow((val - *it), 2); ++it; });

	return result;
}

template <class S>
void printSignal(S& vec)
{
	int count = 0;
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		//std::cout << std::fixed << std::setprecision(10);
		std::cout << std::left << std::setw(8) << *i ;
		//std::cout << std::right << *i << '\t';
			

	}
	std::cout << std::endl;
}


/*----------------------------------------------------------------------*/

int main()
{
	std::cout << "\n---------- Task 1 ------------\n";

	std::vector<int> vec{ 1, 2, 3, 5, 7, 9 };
	std::cout << "Before: " << std::endl;
	
	printContainer(vec);
	std::vector<std::string> strVec{ "aaa", "bbb", "ccc", "fff" };
	printContainer(strVec);
	std::deque<double> deq{ 0.1, 0.2, 0.4, 0.5 };
	printContainer(deq);
	std::string str = "abcefghj";
	printContainer(str);
	std::list<char> lst{ 'a', 'b', 'e', 'f' };
	printContainer(lst);
	
	std::cout << "After : " << std::endl;

	insert_sorted(vec, 4);
	insert_sorted(vec, 4);
	insert_sorted(vec, 6);
	insert_sorted(vec, 8);
	printContainer(vec);
	
	insert_sorted(strVec, "ddd");
	insert_sorted(strVec, "eee");
	printContainer(strVec);

	insert_sorted(deq, 0.3);
	printContainer(deq);
	
	insert_sorted(str, 'd');
	insert_sorted(str, 'i');
	printContainer(str);

	insert_sorted(lst, 'd');
	insert_sorted(lst, 'c');
	printContainer(lst);
	

	std::cout << "\n---------- Task 2 ------------\n";

	std::vector<double> analogueSignal(100);

	generate(analogueSignal.begin(), analogueSignal.end(),
		[]() { return (static_cast<double>(rand() % 100) / ((rand() % 10) + 1)); });

	printSignal(analogueSignal);

	std::vector<int> digitalSignal(100);

	copy(analogueSignal.begin(), analogueSignal.end(), digitalSignal.begin());
	printSignal(digitalSignal);

	std::cout << "Signal error = " << getSignalError(analogueSignal, digitalSignal) << std::endl;
}