// Vault object- Radix 1996
// Reviewed, neverbot 7/03
 
inherit "/lib/core/basic/container";
inherit "/lib/core/basic/auto_load";

#include <room/storage.h>

mixed * auto_load;
static string savefile;

void create()
{
  ::create();
  reset_get();
}
 
// Para objetos unicos, neverbot 08/07/04
int query_vault_object() { return 1; }

string query_savefile() { return savefile; }

void set_save_file(string file) 
{
  object * olist;
  savefile = file;

  if (!environment() || 
     (!environment()->query_vault_room() && !environment()->query_shop()) )
    destruct(this_object());    // die screaming
  auto_load = ({ });

  seteuid("Room");
  restore_object(savefile);
  seteuid("PLAYER");

  if (sizeof(auto_load))  
    olist = load_auto_load(auto_load,this_object());
  else
    olist = ({ });
  reset_get();
  environment()->add_property(VAULT_USE_PROP,1);
}
 
void dest_me() 
{
  object * olist;
  int i;

  olist = all_inventory(this_object());

  if (!savefile || !environment() || 
     (!environment()->query_vault_room() && !environment()->query_shop()) )
  {
    destruct(this_object());   // die screaming
    return;
  }
  
  if (sizeof(olist)) 
    auto_load = create_auto_load(olist);
  else
    auto_load = ({ });

  seteuid("Room");
  save_object(savefile);
  seteuid("PLAYER");

  // Hack para objetos unicos, neverbot 08/07/04
  for (i = 0; i < sizeof(olist); i++)
  {
    if (olist[i] && olist[i]->query_unique_object())
   {
      tell_object(find_living("folken"), "Objeto unico en vault_obj, destruyendo\n");
      olist[i]->dest_unique();
    }
  }
  environment()->remove_property(VAULT_USE_PROP);

  ::dest_me();
}
