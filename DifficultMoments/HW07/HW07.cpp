
#include <iostream>
#include <fstream>
#include <numeric>
#include "Univer.pb.h"


using UFN = Univer::FullName;
using US = Univer::Student;
using USG = Univer::StudentsGroup;

int main()
{
    /*-----------------------------------------------------------*/
    UFN fName;
    fName.set_name("Pavel");
    fName.set_surname ("Klemenya");
    fName.set_patronymic("Anatolievich");

    US uStudent;
    *uStudent.mutable_name() = fName;
    uStudent.add_scores(5);
    uStudent.add_scores(4);
    uStudent.add_scores(3);
    uStudent.add_scores(6);
    uStudent.add_scores(7);
    uStudent.add_scores(8);
    uStudent.set_sc_average(std::accumulate(uStudent.scores().begin(), uStudent.scores().end(),0 ) / uStudent.scores().size());

    USG uSgroup;
    *uSgroup.add_students() = uStudent;
    
    std::ofstream out("student.bin", std::ios_base::binary);
    uSgroup.SerializeToOstream(&out);
    out.close();

    /*-----------------------------------------------------------*/
    USG sGroup2;
    std::ifstream in("student.bin", std::ios_base::binary);
    if (sGroup2.ParseFromIstream(&in))
    {
        std::cout << sGroup2.students(0).name().surname() << " ";
        std::cout << sGroup2.students(0).name().name() << " ";
        std::cout << sGroup2.students(0).name().patronymic() << std::endl;
        std::cout << sGroup2.students(0).sc_average() << std::endl;
    }
    else
    {
        std::cout << "ERROR !!!\n";
    }
    /*-----------------------------------------------------------*/



    return 0;
}
