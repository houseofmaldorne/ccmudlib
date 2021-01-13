/* Created by Lummen 27-Mayo-1997 */

#include "../path.h"
#include <language.h>

inherit "/lib/room.c";

void setup()
{
  set_short(_LANG_ROAD_SHORT);
  set_long(_LANG_ROAD_LONG);
  set_light(60);
  add_exit(DIR_EAST, ROOMS + "4.c", "road");
  add_exit(DIR_SOUTH, ROOMS + "2.c", "road");
  set_zone("road");
  add_property("no_undead", 1);
  add_clone(NPCS + "pilgrim.c", 1);
}
