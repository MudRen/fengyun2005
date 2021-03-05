inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "小饭馆");
        set("long", @LONG
虽然这是边远的一个小镇，可是倒有百几十户人家，简陋的客栈和小饭馆也有
好几家，看样子是准备那些来不及连夜赶路的旅人食宿之所。阴暗的光线，招牌油
腻得连店名也分不出，唯有阵阵的菜香在向过路的人招手。
LONG
        );
        set("exits", ([ 
	"south": __DIR__"road4",
	]));
        set("objects", ([
        	__DIR__"npc/bossding":	1,
	]) );
	set("coor/x",-30);
        set("coor/y",10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

void reset(){
	if (present("qingzhu she",this_object()))	return;
	::reset();
}	