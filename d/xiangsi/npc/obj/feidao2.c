// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("玉竹屑", ({ "bamboo shard","shard" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "片");
                set("base_weight", 1);
                set("base_value", 0);
                set("material", "wood");
                set("long",     "一把自竹上抓下的碎屑。\n");
                set("volumn",50);
        }
        set_amount(50);
		::init_throwing(15);
}

