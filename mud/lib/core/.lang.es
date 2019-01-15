
// login.c

#define _LANG_LPMUD_VERSION "Versi�n de LPmud: "
#define _LANG_MUDLIB_VERSION "Versi�n de Mudlib: "
#define _LANG_PATCH_VERSON "�ltimo parche: "
#define _LANG_LANGUAGE_VERSION "version en castellano"

#define _LANG_WHO_COMMAND "who"
#define _LANG_CREATE_COMMAND "crear"
#define _LANG_FINGER_COMMAND "finger"

#define _LANG_WORLD_STILL_BEING_CREATED "El mundo a�n se est� formando, int�ntalo de nuevo en unos minutos.\n"
#define _LANG_TOO_MANY_PLAYERS "Hay demasiados jugadores conectados, int�ntalo dentro de unos minutos.\n"
#define _LANG_ENTER_AN_OPTION "Introduce la opci�n elegida: "
#define _LANG_TIMED_OUT "Se termin� el tiempo.\n"
// #define _LANG_COME_AGAIN_SOON "�Vuelve dentro de poco!\n"
#define _LANG_OPTION_STRING_TOO_SHORT "La opci�n introducida es demasiado corta, el m�nimo son " + MIN_LEN + " caracteres.\n"
#define _LANG_INVALID_CHARACTER "Caracter inv�lido '" + str[tmp..tmp] + "' en (" + str + ").\n"
#define _LANG_PLAYER_ACCESS_FORBIDDEN "El acceso a jugadores no est� permitido en estos momentos.\n"
#define _LANG_ANSWER_YES_NO "Debes responder s� o no (s/n): "
#define _LANG_YES_OPTIONS_ARRAY ({ 's', 'S' })
#define _LANG_NO_OPTIONS_ARRAY ({ 'n', 'N' })
#define _LANG_TRY_AGAIN "De acuerdo, int�ntalo de nuevo.\n"

#define _LANG_ENTER_EMAIL "Introduce tu direcci�n de email: "
#define _LANG_ENTER_VALID_EMAIL "\nIntroduce una direcci�n de email v�lida: "
#define _LANG_USED_EMAIL "Lo sentimos, pero esa direcci�n ya est� utilizada.\n" + \
      "Por favor, introduce otra direcci�n de email: "
#define _LANG_ACCOUNT_RECOMMEND "Si ya tienes otra cuenta en " + mud_name() + ", recomendamos " + \
      "encarecidamente que crees tus " + \
      "distintos personajes dentro de la misma cuenta, ya que esto tiene muchas ventajas a la " + \
      "hora de compartir objetos, recursos, logros, etc.\n"
#define _LANG_ACCOUNT_NAME_CHOSEN "Has escogido como nombre de cuenta: '" + account_name + "', �est�s seguro? (s/n): "
#define _LANG_DEFINE_ACCOUNT_PASSWORD "Introduce la contrase�a que estar� asociada a tu cuenta: "
#define _LANG_DEFINE_ACCOUNT_PASSWORD_REPEAT "Repite la contrase�a para confirmar que no hay ning�n error: "
