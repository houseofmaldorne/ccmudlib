
// common

#define _LANG_CMD_NOTHING_HERE "No hay nada con el nombre '"+arg+"' aqu�.\n"

// look.c

#define _LANG_CMD_LOOK "mirar"
#define _LANG_CMD_LOOK_SYNTAX "mirar [a] [<objeto>]"
#define _LANG_CMD_LOOK_HELP "Devuelve la descripci�n de un objeto o (por defecto) " + \
                    "la localizaci�n en la que te encuentras."
#define _LANG_CMD_LOOK_NO_ENVIRONMENT "No est�s en ning�n sitio... no puedes ver nada.\n"
#define _LANG_CMD_LOOK_BLINDED "No puedes ver nada. �Est�s cegado!\n"

// whoami

#define _LANG_WHOAMI_HELP "Muestra onformaci�n sobre tu propio personaje."
#define _LANG_WHOAMI_CLASS_FIRST "   Clase:\n"
#define _LANG_WHOAMI_CLASS_EACH "     " + (me->query_class_ob())->query_short() + \
      " de nivel " + me->query_level() + ".\n"
#define _LANG_WHOAMI_GUILD_FIRST "   Gremios:\n"
#define _LANG_WHOAMI_GUILD_EACH "     " + capitalize(g_names[i]->query_short()) + \
      " de nivel " + guilds[g_names[i]][0] + ".\n";
#define _LANG_WHOAMI_JOB_FIRST "   Oficios:\n"
#define _LANG_WHOAMI_JOB_EACH "     " + capitalize(j_names[i]->query_short()) + \
      " de nivel " + jobs[j_names[i]][0] + ".\n";
