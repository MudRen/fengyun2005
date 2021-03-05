#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("花花道长",({"hua hua","hua"}));
    	set("title",WHT"江湖五毒"NOR);
	set("long", "
江湖五毒之首，原是武当的护教长老，因贪恋女色被石雁重责后赶出，从
此变本加厉，勾结一批臭味相投之采花贼，足迹遍布中原。\n");

	set("age",59);
	set("gender","男性");

	set("combat_exp", 7000000);
	 set("attitude", "aggressive");
	
    	set("reward_npc",1);
    	set("difficulty",5);
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(60) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","taiji-sword",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/a_book");
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
	message("vision",name() + "诡异地一笑，又成了那个愁眉苦脸的宋富贵。\n", 
		environment(),this_object() );
	another = new(__DIR__"bosssong");
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
                        me->set_temp("marks/wanma/江湖五毒c",1);
        ::die();
}