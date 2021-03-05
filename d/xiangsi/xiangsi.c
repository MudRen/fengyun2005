// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "相思岭");
        set("long", @LONG
爬到这里，道路在万仞悬崖前陡而中断，眼前的景色豁然开朗，放眼望去
，悬崖下是碧波千顷，涛声雷鸣。站在崖边，凉爽而微腥的海风扑面而过，你
顿觉神气清爽，灵智开明。右边是高耸的山壁，左边不远的低处有个小小池塘
，不妨过去捧些清水，稍作休息。
LONG
        );
	set("objects", ([
		__DIR__"npc/weeds" : 2,
		__DIR__"obj/vine" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"ninglu",
  		"west" : __DIR__"leidashi",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}
