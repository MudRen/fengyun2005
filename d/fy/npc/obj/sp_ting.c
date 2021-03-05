#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("木琴", ({ "ting","qin" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 2000);
		set("material", "wood");
		set("long", "一个古色古香、然而却是新仿制出的木琴。（琴质5）\n");
		set("timbre",5);
		set("wield_msg","$N从怀里取出一张$n，信手一划，泉水般的琴声从指尖流泻而出。\n");
		set("unwield_msg","$N将$n收起在身后。\n");
	}
	::init_staff(5);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_play","play");
}


int do_play(string arg)
{
	object me;
	me = this_player();
	if (!arg || (arg!="qin" && arg!="木琴" && arg!="琴" && arg != "ting"))
		return notify_fail("你要弹什么？\n");
	if (!me->query("annie/古松琴"))
		return notify_fail("你心里一片空白，不知道该弹什么。\n");
	message_vision("$N一划木琴，忽然想起古松琴曲，指下随意挥洒，乐声行云流水般流出。\n",me);
	me->set_temp("played_qin",1);
	return 1;
}
