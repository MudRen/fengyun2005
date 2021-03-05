inherit SMART_NPC;
#include <ansi.h>

int dragon_shield();
int dragonclaw();

void create()
{
    	set_name(HIR"烈火孽龙"NOR, ({ "red dragon", "dragon" }) );
        set("race", "龙");
        set("gender", "雄性");
        set("age", 200);
        set("group","giant");
        set("reward_npc", 1);
        set("difficulty", 40);        
        set("long", "
这是一条全身赤红，吸天地之间的火气而长大的孽龙！它全身散发着赤红色的
火焰，正恶狠狠地看着你，似乎要把你一口吞下去。\n");
        
    	set("attitude", "aggressive");
		set("big_boss",1);       
        set("toughness",900);
        
//		set_temp("damage_shield",1);
		set_temp("damage_shield/amount",400);
		set_temp("damage_shield/type","kee");
		set_temp("damage_shield/msg",HIR"烈火孽龙身畔烈焰滚滚，$n差点没晕了过去。\n"NOR);
    	   	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		80:	(: dragon_shield() :),
        ]) );    	
    	
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: dragonclaw()	:),
        }) );

        set("combat_exp", 2500000);
        set("bellicosity", 3000 );
        
    	set_temp("apply/attack", 400);
    	set_temp("apply/dodge", 400);
		set_temp("apply/parry", 400);

        setup();
		carry_object(BOOKS"force_70");
		carry_object(BOOKS"force_70");
}


int dragon_shield(){
	if (time()>query("dragon/breath")+ 300 && !query_temp("damage_shield")) 
	{	
		message_vision(HIR"\n
烈火孽龙从黑水里深深地吸入一口火气，全身转为鲜红的火色，整个龙腹胀大了几倍！！\n\n"NOR,this_object());
//		set_temp("damage_shield",1);
		set_temp("damage_shield/amount",200);
		set_temp("damage_shield/type", "kee");
		set_temp("damage_shield/msg",HIR"烈火孽龙身畔烈焰滚滚，$n差点没晕了过去。\n"NOR);
		set("dragon/breath",time());
	}
	return 1;
}

int dragonclaw()	{
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	ob->set("bite_time",time());
	enemy=ob->query_enemy();
	me=enemy[random(sizeof(enemy))];
	message_vision(HIG"\n烈火孽龙举起巨灵般的前爪，挟风雷之势，迅急地向$n的头部一抓。\n"NOR,ob,me);
	me->receive_damage("kee",200+random(200),ob);
	COMBAT_D->report_status(me);
	ob->perform_busy(2);
	return 1;
}

void die()
{
        object book;
        object me, owner,*team,*team2;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
			me = owner;
		} 
		
        if (me){	
        	team = me->query_team();
        	if (team && sizeof(team)){
        		team2 = filter_array(team, (:environment($1)==environment($2):),this_object());
        		map_array(team2, (:REWARD_D->riddle_done($1,"勇杀孽龙",100,1):));
        	} else
        		REWARD_D->riddle_done(me,"勇杀孽龙",100,1);
        }
        
        ::die();
}

mapping ob_hit(object ob, object me, int damage) {
	
	int amount;
	object weapon;
	mapping data =([]);
	
	if (damage <=0 || !me->query_temp("damage_shield"))	
		return 0;
	
	weapon = ob->query_temp("weapon");
	if (objectp(weapon) && weapon->query_temp("icy_dipped"))
	{
		
		if (amount <=800)
		{
data["msg"] = WHT"＊$N的"+weapon->name() + NOR WHT"寒气暴涨，烈火孽龙的火光却更强烈了！＊\n"NOR;
			me->add_temp("damage_shield/amount",50);
			data["damage"] = 0;
			return data;
		}
	}
	
	if (objectp(weapon) && weapon->query("red_dragon_bane") && me->query_temp("damage_shield"))
	{
data["msg"] = HIW"$N手中的火焰长刀喷出一股猩热，与孽龙蓄势欲发的火一碰而爆，孽龙身畔的火焰顿时灰飞烟灭！\n"NOR;
		me->delete_temp("damage_shield");
		data["damage"] = 0;
		return data;
		
	}
	return 0;
		
}
