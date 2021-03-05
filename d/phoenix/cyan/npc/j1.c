// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();

void create()
{
	object weapon;
        set_name("饭冢", ({ "samurai iizuka","iizuka", "samurai" }) );

        set("gender", "男性" );
		set("age",47);

        set("long","一个双手持长刀，混身带著无限杀气的倭人。\n");



	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",MAG"绝情"NOR);
	set("title","流浪倭人");

        set("combat_exp", 2900000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


        set_skill("blade", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("ittouryu", 300);
        set_skill("ghosty-steps", 220);

		set_temp("no_busy",3);
		set("no_busy",3);

		set("max_kee",16000);

        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("dodge", "ghosty-steps");

		setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(RED"野太刀"NOR, ({ "no-dachi" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("青灰衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("大斗笠", ({ "hat" }) );
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wear();



}

void smt_fight()
{
	set("bellicosity",1);
	ccommand("perform hyakki");
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	
	message_vision(HIR"\n饭冢满脸是血，仰天大叫道：八嘎～～～～\n"NOR+CYN"你获得了一个大馒头。\n"NOR,me);

	if (REWARD_D->riddle_check(me,"韶光虚掷") == 3) 
		REWARD_D->riddle_set(me,"韶光虚掷",4);

	tell_object(me,HIC"\n冥冥之间似有一个声音在你心中道：两月前夜魔坛主定计假意取信倭贼，在诱出尽数情报后
又暗以谣言流传给中原各派知晓，神教于此事上业已仁至义尽，何用再助那些名门正道？\n\n"NOR);
	
	tell_object(me,HIY"你的任务改变了！\n"NOR);

	me->set("quest/short", WHT"到附近打听"CYN+"饮血平寇"+WHT"大会之事"NOR);
	me->set("quest/location", "明霞山上");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());

	new("/obj/food_item/newbie_food")->move(me);

	::die();
	return;
}