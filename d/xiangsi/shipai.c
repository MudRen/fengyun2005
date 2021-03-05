// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "石牌峰");
        set("long", @LONG
爬上山来，眼前却又是另一番景致。丛生的榕树林边是一块飞于崖外的偌
大山岩，岩面被人打磨得如镜面般光滑，铭着两行朱红的文字。树林一条若隐
若现的草径向山顶延去，空气中漂浮着淡淡的木叶清香，榕须随着微风轻轻摇
晃，不时拂拭过你的脸庞。
LONG
        );
	set("objects", ([
		__DIR__"obj/rock4" : 1,
	]));
	set("exits",([
  		"northdown" : __DIR__"xiangsi",
  		"southup" : __DIR__"haoyue",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
    replace_program(ROOM);
}
