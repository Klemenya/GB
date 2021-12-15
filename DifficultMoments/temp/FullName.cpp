#include "FullName.h"

namespace University
{
	FullName::FullName(std::string surname, std::string name)
		:FullName(surname, name, std::nullopt)
	{}

	FullName::FullName(std::string surname, std::string name, std::optional<std::string> patronymic)
		: surname_(surname), name_(name), patronymic_(patronymic)
	{}

	bool FullName::operator==(FullName other)
	{
		return std::tie(this->surname_, this->name_, this->patronymic_)
			== std::tie(other.surname_, other.name_, other.patronymic_);
	}
}