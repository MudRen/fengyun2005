inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("琵琶公主", ({ "princess" }) );
	set("title","起舞");
	set("gender", "女性" );
	set("age", 22);
	set("per",100);
	set("class","baiyun");
	set("group","guizi");
	set("long","
她那美丽的胴体在半透明的纱衣中忽隐忽现，让人忍不住想多看几眼。她
的语声清柔婉转，如出谷黄莺，只不过口音中微微带着些生涩，就正如吴
侬少女，初学京语。\n");
	set("combat_exp", 6400000);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
		"琵琶公主轻笑道：“偷看的人，你难道还是没有看够麽？”\n",
    	}) );  
    	
    set("chat_chance_combat", 100);
       set("chat_msg_combat", ({
	       	(: auto_smart_fight(60) :),    
     }) );
        
    auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","musician",1);
	set_skill("music",250);
	setup();
	carry_object(__DIR__"obj/pcloth")->wear();
	carry_object(__DIR__"obj/dsword")->wield();

}
	