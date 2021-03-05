// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
		object weapon;
        set_name("唐剑麟", ({ "tang jianlin","tang","jianlin" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"顾曲"NOR);

		set("no_curse",1);

		set("always_duxin",1);

    	set("attitude","friendly");

		set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
		set("group","demon");

		set("difficulty",10);
		set("reward_npc",1);
        set("gender", "男性" );
		set("age",27);

	set("chat_chance",1);
	set("chat_msg", ({
		"唐剑麟叹道：其实我只是不想离开你．．．\n",
	}) );

        set("combat_exp", 6000000);
		auto_npc_setup("tang",190,150,0,"/obj/weapon/","fighter_w","tempestsword",4);

		set("death_msg",CYN"\n$N合上眼，嘴角一抿，轻笑道：罢了．．．\n"NOR);

		setup();
		weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("浮痕浅", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();
	
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("静夜缠绵", ({ "cloth" }) );
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