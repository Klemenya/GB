#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

/* Имеется отсортированный массив целых чисел. Необходимо разработать функцию 
  insert_sorted, которая принимает вектор и новое число и вставляет новое число 
  в определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась. 
  Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать 
  с любым контейнером, содержащим любой тип значения.                           */

void InsertSorted(std::vector<int>& vec, int value)
{
	auto it = upper_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}


template<class C, class T>
void InsertSorted(C& container, T value)
{
	auto it = upper_bound(container.begin(), container.end(), value);
	container.insert(it, value);
}

template<class C>
void PrintContainer(C& vec)
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

double SignalError(std::vector<double> analogue, std::vector<int> digital)
{
	double result = 0.0;

	auto it = digital.begin();

	for_each(analogue.begin(), analogue.end(), 
		[&] (auto& val) { result += pow((val - *it), 2); ++it; });

	return result;
}

/*----------------------------------------------------------------------*/

int main()
{
	std::cout << "\n---------- Task 1 ------------\n";

	std::vector<int> vec{ 1, 2, 3, 5, 7, 9 };
	std::cout << "Before: " << std::endl;
	PrintContainer(vec);
	std::vector<std::string> strVec{ "aaa", "bbb", "ccc", "fff" };
	PrintContainer(strVec);
	std::deque<double> deq{ 0.1, 0.2, 0.4, 0.5 };
	PrintContainer(deq);
	std::string str = "abcefghj";
	PrintContainer(str);
	std::list<char> lst{ 'a', 'b', 'e', 'f' };
	PrintContainer(lst);
	
	std::cout << "After : " << std::endl;

	InsertSorted(vec, 4);
	InsertSorted(vec, 4);
	InsertSorted(vec, 6);
	InsertSorted(vec, 8);
	PrintContainer(vec);
	
	InsertSorted(strVec, "ddd");
	InsertSorted(strVec, "eee");
	PrintContainer(strVec);

	InsertSorted(deq, 0.3);
	PrintContainer(deq);
	
	InsertSorted(str, 'd');
	InsertSorted(str, 'i');
	PrintContainer(str);

	InsertSorted(lst, 'd');
	InsertSorted(lst, 'c');
	PrintContainer(lst);
	

	std::cout << "\n---------- Task 2 ------------\n";

	std::vector<double> analogueSignal(100);

	//srand(time(0));
	generate(analogueSignal.begin(), analogueSignal.end(),
		[]() { return (static_cast<double>(rand() % 100) / ((rand() % 10) + 1)); });

	PrintContainer(analogueSignal);

	std::vector<int> digitalSignal(100);

	copy(analogueSignal.begin(), analogueSignal.end(), digitalSignal.begin());
	PrintContainer(digitalSignal);

	std::cout << "Signal error = " << SignalError(analogueSignal, digitalSignal) << std::endl;
}