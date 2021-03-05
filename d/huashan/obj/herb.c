inherit ITEM;
#include <ansi.h>
#include <condition.h>

void create()
{
  	set_name(MAG"紫烟草"NOR,({"ziyan","ziyan grass"}));
  	set("long", "一棵通体碧绿的小草，茎叶的背面微微透着紫色，据说可以解某一种奇毒（ｃｕｒｅ）。\n");
  	set("value",100);
  	set("unit","棵");
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure", "cure");
}

int do_cure()
{
	object me;
	me = this_player();
	message_vision("$N把紫烟草细细嚼烂咽了下去！\n",me);
	if (me->query_condition("canxia"))
		tell_object(me,"你中的"MAG"烟锁残霞"NOR"终于消失了。\n");
	me->change_condition_duration("canxia",0); 
	destruct(this_object());
        return 1;
}


