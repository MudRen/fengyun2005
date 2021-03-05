inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    object weapon;

	set_name("景因梦", ({ "jing yinmeng","boss","yinmeng","jing","meng"}) );
	set("gender", "女性" );
    set("title",WHT"情深不寿"NOR);
	set("nickname",BLU"莫恨飞花容易散"NOR);
	set("class","moon");
	set("age",30);
	set("agi", 60);
	set("spawn_location","/d/zangbei/mirage");

set("long","一条纤细的人影，白如雪，静如岩，飘逸如风，美如幽灵，她脸上绽着淡
淡的笑容，就像是白雪中忽然绽开的一朵梅花。\n");

        set("gender", "女性" );
    
        set("gold", 15);
		set("per",40);

		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 2600000);	// L60. Cap @ L50.
    
        set_skill("parry", 200);
        set_skill("blade", 200);
		
        set_skill("dodge", 200);
        set_skill("stormdance",150);

		set_skill("force", 400);
        set_skill("snowforce",200);	
		set_skill("chillblade",190);
		
		set_skill("spells", 200);
        set_skill("heart-listening",200);	

        map_skill("blade", "chillblade");
        map_skill("parry", "chillblade");
        map_skill("dodge", "stormdance");
        map_skill("force", "snowforce");
        map_skill("spells", "heart-listening");
		
		set("max_kee",20000);
		set("max_gin",16000);
		set("max_sen",16000);
        
		setup();

		weapon=carry_object("/obj/weapon/blade");
		weapon->set_name(WHT"沉月飞霜"NOR, ({ "frost blade","blade" }) );
		weapon->set("long","沉月飞霜(Frost blade)。");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->set("ice_blade",2);
		weapon->wield();


		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(HIW"空语纱衣"NOR, ({ "shayi" }) );
		weapon->set("long"," ");
//		weapon->set("armor_prop/armor",80);
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();

		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({
			BOOKS"class/dragonstrike_zjbl_2",	
			BOOKS"class/gouyee_heal_2",	
		}));
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",2);
	set("drop/common_drop",({
"/obj/generate/wrists_55_3.c",
"/obj/generate/neck_55_14.c",
"/obj/generate/cloth2_55_4.c",
"/obj/generate/cloth2_55_14.c",
"/obj/generate/boots_55_5.c",
"/obj/generate/boots_55_15.c",
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

//	 straight fight NPC, tough because it hurts sen

void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	int i;
	object me = this_object();

	target = select_opponent();

	ccommand("perform binglunyinjing");
	
	if (!present("wall of ice",me))
		ccommand("exert bingpojingbi");

	// 太厉害啦，气少的时候用
	if (query("kee") < query("max_kee")/4
		|| query("sen")< query("max_sen")/4
		|| query ("gin") < query("max_gin")/4)
	if (!ANNIE_D->check_buff(me,"feat"))		// possible +50% sen damage
	{
		set_skill("stormdance",150);
		SKILL_D("stormdance")->perform_target(this_object(),"shinra",me);
		set_skill("stormdance",150);
	}

	if (!ANNIE_D->check_buff(me,"dodgeup"))		// Haste
	{
		set_skill("stormdance",200);
		SKILL_D("stormdance")->perform_target(this_object(),"shuangtianxuewu",me);
		set_skill("stormdance",150);
	}

	i = ANNIE_D->check_buff(target,"gks");
	if (i>0)
	{
		buff = target->query_temp("buff/"+i);
		if (!mapp(buff) || buff["att"] == "curse")
		{
		}
		else
		{
			set_skill("stormdance",200);
			SKILL_D("stormdance")->perform_target(me,"hanlinluoxue",target);
			set_skill("stormdance",150);
		}
	}
	else if (!i)
	{
		set_skill("stormdance",200);
		SKILL_D("stormdance")->perform_target(me,"hanlinluoxue",target);
		set_skill("stormdance",150);
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

