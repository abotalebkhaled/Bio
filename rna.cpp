#include "rna.h"
#include "dna.h"
#include "protein.h"
#include "Sequence.h"
#include "codonstable.h"
#include<cstring>
#include<iostream>

using namespace std;


// Default constructor
RNA::RNA()
{

}
// constructor

RNA::RNA(char * s, RNA_Type atype)
{
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}
RNA::RNA(const RNA& rhs) // Copy constructor.
{
    seq=new char [100];
    strcpy(seq,rhs.seq);
}
// Function that changes RNA type to Protein type
Protein RNA::ConvertToProtein( CodonsTable & table)
{

    Codon x;
    int counter=0;
    Protein obj;
    obj.seq=new char[strlen(seq)/3];
    char* value = new char[3];
    for(int i=0; i<strlen(seq)/3 ; i++ )
    {
        value[0]= seq[counter];
        value[1]= seq[counter+1];
        value[2]= seq[counter+2];
        counter+=3;


        x = table.getAminoAcid(value);
        obj.seq[i] = x.AminoAcid;

    }

    return obj;
}
// Function to check if the RNA sample ( Exception handling )

void RNA::CheckRNAValid()
{
    string f;
    for (int i=0; i<strlen(seq)  ; i++)
    {
        if( (seq[i]=='A') || (seq[i]=='a') || (seq[i]=='G') || (seq[i]=='g') || (seq[i]=='c') || (seq[i]=='C') || (seq[i]=='U') || (seq[i]=='u') )
        {
            f= "No Error Found in RNA sample";
            cout << endl;
            throw f;
        }
        else
        {
            f = "There is a not allowed char ";
            throw f;
            break;
        }
    }

}
// This function allows the programmer to input the RNA sample or object directly

istream& operator>> (istream& in, RNA& s)
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
    cout <<"Choose your RNA type : 1-mRNA - 2-pre_mRNA - 3-mRNA_exon - 4-mRNA_exon "<< endl;
    cin >> z;
    if (z==1)
    {

        RNA(s.seq,mRNA);
    }
    else if(z==2)
    {
        RNA(s.seq,pre_mRNA);
    }
    else if (z==3)
    {
        RNA(s.seq,mRNA_exon);
    }
    else if (z==4)
    {
        RNA(s.seq,mRNA_exon);
    }


    return in;
}
// This function allows the programmer to Output the RNA sample or object directly

ostream& operator<< (ostream& out,RNA &s)
{
    for(int i=0; i<strlen(s.seq) ; i++)
    {
        out << s.seq[i];
    }
    out <<endl;
    return out;
}
// Function converts DNA sample to RNA sample
DNA RNA::ConvertToDNA()
{
    for(int i=0 ; i<strlen(seq); i++)
    {
        if((seq[i]=='U')||(seq[i]=='u'))
        {
            seq[i]='T';
        }
    }
    DNA obj;
    obj.setSeq(seq);
    return obj;
}
// Function to print a RNA sample
void RNA::Print()
{
    for(int i=0; i<strlen(seq) ; i++)
    {
        cout << seq[i];
    }
}
// function that equalizes two RNA sample
RNA RNA::operator= (RNA& s2)
{

    this->seq=new char [strlen(s2.seq)];
    for(int i=0 ; i<strlen(s2.seq); i++ )
    {
        this->seq[i] = s2.seq[i];
    }
}
// Function checks if two RNA sample are equal
bool RNA::operator==(RNA &s1)
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
// Function checks if two RNA sample are not equal
bool RNA::operator!=(RNA &s1)
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
// Function that merges  two RNA samples
RNA& RNA::operator+(RNA &s1)
{
    RNA s2;
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

RNA::~RNA()
{
    delete[] seq;
}
