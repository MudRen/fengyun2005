// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
		object weapon;
        set_name("顾砚耕", ({ "gu yangen","gu","yangen" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"唐棋"NOR);

		set("no_curse",1);

		set("always_duxin",1);

    	set("attitude","friendly");


	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
	
	set("group","demon");

	set("difficulty",10);
	set("reward_npc",1);


        set("gender", "男性" );

		set("age",27);

	set("chat_chance",1);
	set("chat_msg", ({
		"顾砚耕道：我心里又何其好受呢，可是楚司律既然有令．．．\n",
	}) );

        set("combat_exp", 6000000);
		auto_npc_setup("gu",190,150,0,"/obj/weapon/","fighter_w","spring-blade",4);

		set("death_msg",CYN"\n$N挣扎道：唐．．．\n"NOR);
		setup();

		weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("清泪绝", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();
		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("断桥残雪", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}




int kill_ob(object who)
{
	if (who->is_zombie() == 1 || base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N扬了扬手，空气中点点星光闪烁，刹那间四周万籁俱寂．．．\n" NOR,this_object());
		who->die();
		return 1;
	}
	::kill_ob(who);
	return 1;
}