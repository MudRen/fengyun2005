#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name("大石头", ({ "giant rock","rock" }) );
	set("race","元素");
	set("long","一块高墙一般的大石阻住了你的去路。\n");
	set("combat_exp",1);
	set("no_fly",1);
	set("no_curse",1);
	set("busy_immune",4);
	set("no_arrest",1);
	set("no_heal",1);

	set("spawn_location","/d/taoyuan/treasure");

	set("real_boss",1);
	
	set("reward_npc", 1);
    set("difficulty", 10);
	
	set("drop/bg",0);
	// as a low lv boss, giant rock w never bg..
	set("drop/common",100);
	set("drop/rare",0);	// no rare drops.
	set("drop/amount",2);	// drop 3 stuffz sometimes..
	set("drop/common_drop",({
		"/obj/generate/wrists_15_1.c",
		"/obj/generate/surcoat_15_13.c",
		"/obj/generate/neck_15_11.c",
		"/obj/generate/head_15_1.c",
		"/obj/generate/boots_15_2.c",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );
	
	set_temp("apply/armor",30);	// So that you need certain damage/level to defeat it.
	setup();
}


void die()
{
	object tis, me = this_object();
	object who = query_max_damage_dealer();
	int i;
	object *itemx;

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	tis = find_object("/d/taoyuan/treasureroom");
	if (!tis)
		tis=load_object("/d/taoyuan/treasureroom");

//	SPAWN_D->restart_spawn(1,0);

	if (objectp(who))
	{
		// random drop code..
		ANNIE_D->generate_drop_item(this_object(),who);
		// now move all stuffs to the treasure room.
		itemx=all_inventory(this_object());
		for (i=0;i<sizeof(itemx) ;i++ )
			itemx[i]->move(tis);

	}

	::die();
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
