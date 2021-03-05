#include <ansi.h>
inherit SMART_NPC;
inherit F_PAWNOWNER;
inherit INQUIRY_MSG;

void create()
{
	set_name("轩辕三光",({"san guang","san","guang"}));
	set("title",YEL"天光，地光，人也光"NOR);
	set("long", "
一条丈八的汉子坐在柜台后面闭目养神，两腿搁在桌上。这双腿黝黑如铁，
上面还长满了黑茸茸的毛，裤管直卷到膝盖。\n");
	set("age",40);
	set("gender","男性");
	set("combat_exp", 7500000);

	set("reward_npc",10);
		
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("guardian",250,200,0,"/obj/weapon","fighter_w","shadowsteps+lingxi",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/armor/sandal",([	"name": "破草鞋",
					"long": "一双破草鞋。\n",
					 ]))->wear();    
}

void init()
{	
	::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");

}