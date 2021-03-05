#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("试试", ({"justdoit"}) );
        set("gender", "女性" );
		set("group","berserker");
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
     	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

   
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("justdoit",300,220,1,"/obj/weapon/","fighter_w","tempestsword",4);
	setup();
	carry_object("/obj/weapon/dagger");
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

/*
update here;update /adm/daemons/smartd;update /std/char/npc_mid;update /d/bashan/npc/yawnboy2;clone;update /d/bashan/npc/yawngirl2;clone;ask ke about silencer;call sinny->ccommand(kill fighter)
*/