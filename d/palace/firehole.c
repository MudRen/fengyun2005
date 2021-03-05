// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火窟");
	set("long", @LONG
才入洞口，就觉的一阵热气扑面而来。入洞越深，四周空气越热，渐渐热如火
窟。你不禁汗如雨下，转目四望，只见四面山壁，竞已变作了暗赤之色，仿佛随时
会有火炎涌出。
LONG
	);
	set("exits", ([ 
 		 "north" : __DIR__"interroad",
	]));

	set("outdoors", "palace");
        set("objects", ([
        	__DIR__"npc/wolfman" : 1,
         ]) );
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void init()
{	object ob;
	if( interactive(ob = this_player())) {
		remove_call_out("arrowing");
		call_out("arrowing", random(10)+5, ob);
	}
}

int arrowing(object ob)

{
	int i;
	int damage;
	if(ob)
        if( environment(ob) == this_object())
	{
		message_vision(HIR"一股炽热的熔炎形成一个大火球向$N激射而出！！\n", ob);
		message_vision("$N被炽热的熔炎喷得焦头烂额，奄奄一息！\n"NOR, ob);
 		i = (int)ob->query("eff_kee");
		damage = random(200)+25	;
        	ob->set("eff_kee",(int) i - damage );
		i =  (int)ob->query("kee");
		ob->set("kee",(int) i - damage);
		if (ob->is_zombie()) ob->die();
		ob->set_temp("last_damage_from","在帝王谷火窟被烧死了。\n");
		if( environment(ob) == this_object())
			call_out("arrowing",5, ob);	
	}
	else
		return 1;
}

