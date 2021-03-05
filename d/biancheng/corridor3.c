#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;
void create()

{
        set("short", "楼道");
        set("long", @LONG
走过楼道往前就是马空群的卧室，向北向南各有一间，这儿一年三百六十五天，
一天二十四小时有人当值。能在这儿守卫的，不是马空群的嫡传弟子，就是跟随他
出生入死多年的侍卫，除了总管公孙断，就连副堂主花满天也要通报了才能上楼。
LONG
        );
        set("exits", ([ 
	"down": __DIR__"pianting2",
	"north": __DIR__"uproom1",
	"east": __DIR__"uproom2",
	]));
        set("objects", ([
        	__DIR__"npc/vguard4":	1,
	]) );
        set("coor/x",-15);
        set("coor/y",130);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	create_door("north","door","木门","south",DOOR_CLOSED);
}
