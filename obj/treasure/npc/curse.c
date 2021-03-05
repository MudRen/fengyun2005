inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    object weapon;

	set_name("裴冥", ({ "pei ming","boss","pei","ming"}) );
	set("title",HIB"通天"NOR);
	set("nickname",BLU"回首扬州梦成空"NOR);
	set("gender", "男性" );
	set("class","yinshi");
	set("age",60);
	set("long","裴冥通天曾经是二十年前江湖中与赫连天虎齐名，人人提及色变的高手之
一。然而岁月催人，他如今已经老了，老得再看不出一点年轻时的影子，
就像个再平凡不过的垂暮老人．．\n");

		set("spawn_location","/d/manglin/hole");

		set("cps",50);
		set("agi",62);
		
		set("gold",15);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.
        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 2350000);	// L55.capped at 45
    
        set_skill("celecurse", 150);
        set_skill("cursism",200);	
		set_skill("qiankunwuxing",200);
		set_skill("dodge",200);
		set_skill("iceheart",200);
		set_skill("force",200);
		set_skill("unarmed",200);
		set_skill("doomstrike",200);
		set_skill("doomsteps",200);
		set_skill("doomforce",200);
		
		map_skill("force","doomforce");		// don't enable iceheart, use NPC inherent hit
		map_skill("cursism","celecurse");
		map_skill("unarmed","doomstrike");
		map_skill("dodge","doomsteps");
		
		set("max_kee",20000);
		set("max_gin",16000);
		set("max_sen",16000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set("armor_prop/armor",80);
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
"/obj/generate/surcoat_55_4.c",
"/obj/generate/surcoat_55_16.c",
"/obj/generate/neck_55_4.c",
"/obj/generate/head_55_4.c",
"/obj/generate/head_55_14.c",
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


void dist(object ghost)
{
	if (!ghost)
		return;
	set_temp("timer/solidghost",0);
	message_vision(BLU"$N在空中打了个旋儿，形体渐渐消散无影．．．\n"NOR,ghost);
	destruct(ghost);
	return;
}

void smart_fight()
{
	object ob;
	mapping buff;
	object *enemy;
	int i;
	object ghost;
	object me = this_object();

	set("atman",query("max_atman")*2);

	// 1/3出治血的，Normal 的时候出攻击的
	if (query("kee")< query("max_kee")) {		
		if (!query_temp("timer/solidghost") && time()>query("annie/sh")+30)
		{
			set_temp("timer/solidghost",1);
			message_vision(HIB"\n一个亡灵突然自远方飘了过来，对$N发出了令人毛骨悚然的笑声：“主人，有什么吩咐．．．”\n"NOR,this_object());
			ghost=new("/obj/npc/solidghost");
			ghost->invocation(me,200);
			ghost->set("name","无名亡灵");
			set("my_pet", ghost);			
			ghost->move(environment());
			set("annie/sh",time());
			ob = ghost;
			enemy=query_enemy();
			i = sizeof(enemy);
			while(i--) {
				if( enemy[i] && living(enemy[i]) ) {
					ob->kill_ob(enemy[i]);
					enemy[i]->kill_ob(ob);
				}
			}
			call_out("dist",180,ob);
				
		}
	}
	
	if (objectp(ob=query("my_pet"))) {		
		
		if (query("kee")< query("max_kee")/3 )
		{ 
			if (!ob->query_temp("pfm/qiankun/heal_curse"))
			{	
				"/daemon/class/yinshi/qiankunwuxing/heal.c"->conjure(me,ob);
				ob->set_skill("cursism",200);	
				ob->set_skill("celecurse",200);
				ob->stop_busy();
			}
		} else if (query("kee")< query("max_kee"))
		{	
			if (!ob->query_temp("pfm/qiankun/turn_curse"))
			{
				"/daemon/class/yinshi/qiankunwuxing/boost.c"->conjure(me,ob);
				ob->set_skill("cursism",200);	
				ob->set_skill("celecurse",200);
				ob->stop_busy();
			} 
		}		
	}
	
	if (!ANNIE_D->check_buff(me,"boostcurse"))
		ccommand("curse boostcurse");

	stop_busy();
	return;
}

mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage, rate;
	object weapon, *enemy;
	string msg;

    extra=  400;
    extra = COMBAT_D->magic_modifier(me, victim,"kee", extra);            
	victim->receive_wound("kee",extra, me);
	msg= RED"$N手中的红虫忽然飞掠出来，悄没声息地落到$n身上。\n"NOR;
	
	return msg;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

