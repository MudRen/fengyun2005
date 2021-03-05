inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
	
void create()	
{
    object weapon;

	set_name("熊姥姥", 	({ "xiong laolao","boss", "xiong","laolao"}) );
	set("gender", "女性" );
	set("nickname",BLU"栗子"NOR);
    set("title","糖炒");

	set("class","moon");
	set("age",70);
	set("spawn_location","/d/wudang/xzroad5");

set("long","她背上仿佛压着块看不见的大石头，压得她整个人都弯曲了起来，
连腰都似巳被压断，手里提着个很古的竹篮子，用一块很厚的棉布
紧紧盖着，竹篮子中散发着一阵阵诱人的香气。\n");

        set("gender", "女性" );
    	set("agi",46);
    	
    	set("gold", 3);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 1600000);	// L40.
    
        set_skill("unarmed", 200);
        set_skill("spicyclaw",140);	
		
        set_skill("throwing", 200);
        set_skill("starrain",140);
		set_skill("parry", 100);
		
        set_skill("dodge", 200);
        set_skill("stormdance",99);

		map_skill("parry","starrain");
		map_skill("dodge", "stormdance");
		map_skill("unarmed", "spicyclaw");
        map_skill("throwing", "starrain");
		
		set("max_kee",16000);
		set("max_gin",10000);
		set("max_sen",10000);
        
		setup();

		weapon=carry_object("/obj/weapon/throwing");
		weapon->set_name(YEL"糖炒栗子"NOR, ({ "lizi" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();


		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(HIR BLK"灰布长裙"NOR, ({ "skirt" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
//		weapon->set("armor_prop/armor",70);
		weapon->set("no_get",1);
		weapon->wear();

		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({
			BOOKS"class/cloud-dance_yegui_1",
			BOOKS"class/iceheart_buffup_2",			
		}));
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",2);
	set("drop/common_drop",({
BOOKS"learn/magic_60",
"/obj/generate/wrists_40_2.c",
"/obj/generate/neck_40_3.c",
"/obj/generate/neck_40_13.c",
"/obj/generate/cloth3_40_3.c",
"/obj/generate/boots_40_4.c",
"/obj/generate/boots_40_14.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


void die()
{
//	object who = query_temp("last_damage_from");

	object who = query_max_damage_dealer();

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);

//	SPAWN_D->restart_spawn(4,0);

	::die();
	return;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	int i;
	object me = this_object();

	target = select_opponent();

	if (me->query("timer/spicyclaw1") + 15 < time()){
		command("unwield all");
		ccommand("perform extrahit1");
		command("wield all");
		return;
	}
	
	if (me->query("timer/spicyclaw2") + 15 < time()){
		command("unwield all");
		ccommand("perform extrahit2");
		command("wield all");
		return;
	}
	
	if (me->query("timer/spicyclaw3") + 15 < time()){
		command("unwield all");
		ccommand("perform extrahit3");
		command("wield all");
		return;
	}		
/*		
	ccommand("unwield all");
	if (!ccommand("perform extrahit1"))
		if (!ccommand("perform extrahit2"))
			ccommand("perform extrahit3");
	ccommand("wield all");
*/	
	return;
}

