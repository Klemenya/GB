#include <iostream>
#include <thread>
#include <mutex>
//#include <random>
#include <stdlib.h>
//#include <chrono>


/*----------------------------------------------------------------------*/
/*
	Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout.
	Необходимо, чтобы несколько потоков могли обращаться к pcout
	и информация выводилась в консоль. Продемонстрируйте работу pcout.  */

std::mutex m;

template<class T>
void pcout(T data)
{
	m.lock();
	std::cout << "Data:\t" << data << "\nThread id:\t" << std::this_thread::get_id() << "\n\n";
	m.unlock();
}

/*----------------------------------------------------------------------*/
/*  Реализовать функцию, возвращающую i-ое простое число (например, 
    миллионное простое число равно 15485863). Вычисления реализовать 
	во вторичном потоке. В консоли отображать прогресс вычисления.      */



bool SimplePrimalityTest(int value)
{
	if (value > 1 && value < 4)
		return true;
	for (int i = 3; i < value; ++i)
	{
		if (value % i == 0)
			return false;
	}
	return true;
}


int PrimeNumber(int findNum)
{
	int counter = 1;			// 2

	for (size_t i = 3; counter != findNum; i+=2)
	{
		system("cls");
		std::cout << "Progress: " << (static_cast<double>(counter) / findNum) * 100 << "%";
		if (SimplePrimalityTest(i))
		{
			++counter;
		}

		if (counter == findNum)
			return i;
	}
	return -1;
}



int main()
{
	/*----------------------------------------------------------------------*/
	std::cout << "\n---------- Task 1 ------------\n";

	std::thread th1(pcout<std::string>, "First");
	std::thread th2(pcout<std::string>, "Second");
	std::thread th3(pcout<int>, 25);

	th1.join();
	th2.join();
	th3.join();

	/*----------------------------------------------------------------------*/
	std::cout << "\n---------- Task 2 ------------\n";

	std::cout << "press any button to find 100 prime numbers.\n";
	std::cin.get();
	int result = 0;
	std::thread CPT([&result]() { result = PrimeNumber(100); });
	CPT.join();
	std::cout << "\nrequired number is: " << result;

	/*----------------------------------------------------------------------*/
	std::cout << "\n---------- Task 3 ------------\n";

}