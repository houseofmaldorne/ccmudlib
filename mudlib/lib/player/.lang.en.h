
// events.c

#define _LANG_EVENTS_SOMEBODY_ARRIVES "You notice somebody arrived here.\n"
#define _LANG_EVENTS_SOMEBODY_LEAVES "You notice somebody leaves.\n"

// start.c

// quit.c

#define _LANG_QUIT_LOADING "Your inventory is still loading, please wait until the process ends.\n"
#define _LANG_QUIT_EXITING "Quitting...\n"
#define _LANG_QUIT_ENV_MSG this_object()->query_cap_name()+ \
            " looks for a safe place where exiting the game.\n"
#define _LANG_QUIT_STOP_COMBAT_FIRST "You must end your fights first.\n"+ \
        "Write '%^BOLD%^stop fights%^RESET%^' to end them as soon as possible.\n"
#define _LANG_QUIT_STOP_MOVING_FIRST "If you don't stop moving, it will be impossible "+ \
        "to quit the game.\n"
#define _LANG_QUIT_BEEN_MOVED "In your previous location was not possible to quit, "+ \
        "you've been moved to the nearest one (try again here if you "+ \
        "still want to quit).\n"
#define _LANG_QUIT_DROP_ITEM "You drop your "+ob[i]->short()+".\n"
#define _LANG_QUIT_THANKS "Thanks for playing, see you next time!\n"
#define _LANG_QUIT_INFORM_CODERS this_object()->query_cap_name()+" quits "+mud_name()
#define _LANG_QUIT_INFORM_PLAYERS this_object()->query_cap_name()+" quits "+mud_name()
#define _LANG_QUIT_ENV_QUIT this_object()->query_cap_name()+" quits "+mud_name()+".\n"