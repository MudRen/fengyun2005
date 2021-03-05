// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山道");
        set("long", @LONG
到了少林门前，左右两座石坊，高大雄伟，似乎讲述着少林兴旺的过去，西北
角一座石桥，前方便是山门殿的殿角，抬头已经可以看见少林寺三个大字在阳光下
跃然生辉。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"shandan",
  "northeast" : __DIR__"dongshi",
  "northwest" : __DIR__"xishi",
  "southdown" : __DIR__"ent2",
]));
/*        set("objects", ([
                __DIR__"npc/monk3" : 1,
       ]) );*/
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}
