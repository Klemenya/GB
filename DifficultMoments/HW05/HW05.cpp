#include <list>
#include <array>
#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <algorithm>
#include <string>

/* Создать шаблонную функцию, которая принимает итераторы на начало и конец 
   последовательности слов, и выводящую в консоль список уникальных слов (если 
   слово повторяется больше 1 раза, то вывести его надо один раз). 
   Продемонстрировать работу функции, передав итераторы различных типов.      */

template<typename T>
void PrintUnique(T begin, T end)
{
	std::vector<std::string> tmp;

	while (begin != end)
	{
		if (find(tmp.begin(), tmp.end(), *begin) == tmp.end())
		{
			tmp.push_back(*begin);
		}
		++begin;
	}

	for (auto sentence : tmp)
	{
		std::cout << sentence << "\t";
	}
	std::cout << std::endl;
}

void PrintUniqueS(std::string::iterator begin, std::string::iterator end)
{
	std::vector<std::string> tmp;

	std::string str;
	while (begin != end)
	{
		if (*begin != ' ')
		{
			str.push_back(*begin);
		}
		else
		{
			if (find(tmp.begin(), tmp.end(), str) == tmp.end())
			{
				tmp.push_back(str);
			}
			str.clear();
		}
		++begin;
	}
	
	for (auto sentence : tmp)
	{
		std::cout << sentence << "\t";
	}
	std::cout << std::endl;
}


/* Используя ассоциативный контейнер, напишите программу, которая будет 
   считывать данные введенные пользователем из стандартного потока ввода и 
   разбивать их на предложения. Далее программа должна вывести пользователю 
   все предложения, отсортировав их по длине.                                */

class SentenceSort
{
private:
	std::multimap<size_t, std::string>	m_dict;

public:
	void ParsingIntoSentences(std::string text)
	{
		size_t start = 0, newStart;
		std::string tmp;
		while (start < text.size())
		{
			newStart = FindSeparator(text, start);
			tmp = text.substr(start, (newStart - start) + 2);
			m_dict.insert({ tmp.size(), tmp });
			start = newStart + 2;
		}
	}

	size_t FindSeparator(std::string text, size_t offset)
	{
		std::vector<size_t> positions;
		positions.push_back(text.find('.', offset));
		positions.push_back(text.find('!', offset));
		positions.push_back(text.find('?', offset));

		auto it = std::min_element(positions.begin(), positions.end());
		if (*it != std::string::npos)
		{
			return *it;
		}
		return std::string::npos;
	}

	void Print()
	{
		std::for_each(m_dict.begin(), m_dict.end(), [](auto& val) {std::cout << val.second << std::endl; });
	}
};


int main()
{
	/* Alpha, Beta, Gamma, Delta, Epsilon,
	/  Zeta, Eta, Theta, Iota, Kappa, Lambda,
	/  Mu, Nu, Xi, Omicron, Pi, Rho, Sigma, 
	/  Tau, Upsilon, Phi, Chi, Psi, Omega    */

	/*----------------------------------------------------------------------*/
	std::cout << "\n---------- Task 1 ------------\n";
	
	std::vector<std::string> vStr{ "Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Alpha", "Beta", "Zeta", "Zeta" };
	std::cout << "Vector -> ";
	PrintUnique(vStr.begin(), vStr.end());

	std::list<std::string> lStr{ "Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Alpha", "Beta", "Zeta", "Zeta" };
	std::cout << "List   -> ";
	PrintUnique(lStr.begin(), lStr.end());

	std::string sStr{ "Alpha Beta Gamma Delta Epsilon Alpha Beta Zeta Zeta" };
	std::cout << "String -> ";
	PrintUniqueS(sStr.begin(), sStr.end());

	std::array<std::string, 12> aStr{ "Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Alpha", "Beta", "Zeta", "Zeta" };
	std::cout << "Array  -> ";
	PrintUnique(aStr.begin(), aStr.end());

	std::cout << "\n---------- Task 2 ------------\n";

	std::string text;
	std::cout << "Enter text: ";
	std::getline(std::cin, text);
	
	SentenceSort vec;
	vec.ParsingIntoSentences(text);
	vec.Print();
}