#include "StudentsGroup.h"

namespace University
{
	StudentsGroup::StudentsGroup(std::vector<Student> students, std::string path)
		:students_(students), path_(path)
	{}

	void StudentsGroup::Open()
	{
		std::ifstream in(path_, std::ios::binary);
		allInfo_.resize(1024);
		in.read(allInfo_.data(), allInfo_.size());
		allInfo_.resize(in.gcount());
	}

	void StudentsGroup::Save()
	{
		std::ofstream out(path_, std::ios::binary);
		std::string tmp = this->GetAllInfo();
		out.write(tmp.c_str(), tmp.size());
	}

	double StudentsGroup::GetAverageScore(const FullName& name)
	{
		auto it = std::find_if(students_.begin(), students_.end(),
			[&name](Student student) { return student.GetName() == name; });
		if (it != students_.end())
		{
			Student tmp = *it;
			return tmp.GetAverage();
		}
		return 0.0;
	}

	std::string StudentsGroup::GetAllInfo(const FullName& name)
	{
		std::ostringstream info;

		auto it = std::find_if(students_.begin(), students_.end(),
			[&name](Student student) { return student.GetName() == name; });

		if (it != students_.end())
			info << *it;

		return info.str();
	}

	std::string StudentsGroup::GetAllInfo()
	{
		if (allInfo_.empty())
		{
			std::ostringstream info;

			for (auto it : students_)
				info << it;
			allInfo_ = info.str();
		}
		return allInfo_;
	}
}