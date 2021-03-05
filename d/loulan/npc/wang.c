#include <ansi.h>
inherit SMART_NPC;

void create()
{
        object armor;
        set_name("王怜花", ({ "wang lianhua","wang" }) );
        set("gender", "男性" );
        set("title", "千面公子" );
        set("nickname", HIM"惊才绝艳七巧心"NOR );
        set("long",
		"一个狐裘华服的美少年。唇红齿白，修眉朗目，面色白里透红，有如良质美玉。\n"
                );
        set("attitude", "peaceful");
		set("class","bat");
		
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
		set("age", 25);
        set("combat_exp", 2500000);

        set("chat_chance", 1);
        set("chat_msg", ({
		"王怜花狂笑道：老天有眼，也要看看人间的这场好戏！ \n",
		"王怜花冷笑道：沈浪。。沈浪。。他此刻怕是正和白飞飞。。。  \n",
		}) );

        set_skill("unarmed", 140);
        set_skill("blade", 200);
        set_skill("bat-blade", 150);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 200);
        set_skill("meng-steps", 140);
        set_skill("nine-moon-claw", 140);
        
        map_skill("move","meng-steps");
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
        carry_object(__DIR__"obj/blade1")->wield();
        armor=new("/obj/armor/cloth");
	armor->set_name("裘皮大衣",({"coat"}) );
	armor->move(this_object());
	armor->wear();
}