// - neon

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(MAG"九佩"NOR, ({ "jiupei", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 60);
		set("long", "这是一把唐琴，漆色富贵喜伏羲式，形体饱满，上髹紫漆，间杂朱砂补
之色， 声形俱佳，为传世之极品。。\n");
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N缓缓拨动琴弦，"MAG"九佩"NOR"发出玲珑之声，宛若空山新雨。\n",this_player());
	return 1;
}













