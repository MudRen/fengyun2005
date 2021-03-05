#include <ansi.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("夜叉部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );
	set("nickname",HIR"精 血 无 价"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(50) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","necromancy",1);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(BLU"血魂之衣"NOR, ({ "cloth"}) );
	weapon->set("long","一件带有斑斑血迹的蓝衣。\n");
	weapon->set("value",0);
	weapon->wear();

}

/*
void dispell(object me)
{
	me->die();
}

int kill_ob(object who)
{
	object corpse,me = this_object(),*enemy;
	int i,j;
	string str;
	seteuid(getuid());
	::kill_ob(who);
	set("atman",query("max_atman"));
	if (is_busy())
		return 1;

	if (random(2) == 1)
	{
	// exhume
		message_vision(HIB"$N口中喃喃地念著咒文，左手一挥，忽然，数团黑烟从地面上冒起！\n" NOR,me);
		message_vision(HIB"片刻，黑烟凝聚成人形，却没有一点生气。\n"NOR,me);
		for (i=0; i < random(4)+1; i++)
		{
			corpse = new("/obj/item/mocorpse");   
			corpse->set("name",HIR"恶魔"NOR);
			corpse->set("victim_name",HIR"恶魔"NOR);
			corpse->set("no_burn",1);
			corpse->set("long",
		"这是一团阴界邪恶精灵聚成的鬼气，青面獠牙，还长着一只犄角。\n");
			corpse ->move(environment(this_player()));
			message_vision("$N对著地上的$n喃喃地念了几句咒语，$n抽搐了几下竟站了起来！\n", me, corpse);
			corpse = corpse->animate(me, 300+random(100));
			corpse->start_call_out( (: call_other, __FILE__, "dispell", corpse :), 60);

				enemy = query_enemy();
				j = sizeof(enemy);
				while(j--) {
					if( enemy[j] && living(enemy[j]) ) {
						corpse->kill_ob(enemy[j]);
						if( userp(enemy[j]) ) enemy[j]->fight_ob(corpse);
						else enemy[j]->kill_ob(corpse);
					}
				}
		}
	}
	else
	{
		// sanqin sheet
		message_vision(HIC"$N集中精神，祭起三味真火，唿的一声燃起三清符，三道青气从头顶盘旋而起！\n"NOR, me);
		for (i=0; i < 3; i++)
		{
			str = "sanqing/sq"+(i+1);
			if (!query_temp(str))
			{
				me->add_temp(str,1);
				str = "/obj/npc/sq_guard"+(i+1);
				corpse =new(str);
				corpse->move(environment(me));
				corpse->invocation(me, 400);
				corpse->set("possessed", me);
			}
		}
		message_vision(CYN"$N呵呵笑道：死道友不死老道，三位道友拜托了！\n"NOR, me);
	}
	start_busy(2);
	return 1;
}

void smart_fightx()
{
	object corpse,me = this_object(),*enemy;
	int i,j;
	string str;
	seteuid(getuid());
	auto_smart_fight(100);	// rascal design :p
	if (is_busy())
		return;
	if (random(2) == 1)
	{
	// exhume
		message_vision(HIB"$N口中喃喃地念著咒文，左手一挥，忽然，数团黑烟从地面上冒起！\n" NOR,me);
		message_vision(HIB"片刻，黑烟凝聚成人形，却没有一点生气。\n"NOR,me);
		for (i=0; i < random(4)+1; i++)
		{
			corpse = new("/obj/item/mocorpse");   
			corpse->set("name",HIR"恶魔"NOR);
			corpse->set("victim_name",HIR"恶魔"NOR);
			corpse->set("no_burn",1);
			corpse->set("long",
		"这是一团阴界邪恶精灵聚成的鬼气，青面獠牙，还长着一只犄角。\n");
			corpse ->move(environment(this_player()));
			message_vision("$N对著地上的$n喃喃地念了几句咒语，$n抽搐了几下竟站了起来！\n", me, corpse);
			corpse = corpse->animate(me, 300+random(100));
			corpse->start_call_out( (: call_other, __FILE__, "dispell", corpse :), 60);

				enemy = query_enemy();
				j = sizeof(enemy);
				while(j--) {
					if( enemy[j] && living(enemy[j]) ) {
						corpse->kill_ob(enemy[j]);
						if( userp(enemy[j]) ) enemy[j]->fight_ob(corpse);
						else enemy[j]->kill_ob(corpse);
					}
	}			

		}
	}
	else
	{
		// sanqin sheet
		message_vision(HIC"$N集中精神，祭起三味真火，唿的一声燃起三清符，三道青气从头顶盘旋而起！\n"NOR, me);
		for (i=0; i < 3; i++)
		{
			str = "sanqing/sq"+(i+1);
			if (!query_temp(str))
			{
				me->add_temp(str,1);
				str = "/obj/npc/sq_guard"+(i+1);
				corpse =new(str);
				corpse->move(environment(me));
				corpse->invocation(me, 400);
				corpse->set("possessed", me);
			}
		}
		message_vision(CYN"$N呵呵笑道：死道友不死老道，三位道友拜托了！\n"NOR, me);
	}
	start_busy(2);

}


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
