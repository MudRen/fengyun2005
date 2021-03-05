#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("金无望", ({ "jin wuwang","jin" }) );
        set("gender", "男性" );
        set("long",
"一袭灰衣，面无表情，有如冰山一般。但目光转动之间，顿现摄人的威严。
乃快活王手下四使之财使，专为其管理并搜集宇内财宝。\n");

        create_family("快活林", 1, "财使");
        set("attitude", "peaceful");
		
		set("perform_busy_u", "bat/dodge/meng-steps/huanyinqianchong");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
		set("age", 34);
        set("combat_exp", 1000000);

        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"金无望双目微阖，彷佛老僧入定般一动不动。\n",
        }) );

        set_skill("unarmed", 160);
        set_skill("blade", 160);
        set_skill("bat-blade", 130);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("meng-steps", 150);
        set_skill("nine-moon-claw", 140);
        
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
        carry_object(__DIR__"obj/foxcloth")->wear();
}


int accept_object(object who, object obj)
{	
		mapping all;
		
		if (REWARD_D->check_m_success(who,"酒色财气"))	return 0;
			
		if( (int) obj->value() >= 20 * 10000)
		{
			message_vision("$N收下礼金，向$n点了点头。\n",this_object(),this_player());
			REWARD_D->riddle_set(who, "酒色财气/cai", 1);
			tell_object(who, WHT"你完成了『酒色财气』中的“财”\n"NOR);
			all = who->query("riddle/酒色财气");
			if (mapp(all) && sizeof(all) == 4)
				REWARD_D->riddle_done(who,"酒色财气",50,1);			
			return 1;
		}
		else
		{
			message_vision("$N道：王爷办喜事，没有二十两金子就不必出来丢人现眼了。\n",this_object());
			return 0;
		}
}
