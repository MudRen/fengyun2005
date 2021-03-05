#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("宋赛玉",({"song saiyu","saiyu","song"}));
    	set("title","貌比潘安");
    	set("long","
这人是宋妈妈的干儿子，身上穿着件水绿色的袍子，手里还在摇着柄折扇。
年轻人非但长得不难看，装束打扮也很考究，却偏偏有点讨人厌。\n");
    	set("gender","男性");
    	set("age",22);
    	set("no_arrest",1);
    	
    	set("combat_exp",1500000);
		set("attitude","friendly");
	
		
		set("per",40);
	    	
    	set("inquiry", ([
        	"*" : 	"血奴姑娘在等我，没工夫跟你聊。\n",
        ]));
    	set("death_msg",CYN"\n$N说：天，宋家绝后了。。。。 \n"NOR);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"宋赛玉斟酌着道：“血奴姑娘若要养小白脸，本该养我的，我哪点比十方差？”\n",	
    		"宋赛玉说：“鬼母在此，快快跪下磕头（kneel）。”\n"NOR,
    	}) );
    	
    	auto_npc_setup("wang",150,120,0,"/obj/weapon/","fighter_w","xinyue-dagger",1);
		set_skill("iron-cloth",100);
		set_skill("xinyue-dagger",80);			
		setup();   
    	carry_object(__DIR__"obj/greencloth")->wear();
    	carry_object(__DIR__"obj/zheshan")->wield();
}


