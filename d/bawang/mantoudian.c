#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "老山东馒头店");

	set("long", @LONG
		“老山东，大馒头。” 
山脚下是家“老山东馒头店”，这馒头店的资格已很老，外面的招牌，里面的桌椅
都已被烟熏得发黑了。店里的老板、跑堂、厨子，都是同一个人，这个人没有什么
特别，大家都把他叫做老山东。
LONG);

	set("type","street");
	set("exits",([
        "west":"/d/wudang/xzroad4",
	]) );
	set("objects", ([
		__DIR__"npc/oldshan": 1,
	]));
	set("coor/x",-30);
	set("coor/y",120);
	set("coor/z",-70);

	set("indoors", "bawang");
	setup();
	replace_program(ROOM);
}
