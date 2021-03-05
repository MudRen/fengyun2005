#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"极乐之星"NOR, ({ "stargem" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("value", 500);
 			set("no_drop",1); 
           	set("long", "一枚状如鸽卵、价值连城的宝石，为西域龟兹王之物。\n");
          }
	::init_item();
}
