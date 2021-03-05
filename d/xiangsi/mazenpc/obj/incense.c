#include <ansi.h>
inherit ITEM;
string description();

void create()
{
        set_name("梦甜香", ({ "incense" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 50000);
                set("material", "herb");
				set("no_drop",1);
				set("no_clean_up",1);

        }
}

int do_sleep(object me)
{
	int gin,kee,sen;
	mapping buff;
      	message_vision(CYN"\n$N燃起梦甜香，散发出幽幽的香气，熏得你打了一个哈欠,", me);
      	tell_object(me, "很快你就觉得睡意朦胧。\n\n");
      	message("vision", me->name()+"在地上和衣一躺，很快就进入了梦乡。\n\n", environment(me), me);
		  gin = me->query("max_gin");
		  me->set("eff_gin", gin);
		  me->set("gin", gin);
		  kee = me->query("max_kee");
		  me->set("eff_kee", kee);
		  me->set("kee", kee);
		  sen = me->query("max_sen");
		  me->set("eff_sen", sen);
		  me->set("sen", sen);
			me->status_msg("all");
	  		buff =
			([
				"caster":me,
				"who":me,
				"type":"freeze",
				"att":"curse",
				"name":"皓月天宫·梦甜香",
				"buff1":"disable_inputs",
				"buff1_c":1,
				"buff2":"is_unconcious",
				"buff2_c":1,
				"buff3":"block_msg/all",
				"buff3_c":1,
				"disable_type":HIG " <睡梦中>"NOR,
				"time":20+random(20),
				"buff_msg":"\n$N在地上和衣一躺，很快就进入了梦乡。\n\n"NOR,
				"disa_msg":CYN"\n\n$N睁开了眼睛，一个鲤鱼打挺跳了起来。\n"NOR,
				"disa_type":1,
			]);
			ANNIE_D->buffup(buff);
      	move(load_object("/obj/void"));
		destruct(this_object());
      	return 1;
}


void init()
{
	object me;
	me = this_player();
	if (me && userp(me))
	{
		me->start_busy(1);
		call_out("do_sleep",1,me);		
	}
}
    
    
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
