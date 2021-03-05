// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name("小丫鬟", ({ "xiao yahuan", "yahuan","girl" }) );
	set("class","moon");
	set("gender", "女性" );
	set("age", 15);
	set("str",20);
	set("force_factor",30);
	set("per", 27);
	set("attitude", "friendly");
	set("long","一个坐在井边打盹的小丫鬟。\n");

	set("nickname",CYN"正在打盹的"NOR);
	set("title","皓月宫"NOR);

	set("inquiry",([
       	"*": 	"不要吵我．．\n小丫鬟又朦朦胧胧的沉进梦乡。",
    	]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"小丫鬟睡眼惺忪的喃喃自语：天天喝这水，真是会冻死人．．\n",
		"小丫鬟神秘兮兮地说：不知道二师姐的那把寒泉刀，是不是就是在这里淬练（dip）出来的。\n",
		"小丫鬟窃窃私语，听说只要练好了冰境七诀，就能从湛蓝姐姐那儿学到咱们皓月宫的幻念聆音。\n",
	}) );

	set("no_arrest",1);

	set_temp("condition_type",CYN" <睡眠中>"NOR);

	set("combat_exp", 500000);

	set_skill("tenderzhi", 90);
	set_skill("unarmed", 120);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("unarmed", "tenderzhi");
	setup();

	carry_object(__DIR__"obj/wcloth")->wear();

}

void init()
{
	if (!is_fighting())
		set_temp("condition_type",NOR CYN" <睡眠中>"NOR);
}

int kill_ob(object who)
{
	if (query_temp("condition_type"))
	{
		delete_temp("condition_type");
		ccommand("wake");
		ccommand("ack "+who->get_id());
	}
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();
	target = select_opponent();
	if( ANNIE_D->check_buff(target,"freeze")) 
		return;

	message_vision(WHT "\n小丫鬟手忙脚乱的从不老寒泉中拎起一桶水，对着$N泼去！\n",target);

		buff =
		([
			"caster":me,
			"who":target,
			"type":"freeze",
			"att":"curse",
			"name":"不老寒泉·千冰冻魄",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <冻僵中>"NOR,
			"time":4+random(4),
			"buff_msg":HIW"奇冷的寒气包围了$N的全身，将$N冻成了一块冰雕！\n"NOR,
			"disa_msg":HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
	if (random(2))
		ccommand("giggle "+target->get_id());
	else
		ccommand("fox");
}

void die()
{	
	object me,target;
	mapping buff;
	me = this_object();
	target = query_temp("last_damage_from");
	if (!target)
	{
		::die();
		return;
	}
	if( ANNIE_D->check_buff(target,"freeze")) 
		return;

	message_vision(WHT "\n小丫鬟用尽最后的力气，将桶中剩下的寒泉水泼向$N。\n",target);

		buff =
		([
			"caster":me,
			"who":target,
			"type":"freeze",
			"att":"curse",
			"name":"不老寒泉·千冰冻魄",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <冻僵中>"NOR,
			"time":6+random(16),
			"buff_msg":HIW"奇冷的寒气包围了$N的全身，将$N冻成了一块冰雕！\n"NOR,
			"disa_msg":HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
	message_vision(CYN"小丫鬟只觉心中酸楚，对"+target->name()+"长叹一声道：人生不如意之事，常十之八九，我死先，你快点来。\n"NOR,target);
	::die();
}



void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("duck "+who->query("id"));
	if (!is_fighting())
	{
		message_vision(CYN"小丫鬟擦了擦衣袖，又倚着井壁开始打盹。\n"NOR,who);
		set_temp("condition_type",NOR CYN" <睡眠中>"NOR);
	}
}
