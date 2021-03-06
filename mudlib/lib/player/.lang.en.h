
#define _LANG_YES_OPTIONS_ARRAY ({ 'y', 'Y' })
#define _LANG_NO_OPTIONS_ARRAY ({ 'n', 'N' })

// alias.c 

#define _LANG_ALIAS_LIST_HEADER "List of defined alias:\n"
#define _LANG_ALIAS_SEMICOLON_NOT_ALLOWED "\";\" not allowed in aliases.\n"
#define _LANG_ALIAS_CONFIRM_FLUSH "This will remove all your aliases, are you sure? (y/n)\n"
#define _LANG_ALIAS_FLUSHED "Ok, aliases removed.\n"
#define _LANG_ALIAS_OK "Ok.\n"
#define _LANG_ALIAS_NO_ALIAS "You haven't defined any alias yet.\n"
#define _LANG_ALIAS_NO_ALIAS_WITH_THAT "You haven't defined any alias with '"+str+"'.\n"
#define _LANG_ALIAS_TOO_MANY "Too many aliases defined, you can't define any more.\n"
#define _LANG_ALIAS_TOO_LONG "Alias too long.\n"
#define _LANG_ALIAS_NOT_ALLOWED "That is not allowed.\n"
#define _LANG_ALIAS_CHANGED "Ok, alias '" + s1 + "' defined.\n"
#define _LANG_ALIAS_SYNTAX "Syntax: " + query_verb() + " <alias>\n"
#define _LANG_ALIAS_REMOVED "Ok, alias '" + str + "' removed.\n"
#define _LANG_ALIAS_NO_RECURSIVE "Recursive aliases? That is not allowed.\n"

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

// read.c

#define _LANG_READ "You read:\n" + str +"\n"
#define _LANG_READ_IN_LANGUAGE "You read a text written in " + lang + ":\n" + str + "\n"
#define _LANG_READ_UNABLE_WITH_GARBLE "You aren't able to understand the following text:\n" + \
        str + (lang ? "\nIt seems written in " + lang + "." : "") + "\n"
#define _LANG_READ_WHAT "You could have sworn there was something written here...\n"; 
#define _LANG_READ_UNABLE_WITHOUT_GARBLE "You aren't able to understand the text" + \
        (lang ? ", it seems written in " + lang : "") + ".\n"
#define _LANG_READ_IMPOSSIBLE "All of " + mud_name() + " trembles when you find a magical text " + \
        "without any way to be interpreted.\n"
