#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "蛰龙沙穴");
	set("long", @LONG
这里是一个地下溶洞，四周黑黑的，隐约可以看见周围怪石密布，地上有一黑
洞，似有一条暗河从中流过，隐约可以听到水声。如此地下深处居然还可以见物，
只因为在角落里，有一点暗红的光芒，蒙蒙照亮了幽幽的沙水洞。
LONG
	);
	set("exits", ([ 
  		"down" : __DIR__"sandriver1",
  		"east" : __DIR__"dongd1",		
	]));
	set("no_fly",1);
	set("objects", ([
	]) );
	set("indoors", "quicksand");
	set("coor/x",-1060);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}


int valid_enter(object me) {
	tell_object(me, HIR"\n你往上一钻，吃惊地发现，这里竟然是一个巨大的空洞。
四周怪石嶙峋，给你一种不祥之感。 \n\n"NOR);
	return 1;
}