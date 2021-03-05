// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();

void create()
{
	object weapon;
        set_name("今田魅知子", ({ "konda michiko","konda", "michiko" }) );

        set("gender", "女性" );
		set("age",27);

        set("long","虽然蒙著面孔，你依然可以自她姣好的身段上推出．．．\n");



	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",MAG"真信"NOR);
	set("title","流浪倭人");

        set("combat_exp", 5000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("kongshoudao", 200);
        set_skill("ghosty-steps", 220);

		set_temp("no_busy",3);
		set("no_busy",3);

		set("max_kee",12000);

        map_skill("unarmed", "kongshoudao");
        map_skill("dodge", "ghosty-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("夜行装", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("蒙面巾", ({ "mask" }) );
		weapon->set("armor_worn","笼著");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wear();



}

void smt_fight()
{
	set("bellicosity",1);
	ccommand("perform yaozhan");
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	
	message_vision(HIB"\n今田魅知子一扬手，烟雾突在你眼前爆开。\n等到烟雾散尽，人已离去。",me);

	tell_object(me,MAG"\n你心神稍定，擦了擦额头，才发现额前的头发已湿了一片；方才这个
女子出手尽得快狠准精要，实在是一个难缠的对手。\n\n"NOR);
	
	tell_object(me,WHT" 遥远的山间传来飘渺不定的笛音，笛声中你隐约听到有清凉的嗓音在
唱：枝上花，花下人，可怜颜色俱青春。昨日看花花灼灼，今朝看花花欲落．．．

"CYN"你慢慢合上眼睛，让一阵无边的倦意袭卷而下．．．\n"NOR);

	me->set_temp("disable_inputs",1);
	call_out("do_no",1,me);

//	me->leftnow();

//	::die();
	return;
}

void do_no(object me)
{
	if (objectp(me)) {
		me->delete_temp("disable_inputs");
		me->leftnow();
		return;
	}
	if (objectp(this_object()))
		::die();
}