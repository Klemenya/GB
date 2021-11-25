#include <iostream>
#include <vector>

#include <iostream>
#include <any>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

template <typename T>
void Swap (T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
template <typename T1>
void Swap2(T1** a, T1** b) {
		T1* temp = *a;
		*a = *b;
		*b = temp;;
}
void printVariable (int a, int b, int* pA, int* pB, int** ppA, int** ppB){
    cout << "A = " << a << " ["<<&a<<"] " <<"  " << "B = " << b << " ["<<&b<<"] " << '\t';
    cout << "*pA = " << " [" << *pA << "] " << "*pB = " << " [" << *pB << "] " <<'\t' ;
    cout << "**ppA = " << " [" << **ppA << "] " << "**ppB = " << " [" << **ppB << "] " <<'\n';
}

template <typename T>
void vectorSort(vector <T>& v){
	sort(v.begin(), v.end(), [](T left, T right)
                                {return *left < *right;});
}





int main()
{
/*---------------------------------------------------------*/
    int a = 1;
    int b = 2;
    int* pA = &a;
    int* pB = &b;
    int** ppA = &pA;
    int** ppB = &pB;

    printVariable (a, b, pA, pB, ppA, ppB);
    Swap (ppA, ppB);
    cout << "--------Swap (ppA, ppB)----------------------\n";
    printVariable (a, b, pA, pB, ppA, ppB);

    pA = &a;
    pB = &b;
    ppA = &pA;
    ppB = &pB;
    Swap2 (ppA, ppB);
    cout << "--------Swap2(ppA, ppB)----------------------\n";
    printVariable (a, b, pA, pB, ppA, ppB);


    /*---------------------------------------------------------*/
    vector<int*> myVector;
    for(int i=0; i<10;++i)
        myVector.push_back(new int(rand()%10));

    for(auto v : myVector)
        cout << v << ' ' << *v <<'\n';

    vectorSort(myVector);
    cout << "-------- After sort --------------\n";

    for(auto v : myVector)
        cout << v << ' ' << *v <<'\n';
}
