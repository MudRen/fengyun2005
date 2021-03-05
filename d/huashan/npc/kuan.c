inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("苦庵上人", ({ "ku an" }) );
        set("gender", "男性");
        set("age", 65);
        set("long","一个愁眉苦脸的老道。\n");
              
      	set("chat_chance", 1);
		set("chat_msg", ({
		 	"苦庵上人叹道：“那七妙神君果真厉害，我们实在是不得已啊。”\n",
		}) );
	  
        set("attitude", "friendly");
        set("title",HIG"峨嵋"NOR);
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","bonze");
        set("fly_target",1);
        
        set("combat_exp", 3500000);        

		set("toughness",140);
               
		set("perform_weapon_attack", "bonze/staff/cloudstaff/longxianyuye");
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		set("skill_type_w", "staff/cloudstaff");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
		
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);              
        set_skill("lotusforce", 150);
		set_skill("notracesnow",150);
		set_skill("dabei-strike",165);
        set_skill("cloudstaff",150);
        set_skill("staff",150);

        map_skill("staff","cloudstaff");
        map_skill("unarmed","dabei-strike");
        map_skill("force", "lotusforce");
        map_skill("dodge","notracesnow");
        map_skill("move","notracesnow");
        map_skill("parry","cloudstaff");
        map_skill("sword","cloudstaff");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object("/obj/weapon/staff")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

 
