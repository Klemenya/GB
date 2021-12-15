#include "Student.h"

namespace University
{
	Student::Student(FullName& name, std::multimap<std::string, int> scores)
		:FullName(name), scores_(scores)
	{
		average_ = CalculateAverage(scores);
	}

	FullName Student::GetName() const
	{
		return FullName(this->surname_, this->name_, this->patronymic_);
	}

	void Student::PrintScores() const
	{
		for (auto it : scores_)
			std::cout << it.first << ": " << it.second << std::endl;
	}

	double Student::GetAverage() const
	{
		return this->average_;
	}

	void University::Student::RecalculateAverage()
	{
		average_ = 0;
		for (auto it : scores_)
			average_ += it.second;
		average_ /= scores_.size();
	}

	std::multimap<std::string, int> Student::GetScores() const
	{
		return scores_;
	}

	double Student::CalculateAverage(std::multimap<std::string, int> scores)
	{
		double average = 0;
		for (auto it : scores)
			average += it.second;
		average /= scores.size();
		return average;
	}

	std::ostream& operator<<(std::ostream& out, Student student)
	{
		out << student.GetName().surname_ << " " << student.GetName().name_;
		if (student.GetName().patronymic_)
			out << " " << student.GetName().patronymic_.value() << '\n';
		else
			out << '\n';

		for (auto it : student.GetScores())
			out << it.first << ": " << it.second << '\n';

		out << "Average: " << student.GetAverage() << "\n\n";

		return out;
	}
}