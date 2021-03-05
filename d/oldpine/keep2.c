// Room: /d/oldpine/keep2.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "寨内");
        set("long", @LONG
这里应该是老云寨了，虽然围绕著你的墙都是木头搭成的，但是仔细一看，在
许多险要的位置都放了不少沙包石堆，後面显然是埋伏人手的好地方，如果有人贸
然从大门口攻进来，肯定会吃大亏的，大寨的门在你的西边，东边越过一排木桩之
後就是大厅。
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"keep15",
                "east" : __DIR__"keep3",
        ]));
        set("objects", ([
        	__DIR__"npc/bandit_guard" : 2,
        ]) );

	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string exit)
{
//      int i;
//      object ob;

        if( exit != "east"
        ||      !query("exits/west") || !userp(me) )
                return 1;

        message("vision",
                HIY "你听到你身後有几个声音大叫：把门关上！把门关上！一个也不许让他们溜走！\n"NOR
                        "接著「轰」地一声，通往外面的大门已经被一块大石堵死了。\n",
                this_object() );
        delete("exits/west");

		REWARD_D->riddle_done(me,"闯老云寨",10, 1);
        if (QUESTS_D->verify_quest(me,"探老云寨"))
			QUESTS_D->special_reward(me,"探老云寨");

        return 1;
}

void reset()
{
//      object ob;

        ::reset();
        set("exits/west", __DIR__"keep15" );
        
}

void pipe_notify()
{
        object ob;

        message("vision",
                "你听到一阵轧轧的轮盘绞动声，堵住门口的大石慢慢地被移开了。\n",
                this_object() );
        set("exits/west", __DIR__"keep15" );
        if( ob = find_object(__DIR__"keep15") )
                ob->set("exits/east", __DIR__"keep2");
}