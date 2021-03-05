inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
    set_name("蓝阳光", ({ "sunshine" }) );
    set("gender", "女性" );
    set("age", 17);
    set("title", HIY "金色的"NOR);
    set("long",
      "一个年轻的女孩子，身上穿的衣服，比蓝天更蓝，比海水更蓝。\n你也从未见过如此明朗，如此令人愉快的女孩子。\n");
    set("attitude", "friendly");
    set("class","legend");
    set("chat_chance", 1);
    set("chat_msg", ({
	"蓝阳光突然收敛了笑容，肃然道：圣母恰母尊的子孙们只流血，不流泪，\n男人去前方流血，就由我们女人来打造兵器。\n",
	"蓝阳光噗哧一笑道：那个小方看上去凶巴巴的，心比我们女人还要软。。\n",
      }) );
    set("per",30);
    set("combat_exp",4200000);
	set("vendor_goods", ([
	"/obj/generate/commonweapon/40/axe":20,
	"/obj/generate/commonweapon/40/blade":20,
	"/obj/generate/commonweapon/40/fist":20,
	"/obj/generate/commonweapon/40/hammer":20,
	"/obj/generate/commonweapon/40/spear":20,
	"/obj/generate/commonweapon/40/staff":20,
	"/obj/generate/commonweapon/40/sword":20,
	"/obj/generate/commonweapon/40/throwing":20,
	"/obj/generate/commonweapon/40/whip":20,
	]) );

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: auto_smart_fight(20) :),
      }) );

    auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
    setup();
    carry_object("/d/jinan/npc/obj/changbao")->wear();
}


void init()
{
    add_action("do_vendor_list", "list");
    ::init();
}


void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/40/axe":20,
	"/obj/generate/commonweapon/40/blade":20,
	"/obj/generate/commonweapon/40/fist":20,
	"/obj/generate/commonweapon/40/hammer":20,
	"/obj/generate/commonweapon/40/spear":20,
	"/obj/generate/commonweapon/40/staff":20,
	"/obj/generate/commonweapon/40/sword":20,
	"/obj/generate/commonweapon/40/throwing":20,
	"/obj/generate/commonweapon/40/whip":20,
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

