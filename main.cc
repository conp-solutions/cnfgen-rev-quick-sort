#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* output a vector to ostream */
template <class T> inline std::ostream &operator<<(std::ostream &out, const vector<T> &cls)
{
    for (size_t i = 0; i < cls.size(); ++i) out << cls[i] << " ";
    return out;
}

/* add next nr for quick sort worst case */
int append(vector<int> &v)
{
    const int n = v.size() + 1; // CNF starts with 1
    int new_size = v.size() + 1;
    int i = new_size / 2;

    if (v.size() == 0) {
        v.push_back(n);
    } else {
        if (v.size() == 1) i = 0;
        int old = v[i];
        v[i] = n;
        v.push_back(old);
    }
    return 0;
}

void usage()
{
    cerr << "cnfgen-rev-quick-sort, Norbert Manthey, 2021" << endl
         << endl
         << "Generate a CNF that hits the worst case of MiniSat based solver's quicksort" << endl
         << "By increasing the clause size, the parsing in a consuming SAT solver will be" << endl
         << "recursively call quicksort, splitting only 1 element after each iteration." << endl
         << "By repeating such a clause, the parsing time can be controlled linearly."
         << "" << endl
         << "cnfgen-rev-quick-sort clause-size nr-clauses" << endl
         << endl
         << "   clauses-size ... each clause is of this size" << endl
         << "   nr-clauses ..... use N times of this clause" << endl
         << endl;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        usage();
        exit(1);
    }

    int clause_size = stoi(argv[1]);
    int repeat = stoi(argv[2]);

    /* generate counter quick-sort filled vector */
    vector<int> d;
    for (int i = 0; i < clause_size; ++i) {
        append(d);
    }

    /* print formula */
    cout << "p cnf " << clause_size << " " << repeat << endl;
    cout << "c cnfgen-rev-quick-sort, Norbert Manthey, 2021" << endl;
    cout << "c create clauses that hit the worst case of the sort implementation of MiniSat based SAT solvers" << endl;
    cout << "c generate " << repeat << " clauses of size " << clause_size << endl;
    for (int i = 0; i < repeat; ++i) {
        cout << d << "0" << endl;
    }

    return 0;
}