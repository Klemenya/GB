#include <iostream>

using namespace std;

template <class T>

void Swap (T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
};

void Swap2 (int** &a, int** &b)
{
    int **temp;
    temp = a;
    a = b;
    b = temp;
};

int main(){
   int a = 10;
   int b = 33;

   int *ptr1 = &a;
   int *ptr2 = &b;

   int **pptr1 = &(ptr1);
   int **pptr2 = &(ptr2);

   cout << " a =    " << a     << "\t\t" << " b =    " <<b << '\n';
   cout << " ptr1 = " << ptr1  << '\t' << " ptr2 = " << ptr2 << '\n';
   cout << "*ptr1 = " << *ptr1 << "\t\t" << "*ptr2 = " << *ptr2 << '\n';

   cout << "pptr1 = " << pptr1 << '\t' << "pptr2 = " << pptr2 << '\n';
   cout << "*pptr1= " << *pptr1 << '\t' << "*pptr2= " << *pptr2 << '\n';
   cout << "**pptr1=" << **pptr1 << "\t\t" << "**pptr2=" << **pptr2 << '\n';

   cout << "------------------------------\n";
//   temp = pptr1;
//   pptr1 = pptr2;
//   pptr2 = temp;
//   cout << *pptr1 << '\t' << *pptr2 << '\n';
//   cout << **pptr1 << '\t' << **pptr2 << '\n';


   Swap (pptr1, pptr2);

   cout << " a =    " << a     << "\t\t" << " b =    " <<b << '\n';
   cout << " ptr1 = " << ptr1  << '\t' << " ptr2 = " << ptr2 << '\n';
   cout << "pptr1 = " << pptr1 << '\t' << "pptr2 = " << pptr2 << '\n';
   cout << "*pptr1= " << *pptr1 << '\t' << "*pptr2= " << *pptr2 << '\n';
   cout << "**pptr1=" << **pptr1 << "\t\t" << "**pptr2=" << **pptr2 << '\n';

   cout << "------------------------------\n";

   int a1,b1;
   a1=1;
   b1=2;
   int *pa, *pb;
   pa = &a1;
   pb = &b1;

   cout << " A =    " << a1 <<" "<< &a     << "\t\t" << " B =    " <<b1 << " "<<&b << '\n';
   cout << " pA = " << pa  << '\t' << " pB = " << pb << '\n';
   cout << "*pA = " << *pa  << '\t' << "*pB = " << *pb << '\n';

   Swap (pa, pb);
   cout << " A =    " << a1 <<" "<< &a     << "\t\t" << " B =    " <<b1 << " "<<&b << '\n';
   cout << " pA = " << pa  << '\t' << " pB = " << pb << '\n';
   cout << "*pA = " << *pa  << '\t' << "*pB = " << *pb << '\n';




   cin.get();
}
