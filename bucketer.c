#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int i,m,l,h;
  m=l=h=0;
  for(i=0;i<nBatteries;i++){
    if(cycles[i]<=410){
      (counts.lowCount)++;
    }
    else if(cycles[i]>410 && cycles[i]<950){
      (counts.mediumCount)++;
    }
    else{
      (counts.highCount)++;
    }
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000, 949, 950, 410};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 3);
  assert(counts.mediumCount == 4);
  assert(counts.highCount == 2);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
