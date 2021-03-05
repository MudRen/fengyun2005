inherit SMART_NPC;
#include <ansi.h>
 
void create()
{
	set_name(HIW"白衣人"NOR, ({ "whitecloth man", "man" }) );
	set("gender", "男性" );
	set("age", 32);
	set("class","yinshi");
	set("long","
清清爽爽的一身白衣裳，文文雅雅的一张笑脸，再加上秋星明月般的一对笑
眼，笑眼中还仿佛不时有白云飘过，悠悠远远的那么样一朵白云。 \n");
    	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"白衣人笑道：“楚人江南留香久，海上渐有白云生。”\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
    	
	setup();
	carry_object("/obj/armor/cloth", 
		([	"name"  :       HIW"白衣"NOR ,
			"long" : "白色长衫，干净平整的没有一丝折痕。"])
		)->wear();
	carry_object("/obj/weapon/whip", 
		([	"name"  :       MAG"金丝软鞭"NOR ,
			"long" : "一条金光灿灿的长鞭。",
			"value": 1,
			]))->wield();
}
