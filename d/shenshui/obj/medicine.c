//XXDER
inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"九转还魂丹"NOR, ({ "pill", "magic pill" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  set("long", WHT
      "这是传说中的有起死回生功效的九转还魂丹．\n"
      "只要你还有一口气在，无论任何病痛它都可以治！\n"NOR);
		
		set("desc_ext","eat pill");
		set("unit", "颗");
		set("value", 1);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	object me;
	int gin, kee, sen;
	me = this_player();
	gin = (int) me->query("max_gin");
        kee = (int) me->query("max_kee");
        sen = (int) me->query("max_sen");
	message_vision( HIR "$N的脸上由白变红，红的象要滴出血来，慢慢的红色又退了下去！！\n"NOR, me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
	destruct(this_object());
        return 1;
}
