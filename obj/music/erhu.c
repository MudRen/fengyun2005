#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("二胡琴", ({ "erhu", "er hu", "二胡琴" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("timbre",10);
		set("material", "wood");
		set("long", "一个古色古香的二胡琴。（琴质10）\n");
		set("wield_msg","$N从怀里取出一张$n，信手一划，泉水般的琴声从指尖流泻而出。\n");
		set("unwield_msg","$N将$n收起在身后。\n");
	}
	::init_staff(1);
}

void init()
{
   	if (environment()==this_player())
   		add_action("do_play","play");
}


int do_play(string arg)
{
   	object me;
   	me = this_player();

   	if (!arg || arg != "qin") {
      		tell_object(me, "你要做什么。\n");
      		return 1;
   	}
   	message_vision("$N随意拨弄了几下"+name()+"，但觉洋洋洒洒，虽不成曲，却也别有意趣。。\n",me);
   	return 1;
}
