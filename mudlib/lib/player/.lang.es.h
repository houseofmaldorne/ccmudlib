
// events.c

#define _LANG_EVENTS_SOMEBODY_ARRIVES "Notas que alguien llega a tu posici�n.\n"
#define _LANG_EVENTS_SOMEBODY_LEAVES  "Notas marcharse a uno de los que estaban aqu�.\n"

// start.c


// quit.c

#define _LANG_QUIT_LOADING "Todav�a se esta cargando tu equipo, espera a que termine el proceso.\n"
#define _LANG_QUIT_EXITING "Saliendo...\n"
#define _LANG_QUIT_ENV_MSG this_object()->query_cap_name()+ \
            " busca un lugar c�modo para salir del juego.\n"
#define _LANG_QUIT_STOP_COMBAT_FIRST "Debes terminar primero tus combates.\n"+ \
        "Escribe '%^BOLD%^detener combates%^RESET%^' para terminarlos lo antes posible.\n"
#define _LANG_QUIT_STOP_MOVING_FIRST "Si no paras de moverte ser� imposible buscar un buen lugar "+ \
        "para salir del juego.\n"
#define _LANG_QUIT_BEEN_MOVED "En tu localizaci�n previa no es posible salir, "+ \
        "has sido movido a la m�s cercana (vuelve a intentarlo aqu� si a�n "+ \
        "deseas desconectar).\n"
#define _LANG_QUIT_DROP_ITEM "Dejas tu "+ob[i]->short()+".\n"
#define _LANG_QUIT_THANKS "Gracias por jugar, �hasta la pr�xima!\n"
#define _LANG_QUIT_INFORM_CODERS this_object()->query_cap_name()+" sale de "+mud_name()
#define _LANG_QUIT_INFORM_PLAYERS this_object()->query_cap_name()+" sale de "+mud_name()
#define _LANG_QUIT_ENV_QUIT this_object()->query_cap_name()+" sale de "+mud_name()+".\n"
