#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIW"玉壶冰"NOR, ({ "ice-qin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 50000);
		set("material", "wood");
		set("timbre",120);
		set("long",WHT"
直如硃丝绳，清如玉壶冰，其时名琴，传乃白云仙子琴心之物，后不知为何，
失落人间。（琴质60）\n"NOR);
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

   	if (!arg || arg != "qin" || arg != "ice-qin" ) {
      		tell_object(me, "你要做什么。\n");
      		return 1;
   	}
   	message_vision("$N随意拨弄了几下"+name()+"，清风拂面，若似冰心。\n",me);
   	return 1;
}
