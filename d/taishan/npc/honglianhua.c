inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name(HIR"红莲花"NOR, ({ "hong lianhua","hong" }) );
        set("gender", "男性");
        set("age", 18);
        set("long",
"一个乾枯瘦小，却长着两只大眼睛的少年乞丐，手里拿着根竹竿，正瞧着你笑。\n"
);
        set("inquiry", ([
        ]) );
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"红莲花喃喃道：“这里面一定有一个大阴谋，是什么呢？”\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","少年乞丐");
        set("score", random(50000));
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","beggar");
        
        set("combat_exp", 4000000);        
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     	}) ); 		

		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
        setup();
        carry_object(__DIR__"obj/bamboo_staff")->wield();
		carry_object("/obj/armor/cloth")->wear();
		if (!random(10)) carry_object(BOOKS"staff_75");
}
