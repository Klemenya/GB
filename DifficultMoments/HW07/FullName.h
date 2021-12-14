#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <tuple>

namespace University
{
	struct FullName
	{
		FullName(std::string surname, std::string name);
		FullName(std::string surname, std::string name, std::optional<std::string> patronymic);
		bool operator==(FullName other);
		std::string surname_;
		std::string name_;
		std::optional<std::string> patronymic_;
	};
}