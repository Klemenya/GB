#pragma once
#include <string>
#include "FullName.h"

namespace University
{
    class IMethods
    {
        virtual double GetAverageScore(const FullName& name) = 0;
        virtual std::string GetAllInfo(const FullName& name) = 0;
        virtual std::string GetAllInfo() = 0;
    };
}