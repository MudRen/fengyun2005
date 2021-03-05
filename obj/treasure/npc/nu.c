inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
	    object weapon;
	
		set_name("怒真人", ({ "nu zhenren","boss","nu","zhenren" }) );
		set("gender", "男性" );
		set("nickname",HIR"　怒　"NOR);
	    set("title",BLU"隐居华山"NOR);
		set("class","swordsman");
		set("spawn_location","/d/huashan/zd2");
		set("long","这人目如火炬，满面虬髯，两条浓眉，竟已纠结到一处，
满头乱发，如刺般根根蓬起，身材却是乾枯瘦小。\n");

        set("gender", "男性" );
    	set("agi", 70);
    	set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

//		set_temp("apply/armor",250);		
        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 10100000);	// L140. CAP @ L110.
    
        set_skill("unarmed", 1);
        set_skill("shuaijiao", 400);
        set_skill("force", 200);
        set_skill("gaunforce", 200);
        set_skill("dodge", 200);
        set_skill("shadowsteps", 200);
        set_skill("xisui",200);
        set_skill("iron-cloth",200);

        map_skill("force", "gaunforce");
        map_skill("dodge", "shadowsteps");
        map_skill("unarmed", "shuaijiao");
				
		set("max_kee",340000);
		set("max_gin",340000);
		set("max_sen",340000);
        
		setup();

		weapon = carry_object("/obj/weapon/fist");
		weapon->set_name(YEL"金丝手套"NOR, ({ "glove" }));
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(BLU"破旧的蓝布道袍"NOR, ({ "cloth" }) );
		weapon->set("long","破旧的蓝布道袍(Cloth)。");
		weapon->set("value",0);
		weapon->wear();

//		set_temp("apply/attack",30);	// 这家伙的命中实在是太·糟·糕·了！！！

	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/surcoat_150_9.c",
"/obj/generate/neck_150_19.c",
"/obj/generate/head_150_9.c",
"/obj/generate/head_150_19.c",
"/obj/generate/cloth3_150_9.c",
"/obj/generate/boots_150_20.c",
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
        smart_fight();
        return 1;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object me = this_object();
	int i;
	object ghost;

	ccommand("exert npc_hurtless");

	if (query("kee")< query("max_kee")/2 && !me->query_weapon()) {
		message_vision(CYN"$N气得吹胡子瞪眼，$N叫道：拼了拼了！！！\n"NOR, me);
		me->ccommand("wield all");
	} else if (query("kee")> query("max_kee")/2 && me->query_weapon()) {
		message_vision(CYN"$N说，咱家先空手会会你们！！！\n"NOR, me);		
		me->ccommand("unwield all");
	}
				
/*	if (!random(3))
		if (!ANNIE_D->check_buff(me,"strup"))
			SKILL_D("xisui")->perform_target(this_object(),"yijinjue",me);
	stop_busy();*/
	
	if (!random(3))
		if (!ANNIE_D->check_buff(me,"powerup") && !is_busy())
		{
			message_vision(BRED WHT"\n碎玉断空烈诀\n\n"NOR,this_object());
			ccommand("exert forceup");
			stop_busy();
		}

	if (!random(8))
		if (!ANNIE_D->check_buff(me,"damagecurse") && !is_busy())
		{
			message_vision(BCYN HIW"\n碎玉撼天破诀\n\n"NOR,this_object());
			ccommand("exert damageup");
			stop_busy();
		}

	if (!random(3) && !is_busy())
	{
		if (!ANNIE_D->check_buff(me,"damageup"))
		{
		message_vision(BBLU HIW"\n折戟沉沙\n\n"NOR,this_object());
				buff =
				([
					"caster":this_object(),
					"who":me,
					"type":"damageup",
					"att":"bless",
					"name":"天魔无相·折戟沉沙",
					"buff1":"apply/attack",
					"buff1_c":100,
					"time":60,
					"buff_msg":HIR"$N暴跳如雷，一声大喝，竟似疯狂一般博命击来。\n"NOR,
				]);
				ANNIE_D->buffup(buff);
		}
	}

	if (!me->is_busy() && me->query_temp("xxx/1") + 20 < time()) {
		ccommand("perform dodge.lianhuanjiao");
		stop_busy();
		me->set_temp("xxx/1",time());
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

