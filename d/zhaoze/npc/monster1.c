inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("火巨灵", ({ "fire giant","giant"}) );
        set("long","一个高大的，全身通红的巨人。\n");
        set("age", 51);
        set("combat_exp", 1500000);
	set("group","giant");
        set("attitude", "aggressive");    	
//	set_temp("damage_shield",1);
	set_temp("damage_shield/amount",200);
	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/msg",HIR"火巨灵周身灼热无比，$n只觉热浪扑面，差点没晕了过去。\n"NOR);
	
	set("NO_CORPSE",RED"火巨灵惨叫一声，化成一团红焰，红焰愈烧愈烈，篷地一声炸成千万点火星消失无踪。。\n\n\n"NOR);
	
	auto_npc_setup("wang",150,120,0,"/obj/weapon/","fighter_w","bat-blade",1);	
	setup();
    	carry_object(__DIR__"/obj/firespirit");    
    	carry_object(__DIR__"obj/fireblade")->wield();
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
		
		amount = me->query_temp("damage_shield/amount");
		switch (amount)
		{
			case 200: 	data["msg"] = WHT"＊$N的"+weapon->name() + NOR WHT"寒气暴涨，罩住$n！＊\n"NOR;
					me->set_temp("damage_shield/amount",100);
					break;
			case 100: 
					data["msg"] = WHT"＊$N的"+weapon->name() + NOR WHT"吐出一团白雾，$n如临冰窟！＊\n"NOR;
					me->set_temp("damage_shield/amount",50);
					break;
			case 50:
					data["msg"] = WHT"＊$N的"+weapon->name() + NOR WHT"炸出千点雪晶，$n热焰尽灭！＊\n"NOR;	
					me->delete_temp("damage_shield");
					break;
			default:	return 0;
		}
		data["damage"] = 0;
		return data;
	}
	
	return 0;
		
}
