inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
    set_name("欧阳朔", ({ "ouyang shuo" }) );
    set("gender", "男性" );
    set("age", 39);
    set("title", MAG"紫电青霜阁主人"NOR);
    set("long", "一个穿戴整齐的中年人，举止谈吐优雅。\n");
    set("combat_exp", 2500000);
    set("attitude", "friendly");
    set("class","beggar");
    set("per",30);

	set("vendor_goods", ([
	"/obj/generate/commonweapon/50/axe":20,
	"/obj/generate/commonweapon/50/blade":20,
	"/obj/generate/commonweapon/50/fist":20,
	"/obj/generate/commonweapon/50/hammer":20,
	"/obj/generate/commonweapon/50/spear":20,
	"/obj/generate/commonweapon/50/staff":20,
	"/obj/generate/commonweapon/50/sword":20,
	"/obj/generate/commonweapon/50/throwing":20,
	"/obj/generate/commonweapon/50/whip":20,
	]) );

	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
     }) ); 		

	auto_npc_setup("wang",180,160,0,"/obj/weapon/","fighter_w","dragonstrike",1);
    setup();
    carry_object(__DIR__"obj/oucloth")->wear();
}




void init()
{
    add_action("do_vendor_list", "list");
    ::init();
}


void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/50/axe":20,
	"/obj/generate/commonweapon/50/blade":20,
	"/obj/generate/commonweapon/50/fist":20,
	"/obj/generate/commonweapon/50/hammer":20,
	"/obj/generate/commonweapon/50/spear":20,
	"/obj/generate/commonweapon/50/staff":20,
	"/obj/generate/commonweapon/50/sword":20,
	"/obj/generate/commonweapon/50/throwing":20,
	"/obj/generate/commonweapon/50/whip":20,
	]) );
}
