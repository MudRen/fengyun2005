inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("火巨灵", ({ "fire monster","monster"}) );
        set("long","一个高大的，全身通红的巨人。\n");
        set("age", 51);

        set("combat_exp", 2000000);
	set("group","giant");
        set("attitude", "aggressive");
        set_skill("move",200); 	
//	set_temp("damage_shield",1);
	set_temp("damage_shield/amount",300);
	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/msg",HIR"火巨灵周身灼热无比，$n只觉热浪扑面，差点没晕了过去。\n"NOR);
	
	auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","bat-blade",1);	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
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
			case 300: 	data["msg"] = WHT"＊$N的"+weapon->name() + NOR WHT"寒气暴涨，罩住$n！＊\n"NOR;
					me->set_temp("damage_shield/amount",200);
					break;
			case 200: 
					data["msg"] = WHT"＊$N的"+weapon->name() + NOR WHT"吐出一团白雾，$n如临冰窟！＊\n"NOR;
					me->set_temp("damage_shield/amount",100);
					break;
			case 100:
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