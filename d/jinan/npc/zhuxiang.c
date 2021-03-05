// waiter.c
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
    set_name("朱香", ({ "zhu xiang","zhu","zhuxiang","xiang" }) );
	set("gender", "女性" );
	set("age", 21);
	set("price_modifier",500);
	set("per",36);
	set("score",-32);
	set("str",14);
	set("title",WHT"只那时盈香满袖"NOR);
	set("nickname",MAG"雪如初积 人如初见"NOR);
	set("long","一个清秀动人的长发少女，斜倚著烟水亭的扶栏，\n正想著自己的心事。\n");
	set("combat_exp", 5200000);
	set("attitude", "friendly");

	set("no_arrest",1);
	
	set("chat_chance",1);
	set("chat_msg", ({
		CYN"朱香长长的睫毛下笼着一层水雾，泪光点点，看起来分外动人。\n"NOR,
		CYN"朱香咬着嘴唇，轻轻抚著扶栏：竹马……人家好想你……\n"NOR,
		CYN"朱香向你幽婉一笑：在别人的剧本中蹉跎半生，到最后却发现自\n己不过是个配角．．你觉得我家的竹马，是不是好傻好傻？\n"NOR,
		CYN"朱香低低吟咏：\n冬夜夜寒觉夜长，沉吟久坐坐北堂。\n冰合井泉月入闺，金缸青凝照悲啼。\n金缸灭，啼转多，\n掩妾泪，听君歌。\n歌有声，妾有情，\n情声合，两无违。\n一语不入意，从君万曲梁尘飞。\n"NOR,
		CYN"朱香轻叹道：一语不入意，从君万曲梁尘飞．．．．便是这样的\n了，所有我所不能道的，前人都已经替我道出了。\n"NOR,
		CYN"朱香慢慢合眼，一滴晶莹的泪珠缓缓滑过莹玉般的脸颊，打落在\n石桌上，飞溅四碎。\n"NOR,
		CYN"朱香望著亭外的云霞变幻，久久不发一语。\n"NOR,
		CYN"朱香低头看著自己的手，慢慢地说：我们彼此如此地贪恋了，却\n还是得不到彼此的欢心……可是，又能怪谁呢。\n"NOR,
		CYN"朱香斜倚著扶栏，垂头道：竹马，你说你跋涉三千里，追寻十一\n年未能做到的，别人只花了十分之一的代价便做到了．．可你，\n怎会不知我的心情？\n"NOR,
		CYN"朱香凄楚一笑：明年织巧？呵，明年织巧，永远不是今朝今夕。\n"NOR,
		CYN"朱香轻扯著自己的长发，低声道：不．．．竹马，我不企盼，也\n不希望。没有希望，就没有绝望。很久以前，我就决定不再绝望了。\n"NOR,
		CYN"朱香轻轻地拥住自己，脸上露出孤寂的表情。\n"NOR,
		CYN"朱香幽幽道：佳期不可再，风雨杳如年．．．风雨杳如年．．．\n"NOR,
		CYN"朱香望著大明湖波光荡漾，微微而笑：竹马，你还记得，当年我\n们曾携手在这里折出那么多的小船么？\n"NOR,
	}) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );

		set("death_msg",CYN"\n$N捂着心口，踉跄了两步，咬牙道：你……好狠心……\n"NOR);

		setup();

		carry_object("/d/bashan/npc/obj/stone")->wear();

	
	weapon = carry_object("/d/huashan/npc/obj/qingcong");
	weapon->set_name(WHT"风雨长烟"NOR, ({ "slippery sleeve" }) );
	weapon->set("unit", "双");
	weapon->set("long", "\n");
	weapon->set("weapon_wielded","笼");
	weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(MAG"淡紫云袍"NOR, ({ "longskirt" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/boots");
        weapon->set_name("素色绣鞋", ({ "shoes" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",150,200,0,"/obj/weapon/","fighter_w","daimonsword2",4);

}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "朱香抬头看了你一眼，嘴唇蠕动了两下，又低下头去。\n");
			break;
		case 1:
			say( "朱香默默地望著烟水亭外的云霞，有清泪缓缓滚落大明湖中。\n");
			break;
	}
}


int accept_object(object who, object ob)
{
	object me = this_object();

	if (query("ggyying"))
		return notify_fail(CYN"朱香现在正忙，显然没空理你。\n"NOR);
	if (!ob->query("real") || ob->query("id") != "paper boat" 
		|| REWARD_D->riddle_check(who,"七夕别离")!=1)
//		|| who->query("annie/void") != 1)
		return 0;
	set("ggyying",1);
	message_vision(CYN"\n$N低下头，看看手中的纸折小船，又看看$n：这是他给我的么？\n"NOR,me,who);
	set("chat_chance",0);
	who->start_busy(9);
	call_out("do_ggyy",3+random(2),me,who,0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$N微微一笑，向远方望去：这么久了，还是放不下么．．．",
"$N的眼中有些朦胧，慢慢的说：呵．．．不过是一场随处可见的误会和遗憾，他竟然还没有释怀呢。
拼将一生休，尽君一日欢．．．那都是很久很久以前，对我而言早已经过去的事了。",
"\n说到底，就是一场，无限繁华，无限旖旎，的，大戏啊．．．\n$N遥遥地看著大明湖上夕阳残照，柔声道：一生倥傯一生休，便一生只做一件事情也罢．．．\n请告诉他，就说我说＂"WHT"青梅已不可能回头了，我们缘分已尽"CYN"＂，叫他．．不用再念着我了。",
});

	set("chat_chance",1);

	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,me,target);
	set("chat_chance",0);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",3+random(2),me,target,count+1);
	else
	{
		set("ggyying",0);
		REWARD_D->riddle_set( target,"七夕别离", 2);
//		target->add("annie/void",1);
		set("chat_chance",1);
		return;
	}
	return;
}
