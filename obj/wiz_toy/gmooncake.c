// dumpling.c


inherit ITEM;

inherit F_FOOD;
#include <ansi.h>;
void create()

{

string *order = ({"豆沙", "莲蓉", "枣泥", "凤梨", "百果"});
    set_name( order[random(5)] + "月饼", ({ "mooncake", "moon cake" }) );
	
set_weight(250);
	
if( clonep() )
		
set_default_object(__FILE__);

else {
		
set("long", "一个皮薄馅多香气扑鼻的月饼。\n");
		
set("unit", "个");

set("value", 500);
		
set("food_remaining",1);
		
set("material", "food");

set("no_drop", 1);
        set("no_get", 1);
        set("no_sell", 1);

      
       set("food_supply", 100);
		
       set("holiday", "中秋节");
	}
	 ::init_item();
}


int finish_eat()
{
	object me;
	me = this_player();
 	message_vision( HIY"$N只觉精神为之一振，整个人都看起来更有活力了。\n"NOR, me);

			me->add("max_mana",200);
                        me->add("max_force",200);
                        me->add("max_atman",200);
                        
                        
			
	destruct(this_object());
	return 1;
}
