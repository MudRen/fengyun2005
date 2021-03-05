#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("乾达婆部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "女性" );
	set("nickname",HIR"太极原生无极中 混元一气感斯通"NOR);
	
	set("attitude", "aggressive");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: smart_fightx() :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	set_skill("taiji",300);
	set_skill("unarmed",200);
	set_skill("five-steps",240);
	set_skill("dodge",200);
	set_skill("parry",200);
	map_skill("unarmed","taiji");
	map_skill("dodge","five-steps");
	
	set_skill("divineforce",200);
	map_skill("force","divineforce");

	setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("鲜红围衣", ({ "scarlet scarf","scarf" }) );
	weapon->set("long","鲜红围衣(Scarlet scarf)。\n");
	weapon->set("value",0);
	weapon->wear();

	set_temp("apply/damage",500);
}

void smart_fightx()
{
	object *tar;
	int i,j;
	object target;

	if (is_busy())
		return;

	tar = query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(HIY"\n$N使出武当派失传的借力打力功夫，左掌虚虚画了个半圆。\n$N沉气开声，大喝一声将右掌向场中拍去。\n"NOR,this_object());
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// 为了让parry busy生效(爆,太恶毒了),这里不使用mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,HIY"$N"HIY"只觉得一道大力推来，身不由己的向$n"HIY"攻去！"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
			target->receive_damage("kee",1,this_object());
		}
		perform_busy(2);
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
