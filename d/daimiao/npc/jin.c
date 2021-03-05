#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("金护卫", ({ "jin wei", "jin"}) );
        set("title",YEL"西方神教"NOR" 五护卫之 ");
        set("gender", "男性" );
        set("age", 32);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("long", "
西方神教复现江湖，天地人三长老，四金刚，金银铜铁锡五护卫。
这是西方神教五大护卫之一的金护卫，负责外围巡查事务。\n");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "金护卫向你喝道：今天的口令？？\n",
                "金护卫向你喝道：站住．亮你的腰牌？ 没腰牌就让你血溅当场！\n",
        }) );
	
		setup();
		auto_npc_setup("wang",120,140,0,"/obj/weapon/","fighter_w","dragonwhip",4);
		carry_object(__DIR__"obj/blackrobe",([	
    						"name":  "金卫服",
    						"long": "一件黄色的长袍，上面绣着一个“金”字。\n",
    						 ]))->wear();
		set_skill("moon-blade",70);

}

