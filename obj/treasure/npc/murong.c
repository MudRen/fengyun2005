inherit NPC;
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void smart_fight();
string do_flee();

void create()	
{
    	object weapon;

		set_name("慕容秋水", ({ "murong qiushui", "boss","murong" }) );
		set("gender", "男性" );
		set("nickname",BLU"京都第一花花公子"NOR);
    	set("title","世袭一等威灵候");
		set("class","official");
		set("long","三代为官，才懂穿衣吃饭。慕容秋水对自己花花公子的名
号十分满意：要作一个第一号的花花公子，可不是随随便
便什么人都能做到的。\n");

		set("spawn_location","/d/taiping/house3d");

		set("agi", 70);
        set("gender", "男性" );
    	set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
		set("family/master_id","master yue");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 9600000);	// L135.
    
        set_skill("force", 200);
        set_skill("manjianghong", 200);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("yue-spear",200);

        set_skill("leadership", 250);
        set_skill("strategy", 250);
		set_skill("puti-steps",200);
		set_skill("dodge",200);

		set_skill("celecurse",200);
		set_skill("qiankunwuxing",200);
		
		map_skill("dodge","puti-steps");
        map_skill("force", "manjianghong");
        map_skill("parry", "yue-spear");
        map_skill("spear", "yue-spear");
		
		set("max_kee",300000);
		set("max_gin",300000);
		set("max_sen",300000);
        
		setup();

		weapon=carry_object("/obj/weapon/spear");
		weapon->set_name(YEL"祖传宝枪"NOR, ({ "spear" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(HIW"波斯绣缎的长袍"NOR, ({ "cloth" }) );
		weapon->set("long","波斯绣缎的长袍(Cloth)。");
		weapon->set("value",0);
		weapon->wear();

	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_150_8.c",
"/obj/generate/surcoat_150_23.c",
"/obj/generate/neck_150_9.c",
"/obj/generate/cloth1_150_19.c",
"/obj/generate/boots_150_10.c",
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
        object *shiwei;
        object me = this_object();
        int i;
        ::kill_ob(who);
        shiwei = filter_array(all_inventory(environment(me)),
       		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
        if (shiwei && sizeof(shiwei))
        {
        	for (i=0;i<sizeof(shiwei);i++)
        		shiwei[i]->kill_ob(who);
        }	
        smart_fight();
        return 1;
}


int get_baby()
{
    int skill, num, i, duration;
	object *shiwei;
	mapping buff;
	string msg;
	object me= this_object();
	
	int extra, maximum, gcount;
	object recruit;
	
	object *enemy;
	
    gcount=me->query_temp("guard_count");
	if(gcount>3)
		return 1;
                	
	msg = BGRN + HIY "$N"BGRN + HIY "挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"三才天地人之阵！\n" NOR YEL"
忽见阵外腾腾腾走来一名壮士，扑地拜倒在$N"NOR+YEL"身前，朗声说道：将军之义，天高水长，
在下$n愿在帐前效力，卫国杀敌，万死不辞。\n\n"NOR; 	
  	
  	extra=me->query_skill("strategy",1)+ me->query_skill("leadership",1);
	seteuid(getuid());
	recruit=new("/obj/npc/huwei");
	recruit->invocation(me,extra);
	recruit->move(environment(me));
	recruit->set("max_kee",8000);
	recruit->set("max_sen",8000);
	recruit->set("max_gin",8000);
	recruit->full_me();
  	message_vision(msg, me, recruit);
	me->add_temp("guard_count",1);
	
	if (!userp(me))
	{
		enemy = me->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				recruit->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(shiwei);
				else enemy[i]->kill_ob(recruit);
			}
		}
	}
    return 1;
}

int perform_si(object me)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	if (me->query_temp("guard_count")<4)	return 1;
        	
	msg = BGRN + HIY"$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"四车兜底之阵！\n" NOR; 	
  	message_vision(msg, me);
  	
	skill = 100;
	
	// Well: SHiwei = shiwei + friend + myself:)
    shiwei = filter_array(all_inventory(environment(me)),
       		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    
    num = sizeof(shiwei);	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"兵法·四车兜底阵",
				"buff1":"apply/parry",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",
				"disa_type":1,			
			]);
		ANNIE_D->buffup(buff);		
    }
    me->set_temp("xxx/4",time());
    return 1;
}

