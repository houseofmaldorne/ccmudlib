
// Radix - fixes from new driver .. void was an unfriendly place
// after we moved to Aurora...
// Sept 28, 1995
// This got COMPLICATED .. argh
// Translated for CcMud, neverbot 7/03
// Player now go to ENTRY_POS

#define ENTRY_POS "/game/areas/ciudad-capital/barrio-antiguo/rooms/calzada02"

#include <areas/common.h>

inherit "/lib/room";

int do_update(string str)
{
   int i;
   object *all;
   all = all_inventory(this_object());
   // if(!stringp(str) || str == "here")
   // {
      // load destinations
      CODER_COMMON_ROOM->BAH();
      ENTRY_POS->BAH();

      for(i = 0; i < sizeof(all); i++)
         if(interactive(all[i])) 
         {
            if(!all[i]->query_creator())
            {
               tell_object(all[i], "Sac�ndote del infierno...\n");
               all[i]->move(ENTRY_POS);
               all[i]->do_look();
            }

            if(all[i]->query_creator())
            {
               tell_object(all[i],"Viajando hasta la habitaci�n com�n...\n");
               all[i]->move(CODER_COMMON_ROOM);
               all[i]->do_look();
               tell_room(find_object(CODER_COMMON_ROOM), all[i]->query_cap_name()+
                  " llega con cara de cansancio... \n", all[i]);
            }
         }
         else
            all[i]->dest_me();     // dest those NPCs and items
   // }
   return 1; 
}

void setup() {
     set_light(40);
     set_short(mud_name()+": El Vac�o");
     set_long("�ste es el lugar al que vienes cuando el lugar en el que " +
              "est�s desaparece y no tienes ning�n lugar al que ir. " +
              "La raz�n por la que est�s en �l se deber� muy probablemente " +
              "a alg�n fallo involuntario del programador de la zona en la " +
              "que estabas.\n");

     add_exit("ciudad", ENTRY_POS, "standard");
}

void init()
{
   add_action("do_update", ({"update", "up"}));
   ::init();
}

