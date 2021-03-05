#include <ansi.h>

inherit SMART_NPC;
int kill_him();

void create()
{

	set_name("袁秋云",({"yuan qiuyun","yuan","qiuyun"}));
    	set("title",WHT"白云山庄  庄主"NOR);
    	set("long", "
这人当然已是个老人，是个很有威仪的老人。他穿着也极考究，
态度却比柳东来还严肃有威，\n");
	set("age",59);
	set("combat_exp", 6000000);
        set("attitude", "friendly");
	
	set("inquiry", ([
             "白天羽" : (: kill_him :),
             "bai tianyu" : (: kill_him :),
       	]));
	
	
	set("reward_npc",8);
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
     }) );
	
	auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","dragonstrike-jg",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "貂皮大袍",
    						"long": "一件名贵的貂皮大袍。\n",
    						"value": 100,
    						 ]))->wear();    
}


int kill_him()
{
        object me/*, another*/;
        
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"袁秋云现在没空回答你。\n");
 		return 1;
 		}
        message_vision(CYN"
袁秋云的笑声突然停顿，目光中忽然露出恐惧之色，一张严肃的脸，也突然变
得扭曲变形，失色道：“你是白……白大侠的什么人？”\n"NOR,this_object());
        return 1;
}