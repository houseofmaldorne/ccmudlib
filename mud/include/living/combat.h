
#define FUMBLE "fumble"
#define HIT "hit"
#define MISS "miss"
#define DODGE "dodge"

#define ATT "%^BOLD%^%^GREEN%^# %^RESET%^"
#define DFF "%^BOLD%^%^RED%^* %^RESET%^"

#define SPE_ATT "%^BOLD%^%^GREEN%^# # %^RESET%^"
#define SPE_DFF "%^BOLD%^%^RED%^* * %^RESET%^"
#define SPE_FAIL "%^BOLD%^YELLOW%^~ ~ %^RESET%^"
#define SPE_INFO "%^BOLD%^YELLOW%^~ %^RESET%^"

// Tipos de combate
#define MORTAL_COMBAT 0
#define SAFE_COMBAT 1
#define COMBAT_MODE_STRINGS ({ "letal", "no letal" })

// Actitud de combate (combat role)
#define NEUTRAL_ROLE 0
#define DPS_ROLE 1
#define TANK_ROLE 2
#define HEALER_ROLE 3
#define COMBAT_ROLE_STRINGS ({ "cualquiera", "ofensiva", "defensiva", "de apoyo" })

#define COMBAT_ROLE_CHANGED_PROP "combat_role_changed"
