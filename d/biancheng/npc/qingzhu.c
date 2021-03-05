#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("青竹蛇",({"qingzhu she","qingzhu","she"}));
    	set("title",WHT"江湖五毒"NOR);
	set("long", "青竹蛇的毒只有与他交过手的人才知道。。。。\n");

	set("age",59);
	set("gender","男性");
	set("combat_exp", 6000000);
	 set("attitude", "aggressive");
	
    	set("reward_npc",1);
    	set("difficulty",5);
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(60) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","herb",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "蛇皮服",
    						"long": "其实这只是一间普普通通的紧身衣，幽幽地透着绿光。\n",
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
	message("vision",name() + "诡异地一笑，又成了那个裹着油围裙招待客人的丁老四。\n", 
		environment(),this_object() );
	another = new(__DIR__"bossding");
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
                        me->set_temp("marks/wanma/江湖五毒d",1);
        ::die();
}