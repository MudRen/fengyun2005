#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("采花蜂",({"caihua feng","feng"}));
    set("title",WHT"江湖五毒"NOR);
	set("long", "
这人的眼皮在跳，脸上却还是带着微笑——这笑容本就是刻在脸上的。。\n");
	set("age",39);
	set("gender","女性");
	set("combat_exp", 6200000);
	set("attitude", "aggressive");
	
	set("reward_npc",1);
    set("difficulty",3);
    	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	      	(: auto_smart_fight(20) :),    
       }) );
	
	auto_npc_setup("liaoyin",200,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
	set_skill("tanzhi-shentong",170);
	
	setup();
	carry_object("/obj/armor/cloth",([	"name": RED"穿花大红箭袖"NOR,
    						"long": "一件穿花大红箭袖，俗气得很。\n",
    						 "value":	1,
    						 ]))->wear();  
}


int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object another;
	message("vision",name() + "诡异地一笑，又成了那个满脸堆笑的陈大倌。\n", 
		environment(),this_object() );
	another = new(__DIR__"bosschen");
	another->move(environment(this_object()));
	destruct(this_object());
}


void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if(me->query("marks/wanma/棺材之谜"))
                        me->set_temp("marks/wanma/江湖五毒b",1);
        ::die();
}

