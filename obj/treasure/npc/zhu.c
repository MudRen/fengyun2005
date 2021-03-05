inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    object weapon;
	set_name("朱媚", ({ "zhu mei","boss","zhu"}) );
	set("title",MAG"紫帐销魂"NOR);
	set("nickname",BLU"蛾眉秋恨满三霜"NOR);
	set("class","demon");
	set("age",50);

set("long","她已到中年，却依然风华不减，秀丽的脸廓上还能辨出少女时的绝色，
只是眉间愁色几许，惹人疑异。\n");

        set("gender", "女性" );
		set("per",99);
    	set("agi",60);
    	
		set("spawn_location","/d/libie/bossroom");


		set("gold",15);
		
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 2850000);	// L65. Cap @ L55.
    
        set_skill("dodge", 200);
        set_skill("nodust-steps", 120);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("daimonsword",180);	// for last hit.
        set_skill("zensword",180);	// for last hit.

		set_skill("force", 400);
        set_skill("divineforce",220);	

        map_skill("parry", "zensword");
        map_skill("dodge", "nodust-steps");
        map_skill("sword", "daimonsword");
        map_skill("force", "divineforce");
		
		set("max_kee",30000);
		set("max_gin",20000);
		set("max_sen",20000);
        
        set_temp("apply/armor",50);
        set_temp("apply/damage",300);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(HIR"七巧剑"NOR, ({ "thin sword","sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(MAG"紫阑衣"NOR, ({ "cloth" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();
		
		
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({
			BOOKS"class/cloud-dance_yegui_1",
			BOOKS"class/dragonstrike_zjbl_2",			
		}));
		set("drop/bg",0);
		set("drop/common",100);
		set("drop/rare",0);	
		set("drop/amount",3);
		set("drop/common_drop",({
"/obj/generate/surcoat_70_5.c",
"/obj/generate/head_70_5.c",
"/obj/generate/cloth3_70_15.c",
"/obj/generate/cloth1_70_5.c",
"/obj/generate/boots_70_6.c",
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

int kill_ob(object who)
{
        ::kill_ob(who);
//        smart_fight();
        return 1;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	object me = this_object();
	object *enemy;
	int i;
	enemy = me->query_enemy();


	if (!random(3))
		if (ccommand("perform force.check_gspm"))
			ccommand("perform force.guishenpomie");

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (ANNIE_D->get_buff_num(enemy[i],1) > 0 && !is_busy())
			{
				target=enemy[i];
				SKILL_D("daimonsword")->perform_target(this_object(),"chousi",target);
			}
	
	i = sizeof(enemy);
	if (!random(3) && i > 1 && query("kee") < query("max_kee") / 3)
		ccommand("perform force.terror2");

	ccommand("perform force.baocanshouque");
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

