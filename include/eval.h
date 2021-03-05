
#include <location.h>

#define PRINT(x)        printf("%O\n", x)
#define write(x)        PRINT(x)

#define ME              this_player()
#define MY_ENV          environment(this_player())
#define MY_NAME         this_player()->query_idname()

#define USER(x)         find_player(x)
#define USER_ENV(x)     environment(find_player(x))
#define USER_NAME(x)    find_player(x)->query_idname()

#define ENV(x)          environment(x)


