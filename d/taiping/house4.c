#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "猎人居");
        set("long", @LONG
墙上一排挂着几张野獾，山狼，狐狸等的皮毛，旁边是一张黄杨树削成的长弓，
这里的主人是远近闻名的张猎户。张猎户三代打猎为生，一手百步穿杨的绝技让武
三爷都动了心，几次派人来请他去做武师，但每次都被张猎户婉言谢绝，他爱的只
是山，只是林子，和林子的野兽。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"sroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("objects", ([
	        __DIR__"npc/hunter": 1,
	]));
	set("coor/x",-50);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
