
inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long", @LONG
禅房阴暗潮湿，破旧不堪，和雄伟瑰丽的布达拉宫行成鲜明的对比。每一个进
入禅房的人都感到阴暗衰老，暮气沉沉，连感觉都似乎麻木了起来。
LONG
        );

        set("valid_startroom", 1);
        set("exits", ([ 
  		"east" : __DIR__"tower",
	]));
        set("objects", ([
                __DIR__"npc/lama3" : 3,
		__DIR__"npc/master" : 1,
//        __DIR__"npc/yellama" : 1,
		__DIR__"obj/ironstaff" : 1,
        ]) );
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

