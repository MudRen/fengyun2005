#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("黄衫卫", ({ "yellow sentry","sentry"}) );
        set("gender", "男性" );
        set("title","金钱帮 死士");
        set("age", 22);
        set("maze","jq1");
        set("target_name","金衣卫");
	set("long", "
这人从头至脚都蒙上了黄衫，只在眼睛处留了两个孔，不时流露出凶狠疯狂的
神色。黄衫卫并非金钱帮嫡系弟子，而是上官金虹从各地网罗来的穷凶极恶之
徒，武功来历少有人知。\n");
        
        set("combat_exp", 900000);
        
        set("attitude", "aggressive");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "黄衫卫狞笑道：私闯武堂禁地者死！\n",
        }) );
	
		auto_npc_setup("liaoyin",100,120,1,"/obj/weapon/","fighter_w","smallguy",1);
		delete_skill("iron-cloth");
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "黄衫",
					"long": "一件黄衫。\n",
					 ]))->wear();    
    	
}