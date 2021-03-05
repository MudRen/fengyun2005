#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("胡琴", ({ "erhu", "er hu", "胡琴" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("timbre",10);
		set("material", "wood");
		set("long", "一个古色古香的胡琴。（琴质10）\n");
		set("weapon_prop/karma",3);
	}
	::init_staff(15);
}

void init()
{
   add_action("do_play","play");
}


int do_play(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "erhu") {
      tell_object(me, "你要拉什么。\n");
      return 1;
   }
   message_vision("$N一拉二胡琴，立时响起了一阵幽怨的琴声。\n",me);
   return 1;
}
