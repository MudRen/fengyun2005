
inherit ROOM;

void create()
{
    set("short", "山门");
    set("long", @LONG
山峦以近，眼前一道石门耸立，石门上书[33m『华山』[32m两个隶书大字，石门后山峰秀
丽挺拔，仰头看重峦叠嶂高耸入云，一条青石小路穿过山石门向南延伸去。小路旁
是用碗口的毛竹搭起个凉棚，四面一片青翠，凉风阵阵送爽，在酷热的天气里，赶
路赶累了能够找一这么样一个地方歇脚，实在很不错。
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"road4",
  		"south" : __DIR__"xiaojing",
	]));
	set("objects", ([
		__DIR__"npc/fatman" : 1,
		__DIR__"npc/xiaobao" : 1,
	]));
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",20);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}

