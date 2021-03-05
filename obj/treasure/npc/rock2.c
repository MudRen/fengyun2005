#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name("长满青苔的礁岩", ({ "moss rock","rock" }) );
	set("race","元素");
	set("long","长满青苔的礁岩封住了洞口。\n");
	set("combat_exp",1);
	set("no_fly",1);
	set("no_curse",1);
	set("busy_immune",4);
	set("no_arrest",1);
  set("no_heal",1);

	set("spawn_location","/d/palace/bao");

	set("real_boss",1);
    set("reward_npc", 1);
    set("difficulty", 10);
    
    // HEHE, just a little damage to keep ppl awaken
	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/amount",20);
	set_temp("damage_shield/msg",CYN"礁岩上的青苔纷纷扬扬地飞了起来，$n忍不住打了个喷嚏！\n"NOR);
				
	set("drop/bg",0);
	// as a low lv boss, giant rock w never bg..
	set("drop/common",100);
	set("drop/rare",0);	// no rare drops.
	set("drop/amount",2);	// drop 3 stuffz sometimes..
	set("drop/common_drop",({
		"/obj/generate/surcoat_15_1.c",
		"/obj/generate/neck_15_1.c",
		"/obj/generate/head_15_11.c",
		"/obj/generate/cloth2_15_11.c",
		"/obj/generate/cloth2_15_1.c",
		"/obj/generate/boots_15_12.c",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );

	set_temp("apply/armor",20);	// So that you need certain damage/level to defeat it.
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
		
	tis = find_object("/d/palace/bao2");
	if (!tis)
		tis=load_object("/d/palace/bao2");

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
