// annie 07.2003
// dancing_faery@hotmail.com


#include <ansi.h>
#include <combat.h>
//inherit __DIR__"maze_npc.c";
inherit SMART_NPC;

void smart_fight();

void create()
{	
	object weapon;
	set_name("七情水仙", ({ "narcissus","boss" }) );
	set("class","moon");
	set("group","icecave_maze");
	set("gender","女性");
	set("age",16);
	set("per",34);
	set("score",-10000);
	set("force_factor",160);
	set("spawn_location","/d/xiangsi/narcissus_place");
	set("str",24);
	set("agi", 80);
	set("gold", 40);
	set("real_boss",1);
	set("boss",1);

	set("max_gin",140000);
	set("max_sen",140000);
	set("max_kee",140000);
	set("max_force",2000);
	set("force",3000);

	set_temp("buff_type/blocked",1);

	set("combat_exp", 8100000);	// L120
	set_skill("mapo", 200);
	set_skill("spells", 200);
	set_skill("stormdance", 200);
	set_skill("snowforce", 280);
	set_skill("shuaijiao", 210);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("divineforce", 200);

	set("nb_chat_chance", 100);
	set("nb_chat_msg_combat", ([
		100: 	(: smart_fight() :),
	]) );    	

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("unarmed", "shuaijiao");
	map_skill("force", "snowforce");
	map_skill("spells", "mapo");
	setup();

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name(HIG"束额玉环"NOR, ({ "emerald diadem"}) );
	weapon->set("long","一个纯银打造的玉环，上面镶嵌着一块透绿的翡翠。\n");
	weapon->set("no_get",1);
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/d/xiangsi/npc/obj/longskirt");
	weapon->set_name(HIR BLK"莲台舞衣"NOR, ({ "dancer skirt"}) );
	weapon->set("long","一件轻柔有如无物的薄纱。\n");
	weapon->set("no_get",1);
	weapon->set("value",0);
	weapon->wear();

	carry_object("/d/xiangsi/mazenpc/obj/nacrissus_boot")->wear();

	set("attitude", "friendly");

	set("long",WHT"她姿态婉然，容色艳丽，此刻正在沉坐静思。\n她就是玄冰前洞的守卫者七情水仙。\n\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);

	add_temp("apply/damage",500);
	set("drop/fixed_amount",1);
	set("drop/fixed_drop", ({		// L80-90 books
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/xueyeqianzong_wolverine_3",
			BOOKS"class/nine-moon-claw_weiwoduzun_2",
			BOOKS"class/yijinjing_shield_2",
			BOOKS"class/yue-spear_juechufengsheng_2",
	}));
		
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_130_7.c",
"/obj/generate/neck_130_8.c",
"/obj/generate/head_130_18.c",
"/obj/generate/boots_130_9.c",
"/obj/generate/boots_130_19.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}

//  chaos attack
int do_berserk(){

	object *tar;
	int i,j;
	object target;

	tar = query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(HIY"\n$N左掌虚虚画了个半圆。沉气开声，大喝一声将右掌向场中拍去。\n"NOR,this_object());
		message_vision("			"BMAG YEL"七情水仙·反\n"NOR,this_object());
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// 为了让parry busy生效(爆,太恶毒了),这里不使用mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,HIY"$N"HIY"只觉得一道大力推来，身不由己的向$n"HIY"攻去！"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
			target->receive_damage("kee",1,this_object());
		}
		perform_busy(2);
	}	
}

//  20秒钟内No perform
int do_lock(object ob, object me){
		mapping buff;
		if (!ANNIE_D->check_buff(ob, "lockup"))		
		{	
			tell_object(ob, "			"BMAG YEL"七情水仙·封\n"NOR);
			buff =
			([
				"caster":me,
				"who":	 ob,
				"type": "lockup",
				"att":  "curse",
				"name": "七情水仙·封",
				"time":  20,
				"buff1": "till_death/lockup",
				"buff1_c": 1,
				"buff_msg": "",
				"warn_msg":"",
			]);
			ANNIE_D->buffup(buff);				
		}	
		return 1;
}

//  20 秒钟内 heal curse
int do_healcurse(object ob, object me){
		mapping buff;
		if (!ANNIE_D->check_buff(ob,"cursedflesh"))
		{
			tell_object(ob, "			"BMAG YEL"七情水仙·伤\n"NOR);
			buff =
			([
				"caster":me,
				"who":	ob,
				"type": "cursedflesh",
				"att":  "curse",
				"name": "七情水仙·伤",
				"time": 20,
				"buff_msg": "",
				"warn_msg":"",
			]);
			ANNIE_D->buffup(buff);
		}
		return 1;
}

// 10 sec blindness
int do_blind(object ob, object me){
	mapping buff;
	if (!ANNIE_D->check_buff(ob,"blind"))
	{
		tell_object(ob, "			"BMAG YEL"七情水仙·盲\n"NOR);
		buff =
		([
			"caster":me,
			"who": ob,
			"type":"blind",
			"att":"curse",
			"name":"七情水仙·盲",
			"buff1":"block_msg/all",
			"buff1_c":1,
			"time": 10,
			"buff_msg":"",
		]);
		ANNIE_D->buffup(buff);
   	}
	return 1;
}

