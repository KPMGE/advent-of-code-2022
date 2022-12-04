#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int solve_puzzle(const char *file_path);

int main (int argc, char *argv[]) {
  printf("RESULT: %d\n", solve_puzzle("./input.txt"));
}

int solve_puzzle(const char *file_path) {
  FILE *f = fopen(file_path, "r");
  assert(f != NULL);

  int qtd_overlaps = 0;
  int first_elve_start, first_elve_end, second_elve_start, second_elve_end; 

  while(fscanf(f, "%d-%d,%d-%d\n", &first_elve_start, &first_elve_end, &second_elve_start, &second_elve_end) == 4) {
    if (first_elve_start == second_elve_start || second_elve_end == first_elve_end) {
      qtd_overlaps++;
      continue;
    }

    if (first_elve_start < second_elve_start) {
      if (first_elve_end >= second_elve_end) {
        qtd_overlaps++;
        continue;
      }
    } 
    if (second_elve_start < first_elve_start) {
      if (second_elve_end >= first_elve_end) {
        qtd_overlaps++;
      }
    }
  }

  fclose(f);
  return qtd_overlaps;
}