int perform_qi(object me)
{
    int skill, num, i, duration, mod,apply;
	string msg, name;
	object *env, *huwei, weapon,target;
	int j=0;
	
	skill = me->query_skill("strategy",1);

	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return 1;
		
    if (me->query_temp("guard_count")<3)
        	return 1;
        
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2 
		&& $1->query("id")!="sishi" && $1->query("id")!="bodyguard" :), me);
	if (!sizeof(huwei))
		return 1;
	
	if (huwei[0]->query_temp("is_unconcious") 
  		|| !huwei[0]->is_fighting(target) || huwei[0]->is_busy())	
  		return 1;
  		
	msg = BGRN + HIY"$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"七星斩将之阵！\n"NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	for (i=1;i<sizeof(huwei);i++) {
  		if (huwei[i]->query_temp("is_unconcious") 
  			|| !huwei[i]->is_fighting(target)
  			|| huwei[i]->is_busy())	continue;
  		else {
  			message_vision(CYN""+huwei[i]->name()+"伸出左掌，搭于"+ huwei[i-1]->name()+"肩上。\n"NOR,me);	
  			j++;
  		}	
  	}
	
	// normally atk+375, dmg+750, maximum with 十面埋伏 atk+375, dmg+1250
  	huwei[0]->add_temp("apply/attack", skill*5/2);
  	huwei[0]->add_temp("apply/damage",j * skill);
// 	write("add + "+ j + "\n");
  	
	target->add_temp("buff/no_abs",1);
	
	huwei[0]->add_temp("apply/damage",500);
  	if (huwei[0]->query("skill")== "spear") {
  		huwei[0]->ccommand("perform zonghengtianxia");
  	}
  	if (huwei[0]->query("skill")=="hammer") {
  			huwei[0]->ccommand("perform fanbei");
  	}	
	huwei[0]->add_temp("apply/damage",-500);
	
  	if (target) {
		target->add_temp("buff/no_abs",-1);
		if (!target->query_temp("buff/no_abs"))
			target->delete_temp("buff/no_abs");
	}
  		
  	huwei[0]->add_temp("apply/attack", -skill*5/2);
  	huwei[0]->add_temp("apply/damage",-j* skill);

	me->set_temp("xxx/7",time());
    return 1;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object me = this_object();
	int i,extra,tmp;
	object ghost,target;
	string msg;

	set("atman",query("max_atman")*2);

	get_baby();		// one each time, up to enemy number :P
	
	
	if (me->query_temp("xxx/4") + 600 < time()) {			// huwei 30 sec a hit
		perform_si(me);
	}
	
	if (me->query_temp("xxx/7")+ 16 < time()) {			// huwei 16 sec a hit
		perform_qi(me);
	}
		
	ccommand("perform likangqunmo");		// AOE every 10 sec 

	if (!me->is_busy() && me->query_temp("xxx/zhtx")+ 40 < time()) {
		ccommand("perform zonghengtianxia");
		me->set_temp("xxx/zhtx",time());
		me->stop_busy();
		return;
	}

	if (!me->is_busy() && me->query_temp("xxx/jcfs")+ 22 < time() && query("kee") < query("max_kee")/5*3
		|| query("sen")< query("max_sen")/5*3 
		|| query("gin")< query("max_gin")/5*3
		) {	
		ccommand("exert npc_hurtless");
		// ok , this is the real killer
		target=select_opponent();
		extra = me->query_skill("yue-spear",1);
		tmp = 5000;		
		me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", tmp);
        target->add_temp("cant_dodge",1);
        target->add_temp("cant_parry",1);
        msg = HIW  "\n$N"HIW"大喝一声，双手抓住枪柄，斗然间拧腰纵臂，回身出枪，直刺$n"HIW"面门！！" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
   		target->add_temp("cant_dodge",-1);
        target->add_temp("cant_parry",-1);
   		me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -tmp);
		
		me->set_temp("xxx/jcfs",time());
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

