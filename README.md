cnfgen-rev-quick-sort, Norbert Manthey, 2021

Many SAT solvers that are based on MiniSat implement two sort algorithms,
a recursive implementation of quicksort and insertion sort. As quicksort has a
theoretical worst case, recursively calling a function can lead to a
segmantation fault. Furthermore, sorting the input for this worst case can lead
to a high overall run time, which the satisfiability of the input formula is
actually trivial.

By repeating a generated clause of this size a few times, the parsing time can
be increased linearly, as parsing each clause involves sorting again.

The tool in this package allows input formulas to hit this worst case scenario.

#### Build:

    make

#### Usage:

`cnfgen-rev-quick-sort clause-size nr-clauses`  
  
    clauses-size ... each clause is of this size  
    nr-clauses ..... use N times of this clause  

#### Example:

This generates a formula that requires around 20s parsing

```
C=120000
N=4
./cnfgen-rev-quick-sort "$C" "$N" > "cnfgen-rev-quick-sort-C${C}-N${N}.cnf"
```
