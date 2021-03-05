#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", BMAG HIW"踩平居"NOR);
        set("long", @LONG
栈道尽处是一片数坪见方的草地，草地上盖搭着一座小小的木屋，屋外有大
石一块，大石上被人以刚猛的指力雕着“踩平居”三个大字，下有注解三行：

　　　　　　　　　先将天下豪强客　一拳打飞
　　　　　　　　　再把世间不义人　尽数踩平

　　　　　　　　　　　　　岂不快哉！

LONG
        );
    set("exits", ([ 
  		"southdown" : __DIR__"zhandao",
	]));
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",35);
	set("coor/z",20);
	setup();
	set("no_fly", 1);
	set("max_lv",200);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"zhandao");
	if (!exitroom)
		exitroom = load_object(__DIR__"zhandao");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"怒真人隐居山林已久，非常非常不喜欢有人，特别是有高手，去打扰他。\n"NOR);
	}
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

