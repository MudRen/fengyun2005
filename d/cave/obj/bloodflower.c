inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIB"碧血海棠"NOR,({"bloodflower"}));
  set("long", HIB
      "这是一株在不见天日下的黑暗中成长的碧血海棠花，汲取着鲜血而生，也会带来神秘的生机。\n据传亡命的刺客们都是用它来汲取（absorb）生命的力量。。\n"NOR);
  set("value",0);
  set("unit","株");
}

void init()
{
  if(this_player()==environment())
  add_action("do_cure","absorb");
}

int do_cure()
{
	object me;
	me = this_player();
    message_vision(HIB"$N忘情地将碧血海棠放入嘴中，贪婪地汲取着所有的惨碧的汁液。。\n"NOR,me);
	me->clear_condition();
	me->unconcious();
	destruct(this_object());
	me->unconcious();
  return 1;
}
