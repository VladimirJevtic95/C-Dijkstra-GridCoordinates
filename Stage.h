/*
 * #ifndef directive allows for conditional compilation. 
 * The preprocessor determines if the provided macro does not exist before including the subsequent code in the compilation process.
 */

#ifndef _STAGE_H
#define _STAGE_H

#include "Base.h"
#include "History.h"

/*
 * A single stage represented by a map, path lengths and directions.
 */
typedef struct Stage {

  /*
   * The history of the stage.
   */
  History history;

  /*
   * The map tiles.
   */
  char* tiles;

  /*
   * Tile paths.
   */
  uchar* paths;

  /*
   * Directions to previous tile.
   */
  uchar* directions;

} Stage;

/*
 * Creates and sets up stages.
 */
Stage* CreateStages(char* map, ushort width, ushort height);

/*
 * Deletes stages.
 */
void DeleteStages(Stage* stages);

#endif

/*
 * #endif directive closes off the #ifndef. 
 * When the #endif directive is encountered, preprocessing of the opening directive #ifndef is completed.
 */
