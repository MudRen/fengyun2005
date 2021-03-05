#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("潘伶",({"pan ling","pan"}));
    	set("title",WHT"江湖五毒"NOR);
	set("long", "
这人虽然衣袖又脏、又油、又腻，却有一只很好看的手，手指很长，
也很干净。\n");

	set("age",39);
	set("gender","男性");
	set("combat_exp", 7000000);
	set("attitude", "aggressive");
	
    	set("reward_npc",1);
    	set("difficulty",5);
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": HIG"绿衣裳"NOR,
    						"long": "一件绿衣裳，穿着说不出的奇怪。\n",
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
	message("vision",name() + "诡异地一笑，又成了那个老实的不能再老实的面馆老板。\n", 
		environment(),this_object() );
	another = new(__DIR__"bosszhang");
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
                        me->set_temp("marks/wanma/江湖五毒a",1);
        ::die();
}


