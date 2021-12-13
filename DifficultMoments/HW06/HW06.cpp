#include <iostream>
#include <thread>
#include <mutex>
#include <set>
#include <chrono>

//using namespace std;



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

	for (int i = 3; counter != findNum; i+=2)
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

/*----------------------------------------------------------------------*/
/*  Промоделировать следующую ситуацию. Есть два человека (2 потока): 
    хозяин и вор. Хозяин приносит домой вещи (функция добавляющая 
	случайное число в вектор с периодичностью 1 раз в секунду). При этом 
	у каждой вещи есть своя ценность. Вор забирает вещи (функция, которая 
	находит наибольшее число и удаляет из вектора с периодичностью 1 раз 
	в 0.5 секунд), каждый раз забирает вещь с наибольшей ценностью.     */

std::multiset<int> things = { 50, 45, 80, 12, 67, 54, 30, 90, 5, 8 };

void printThings(std::multiset<int> t, std::string str)
{
	m.lock();
	std::cout << str;
	for (int t : things)
	{
		std::cout << t << ' ';
	}
	std::cout << std::endl;

	m.unlock();
}



class Master
{
public:
	void pushthing()
	{
		while (!things.empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			int n = rand() % 100 + 1;
			if (!things.empty())
			{
				things.insert(n);
				printThings(things, "master -> ");
			}	
		}
	}
};

class Thief
{
public:
	void popthing()
	{
		while (!things.empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			if (!things.empty())
			{
				things.erase(std::prev(things.end()));
				printThings(things, "thief  -> ");
			}
		}
	}
};



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
	Master master;
	Thief thief;

	std::thread mas([&]() {master.pushthing(); });
	std::thread thf([&]() {thief.popthing(); });

	mas.join();
	thf.join();

	return 0;
}