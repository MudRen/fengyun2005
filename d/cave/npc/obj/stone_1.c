inherit ITEM;
#include <ansi.h>

void create()
{
    	int	i;

    	string *names = ({
        	HIY"黄水晶"NOR ,HIG"绿水晶"NOR ,
    	});
	
	string *ids = ({"yellow crystal", "green crystal",});
	
    	i = random(2);
    	set_name(names[i], ({ ids[i],"crystal",}) );
    	set_weight(100);
	set("unit", "粒");
        set("long", "一粒散发出幽幽莹光的水晶石。\n");
        set("value", 200);
        set("lore",1);
	::init_item();
}