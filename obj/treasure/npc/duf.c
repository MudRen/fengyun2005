inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

	set_name("杜先生", ({ "du xiansheng","boss","du"}) );
	set("gender", "女性" );
	set("nickname",BLU"七瓣山茶"NOR);
    set("title","玉剑山庄");
	set("class","shenshui");

	set("age",44);

	set("spawn_location","/d/eastcoast/village3");

set("long","一位穿著曳地长裙的妇人，一种非凡优雅的风姿。她的年华虽已逝去
，却绝不愿意用脂粉来掩饰她眼角的皱纹。她的清丽典雅就像是远山
外那一朵悠悠的白云，可是她的眼睛里却带著一种阳光般明朗的自信
\n她似乎正在等待着什么事情的发生、来临……\n\n");

		set("per",30);
    	set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 11100000);	// L140. CAP @ L110.
    
        set_skill("dodge", 400);
        set_skill("nine-moon-steps", 300);
        set_skill("force", 200);
        set_skill("nine-moon-force", 300);
        set_skill("sword", 200);
        set_skill("nine-moon-sword", 400);
        set_skill("nine-moon-spirit", 300);
        set_skill("nine-moon-claw",250);
        set_skill("unarmed",250);
        set_skill("parry",200);

		set("pfm/qingpingforce-9moon",1);

		map_skill("unarmed","nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("dodge", "nine-moon-steps");
        map_skill("sword", "nine-moon-sword");
        map_skill("parry", "nine-moon-sword");
		
		set("max_kee",300000);
		set("max_gin",300000);
		set("max_sen",300000);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(YEL"山茶花枝"NOR, ({ "branch" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();


		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name("曳地长裙", ({ "cloth" }) );
		weapon->set("long","曳地长裙(Cloth)。");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/neck_170_10.c",
"/obj/generate/head_170_21.c",
"/obj/generate/cloth2_170_20.c",
"/obj/generate/cloth2_170_10.c",
"/obj/generate/boots_170_11.c",
__DIR__"obj/duf_flower.c",
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
	string msg;
	object ghost;
	object target,*enemy;

	set("force",query("max_force")*2);
	ccommand("exert npc_hurtless");

	if (!ANNIE_D->check_buff(me,"damageshield") && !random(3))
		ccommand("exert chill");

	stop_busy();
	
	if (!ANNIE_D->check_buff(me,"damage_to_heal") && !random(3))
		ccommand("exert huaxue");

	stop_busy();
	
	if (!ANNIE_D->check_buff(me,"powerup") && !random(3))
		ccommand("exert powerup");

	stop_busy();
	
	target = select_opponent();
	ccommand("exert mihunshu");

	if (!random(3))
	{
		add_temp("apply/attack",700);
		add_temp("apply/damage",2000);
		ccommand("perform shuanglengcanxia");
		add_temp("apply/damage",-2000);
		add_temp("apply/attack",-700);
		stop_busy();
		return;
	}

	ob=this_object();
	enemy = ob->query_enemy();
	
	if (query("annie/sh")+24 < time())
	{
		add_temp("apply/attack",480);
		add_temp("apply/damage",3000);
		
		msg=YEL"\n杜先生手里的花枝突然一颤，在一颤间似已化作了万千百束点向众人！\n"NOR;
		message_vision(msg, ob,target);
		
		for (i=0;i<sizeof(enemy);i++){
			enemy[i]->add_temp("cant_dodge",1);
			COMBAT_D->do_attack(me,enemy[i],TYPE_PERFORM,"");
			enemy[i]->add_temp("cant_dodge",-1);
			stop_busy();
		}			
		
		add_temp("apply/damage",-3000);			
		add_temp("apply/attack",-480);	 
		set("annie/sh",time());
		return;
	}

//	一个持续攻击Main TANK 的技能

	message_vision("\n    "BMAG HIW"山茶开谢\n"NOR,this_object());
	msg=CYN"　　$N静静的看著瓶中白色山茶花，她的脸色看来也像那一朵朵有八片瓣的茶花一样，
    纯雅、清丽、苍白．一片片、一瓣瓣、一重重叠在一起。
    花瓣忽然散开了。
    她的手指忽然轻轻一弹，花瓣就散开了，花雨缤纷，散乱在$n眼前，散乱了$n的眼。
    "HIC"她的两根手指间已拈起了一根花枝，花枝一抖，刺向$n的双眼！\n"NOR;
	
	message_vision(msg, ob, target);
	
	add_temp("apply/attack",720);
	add_temp("apply/damage",150);

	target->add_temp("apply/no_abs",1);
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,"");
	target->add_temp("apply/no_abs",-1);
	
	if (!random(5))
	if (target->query_temp("damaged_during_attack"))
	{
		ANNIE_D->debuff(target,"powerup");

		if (!ANNIE_D->check_buff(target,"blind"))
		{
			buff =
			([
				"caster":this_object(),
				"who":target,
				"type":"blind",
				"att":"curse",
				"name":"天魔无相·山茶开谢",
				"buff1":"block_msg/all",
				"buff1_c":1,
				"buff2":"apply/attack",
				"buff2_c":-200,
				"buff3":"apply/parry",
				"buff3_c":-200,
				"time":45,
				"buff_msg":YEL"$N"YEL"只觉得眼睛一阵剧痛，登时什么也看不见了。\n"NOR,
			]);
			ANNIE_D->buffup(buff);
		}
	}

	add_temp("apply/damage",-150);
	add_temp("apply/attack",-720);

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
