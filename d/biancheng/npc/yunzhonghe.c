#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("云中鹤",({"yunzhong he","yunzhong","he"}));
    	set("title",WHT"江湖五毒"NOR);
	set("long", "
江湖五毒之首，原是武当的护教长老，因贪恋女色被石雁重责后赶出，从
此变本加厉，勾结一批臭味相投之采花贼，足迹遍布中原。\n");
	set("age",59);
	set("gender","男性");
	set("combat_exp", 7000000);
 	set("attitude", "aggressive");
	
	set("cor", 40);
	set("cps", 40);
	set("agi",40);
	set("fle",100);
    	
    	set("reward_npc",1);
    	set("difficulty",5);
	
//	setting up special NPC function: healer, defense, zombie-killer
// 	defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
	
//	set("defense_type",random(2)+1);	
//	set("zombie-killer",1);
//	set("officer-killer",1);
//	set("dungeon_npc","check");
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,0,"/obj/weapon/","fighter_w","nine-moon-sword",2);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "鹤杉",
    						"long": "一件丝绸的道服，上面绣了一只鹤。\n",
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
	message("vision",name() + "诡异地一笑，又成了那个满脸横肉，留着一把大胡子的胡掌柜。\n", 
		environment(),this_object() );
//	environment(this_object())->reset();
	another = new(__DIR__"bosshu");
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
                        me->set_temp("marks/wanma/江湖五毒e",1);
        ::die();
}