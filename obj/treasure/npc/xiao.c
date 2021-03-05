inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    object weapon;

		set_name("萧少英", ({ "xiao shaoying","boss","xiao"}) );
		set("nickname",BLU"多情"NOR);
    	set("title","双环门弟子");
		set("gender", "男性" );
		set("class","wolfmount");
		set("age",26);
		set("agi",50);
		set("spawn_location","/d/wolfmount/fogpathx");
		set("long","苍白的脸，满脸刚长出来的胡碴子，还带着一身连暴雨都不能
冲掉的酒气，只有一双眼睛，居然还是漆黑明亮的，这一双眼
睛的主人，正在慢慢叹息。\n");
	
        set("gold", 20);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 5100000);	// L90. CAP @ L85.
    	set("sticky_wolf",1);		// Wolf will not leave
    	
        set_skill("unarmed", 200);
        set_skill("wolf-strike",200);
		set_skill("force", 200);
        set_skill("wolf-force",400);	
		set_skill("dodge", 200);
		set_skill("parry",200);
        set_skill("xueyeqianzong",200);	
		set_skill("cursism", 200);
        set_skill("wolf-curse",200);	
		set_skill("summonwolf",250);
		set_skill("hammer", 200);
		set_skill("assassin-hammer",150);

		map_skill("parry","assassin-hammer");
		map_skill("hammer","assassin-hammer");
        map_skill("dodge", "xueyeqianzong");
        map_skill("unarmed", "wolf-strike");
        map_skill("cursism", "wolf-curse");
        map_skill("force", "wolf-force");
		
		set("max_kee",70000);
		set("max_gin",60000);
		set("max_sen",60000);
        set_temp("apply/armor",100);
        set_temp("apply/damage",200);
        
		setup();
		weapon=carry_object("/obj/armor/cloth");
		weapon->wear();
		
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({		// L70-80 books
			BOOKS"class/xueyeqianzong_feline_2",	
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/dream-herb_huanmengluo_2",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/kwan-yin-spells_ma_2",
			BOOKS"class/qidaoforce_juxue_2",
			BOOKS"class/xuezhan-spear_liguang_2",	
		}));
				
		set("drop/bg",0);
		set("drop/common",100);
		set("drop/rare",0);	
		set("drop/amount",3);
		set("drop/common_drop",({
"/obj/generate/wrists_90_5.c",
"/obj/generate/neck_90_6.c",
"/obj/generate/neck_90_16.c",
"/obj/generate/head_90_6.c",
"/obj/generate/head_90_16.c",
"/obj/generate/boots_90_7.c",
	}) );
		set("drop/rare_drop",({
					"none",
			}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus, weapon;
	
	if (weapon=present("hammer",this_object()))
		destruct(weapon);

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
	object ob, weapon,*inv, enemy;
	string msg;
	int i,kee,ke, duration;
	object target, me = this_object();
	mapping buff;
	
	set("force",query("max_force")*2);
	
	// ALways keep three wolves
	ccommand("perform npc_xiao");
	ccommand("perform npc_xiao");
	ccommand("perform npc_xiao");

	// If hurt, cast paragonm 1200* 10 recover
	duration = query("timer/pfm/wm_paragon")+ 180 -time();
	if (query("kee")<query("max_kee")/2 && duration<0) {
		delete("timer/pfm/wm_paragon");
    	message_vision("\n\n			"BMAG YEL"魔王复苏\n"NOR,this_object());
    	command("exert paragon");	
    }
		
	// Self_buff Bloodthirsty to increase kee leech
	if (!ANNIE_D->check_buff(me,"bloodthirsty")) {
		message_vision("\n\n			"BMAG YEL"百战神狼\n\n"NOR,this_object());
		msg = BRED+HIW"$N突然长啸一声，变掌为抓，满头长发，齐地飘起！\n" NOR;
    	buff =
		([
			"caster":me,
			"who": me,
			"type":"bloodthirsty",
			"att":"bless",
			"name":"天狼心法·战狼诀",
			"buff1":"pfm/wm_bloodthirsty",
			"buff1_c":1,
			"time": 120,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
		return;
	}
			
	// Banish a No.1 Hate player to deathgate.		
	if (sizeof(query_enemy()) > 1 && query_temp("timer/pfm/wm_banish")+ 120 < time()) {
		target = select_opponent();
		if (userp(target) && !stringp(target->query_temp("no_move"))) {
			
			message_vision("\n\n			"BMAG YEL"积尸冥界\n"NOR,this_object());
			msg = HIB "\n$N对$n悲声低吟：生亦何欢。。死亦何苦。。莫若归去。。。\n\n" ;
			msg +=  "$n忽然倒了下来，头上冒出一阵浓雾，浓缩成一个黑影，但很快就消失了。\n" NOR;
			message_vision(msg, me,target);
			target->move("/d/death/gate");
			set_temp("timer/pfm/wm_banish",time());
			return;
		}
	}
	
	// AOE attack everyone every 60 sec
	duration = query("timer/pfm/wm_wolfthrow")+ 50 + random(20) -time();
	if (duration<0) {
		if (!(weapon = present("hammer",me))) {
			inv = all_inventory(environment());
			for (i= 0; i<sizeof(inv); i++) {
				if (inv[i]->query("possessed")==this_object()) {
					message_vision(HIY"\n$N大喝一声，右手急伸，将金毛狼王抡了起来，你只觉劲风扑面，难以呼吸。\n"NOR,this_object());
					inv[i]->die();
					weapon= new("/obj/weapon/hammer");
					weapon->set("name",HIY"金毛狼王"NOR);
					weapon->set("nodrop_weapon",1);
					weapon->set("unwield_msg","$N大喝一声，将$n高高甩向半空。\n");
					weapon->set("wield_msg","$N纵身一跃，将$n挥在手中。\n");
					weapon->move(this_object());
					break;
				}
			}
		}
		if (weapon)	weapon->wield();
		if (query_temp("weapon")) {
			call_out("tobe",4);
			set("timer/pfm/wm_wolfthrow",time());
			start_busy(2);
		}
		return;
	}
	
	if (!is_busy() && query("timer/pfm/wm_canzhi")+ 40 < time())
	{
		command("unwield all");
		delete("timer/pfm/wm_canzhi");
		ccommand("perform canzhi");
		command("wield all");
		stop_busy();	
	}	
	return;
}

int tobe()
{
	string msg;
	int hit_damage, i,damage;
	object target,me, *enemy;
	object weapon;
	
	me = this_object();
			
	if(!(weapon=me->query_temp("weapon"))){
		tell_object(me, WHT"手软了？你怎么把武器收起来了？ \n"NOR);
		return 0;
	}
	
	message_vision("\n\n			"BMAG YEL"旋风千斩\n"NOR,this_object());	
	msg = YEL "\n$N跃起，手中金毛狼王一转，带起阵阵风雷之声。
$N手一抖，"HIY"金毛狼王"NOR YEL"旋转飞出，如风卷黄沙呼啸着击向众人！ \n"NOR;
	message_vision(msg, me);
	
	// 460*3 + 100 = 1560; 1560*1.5= 2340 average
	hit_damage = 100 + me->query_skill("hammer") * 3;
	
	enemy = me->query_enemy();
	
	for (i=0;i<sizeof(enemy);i++){
		target = enemy[i];
		if (COMBAT_D->do_busy_attack(me, target, "assassin-hammer/bolangyiji","unarmed", 500, 10))
		{
			damage = hit_damage + random(hit_damage);	
			damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
			if (damage >= hit_damage *3/4)
				msg = HIR"只见"HIY"金毛狼王"HIR"带着一阵低啸和猛烈的劲风“轰”地击中了$n的头部！\n"NOR;
			else
				msg = HIR"只见"HIY"金毛狼王"HIR"带着一阵低啸和猛烈的劲风“轰”地击中了$n的胸口！\n"NOR;
			message_vision(msg, me, target);
			target->receive_wound("kee",damage, me);
			COMBAT_D->report_status(target);		
		}else 
		{
			msg = HIR"只见"HIY"金毛狼王"HIR"带着一阵劲风贴着$n的脑袋飞过，只差几寸没有击中！\n"NOR;
			message_vision(msg, me, target);
		}
	}
	
	destruct(weapon);
	return 1;
}