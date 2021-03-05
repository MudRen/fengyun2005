inherit ITEM;
#include <ansi.h>

void create()
{
    	int	i;

    	string *names = ({
        	HIR"红水晶"NOR ,HIB"蓝水晶"NOR,
    	});
	
	string *ids = ({"red crystal","blue crystal",});
	
    	i = random(2);
    	set_name(names[i], ({ ids[i],"crystal",}) );
    	set_weight(100);
	set("unit", "粒");
        set("long", "一粒散发出幽幽莹光的水晶石。\n");
        set("value", 500);
        set("lore",1);
	::init_item();
}