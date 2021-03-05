#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("阿里木", ({ "eagle alimu", "alimu","eagle" }) );
        set("long", "双头秃鹰阿里木，天山第一杀手。\n");
        set("nickname",HIG "双头秃鹰"NOR);
        set("attitude", "heroism");
//        set("vendetta_mark", "authority");
//	set("vendetta_mark","pker");

	set("reward_npc", 1);
	set("difficulty", 25);
	set("combat_exp", 8000000);

        set("gender", "男性");
               
        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :)
        }) );
        

	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	        
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","mapo",2);
        setup();
        carry_object(__DIR__"obj/kacloth",([	"name": "袷袢",
    						"long": "维吾尔族男服，右衽斜领，无纽扣，用长方巾扎腰。\n",
    						"value": 2, 
    						 ]))->wear();    
}