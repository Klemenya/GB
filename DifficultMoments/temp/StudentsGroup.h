#pragma once
#include "Student.h"
#include "IRepository.h"
#include "IMethods.h"
#include <vector>
#include <sstream>
#include <fstream>

namespace University
{
	class StudentsGroup : public IRepository, IMethods
	{
	public:
		StudentsGroup(std::vector<Student> students, std::string path);

		virtual void Open() override;

		virtual void Save() override;

		virtual double GetAverageScore(const FullName& name) override;

		virtual std::string GetAllInfo(const FullName& name) override;

		virtual std::string GetAllInfo() override;

	private:
		std::vector<Student> students_;
		std::string path_;
		std::string allInfo_;
	};
}