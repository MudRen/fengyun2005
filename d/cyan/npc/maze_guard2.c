//游荡 徘徊 静默 慌张 愤恨 迷失 错乱 

#include <ansi.h>
//inherit SMART_NPC;
inherit __DIR__"mazenpc.c";
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("徘徊的怨魂", ({ "ghost" }) );
	set("gender", "男性" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set("target_name","徘徊的怨魂");
	
	if (!random(10))
		set("attitude", "aggressive");

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(20) :),
	}) );

	set("combat_exp", 7000000);
	set("m_success/销魂传人",1);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"徘徊的怨魂在地上摸索：我的脚．．我的脚哪里去了．．．\n"NOR,
	}) );

	setup();

	set_skill("sword",400);
	set_skill("xiaohun-sword",220);
	map_skill("sword","xiaohun-sword");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("止郊纹衣", ({ "cloth" }) );
	weapon->set("long","这是昔日止郊山庄门下的装束，只是早已在江湖中绝迹多年。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name("断掉的断掉的长剑", ({ "broken sword","sword" }) );
	weapon->set("long","一把断得几乎只剩下剑柄的剑。\n");
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

	ccommand("perform libie");
	if (query("timer/libie") +3 >= time())
		set("timer/libie",time()-270);
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


// call mingyue->set(annie_quest/name,明霞山杀鬼);call mingyue->set(annie_quest/number,1);update /d/cyan/npc/maze_guard2;clone
