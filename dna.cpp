#include "dna.h"
#include "RNA.h"
#include "protein.h"
#include "Sequence.h"
#include "codonstable.h"
#include <cstring>
using namespace std;


DNA::DNA()
{
    //ctor
}
// Constructor
DNA :: DNA(char * s, DNA_Type atype)
{
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}

DNA::DNA(const DNA & rhs) // Copy constructor.
{
    seq=new char [100];
    strcpy(seq,rhs.seq);
}

// This function builds a complementary strand of type DNA
void DNA ::  BuildComplementaryStrand()
{


    for(int i=0; i<strlen(seq); i++ )
    {
        if ((seq[i]=='A') || (seq[i]=='a'))
        {
            seq[i]='T' ;
        }
        else if ((seq[i]=='T') || (seq[i]=='t'))
        {
            seq[i]='A' ;
        }
        else if ((seq[i]=='G') || (seq[i]=='g'))
        {
            seq[i]='C' ;
        }
        else if ((seq[i]=='C') || (seq[i]=='c'))
        {
            seq[i]='G' ;
        }
    }
    char* arr;
    arr = new char [strlen(seq)];
    int c=0;
    for(int i= strlen(seq)-1; i>=0 ; i--)
    {
        arr[c]=seq[i];
        c++;
    }
    for(int i=0; i<strlen(seq); i++)
    {
        seq[i]=arr[i];
    }


}
// A function converts the DNA sample to an RNA sample
RNA DNA:: ConvertToRNA()
{
    for(int i=0 ; i<strlen(seq); i++)
    {
        if((seq[i]=='T')||(seq[i]=='t'))
        {
            seq[i]='U';
        }
    }
    RNA obj;
    obj.setSeq(seq);
    return obj;
}
// This function checks if the DNA is valid ( Exception handling )
void DNA :: CheckDNAValid()
{
    string x;
     for (int i=0; i<strlen(seq)  ; i++)
    {
        if( (seq[i]=='A') || (seq[i]=='a') || (seq[i]=='G') || (seq[i]=='g') || (seq[i]=='c') || (seq[i]=='C') || (seq[i]=='T') || (seq[i]=='t') )
        {
            x = "True sample of DNA";
            cout << endl;
            throw x;
        }
        else
        {
            x = "There is a not allowed char ";
            throw x;
            break;
        }
    }
}
// This function allows the programmer to input the DNA sample or object directly
istream& operator>> (istream& in, DNA& s)
{
    int x,z;
    cout << "Enter your length \n";
    in >> x;
    DNA_Type typ;
    s.setSeqSize(x);
    s.seq= new char[x];
    cout << "Enter your sequence \n";
    for(int i=0; i<x ; i++)
    {
        in >> s.seq[i];
    }

    cout <<"Choose your DNA type : 1-promoter - 2-tail - 3- noncoding - 4-motif "<< endl;
    in >> z;
    if (z==1)
    {
        DNA(s.seq, promoter );
    }
    else if(z==2)
    {
        DNA(s.seq,tail);
    }
    else if (z==3)
    {
        DNA(s.seq,noncoding);
    }
    else if (z==4)
    {
        DNA(s.seq,motif);
    }

    return in;
}
// This function allows the programmer to Output the DNA sample or object directly
ostream& operator<< (ostream& out,DNA &s)
{
    for(int i=0; i<strlen(s.seq) ; i++)
    {
        out << s.seq[i];
    }
    out <<endl;
    return out;
}
// Same as the function above it
void DNA::Print()
{
    for(int i=0; i<strlen(seq) ; i++)
    {
        cout << seq[i];
    }
}
// Operators makes two DNA samples equalized
DNA DNA::operator= (DNA& s2)
{

    this->seq=new char [strlen(s2.seq)];
    for(int i=0 ; i<strlen(s2.seq); i++ )
    {
        this->seq[i] = s2.seq[i];
    }
}
// function checks if two samples are equal and returns true if they are
bool DNA::operator==(DNA &s1)
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
// function checks if two samples are not equal and returns true if they are
bool DNA::operator!=(DNA &s1)
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
// This function merges two DNA samples
DNA& DNA::operator+(DNA &s1)
{
    DNA s2;
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
}

// Destructor
DNA::~DNA()
{
delete[] seq;
}
