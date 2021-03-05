#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("竹叶青", ({ "zhuyeqing","zhu" }) );
        set("gender", "男性");
        set("combat_exp", 4000000);
		set("age",47);
		set("long","竹叶青是一种烈酒的名字，喝下去很少有人能不醉的；竹叶青也是种毒蛇，毒得要命。\n");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	(: auto_smart_fight(40) :),
		}) );
	
        setup();
		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","herb",1);
		carry_object("/obj/armor/cloth")->wear();
		carry_object("/obj/armor/bracelet",	([	"name": "青玉镯",
    						"long": "一只很普通的手镯。\n",
    						 ]))->wear(); 
}
