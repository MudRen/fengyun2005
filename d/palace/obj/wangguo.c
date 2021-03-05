inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG"忘魂果"NOR,({"wangguo"}));
  set("long", HIG
      "这是一颗人们在求生无望，为了减轻死前的痛苦\n"
      "用来解脱（ｄｉｅ）的毒果。\n"NOR);
  set("value",100);
  set("unit","棵");
}

void init()
{
  if(this_player()==environment())
  add_action("do_cure","die");
}

int do_cure()
{
	object me;
	me = this_player();
	message_vision("$N把忘魂果一口吞了下去！\n",me);
	me->clear_condition();
	me->unconcious();
	destruct(this_object());
	return 1;
}
