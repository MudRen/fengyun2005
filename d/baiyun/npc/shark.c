//Created by justdoit at June 2001 
//All Rights Reserved ^_^

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("大白鲨" , ({ "big white shark" , "big shark" , "shark" }) );
	set("nickname", HIW "噬人魔"NOR);
	set("race", "野兽");
	set("age", 10);
	set("long", "这是一只凶猛无比的噬人大白鲨。\n");
	set("str", 30+random(50));
        set("cor", 100);
        set("cps", 30);
	set("dur", 30);
	set("agi", 30);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite"}) );
	set_skill("dodge", 100);
	set("combat_exp", 1000000+random(1000000));
	set("bellicosity", 3000 );
	set_temp("apply/attack", 200);
	set_temp("apply/armor",  200);
	set_temp("apply/damage", 50);
	setup();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) ) 
	  {
	    kill_ob(ob);
          }
}

void die()
{
	object killer;
	if ( objectp(killer = query_temp("last_damage_from")) )
	     killer->set("marks/killed_shark", 1);
	::die();
}	