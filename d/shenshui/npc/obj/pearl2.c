#include <ansi.h>
inherit ITEM;

void create()
{
    	int	i;
        set_name(HIW"大珍珠"NOR, ({ "pearl"}) );
    	set("unit", "个");
    	set_weight(200);
    	set("value",1000000);
    	set("lore",1);
    	set("long", "一粒洁白滚圆的大珍珠，价值连城。\n");
                                            
   	::init_item();
}
