#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include "rna.h"
#include "protein.h"
#include "sequence.h"
#include "dna.h"
#include <iostream>
using namespace std;

class Protein;

struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};
class CodonsTable : public Sequence
{
  	public:
        Codon codons[64];
   	public:
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);


        void print();
};
#endif // CODONSTABLE_H
