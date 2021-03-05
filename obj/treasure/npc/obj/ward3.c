#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( RED"伤"NOR, ({ "shang","伤" }) );
    set("unit", "个");
	set("long","一个涂写在地上的大字，隐隐地散发着红光。\n");
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
		message_vision(RED"\n暗红的光华慢慢消散了。\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	friends = enemy->query_enemy();
	if (environment() != environment(enemy))
	{
		message_vision(RED"\n暗红的光华慢慢消散了。\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	if (!enemy->is_fighting())
	{
		message_vision(RED"\n暗红的光华慢慢消散了。\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	message_vision(CYN"\n暗红的光华黯淡了一些，周围的人气血一阵翻涌，仿如内伤。\n\n"NOR,enemy);
	for (i=0;i<sizeof(friends) ; i++)
	{
		mod = COMBAT_D->can_busy(enemy, friends[i], "tanzhi-shentong");	
		if (COMBAT_D->do_busy_attack(enemy, friends[i], "tanzhi-shentong/tanzhijinghun", "unarmed", 400, mod))
		{
			message_vision(RED"$N脸色苍白，一缕鲜血缓缓自嘴角爬下。\n"NOR,friends[i]);
			friends[i]->receive_damage("kee",300+random(500), enemy);
		}
//		message_vision("test:$N",friends[i]);
	}
	count --;
	if (count < 1)
	{
		message_vision(RED"\n暗红的光华慢慢消散了。\n"NOR,enemy);
		destruct(this_object());
		return 1;
	}
	call_out("heal_ob",10,enemy,count);
}
