#include "Sequence.h"
#include <cstring>
#include "codonstable.h"
#include<iostream>
using namespace std;
//map<string,char>aminoAcid;           //extern to tell the compiler that aminoAcid exist somewhere else
//map<char,string>reversedAcid;

// Default Constructor
Sequence::Sequence()
{
}

// Parameterized Constructor to set the length of Sequence

Sequence :: Sequence(int length)
{
    cout<<"enter the sequence :";
    seq=new char[length+1];
    for(int i=0; i<length; ++i)
    {
        cin>>seq[i];
    }
}


// Function to Get The sequence

char* Sequence::getSeq()const
{
    return seq;
}

// Function to Get The sequence Size

int Sequence::getSeqSiz() const
{
    return strlen(seq);
}

// Copy constructor to create a sequence equal to another sequence

Sequence :: Sequence(const Sequence& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}

// Setter to set a new sequence
void Sequence ::setSeq(char seq2[])
{
    this->seq=new char [ strlen(seq2)+1];
    strcpy(this->seq,seq2);
}

// setter to set the size of a sequence
void Sequence ::setSeqSize(int siz)
{
    this->seq=new char [ siz+1];
}

// Function to get an element of a sequence
char Sequence::getElement(int idx)const
{
    return seq[idx];
}

// Function to set element in a sequence
void Sequence::setElement(char element,int idx)
{
    seq[idx]=element;
}
// Function to be able to input an Sequence object directly
istream& operator>> (istream& in, Sequence& s)
{
    int x;
    cout << "Enter your length \n";
    in >> x;
    s.setSeqSize(x);
    s.seq= new char[x];
    cout << "Enter your sequence \n";
    for(int i=0; i<x ; i++)
    {
        in >> s.seq[i];
    }
    return in;
}
// Function to be able to output an Sequence object directly
ostream& operator<< (ostream& out,Sequence &s)
{
    for(int i=0; i<strlen(s.seq) ; i++)
    {
        out << s.seq[i];
    }
    out <<endl;
    return out;
}
// A Function that equalizes two objects of sequence .
Sequence& Sequence::operator= (Sequence s2)
{

    this->seq=new char [strlen(s2.seq)];
    for(int i=0 ; i<strlen(s2.seq); i++ )
    {
        this->seq[i] = s2.seq[i];
    }
}
// This function checks if the two objects of sequence are equal
bool Sequence::operator==(Sequence &s1)
{
    int check =0 ;
    if(strlen(s1.seq) != strlen(seq))
    {
        return 0;
    }
    else if (strlen(s1.seq) == strlen(seq) )
    {
        for(int i=0 ; i< strlen(seq) ; i++ )
        {
            if(s1.seq[i] == seq[i] )
            {
                check++;
            }
        }
        if (check == strlen(seq))
        {
            return 1;
        }
        else
            return 0;
    }
}
// This function checks if the two objects are not equal
bool Sequence::operator!=(Sequence &s1)
{
    int check =0 ;
    if (strlen(s1.seq) != strlen(seq) )
    {
        return 1;
    }
    else if (strlen(s1.seq) == strlen(seq) )
    {
        for(int i=0 ; i< strlen(seq) ; i++ )
        {
            if(s1.seq[i] == seq[i] )
            {
                check++;
            }
        }
        if (check == strlen(seq))
        {
            return 0;
        }
        else
            return 1;
    }
}
// This function merges two objects
Sequence& Sequence::operator+(Sequence &s1)
{
    Sequence s2;
    s2.seq= new char[(strlen(s1.seq) + strlen(seq))];
    for (int i=0; i<strlen(seq); i++ )
    {
        s2.seq[i] = seq[i];
    }
    for (int i=strlen(seq); i<(strlen(s1.seq) + strlen(seq)); i++ )
    {
        s2.seq[i] = s1.seq[i-strlen(seq)];
    }
    for(int i=0; i<(strlen(s1.seq) + strlen(seq)); i++)
    {
        cout<<s2.seq[i];
    }
    return s2;
}


char* Align(Sequence  s1, Sequence  s2)
{

    if((strlen(s1.seq))<(strlen(s2.seq)))
    {
        Sequence obj;
        obj.seq=new char[strlen(s1.seq)];
        for(int i=0; i<strlen(s1.seq); i++)
        {
            if(s1.seq[i]==s2.seq[i])
            {
                obj.seq[i]=s1.seq[i];
            }
        }
        cout<<obj.seq;
    }
    if((strlen(s2.seq))<(strlen(s1.seq)))
    {
        Sequence obj;
        obj.seq=new char[strlen(s2.seq)];
        for(int i=0; i<strlen(s2.seq); i++)
        {
            if(s1.seq[i]==s2.seq[i])
            {
                obj.seq[i]=s1.seq[i];
            }
        }
        cout<<obj.seq;
    }


}

// default Destructor
Sequence::~Sequence()
{
    delete[] seq;
}
