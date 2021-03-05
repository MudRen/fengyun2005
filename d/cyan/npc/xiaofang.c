// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("小舫", ({ "xiao fang","fang","xiaofang" }) );
        set("title",RED"枫叶境"NOR);
		set("nickname",WHT"只是在想着你"NOR);
        set("gender", "男性" );

//		set("group","couple");

		set("age",16);

set("long","\n");

	set("chat_chance",1);
	set("chat_msg", ({
		"小舫搔着头说：你真的不愿意给我一次机会，让我们忘记过去，重新开始？\n",
		"小舫叹道：只不见你之后半刻，我便开始后悔了，后悔得无以复加。\n",
		"小舫苦笑道：我从不曾求你。便求你饶我一次不行？\n",
	}) );

        set("reward_npc", 1);
        set("difficulty",11);	// Big big npc.

		set("no_arrest",1);

        set("combat_exp", 10000000);
		set("class","wudang");

		set_skill("changelaw",320);

		set_skill("force",320);
		set_skill("divineforce",200);
		map_skill("force","divineforce");


		set_skill("dodge",320);
		set_skill("stormdance",200);
		map_skill("dodge","stormdance");

		set_skill("sword",320);
		set_skill("taiji-sword",240);
		map_skill("sword","taiji-sword");

		set_skill("parry",320);
		map_skill("parry","taiji-sword");


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

		setup();

        carry_object(__DIR__"obj/xiaosword2")->wield();
        carry_object(__DIR__"obj/xiaocloth2")->wear();

}


void smart_fight()
{
	object me,target;
	me = this_object();
	target = select_opponent();

	if (ccommand("perform force.check_gspm"))
	{
		ccommand("perform force.guishenpomie");
		stop_busy();
		return;
	}
	ccommand("perform sancai");
}


void die()
{
	object me = this_object();
	object he;
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");

	message_vision(CYN"\n小舫跌跌撞撞，后避到争雄崖边"NOR,me);

	he = present("xiao wu",environment());
	if (he)
		message_vision(CYN"，望着身侧的$N，伸出沾满鲜血的手掌。\n\n"NOR,he);
	else
	{
		message_vision(CYN"。\n\n"NOR,me);
	message_vision(CYN"小舫叹了口气，低声道：若能让我再一次见到你．．\n\n"NOR,me);
	message_vision(HIB"小舫一扭头，自崖上直跃而下，在云中失了身影。\n\n"NOR,me);
	}
	if (he)
		he->icic(me);
	
	move(room);
	::die();

}

int icic(object he)
{
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");


	message_vision(CYN"小舫一声惊呼，疾冲至争雄崖边，然而只有白云清风，在崖外无端徘徊。\n\n"NOR,he);
	message_vision(HIY"小舫紧紧握住手中长剑，浑身发颤，骤然大喝一声，冲出悬崖．．．\n\n"NOR,he);

	move(room);
	::die();
}
