#include <stdlib.h>
#include <stdio.h>
#include "Path.h"

/*
 * Main function that kills the dragon first and then finds the princesses and returns the path.
 */
int* save_the_princess(char** mapa, int n, int m, int t, int* journeyTime) {

  // make an array for the map
  //printf("inside the savetheprincess\n");
  char* mapArray = malloc(n * m  * sizeof(char));

  // copy the map
  uint i, j;
  uint princessCount = 0;
  
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      // check if it is a princess
     // printf("%c",mapa[i][j]);
      if (mapa[i][j] == 'P') {

        ++princessCount;

        if (princessCount > 2) {
          mapArray[i * m + j] = 'r';
        }
        else if (princessCount > 1) {
          mapArray[i * m + j] = 'q';
        }
        else {
          mapArray[i * m + j] = 'p';
        }
      }
      else {
      	
        mapArray[i * m + j] = mapa[i][j]+32;
      }
    }
  }
  //printf("princess count %d\n",princessCount);

  // create the stages
  Stage* stages = CreateStages(mapArray, (ushort) m, (ushort) n);

  // get the path
  int* path = FindPath(stages, (ushort) m, (ushort) n, (uint*) journeyTime);
  int time =0;
  DeleteStages(stages);
  free(mapArray);

  // return the result
  return path;

}
