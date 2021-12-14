#pragma once
#include "FullName.h"
#include <map>
#include <numeric>

namespace University
{
    class Student : public FullName
    {
    public:
        Student(FullName& name, std::multimap<std::string, int> scores);

        FullName GetName() const;

        void PrintScores() const;

        double GetAverage() const;

        void RecalculateAverage();

        std::multimap<std::string, int> GetScores() const;

        friend std::ostream& operator <<(std::ostream& out, Student student);

    private:
        double CalculateAverage(std::multimap<std::string, int> scores);

        //FullName name_;
        std::multimap<std::string, int> scores_;
        double average_;
    };
}