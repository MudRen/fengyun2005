#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("老老和尚", ({ "old monk", "monk" }) );
	set("gender", "男性" );
	set("age", 62);
	set("class","shaolin");
	set("nickname",HIR"一指定乾坤"NOR);
    set("vendetta_mark","shaolin");
	        
    create_family("少林寺", 18, "老僧");
	set("long",	"专门钻研各种武功的老僧.\n");
       set("chat_chance", 1);
       set("chat_msg", ({
                name()+"埋首苦思，如中魔魇，一言不发．．\n",
                name()+"突然拍了拍头，喃喃道：非也，非也．．．\n",
                name()+"刚要挥笔于条幅之上，又突然停了下来．\n",

        }) );

	set("attitude", "peaceful");
	
	set("combat_exp", 4000000);

	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",170,160,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
	setup();
	carry_object(__DIR__"obj/monklao_cloth")->wear();
	carry_object(__DIR__"obj/ironfist")->wield();
}
