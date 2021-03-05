
inherit ROOM;

void create()
{
        set("short", "闹市");
        set("long", @LONG
市镇在冰上，在辉煌的灯火间，屋里的灯火和冰上的灯火交相辉映，一盏灯变
成两盏灯，两盏灯变成四盏灯，如满天星光闪烁，就算是京城里最热闹的街道也比
不上。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"street",
  "northwest" : __DIR__"downtownx",
  "southeast" : __DIR__"daroad",
]));
        set("outdoors", "laowu");
        set("objects", ([
        	"/obj/npc/beggar" : 2,
        __DIR__"npc/farmer" : 2,
        __DIR__"npc/drunk" : 2,
        	"/obj/npc/scavenger" : 2,
                        ]) );


	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

