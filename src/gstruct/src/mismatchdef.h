#ifndef MISMATCHDEF_INCLUDED
#define MISMATCHDEF_INCLUDED


#define T Mismatch_T
typedef struct T *T;

struct T {
  char nt;
  int shift;			/* Used to record shifts */
  int nm;
  int xs;			/* +1 for +, -1 for -, 0 for others */

  long int count;		/* Includes normal and softclipped */

  long int count_plus;		/* Used by unique elements */
  long int count_minus;		/* Used by unique elements */

  T next;	    /* Used for linking similar mismatches together */
};

#undef T
#endif

