#include <iostream>
#include <thread>
#include <mutex>
//#include "TakeAndRun.h"
#include <random>
#include <stdlib.h>
#include <chrono>
//#include <d:/UsefulHeaders/Timer.h>

//using std::thread;
//using std::cout;
//using std::endl;

std::mutex mtx;

class Storage
{
public:

	Storage(std::initializer_list<std::string> data)
	{
		for (auto& val : data)
			data_.push_back(val);
	}

	friend std::ostream& operator <<(std::ostream& out, Storage& storage);

private:
	std::vector<std::string> data_;
};

std::ostream& operator <<(std::ostream& out, Storage& storage)
{
	std::this_thread::sleep_for(std::chrono::nanoseconds(100));
	for (auto& val : storage.data_)
		out << val << " ";
	return out;
}

//=============== EX.1 ===============

/*
*	Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout.
*	Необходимо, чтобы несколько потоков могли обращаться к pcout
*	и информация выводилась в консоль. Продемонстрируйте работу pcout.
*/
template<class T>
void pcout(T data)
{
	mtx.lock();
	std::cout << "Data:\t" << data << "\nThread id:\t" << std::this_thread::get_id() << "\n\n";
	mtx.unlock();
}

//====================================

//=============== EX.2 ===============

int32_t GetRandomNum(int32_t min, int32_t max)
{
	const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::mt19937_64 generator(seed);
	std::uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

int GreatestCommonDivisor(int lhs, int rhs)
{
	if (lhs < rhs)
		return GreatestCommonDivisor(rhs, lhs);
	else if (lhs % rhs == 0)
		return rhs;
	else
		return GreatestCommonDivisor(rhs, lhs % rhs);
}

int PowAndMod(int base, int power, int mod)
{
	int result = 1;
	base %= mod;

	while (power > 0)
	{
		if (power % 2 == 1)
			result = (result * base) % mod;

		power /= 2;
		base = (base * base) % mod;
	}
	return result;
}

bool FermatPrimalityTest(int value, int repeats)		// Тест простоты на основе малой теоремы Ферма: a^(n-1) % n = 1 
{														// где а - любое число, которое не делится на n
	if (value <= 1 || value == 4)						// n - некоторое простое число
		return false;
	if (value <= 3)
		return true;

	for (size_t i = 0; i < repeats; ++i)
	{
		int randomNum = 2 + GetRandomNum(0, value - 4);

		if (GreatestCommonDivisor(value, randomNum) != 1)
			return false;

		if (PowAndMod(randomNum, value - 1, value) != 1)
			return false;
	}

	return true;
}

bool SimplePrimalityTest(int value)
{
	if (value > 1 && value < 4)
		return true;
	for (size_t i = 2; i < value; ++i)
	{
		if (value % i == 0)
			return false;
	}
	return true;
}

/*
*	Реализовать функцию, возвращающую i-ое простое число
*	(например, миллионное простое число равно 15485863).
*	Вычисления реализовать во вторичном потоке.
*	В консоли отображать прогресс вычисления.
*/
int PrimeNumber(int ordinalNum)
{
	int counter = 0;
	for (size_t i = 2; counter != ordinalNum; ++i)
	{
		std::cout << "Progress: " << (static_cast<double>(counter) / ordinalNum) * 100 << "%";
		if (counter < 100)
		{
			if (SimplePrimalityTest(i))
				++counter;
		}
		else
		{
			if (FermatPrimalityTest(i, 3))
				++counter;
		}

		system("cls");

		if (counter == ordinalNum)
			return i;
	}
	return -1;
}

//====================================

//=============== EX.3 ===============

//const int TakeAndRun::maxPrice_ = 10'000;
//
//std::map<int, std::string> TakeAndRun::collection_ = {
//	{TakeAndRun::maxPrice_, "Diamond neclace"},
//	{9000, "TV"},
//	{8500, "Computer"},
//	{5000, "Suit"},
//	{3000, "Cash"} };

//====================================

int main()
{
	std::cout << "================== EX.1 ==================\n\n";

	//std::mutex mtx;

	std::cout << "main() thread id = " << std::this_thread::get_id() << "\n\n";

	Storage storage{ "Hello world!", "My name is Daniil.", "How are you?" };
	std::thread thStor(pcout<Storage>, storage);

	std::thread thStr(pcout<std::string>, "Hello world!");

	std::thread thInt(pcout<int>, 25);

	thStor.join();
	thStr.join();
	thInt.join();

	std::cout << "================== EX.2 ==================\n\n";

	std::cout << "Press any key.\n";
	std::cin.get();
	int result = 0;
	std::thread CalculatePrimeTh([&result]() { result = PrimeNumber(10); });
	CalculatePrimeTh.join();
	std::cout << result;

	/*cout << "\n\n================== EX.3 ==================\n\n";

	TakeAndRun game(9000, "Spoon");
	game.AddItems(1, 10000, "Diamond necklace");
	game.AddItems(4, 100, "Spoon");
	game.AddItems(2, 9000, "Emerald necklace");
	game.AddItems(3, 5000, "Suit");

	game.PrintStorage();

	Timer timer("Thief has stolen everything in");

	thread host([&game]() { game.BringThing(); });

	thread thief([&game]() { game.TakeThing(); });

	host.detach();
	thief.join();

	timer.print();*/
}