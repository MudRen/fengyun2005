#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "沙穴洞底");
	set("long", @LONG
这里是一个地下溶洞，四周黑黑的，隐约可以看见周围怪石密布，地上有一黑
洞，似有一条暗河从中流过，隐约可以听到水声。
LONG
	);
	set("exits", ([ 
  		"west" : __DIR__"shaxue",
		"eastup" : __DIR__"dongd2",
	]));

	set("indoors", "quicksand");

	set("coor/x",-1040);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}
