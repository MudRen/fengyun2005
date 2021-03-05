inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	object weapon;
    set_name("铁寒魂", ({ "hanhun" }) );
    set("gender", "男性" );
    set("age", 63);
    set("title", HIB "名剑铸手"NOR);
    set("long",
      "铁寒魂已经很老了，老得几乎挥不动那把大锤，\n然而他曾经打造过的兵器，却依然是魔\n教中人最爱用的珍品。\n");
    set("attitude", "friendly");
    set("class","demon");
    set("combat_exp",4200000);
	set("vendor_goods", ([
	"/obj/generate/commonweapon/60/axe":20,
	"/obj/generate/commonweapon/60/blade":20,
	"/obj/generate/commonweapon/60/fist":20,
	"/obj/generate/commonweapon/60/hammer":20,
	"/obj/generate/commonweapon/60/spear":20,
	"/obj/generate/commonweapon/60/staff":20,
	"/obj/generate/commonweapon/60/sword":20,
	"/obj/generate/commonweapon/60/throwing":20,
	"/obj/generate/commonweapon/60/whip":20,
	]) );

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: auto_smart_fight(20) :),
      }) );

	auto_npc_setup("disciple",180,160,0,"/obj/weapon/","fighter_w","dragonwhip2",4);
    setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"蓝衣"NOR, ({ "cloth"}) );
	weapon->set("long"," ");
	weapon->set("value",0);
	weapon->wear();
}


void init()
{
    add_action("do_vendor_list", "list");
    ::init();
}


void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/60/axe":20,
	"/obj/generate/commonweapon/60/blade":20,
	"/obj/generate/commonweapon/60/fist":20,
	"/obj/generate/commonweapon/60/hammer":20,
	"/obj/generate/commonweapon/60/spear":20,
	"/obj/generate/commonweapon/60/staff":20,
	"/obj/generate/commonweapon/60/sword":20,
	"/obj/generate/commonweapon/60/throwing":20,
	"/obj/generate/commonweapon/60/whip":20,
	]) );
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

