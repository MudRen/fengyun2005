#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("象牙软榻", ({ "ivory bed"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "张");
	set("desc", "一张白玉般的象牙雕作而成的软榻，榻上被褥枕叠，睡上去一定舒服极了。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","o");
	set("size",2);
set("tax",80);
set("score_tax",10);
	set("value", 800000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_sleep","sleep");
}


int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen;
	mapping buff;
	function f;

   me = this_player();
   obj = this_object();
	if (!environment(me)->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
   if (me->is_fighting() || me->is_busy()) return 1;
   if (query_temp("marks/taken")) {
      tell_object(me, "床上有人耶．．．．\n");
      return 1;
   }
  message_vision("$N揉揉眼、打个哈欠，躺到了床上，", me);
  tell_object(me, "很快你就觉的睡意朦胧。\n");
  obj->set_temp("marks/taken", 1);
  gin =  me->query("eff_gin");
  kee =  me->query("eff_kee");
  sen =  me->query("eff_sen");
  me->set("gin", gin);
  me->set("kee", kee);
  me->set("sen", sen);
	f = (: call_other, __FILE__, "fullnpc",obj :);

		buff =
		([
			"caster":me,
			"who":me,
			"type":"freeze",
			"att":"bless",
			"name":"江门居家·象牙软榻",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"buff3":"block_msg/all",
			"buff3_c":1,
			"disable_type":HIG " <睡梦中>"NOR,
			"time":10+random(10),
			"buff_msg":"$N翻了几个身，找到个舒适的姿势，很快就进入了梦乡。\n"NOR,
			"disa_msg":CYN"\n$N睁开了眼睛，一个鲤鱼打挺从床上跳了下来。\n"NOR,
			"disa_type":1,
				"finish_function":bind(f, this_object()),
		]);
		ANNIE_D->buffup(buff);

      return 1;
}


void fullnpc(object target,int i)
{
	if (!target)
		return;
	target->delete_temp("marks/taken");
	return;
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
