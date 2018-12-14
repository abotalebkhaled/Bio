#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<bits/stdc++.h>
using namespace std;

//extern map<string,char>aminoAcid;           //extern to tell the compiler that aminoAcid exist somewhere else
//extern map<char,string>reversedAcid;        // so multiple definition error wont appear

class Sequence
{

    public:
        char * seq;
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(const Sequence& rhs);
        // Setters And Getters
        void setSeq(char seq[]);
        void setSeqSize(int siz);
        char* getSeq()const;
        int getSeqSiz()const;
        char getElement(int idx)const;
        void setElement(char element,int idx);
        virtual ~Sequence();
        //static void loadCodon();
        // Operators for sequence
        Sequence& operator= (Sequence s2);
        bool operator==(Sequence &s1);
        bool operator!=(Sequence &s1);
        Sequence& operator+(Sequence &s1);
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
       // virtual void Print()= 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence  s1, Sequence  s2);
        friend istream& operator>> (istream& in, Sequence& s);
        friend ostream& operator<< (ostream& out,Sequence &s);

};

#endif // SEQUENCE_H
