#include <iostream>
#include "StudentsGroup.h"

using std::vector;
using std::multimap;
using std::string;
using std::cout;

using UFN = University::FullName;
using US = University::Student;
using USG = University::StudentsGroup;

int main()
{
	multimap<string, int> fScores{ {"Math", 5}, {"Math", 4}, {"Math", 3}, {"Math", 5},
								{"Literature", 5}, {"Literature", 5}, {"Literature", 4},
								{"Physics", 3}, {"Physics", 4}, {"Physics", 4}, {"Physics", 5} };

	UFN fName("Frolov", "Sergey", "Alexeevich");
	US fStudent(fName, fScores);

	multimap<string, int> sScores{ {"Math", 3}, {"Math", 4}, {"Math", 3}, {"Math", 5},
							{"Literature", 4}, {"Literature", 4}, {"Literature", 4},
							{"Physics", 3}, {"Physics", 4}, {"Physics", 3}, {"Physics", 4} };

	UFN sName("Berezov", "Roman", "Denisovich");
	US sStudent(sName, sScores);

	multimap<string, int> tScores{ {"Math", 5}, {"Math", 5}, {"Math", 4}, {"Math", 5},
							{"Literature", 3}, {"Literature", 4}, {"Literature", 3},
							{"Physics", 5}, {"Physics", 5}, {"Physics", 4}, {"Physics", 5} };

	UFN tName("Petrov", "Alexandr");
	US tStudent(tName, tScores);

	vector<US> students;
	students.push_back(fStudent);
	students.push_back(sStudent);
	students.push_back(tStudent);

	USG group(students, "group.bin");

	group.Save();

	cout << group.GetAllInfo() << "\n\n";

	cout << group.GetAllInfo(tName) << "\n\n";

	cout << group.GetAverageScore(sName) << "\n\n";

	cout << tStudent;
}