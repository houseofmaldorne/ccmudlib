// Edited by Lummen 27-7-97

#include "../path.h"
#include <language.h>

inherit "/lib/room.c";

void setup()
{
  set_short(_LANG_NADUK_SHORT);
  set_long(_LANG_NADUK_LONG);
  set_light(60);
  add_item(_LANG_NADUK_HOUSE_ITEM, _LANG_NADUK_HOUSE_DESC);
  set_zone("naduk");
  add_property("no_undead", 1);
  add_exit(DIR_EAST, ROOMS + "a2.c", "road");
  add_exit(DIR_WEST, ROAD + "rooms/13.c", "road");
  add_clone(NPCS + "guard.c", 2);
}
