#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int kill_him();

void create()
{
    	set_name("陈大倌",({"chen daguan","chen","daguan"}));
	set("title","绸缎行的老板");
   	set("long","
这人白白的脸，脸上好像都带着微笑，正是那绸缎行的老板福州人陈大倌。
镇上没有人比他更会做生意，也没有人比他更得人缘了。\n");
     	set("gender","男性");
    	set("age",52);
    	 	
    	set("combat_exp",2000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
             	"江湖五毒"	:	(: kill_him :),
             	"采花蜂"	:		(: kill_him :),
   		]));
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"陈大倌说：“小店的绸缎是应有尽有。”\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","taiji",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "丝绸大袄",
    						"long": "西北地方人们多穿大袄，但用丝绸做的却很罕见。\n",
    						 "value":	1,
    						 ]))->wear();    
    
}


int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"陈大倌现在没空回答你。\n");
 		return 1;
 		}
        if(!me->query("marks/wanma/棺材之谜")) {
        	tell_object(me,"陈大倌说：没听说过，这名字邪气得紧。\n");
        	return 1;
        }
        
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n"NOR,this_object());
        another = new(__DIR__"caihua");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}