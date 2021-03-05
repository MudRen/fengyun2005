#include <ansi.h>;
inherit ITEM;
void create()
{
        set_name("削断的梅枝", ({ "meizhi"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "段");
                set("long",
                        "一段两三尺长的梅枝，似乎是被什么利器削断。然而断口处很长，
几乎是平行着这根梅枝削下来的。\n");
                set("value", 100);
        }
}

void init()
{
	add_action("do_look","look");
}

int do_look(string arg)
{
	object me,meizhi;
	int i;
	me = this_player();
	if (arg != "meizhi" && arg != "削断的梅枝" && arg != "梅枝")
	{
		return 0;
	}
	if (!meizhi = present("meizhi",me))
	{
		return 0;
	}
/*	if (me->query_temp("lookmeizhi"))
	{
		return 0;
	}*/
	i = me->query_temp("looked");
	i = i + 1;
	me -> set_temp("looked",i);
	if ( i <=20)
	{
		return 0;
	}else 
	{
		if (random(6)&& !me->query_temp("lookmeizhi"))
		{
			tell_object(me, YEL"你观察着梅枝的断口，发现是这断口似乎是随随便便一剑斩开的。 \n"NOR);
		}else
		{
			tell_object(me,YEL "然而，你仔细察看，惊讶地发现这一剑之势，全按梅枝的纹理，丝丝 
入扣，宛如雕琢过一般。这一斩竟是你平生未见的绝妙剑法，你不禁 
动心，要仔细研究 (study)\n"NOR);
			me->set_temp("lookmeizhi",1);
			add_action("do_study","study");
		}
	}
	return 1;
}


int do_study(string arg)
{
	object me,meizhi;
	int i;
	me = this_player();
	if (arg != "meizhi" && arg != "削断的梅枝" && arg != "梅枝")
	{
		return 0;
	}
	if (!meizhi = present("meizhi",me))
	{
		return 0;
	}
	
	// the riddle is temperorily disabled
	me->set_temp("lookmeizhi",2);
	tell_object(me,YEL"你又研究了一会梅枝的断口，觉得这一剑实在奥妙得难以理解。\n "NOR);
	return 1;
		
	if (me->query("marks/少林_神剑") || (string)me->query("class") != "shaolin")
	{
		tell_object(me,"你无法从梅枝的断口中领悟任何东西。\n");
		return 1;
	}
	if (me->query("marks/少林_神剑_梅枝"))
	{

		tell_object(me,"你又研究了一会梅枝的断口，越来越觉得这一剑精妙入微，宛如天成。 \n");
		return 1;
	}
	if (me->query_temp("marks/少林_神剑_初级"))
	{
		me -> set_temp("looked",0);
		tell_object(me," 你又研究了一会梅枝的断口，觉得这一剑实在奥妙得难以理解。\n ");
		return 1;
	}
	i = me->query_temp("studied");
	i = i + 1;
	me->set_temp("studied",i);
	if (i == 4)
	{
		tell_object(me,"你无法从梅枝的断口中领悟任何东西，也许一尘大师能指点一二。 \n");
	}else if (i == 11)
	{
			if ((string)me->query("class") == "shaolin" && me->query_skill("sword",1)>=120)
			{
				tell_object(me,"你又研究了一会梅枝的断口，越来越觉得这一剑精妙入微，宛如天成。 \n");
				me->set("marks/少林_神剑_梅枝",1);
			}else
			{
				tell_object(me," 你又研究了一会梅枝的断口，觉得这一剑实在奥妙得难以理解。 ");
				me->set_temp("marks/少林_神剑_初级",1);
			}
			me -> set_temp("looked",0);
			me->set_temp("studied",0);

	}else
	{
		tell_object(me,"你无法从梅枝中领悟任何东西。\n");
	}
	return 1;
}