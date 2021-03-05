#include <weapon.h>
#include <ansi.h>
//inherit ITEM;
inherit DAGGER;
void create()
{
        set_name( HIG"玉萧"NOR , ({"yuxiao"}) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 100000);
                set("material", "jade");
				set("long",

"一根用东海千年温玉做成的玉萧。\n"
);
                set("wield_msg", "$N将$n握在手中作为武器。\n");
        }
        init_dagger(70);
        setup();
}
