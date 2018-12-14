#include "codonstable.h"
#include "rna.h"
#include "protein.h"
#include "sequence.h"
#include "dna.h"
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}
// Function to load codons from file
void CodonsTable :: LoadCodonsFromFile(string codonsFileName)
{
    fstream myfile;
    myfile.open(codonsFileName, ios::in);
    if (!myfile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    else
        cout<<"File Opened"<<endl;
    int i=0 ;
    while ( myfile && !myfile.eof() )
    {
        myfile >> codons[i].value;
        myfile >> codons[i++].AminoAcid;

    }
    myfile.close();

}
// get function that returns the Aminoacid
Codon CodonsTable::getAminoAcid(char * value)
{
    LoadCodonsFromFile("RNA_codon_table.txt");
    for(int i = 0 ; i < 64 ; i++)
    {
        if( value[0] == codons[i].value[0] && value[1] == codons[i].value[1]&& value[2] == codons[i].value[2])
        {

            return codons[i];

        }
    }
}

// destructor
CodonsTable::~CodonsTable()
{
}
// printing the Codons
void CodonsTable::print()
{
    for (int i=0; i<64; i++)
    {
        cout<<codons[i].value[0];
        cout<<codons[i].value[1];
        cout<<codons[i].value[2];
        cout<<codons[i].value[3];
        cout<<codons[i].AminoAcid;
        cout<<endl;
    }
    cout<<endl;
}
// Function that set codons
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    Codon x;
    for(int i=0 ; i< 4 ; i++)
    {
        x.value[i] = value[i];
        x.AminoAcid = AminoAcid;
    }
}

