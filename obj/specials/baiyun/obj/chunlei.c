// - neon
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"春雷"NOR, ({ "chunlei", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 70);
		set("long", "琴体狭长，琴弦似乎较粗，看来需要很高的演奏技法。是古传名琴之一。\n");
		
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N凝神弹拨琴弦，"HIC"春雷"NOR"发出低沉的声响，如蛰雷初动，震撼心魂。\n",this_player());
	return 1;
}













