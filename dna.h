#ifndef DNA_H
#define DNA_H
#include "rna.h"
#include "protein.h"
#include "sequence.h"
#include "codonstable.h"
using namespace std;
class RNA;
enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
 	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
        int check;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(char * s, DNA_Type atype);
        DNA(const DNA& rhs);
        ~DNA();
        void Print();
        void CheckDNAValid();

        RNA ConvertToRNA();
        // operators for DNA sample
        DNA operator= (DNA& s2);
        bool operator==(DNA &s1);
        bool operator!=(DNA &s1);
        DNA& operator+(DNA &s1);

        void BuildComplementaryStrand();
        friend istream& operator>> (istream& in, DNA& s);
        friend ostream& operator<< (ostream& out,DNA &s);
};

#endif // DNA_H
