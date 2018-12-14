#ifndef RNA_H
#define RNA_H
#include "dna.h"
#include "protein.h"
#include "Sequence.h"
#include "codonstable.h"
#include<iostream>
using namespace std;
class DNA;
class CodonsTable;
class Protein;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * s, RNA_Type atype);
        RNA(const RNA& rhs);
        ~RNA();
        void Print();
        void CheckRNAValid();
        Protein ConvertToProtein( CodonsTable & table);
        // Operators to RNA sample
        RNA operator= (RNA& s2);
        bool operator==(RNA &s1);
        bool operator!=(RNA &s1);
        RNA& operator+(RNA &s1);

        DNA ConvertToDNA();
        friend istream& operator>> (istream& in, RNA& s);
        friend ostream& operator<< (ostream& out,RNA &s);


};

#endif // RNA_H
