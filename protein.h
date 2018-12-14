#ifndef PROTEIN_H
#define PROTEIN_H
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "codonstable.h"
using namespace std;

class DNA;
class RNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
private:
    Protein_Type type;
public:
    // constructors and destructor
    Protein();
    Protein (char * s,Protein_Type atype);
    Protein (const Protein & rhs);
    ~Protein();
    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    // simple operators
    Protein operator= (Protein& s2);
    bool operator==(Protein &s1);
    bool operator!=(Protein &s1);
    Protein& operator+(Protein &s1);
    void CheckProteinValid();
    void Print();
    DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
    friend istream& operator>> (istream& in, Protein& s);
    friend ostream& operator<< (ostream& out,Protein &s);
};

#endif // PROTEIN_H
