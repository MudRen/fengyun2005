#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( MAG"定"NOR, ({ "ding","定" }) );
    set("unit", "个");
	set("long","一个涂写在地上的大字，隐隐地散发着紫光。\n");
    set("value",0);
    set("no_get",1);
	set("no_clean_up",1);
    set_weight(150000);
    ::init_item();
}

int heal_ob(object enemy,int count)
{
	object * friends;
	int i,mod;
	if (!enemy)
	{
		message_vision(MAG"\n淡紫的光华慢慢消散了。\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	friends = enemy->query_enemy();
	if (environment() != environment(enemy))
	{
		message_vision(MAG"\n淡紫的光华慢慢消散了。\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	if (!enemy->is_fighting())
	{
		message_vision(MAG"\n淡紫的光华慢慢消散了。\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	message_vision(CYN"\n淡紫的光华黯淡了一些，周围的人心头一紧，如受巨锤猛撞。\n\n"NOR,enemy);
	for (i=0;i<sizeof(friends) ; i++)
	{
		mod = COMBAT_D->can_busy(enemy, friends[i], "fall-steps");	
		if (COMBAT_D->do_busy_attack(enemy, friends[i], "fall-steps/luoyeqiufeng", "step", 200, mod))
		{
			message_vision(MAG"$N步法一乱，脚下打了个踉跄。\n"NOR,friends[i]);			
//			friends[i]->set_temp("busy_timer/fall-steps",time());
			friends[i]->force_busy(friends[i]->query_busy()+1);
		}
//		message_vision("test:$N",friends[i]);
	}
	count --;
	if (count < 1)
	{
		message_vision(MAG"\n淡紫的光华慢慢消散了。\n"NOR,enemy);
		destruct(this_object());
		return 1;
	}
	call_out("heal_ob",10,enemy,count);
}
