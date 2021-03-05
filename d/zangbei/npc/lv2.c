#include <ansi.h>
inherit SMART_NPC;

int recruit();

void create()
{
    	set_name("律香川",({"lv xiangchuan","lv"}));
	set("title",WHT"文质彬彬"NOR);
	set("long","
律香川是个脸色苍白，文质彬彬的人。所以别人往往会低估了他的力量，
认为他并没有什么了不起。这种错误不但可笑，而且可怕。律香川不但
是孙玉伯最得力的助手，也是武林中三个最精于暗器的人之一，尤其是
属于机簧一类的暗器，天下再也没有任何人能比得上他。。\n");
   	
     	set("gender","男性");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",6400000);  
    	set("attitude", "friendly");
    	
   	set("inquiry", ([
		
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
	set_skill("tanzhi-shentong",160);
	setup();
    	carry_object("obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/throwing/qixing")->wield();
 
}


void die(){
	object owner, me, laobo;
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	}
	if (me) {
		
		if (me->query_temp("marks/kuaihuo/想杀律香川")) {
			me->delete_temp("marks/kuaihuo");
			if (laobo = present("sun yubo",environment(me)))
				 laobo->thank_you(me);
			me->delete_temp("marks/kuaihuo");	
			REWARD_D->riddle_set(me,"菊园传奇",14);
		}
	}
	::die();
}
