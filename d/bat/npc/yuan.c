#include <ansi.h>
inherit SMART_NPC;
inherit F_MASTER;

void create()
{
    	set_name("原随云", ({ "master yuan suiyun", "yuan suiyun","master"}));
    	set("long","
他笑容温柔而亲切，但一双眼睛里，却带着种说不出的空虚、寂寞、萧索
之意, 是个很秀气，很斯文的少年，穿着虽华丽，但却不过火。\n");
    	set("title","无争山庄少主人");
    	set("nickname", HIR "蝙蝠公子"NOR);
    	set("gender", "男性");
    	create_family("蝙蝠岛", 1, "岛主");
    	set("student_title","弟子");
    	set("score_cost",20000);
    	
    	set("class","bat");
    	set("reward_npc", 1);
    	set("difficulty", 25);
    	set("fly_target",1);
    	
    	set("age", 26);
    	set("per", 40);
    
    	set("combat_exp", 10000000);
    	set("attitude", "friendly");
    	
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(10) :),
        }) );
        
    	set("chat_chance", 1);
    	set("chat_msg", ({
        "原随云走到琴边，一首如行云流水般的曲子从他指间溢出。
世间己有很久没有过如此悦耳的琴声了。\n ",
            "\n",
        }) );
        
	    set_skill("unarmed", 200);
	    set_skill("move", 200);
	    set_skill("dodge", 250);
	    set_skill("parry", 250);
	    set_skill("force", 180);
	    set_skill("blade", 200);
	    set_skill("meng-steps", 220);
	    set_skill("bat-blade", 160);
	    set_skill("wuzheng-force", 220);
	    set_skill("perception",250);    
	    set_skill("literate", 120);
    
    	map_skill("force", "wuzheng-force");
    	map_skill("move",  "meng-steps");
    	map_skill("dodge", "meng-steps");
    	map_skill("parry", "bat-blade");
    	map_skill("blade", "bat-blade");

    	set("ranks",({"弟子","小邪","少邪","玄武神","朱雀神","白虎神",
                      "青龙神","副岛主"}));
    	set("rank_nogen",1);

    	setup();
    	carry_object(__DIR__"obj/armor"	)->wear();
    	carry_object(__DIR__"obj/hanhai")->wield();
}

void attempt_apprentice(object me)
{
    	command("recruit " + me->query("id") );
        //command("say  在下并不收徒。");
	return;
    	
}

