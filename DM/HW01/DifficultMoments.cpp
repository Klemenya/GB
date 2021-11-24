#include <iostream>
#include <fstream>
#include <tuple>
#include <optional>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>



struct Person
{
    std::string surname;
    std::string firstname;
    std::optional <std::string> patronymic;

    bool operator < (const Person& _person)
    {
        return (std::tie(surname, firstname, patronymic) < std::tie(_person.surname, _person.firstname, _person.patronymic));
    }

    bool operator == (const Person& _person)
    {
        return (std::tie(surname, firstname, patronymic) == std::tie(_person.surname, _person.firstname, _person.patronymic));
    }
};

struct PhoneNumber
{
    int countryCode;
    int cityCode;
    std::string shortNumber;
    std::optional<int> additionalNumber;

    bool operator < (const PhoneNumber& _phoneNumber)
    {
        return (std::tie(countryCode, cityCode, shortNumber, additionalNumber) <
            std::tie(_phoneNumber.countryCode, _phoneNumber.cityCode, _phoneNumber.shortNumber, _phoneNumber.additionalNumber));
    }

    bool operator == (const PhoneNumber& _phoneNumber)
    {
        return (std::tie(countryCode, cityCode, shortNumber, additionalNumber) ==
            std::tie(_phoneNumber.countryCode, _phoneNumber.cityCode, _phoneNumber.shortNumber, _phoneNumber.additionalNumber));
    }
};

class PhoneBook 
{
    std::vector <std::pair<Person, PhoneNumber>> m_phoneBook;

public:
   
    PhoneBook(std::ifstream& fin)
    {
        if (!fin.is_open())
        {
            std::cout << "Error open file !!!";
        }
        else
        {
            while (!fin.eof())
            {
                std::pair<Person, PhoneNumber> contact;
                Person _person;
                PhoneNumber _phoneNumber;
                std::string temp = "";

                fin >> _person.surname;
                fin >> _person.firstname;
                fin >> temp; if (temp != "-") { _person.patronymic = temp; }
                
                fin >> _phoneNumber.countryCode;
                fin >> _phoneNumber.cityCode;
                fin >> _phoneNumber.shortNumber;         
                fin >> temp; if (temp != "-") { _phoneNumber.additionalNumber = stoi(temp); }

                contact.first = _person;
                contact.second = _phoneNumber;
                
                m_phoneBook.push_back(contact);
            }
        }
    }

    std::vector <std::pair<Person, PhoneNumber>> & GetPhoneBook() 
    {
        return m_phoneBook;
    };
    
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname) 
    {
        size_t counter = 0;
        PhoneNumber num;
        for (auto record : m_phoneBook)
        {
            if (surname == record.first.surname) {
                ++counter;
                num = record.second;
                
            }
        }

        if (counter == 0)
        {
            return std::make_tuple("not found",num);
        }
        else if (counter == 1)
        {
            return std::make_tuple("", num);
        }
        else
        {
            return std::make_tuple("found more then 1", num);
        }
    }
    
    void ChangePhoneNumber(const Person& person, PhoneNumber newPhoneNumber) 
    {
        for (auto contact : m_phoneBook)
        {
            if ((const_cast<Person&>(person)) == contact.first)
            {
                contact.second = newPhoneNumber;
            }
        }        
    }
    
    void SortByPhone() 
    {
        std::sort(m_phoneBook.begin(), m_phoneBook.end(), [](std::pair<Person, PhoneNumber>& left, std::pair<Person, PhoneNumber>& right) {
            return left.second < right.second; });
    }
    
    void SortByName() 
    {
        std::sort(m_phoneBook.begin(), m_phoneBook.end(), [](std::pair<Person, PhoneNumber>& left, std::pair<Person, PhoneNumber>& right) {
            return left.first < right.first; });
    }
};


std::ostream& operator<< (std::ostream& out, const Person& _person)
{
    out << std::setw(11) << _person.surname << ' ' << std::setw(10) << _person.firstname << " ";
    out << std::setw(16) << std::right << (_person.patronymic.has_value() ? _person.patronymic.value_or("") : " ");
    
    return out;
}

std::ostream& operator<< (std::ostream& out, const PhoneNumber& _phoneNumber)
{
    out << '+' << _phoneNumber.countryCode << '(' << _phoneNumber.cityCode << ')' << _phoneNumber.shortNumber; 
    if (_phoneNumber.additionalNumber.has_value())
    {
        out << " " << _phoneNumber.additionalNumber.value();
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, PhoneBook& _phoneBook) 
{
    std::for_each (_phoneBook.GetPhoneBook().begin(), _phoneBook.GetPhoneBook().end(), 
        [&](std::pair<Person, PhoneNumber>& contact) { out << contact.first << " " << contact.second << std::endl;} );
    return out;
}


int main()
{
    std::ifstream file("PhoneBook.txt");
    PhoneBook book(file);
    std::cout << book;
    
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;
    
    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;
    
    std::cout << "-----GetPhoneNumber-----" << std::endl;
    
    auto print_phone_number = [&book](const std::string& surname) { 
                    std::cout << surname << "\t";
                    auto answer = book.GetPhoneNumber(surname);
                    if (std::get<0>(answer).empty()) 
                        { std::cout << std::get<1>(answer); }
                    else 
                        { std::cout << std::get<0>(answer);}
                    std::cout << std::endl; };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    print_phone_number("Solovev");
    
    std::cout << "----ChangePhoneNumber----" << std::endl;
    
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{7, 123, "15344458", std::nullopt});
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    
    std::cout << book;
}