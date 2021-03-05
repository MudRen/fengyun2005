inherit SMART_NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
void summon();
	
void create()	
{
    object weapon;

	set_name("金川", ({ "jin chuan","boss", "jin","jinchuan"}) );
	set("gender", "男性" );
	set("nickname",BLU"金玉湖"NOR);
	set("title","大骗");
	set("class","knight");
	set("age",21);
set("long","一个很温柔很好看的少年，眼中却闪烁着游移不定的
光芒，整个人透出一股邪气。\n");

		set("spawn_location","/d/fugui/kf2");
		set("agi",58);
        set("gender", "男性" );
    
		set("gold",10);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.
        set("attitude","friendly");
    		
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );
		
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			100:  (: summon() :),
        ]) ); 
        		
        set("combat_exp", 2100000);	// L50. Cap @ L40.
    
        set_skill("herb", 300);
        set_skill("dream-herb",230);	
        set_skill("dodge", 200);
        set_skill("tie-steps",160);
        set_skill("unarmed", 200);
        set_skill("hanshan-strike",200);
        set_skill("spells", 200);
        set_skill("sheolmagic",200);

		map_skill("dodge", "tie-steps");
        map_skill("herb", "dream-herb");
        map_skill("unarmed", "hanshan-strike");
		
		set("max_kee",18000);
		set("max_gin",13000);
		set("max_sen",13000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(HIB"玉蓝色的衣服"NOR, ({ "cloth" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
//		weapon->set("armor_prop/armor",80);
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
"/obj/generate/surcoat_40_3.c",
"/obj/generate/surcoat_40_15.c",
"/obj/generate/head_40_3.c",
"/obj/generate/head_40_13.c",
"/obj/generate/cloth1_40_13.c",
BOOKS"learn/spells_100",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;
	
	if (random(2)) {
		lotus = new(AREA_XINJIANG"obj/lotus");
		if (lotus) lotus->move(this_object());
	}

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);

	::die();
	return;
}


void summon() {
	
	// Summon only exits 15 sec... so let it summon as many (2) as possible
	if (time() > 10 + query("timer/demon_guardian2")) {
		delete("timer/demon_guardian2");
		ccommand("perform dodge.npc_summon2");
		stop_busy();
	}
	return;
}

void smart_fight()
{
	if (time()> query("timer/jin_canyunbi") + 30) {
		ccommand("perform herb.canyunbi");
		set("timer/jin_canyunbi",time());
		stop_busy();
	}
	return;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

