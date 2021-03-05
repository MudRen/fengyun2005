#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("胡药师",({"hu yaoshi","hu"}));
    	set("title",HIG"十二星象之"NOR);
	set("long", "“
十二星象中的“捣药神君“，白发苍苍，但颔下胡子却没有几根，一双
眼睛又圆又亮，就像是两粒巨大的珍珠。不但头大，耳朵更大，而且又
大又尖，和兔子的耳朵几乎完全一模一样，只不过大了两倍。\n");
	set("age",33);
	set("combat_exp", 5500000);
	
	set("reward_npc",5);
	
	set("chat_chance", 1);
        set("chat_msg", ({
                "胡药师心满意足地微笑着。\n"
     }) );
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
     }) );
	
	auto_npc_setup("guardian",250,160,0,"/obj/weapon/","fighter_w","xinyue-dagger",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/spader")->wield();
}

