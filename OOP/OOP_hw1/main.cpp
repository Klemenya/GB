#include <iostream>
#include <cmath>
#include <cstdint>


class Power
{
private:
	float m_basis;
	float m_exponent;

public:

    Power()
    {
        m_basis = 2.0;
        m_exponent = 2.0;
    }

	~Power() { }

	void set(float _basis, float _exponent)
	{
		m_basis = _basis;
		m_exponent = _exponent;
	}
	void calculate()
	{
		std::cout << "Number A(" << m_basis << ") to power B(" << m_exponent << ") = " << pow(m_basis, m_exponent) << std::endl;
	}
};


class RGBA
{
private:

    std::uint8_t m_red, m_green, m_blue, m_alpha;

public:

    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : m_red(r), m_green(g), m_blue(b), m_alpha(a)
    {
    }

    RGBA()
    {
        m_red   = 0;
        m_green = 0;
        m_blue  = 0;
        m_alpha = 255;
    }

    ~RGBA() { }

    void print()
    {
        std::cout << "Red:   " << +m_red   << std::endl;
        std::cout << "Green: " << +m_green << std::endl;
        std::cout << "Blue:  " << +m_blue  << std::endl;
        std::cout << "Alpha: " << +m_alpha << std::endl;
    }
};


class Stack
{
    int arr [10]{};
    int lenStack;

public:

    Stack()
    {
        std::fill_n(arr, 10, 0);
        lenStack = 0;
    }

//    Stack(int len, int first, ...)                // делал для быстрого заполнения
//    {                                             // при отладке - проверке
//        lenStack = len-1;                         // работало только под виндой
//        int *p = &first;                          // под убунту и в онлайн - мусор
//        for(int i=0;i<len;i++)                    // пока не разобрался
//        {
//            arr[i] = *p;
//            p++;
//        }
//    }

    void reset()
    {
        std::fill_n(arr, 10, 0);
        lenStack = 0;
    };

    bool push(int val)
    {
        if(lenStack >=0 && lenStack < 10)
        {
            arr[lenStack] = val;
            lenStack++;
            return true;
        }
        else
        {
            return false;
        }
    };

    int pop()
    {
        if(lenStack == 0)
        {
            std::cout << "\nSTACK is EMPTY!!!";
        }
        else
        {
            int tmp = arr[lenStack-1];
            //std::cout << "\nPOP " << lenStack << " element. It contained " << arr[lenStack-1];
            arr[lenStack-1] = 0;
            lenStack--;
            return tmp;
        }
    return 0;
    };

    void print()
    {
        std::cout <<"\n(";
        for(int i=0;i<lenStack;i++)
        {
            std::cout <<" "<<arr[i];
        }
        std::cout <<" )";

    };

};





int main ()
{

    std::cout <<"\n------------- TASK 1 -------------\n";
	Power varOne;
	Power varTwo;

	float a,b;

	std::cout << "Enter a (basis)   : ";
	std::cin >> a;
	std::cout << "Enter b (exponent): ";
	std::cin >> b;
	varOne.set(a, b);
	std::cout << std::endl <<"custom data method:\n";
	varOne.calculate();
	std::cout << std::endl << "method with default values:\n";
	varTwo.calculate();


    std::cout <<"\n------------- TASK 2 -------------\n";
    std::cout << std::endl;
    RGBA colorTwo;
    std::uint8_t red = 5, green =5 , blue=5, alpha=100;
    RGBA colorOne(red,green, blue, alpha);

    colorOne.print();
    std::cout << std::endl;
    colorTwo.print();


    std::cout <<"\n------------- TASK 3 -------------";
    std::cout << std::boolalpha;

    std::cout << "\n\n *** Create stack with 10 elements";

    //Stack stackB(10, 1,2,3,4,5,6,7,8,9,10);               // делал для Stack(int len, int first, ...)

    Stack stackB;
    for(int i = 0; i<10;i++)
    {
        stackB.push(i+1);
    }
    stackB.print();

    std::cout << "\n\n *** Trying to add a value to the stack";
    stackB.push(11);
    stackB.print();
    std::cout << "\nResponse from class object - " << stackB.push(11);

    std::cout << "\n\n *** Reset stack";
    stackB.reset();
    stackB.print();

    std::cout << "\n\n *** Trying to pop a value from an empty stack";
    stackB.pop();
    stackB.print();

    std::cout << "\n\n *** Push 1, Push 2, Push 3, Push 11";
    stackB.push(1);
    stackB.push(2);
    stackB.push(3);
    std::cout << "\nResponse from class object - " << stackB.push(11);
    stackB.print();

    std::cout << "\n\n *** Pop a value from a non-empty stack";
    std::cout << "\nPOP " << stackB.pop();
    //stackB.pop();
    stackB.print();

    std::cout << "\n\n *** Pop,Pop,Pop and Pop";
    stackB.pop();
    stackB.pop();
    stackB.pop();
    stackB.pop();
    stackB.print();



	return 0;

}
