#include "protein.h"
#include "RNA.h"
#include "DNA.h"
#include "sequence.h"
#include<cstring>
using namespace std;
// Default constructor
Protein::Protein()
{
    //ctor
}
// Constructor
Protein::Protein(char * s, Protein_Type atype)
{
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}

Protein::Protein(const Protein & rhs) // Copy constructor.
{
    seq=new char [100];
    strcpy(seq,rhs.seq);
}
// Function checks if the Protein sample is valid

void Protein:: CheckProteinValid()
{
    string f;
    int check =0;
    if ( (strlen(seq)%3 == 0))
    {
        for (int i=0 ; i< strlen(seq) ; i++ )
        {
            if ((seq[i] !='K' ) || (seq[i] !='T' ) || ( seq[i] !='N' ) || (seq[i] !='R' ) || (seq[i] !='S' ) ||  (seq[i] !='I' ) || (seq[i] !='M' ) ||(seq[i] !='Q' ) ||(seq[i] !='Y' ) ||(seq[i] !='P' ) ||(seq[i] !='L' ) ||(seq[i] !='F' ) ||(seq[i] !='V' ) ||(seq[i] !='W' ) ||(seq[i] !='G' ) )
                check++;
        }
        if (check == strlen(seq)){
            f = "True Protein sample ";
            cout << endl;
            throw f;
        }
        else
            f = "Error , False protein sample ";
    }
}
// input protein sample directly
istream& operator>> (istream& in, Protein& s)
{
    int x,z;
    cout << "Enter your length \n";
    in >> x;
    Protein_Type typ;
    s.setSeqSize(x);
    s.seq= new char[x];
    cout << "Enter your sequence \n";
    for(int i=0; i<x ; i++)
    {
        in >> s.seq[i];
    }
    cout <<"Choose your Protein type : 1-Hormon - 2-Enzyme - 3-TF - 4-Cellular_Function "<< endl;
    cin >> z;
    if (z==1)
    {

        Protein(s.seq,Hormon);
    }
    else if(z==2)
    {
        Protein(s.seq,Enzyme);
    }
    else if (z==3)
    {
        Protein(s.seq,TF);
    }
    else if (z==4)
    {
        Protein(s.seq,Cellular_Function);
    }
    if ( (typ == Hormon) || (typ == Enzyme ) || (typ == TF ) || (typ == Cellular_Function)  )
    {
        cout << "True type of Protein\n";
    }
    else
    {
        cout << " Invalid type of Protein "<< endl;
    }


    return in;
}
// output protein sample directly
ostream& operator<< (ostream& out,Protein &s)
{
    for(int i=0; i<strlen(s.seq) ; i++)
    {
        out << s.seq[i];
    }
    out <<endl;
    return out;
}
// Equalizing two protein samples
Protein Protein::operator= (Protein& s2)
{

    this->seq=new char [strlen(s2.seq)];
    for(int i=0 ; i<strlen(s2.seq); i++ )
    {
        this->seq[i] = s2.seq[i];
    }
}
// Checking if two protein samples are equal
bool Protein::operator==(Protein &s1)
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
// Checking if two protein samples are not equal
bool Protein::operator!=(Protein &s1)
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
// Function to merge the two protein samples
Protein& Protein::operator+(Protein &s1)
{
    Protein s2;
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
// Printing a protein sample
void Protein::Print()
{
    for(int i=0; i<strlen(seq) ; i++)
    {
        cout << seq[i];
    }
}
// destructor
Protein::~Protein()
{
    delete[] seq;
}
