#include <ansi.h>
inherit SMART_NPC;
string smart_fight();

void create()
{
        set_name("师太", ({ "sanqing nun","nun" }) );
        set("gender", "女性");
        set("title","三清宫");
        set("age", 42);
        set("long","她原是丁白云出家前的贴身丫环，已跟随丁白云多年了。\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
	set("no_fly",1);
	set("no_arrest",1);

        set("fy41/sq_bolt_1",1);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );

	set("NO_ASK","．．．你在崖上，她在崖底，如何打听得着？\n");
	set("NO_KILL","你在崖上，她在崖底，如何能碰得着？\n");
	set_temp("condition_type",NOR CYN" <山崖下>"NOR);

	auto_npc_setup("nun",200,200,0,"/obj/weapon/","fighter_w","necromancy",2);
        setup();    
	carry_object("/obj/armor/cloth")->wear();
	setup();
}

string smart_fight()
{
	object me = this_object();
	if (query_busy())
		return 0;
	message_vision(HIG"$N口中喃喃地念著咒文，左手一挥，手中聚起五色光芒，霎时化为三股！\n"NOR,me);
	message_vision(HIC"\n一团青光射向水如昔！\n"NOR,me);
	message_vision(WHT"$N的招式甫近水如昔，就为天都水月上散出的一层微光所阻。\n"NOR,me);
	message_vision(HIW"\n一团白光射向水如昔！\n"NOR,me);
	message_vision(WHT"$N的招式甫近水如昔，就为天都水月上散出的一层微光所阻。\n"NOR,me);
	message_vision(HIM"\n一团紫光射向水如昔！\n"NOR,me);
	message_vision(WHT"$N的招式甫近水如昔，就为天都水月上散出的一层微光所阻。\n"NOR,me);
	start_busy(2);
	return 0;
}


void unconcious()
{
	die();
}

void die()
{
	object *sy_inv,obj;
	int j;
	sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			obj = sy_inv[j];
			destruct(obj);
		}
	set("NO_CORPSE",CYN"\n水如昔身影旋动，将"+name()+"的尸体踢得踪影不见。\n"NOR);
	::die();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
