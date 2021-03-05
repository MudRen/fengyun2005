inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    	object weapon;

		set_name("赵飞柳", ({ "zhao feiliu","boss","zhao"}) );
		set("gender", "男性" );
		set("nickname",BLU"阎王伞"NOR);
    	set("title","血雨门");
		set("class","legend");
		set("age",77);
		set("spawn_location","/d/cyan/peakx");

		set("long","一个青衣白发的老人，一个人独行在山道间，手里撑着柄油纸伞。嘴角带
着丝神秘而诡谲的微笑，天上乌云密布，细雨纷纷，滴滴落在老人手上的
油纸伞上。\n");

        set("gender", "男性" );
    	set("agi",70);
    	set("gold",30);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 7100000);	// L110
    	set_temp("apply/armor",80);
    	
        set_skill("force", 400);
        set_skill("divineforce",250);
        set_skill("dodge", 400);
        set_skill("fall-steps",250);
        set_skill("unarmed", 400);
        set_skill("luohan-quan",220);
        set_skill("parry", 200);	

        map_skill("force", "divineforce");
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "luohan-quan");	// 想打落我武器的就来吧..
		
		set("max_kee",90000);
		set("max_gin",70000);
		set("max_sen",70000);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(YEL"油纸伞"NOR, ({ "umbrella" }) );
		weapon->set("long","油纸伞(Umbrella)。");
		weapon->set("value",0);
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(CYN"血雨青衣"NOR, ({ "cloth" }) );
		weapon->set("long","血雨青衣(Cloth)。");
		weapon->set("value",0);
		weapon->wear();
		
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
"/obj/generate/wrists_110_6.c",
"/obj/generate/surcoat_110_19.c",
"/obj/generate/neck_110_7.c",
"/obj/generate/neck_110_17.c",
"/obj/generate/cloth2_110_7.c",
"/obj/generate/boots_110_8.c",
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

void smart_fight()
{
	object ob;
	mapping buff;
	object target,*enemy;
	int f,i;
	
	enemy=query_enemy();
	
	if (!random(3))
	{
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"lowresist"))	continue;
				message_vision(BCYN WHT"\n破世阴雩\n"NOR,this_object());
				message_vision(HIB"\n赵飞柳的伞突然一收，满天的黑云聚起，忽然间一声霹雳，"NOR,this_object());	
				message_vision(HIB"闪电自云层击下，照亮了阴翳的天际。\n"NOR,this_object());
				buff =
					([
						"caster":this_object(),
						"who":ob,
						"name":"天魔无相·破世阴雩",
						"type": "lowresist",
						"att": "curse",
						"buff1":"resistance/kee",
						"buff1_c":-20,
						"time":60,
						"buff_msg":HIB"$N"HIB"心头剧振，眼前一阵眩晕。\n"NOR,
					]);
				ANNIE_D->buffup(buff);
				break;
			}
		}	
	}
		
	if (!random(3))
	{
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"cursedflesh"))	continue;
				message_vision(BBLU HIW"\n空魂异血\n"NOR,this_object());
				buff =
				([
					"caster":this_object(),
					"who":	ob,
					"type": "cursedflesh",
					"att":  "curse",
					"name": "破邪心经·空魂异血",
					"time": 30,
					"buff_msg":HIC"\n$n"HIC"面上浮现出青蓝之色，喷出一团腥臭的烟气。
"HIB"$N"HIB"猝不及防，吸进一口毒雾，登时摇摇欲坠．．．\n\n"NOR,
				]);
				ANNIE_D->buffup(buff);
				break;
			}
		}	
	}

	target = select_opponent();
	add_temp("apply/attack",250);
	add_temp("apply/damage",400);
	message_vision(BRED WHT"\n伤痕措手\n"NOR,this_object());
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,HIB"赵大先生的伞一撑，人影已如鬼魅般贴近$n，五指向$n背上抓去！"NOR,"抓伤！
"HIR"$n的背上被抓得鲜血淋漓．．．"NOR);
	add_temp("apply/damage",-400);
	add_temp("apply/attack",-250);
	
	if (target->query_temp("damaged_during_attack"))
	{
		if (!ANNIE_D->check_buff(target,"armorup"))
		{
				buff =
				([
					"caster":this_object(),
					"who":target,
					"name":"天魔无相·伤痕措手",
					"type": "armorup",
					"att": "curse",
					"buff1":"apply/armor",
					"buff1_c": -100,
					"time":	  60,
					"buff_msg":" "NOR,
				]);
				ANNIE_D->buffup(buff);
		}
	}

	return;
}


mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	object thr;
	if (!thr = attacker->query_temp("weapon"))
		return 0;
	if (thr->query("skill_type") != "throwing")
		return 0;
	data["msg"] = CYN"赵飞柳手里的油纸伞风车般旋转起来，突然间已化成一道光圈。\n只听叮、叮、叮一连串急响，"+thr->name()+CYN"已在一瞬间被震飞。\n"NOR;
	data["damage"] = -damage;
	return data;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

