#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
    set_name(HIY"金链子"NOR, ({ "gold chain" , "chain"}) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "条");
            set("material", "gold");
            set("value",100);
            set("long", "一条金光闪闪链子，上面还挂着个金鸡心，看起来很值钱。\n");
            set("wear_msg", "$N轻轻地把一条$n戴在脖子上。\n");
	    set("unwield_msg", "$N轻轻地把$n从脖子上除了下来。\n");
          }
	::init_neck();
}
