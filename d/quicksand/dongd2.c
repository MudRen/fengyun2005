#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "沙穴洞底");
	set("long", @LONG
这里是一个地下溶洞，四周黑黑的，隐约可以看见周围怪石密布，脚下是柔软
的沙子，路似乎越走越窄，空间也越来越小，沉闷的空气没有一丝流动，让人感觉
分外的压抑。
LONG
	);
	set("exits", ([ 
  		"westdown" : __DIR__"dongd1",
	    "southup" : __DIR__"dongd3",
	]));

	set("indoors", "quicksand");

	set("coor/x",-1020);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}
