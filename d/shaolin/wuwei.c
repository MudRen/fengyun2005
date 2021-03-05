// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "无为楼");
        set("long", @LONG
一间红木小楼，门前匾额上“无为”两字与北面的清静楼遥相呼应，楼内只有
一张茶几，一只小火炉，想来主人必是茶道高手，东墙上悬宝剑一把，剑鞘古色古
香，一看便知绝非凡品，西墙上一条横幅：

			[37m极乐世界[32m

LONG
        );
        set("exits", ([ 
  			"north" : __DIR__"diyuan",
		]));
        set("objects", ([
                __DIR__"npc/girlfy": 1,
       ]) );
		set("coor/x",-20);
		set("coor/y",110);
		set("coor/z",20);
		setup();
        replace_program(ROOM);
}
