//游荡 徘徊 静默 慌张 愤恨 迷失 错乱 

#include <ansi.h>
//inherit SMART_NPC;
inherit __DIR__"mazenpc.c";
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("迷失的怨魂", ({ "ghost" }) );
	set("gender", "男性" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set("target_name","迷失的怨魂");

	if (!random(10))
		set("attitude", "aggressive");

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(20) :),
	}) );

	set("combat_exp", 7000000);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"迷失的怨魂坐在地上，哈哈笑道：看见没？看见没？这是皇上的玉玺啊！\n"NOR,
	}) );

	setup();

	set_skill("spear",300);
	set_skill("eclipse-spear",220);
	map_skill("spear","eclipse-spear");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("锦绣黄袍", ({ "cloth" }) );
	weapon->set("long","一件破破烂烂的黄袍。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/spear");
	weapon->set_name(HIW"重机长枪"NOR, ({ "spear" }) );
	weapon->set("long","这是柄当年南疆第一铸铁师重机先生精心打造的长枪。\n");
	weapon->set("value",0);
	weapon->wield();
}


void init(){
	::init();
//	add_action("do_go", "go");
}


int do_go(string arg) {
	if (!arg)
		return 0;
	if (query("attitude") != "aggressive")
		return 0;
	message_vision(CYN"$N荷荷作声，对着$n怪笑道：你要去哪里？先还我的命来．．．\n",this_object(),this_player());
	return 1;
}


int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight(100);	// rascal design :p
	return 1;
}

void smart_fight(int t)
{
	if (t <= random(100))
		return;

	ccommand("perform riyuetongtian");
	return;
}

int is_ghost()
{
	return 1;
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