// 20 sec can't run
int do_norun(object ob, object me){
	
	mapping buff;
	if (!ANNIE_D->check_buff(ob,"lockfield"))
	{
		tell_object(ob, "			"BMAG YEL"七情水仙·留\n"NOR);
		buff =
			([
				"caster":me,
				"who": ob,
				"type":"lockfield",
				"att":"curse",
				"name":"七情水仙·留",
				"time":20,
				"buff_msg":"",
			]);
		ANNIE_D->buffup(buff);
	}
	return 1;
}

// debuff all blessing
int do_debuff(object ob, object me){
	tell_object(ob, "			"BMAG YEL"七情水仙·衰\n"NOR);
	ANNIE_D->debuff(ob,"all",1);
	return 1;
}

// busy 3 turns
int do_stun(object ob, object me){
	mapping buff;
	if (!ANNIE_D->check_buff(ob, "busy"))
	{
		tell_object(ob, "			"BMAG YEL"七情水仙·乱\n"NOR);
		buff =
		([
			"caster":me,
			"who": ob,
			"type": "busy",
			"att":"curse",
			"name":"七情水仙·乱",
			"time": 6,
			"buff_msg":"",
		]);
		ANNIE_D->buffup(buff);
   		ob->force_busy(3);
   	}
	return 1;	
}


int hurting(){
	int i,dam;
	object *inv,target, me, tt;
	mapping buff;
	me = this_object();
	inv = query_enemy();
	if (!inv || !sizeof(inv))
		return 0;
	message_vision(HIW"\n$N"HIW"额上散出一层雪似的白芒，转瞬间就将众人笼罩在内。\n\n"NOR,this_object());
    
// 喜(berserk)怒(lock)忧(healcurse)思(blind)悲(cant run)恐(debuff) 惊(stun)

	do_berserk();
	    		
	inv = query_enemy();
	if (sizeof(inv))	
  	for (i=0; i<sizeof(inv);i++) {  		
  		target = inv[i];
  	 	if (objectp(tt) && target == tt)	continue;
//  	 	switch (random(6)) {
		switch (random(6)) {
  	 		case 0: do_lock( target, me);	break;
	    	case 1: do_healcurse(target, me); break;
	    	case 2: do_blind(target, me); break;
	    	case 3: do_norun(target, me); break;
	    	case 4: do_debuff(target, me); break;
	    	case 5: do_stun(target, me); break;
	    }
    }
    return 1;	
}


void unconcious()
{
	die();
}

void die()
{
	object *enemies,target,*sy_inv,things,me;
	int i,j;
	object who;

	enemies=query_enemy();
	if (enemies && sizeof(enemies))
	{
		message_vision(BRED HIW"\n尽断七情\n"NOR,this_object());
		message_vision(HIW"\n$N"HIW"咬住下唇，抬手拭去嘴角鲜血，忽然单足点地，旋身飞舞。
但见$N"HIW"身上衣裳化为片片蝴蝶，纷飞而出，你不禁目弛神醉．．．

"HIR"舞尽之时，$N两手微分，身子半躬，突然爆作一片血雨，将众人尽数笼罩在内。\n\n"NOR,this_object());

		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++)
		{
			things = sy_inv[j];
			destruct(things);
		}
		// 每人送个shimon
		set("kee",2000);
		set("sen",80000);
		set("gin",80000);
		add_temp("apply/attack",888);
		add_temp("apply/damage",1333);

		for (i=0; i<sizeof(enemies); i++)
		{
			target = enemies[i];
			target->add_temp("combat_no_report",1);
			stop_busy();
			target->perform_busy(1);
			COMBAT_D->do_attack(this_object(),target, TYPE_PERFORM);
			target->add_temp("combat_no_report",-1);
			if (target->query_temp("damaged_during_attack"))
				COMBAT_D->report_status(target);
		}
	}

	who = query_max_damage_dealer();
	if (!objectp(who))
		who = query_temp("last_damage_from");
	
	if (!objectp(who) && enemies && sizeof(enemies))
		who = enemies[random(sizeof(enemies))];
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
		
	::die();	
	return;
}

void smart_fight()
{
	int i;
	object me,ob,*enemy;
	mapping buff;
	me = this_object();
	
	ccommand("exert npc_hurtless");
	if (time()>query("annie/ec")+20)		// 七情最多延续20秒
	{
		set("annie/ec",time());
		message_vision(BBLU HIW"\n七情之炫\n"NOR,me);
		message_vision(HIR"\n$N"HIR"双手负在背后，轻轻飘起，微敛的眉心中间一点朱砂越发鲜艳．．．\n\n"NOR,this_object());
		call_out("hurting",8);
	}

}

