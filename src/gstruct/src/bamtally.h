/* $Id: bamtally.h 219279 2019-05-21 00:58:53Z twu $ */
#ifndef BAMTALLY_INCLUDED
#define BAMTALLY_INCLUDED
#include "bamread.h"
#include "genome.h"
#include "genomicpos.h"
#include "list.h"
#include "iit-read.h"
#include "tableuint.h"


typedef enum {OUTPUT_BLOCKS, OUTPUT_RUNLENGTHS, OUTPUT_TALLY, OUTPUT_IIT, OUTPUT_EXPR,
	      OUTPUT_SEQUENCE, OUTPUT_SEGMENTS, OUTPUT_SOFTCLIPS, OUTPUT_TOTAL} Tally_outputtype_T;
#define DEFAULT_QUALITY 40  /* quality_score_adj + 40 */

extern void
Bamtally_setup (int ngenes);
extern void
Bamtally_takedown ();


extern long int
Bamtally_run (long int **tally_matches, long int **tally_mismatches,
	      List_T *intervallist, List_T *labellist, List_T *datalist,
	      Bamreader_T bamreader, Genome_T genome, char *printchr,
	      Genomicpos_T chroffset, Genomicpos_T chrstart, Genomicpos_T chrend, IIT_T map_iit,
	      int alloclength, int pastlength, Tableuint_T resolve_low_table, Tableuint_T resolve_high_table,
	      char *desired_read_group, int minimum_mapq, int good_unique_mapq,
	      int minimum_quality_score, int maximum_nhits,
	      bool need_concordant_p, bool need_unique_p, bool need_primary_p, bool ignore_duplicates_p,
	      bool ignore_lowend_p, bool ignore_highend_p,
	      Tally_outputtype_T output_type, bool blockp, int blocksize,
	      int quality_score_adj, int min_depth, int variant_strands, double variant_pct,
	      bool genomic_diff_p, bool signed_counts_p, bool ignore_query_Ns_p,
	      bool print_indels_p, bool print_totals_p, bool print_cycles_p, bool print_nm_scores_p, bool print_xs_scores_p,
	      bool want_genotypes_p, bool verbosep, bool readlevel_p,
	      int min_softclip, int max_softclip, bool print_noncovered_p, int default_scale,
	      char *bamfile);

extern List_T
Bamtally_expr (Bamreader_T bamreader, Genome_T genome, char *printchr,
	       Genomicpos_T chroffset, Genomicpos_T chrstart, Genomicpos_T chrend, IIT_T map_iit,
	       int alloclength, int pastlength, Tableuint_T resolve_low_table, Tableuint_T resolve_high_table,
	       char *desired_read_group, int minimum_mapq, int good_unique_mapq,
	       int minimum_quality_score, int maximum_nhits,
	       bool need_concordant_p, bool need_unique_p, bool need_primary_p, bool ignore_duplicates_p,
	       bool ignore_lowend_p, bool ignore_highend_p,
	       int variant_strands, double variant_pct, int min_softclip, int max_softclip, int default_scale, bool plusp);

/* Version that keeps separate tallies for the low and high ends of paired-end reads */
extern void
Bamtally_run_lh (long int **tally_matches_low, long int **tally_mismatches_low,
		 long int **tally_matches_high, long int **tally_mismatches_high,
		 Bamreader_T bamreader, Genome_T genome, char *printchr,
		 Genomicpos_T chroffset, Genomicpos_T chrstart, Genomicpos_T chrend,
		 IIT_T map_iit, int alloclength, int pastlength,
		 char *desired_read_group, int minimum_mapq, int good_unique_mapq, int maximum_nhits,
		 bool need_concordant_p, bool need_unique_p, bool need_primary_p, bool ignore_duplicates_p,
		 int blocksize, int quality_score_adj, int min_depth, int variant_strands, double variant_pct,
		 bool genomic_diff_p, bool ignore_query_Ns_p, bool verbosep, bool readlevel_p,
		 int min_softclip, int max_softclip, bool print_noncovered_p);

extern IIT_T
Bamtally_iit (Bamreader_T bamreader, char *desired_chr, char *bam_lacks_chr,
	      Genomicpos_T chrstart, Genomicpos_T chrend,
	      Genome_T genome, IIT_T chromosome_iit, IIT_T map_iit, int alloclength, int pastlength,
	      char *desired_read_group, int minimum_mapq, int good_unique_mapq,
	      int minimum_quality_score, int maximum_nhits,
	      bool need_concordant_p, bool need_unique_p, bool need_primary_p, bool ignore_duplicates_p,
	      int min_depth, int variant_strands, double variant_pct, bool ignore_query_Ns_p,
	      bool print_indels_p, int blocksize, bool verbosep, bool readlevel_p,
	      int min_softclip, int max_softclip, bool print_cycles_p, bool print_nm_scores_p,
	      bool print_xs_scores_p, bool print_noncovered_p);

#endif
