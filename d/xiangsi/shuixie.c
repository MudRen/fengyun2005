// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "听风水榭");
        set("long", @LONG
这座小阁楼横架在溪流上，全然是修竹所搭，更不染一点土尘。走进亭中
，但有水声潺潺，竹涛阵阵，习习凉风扑面而来，让人顿忘江湖中红尘里无数
的缠身俗务，便似要乘风归去，烦恼全消，不尽超然。
LONG
        );
	set("objects", ([
		__DIR__"obj/desk" : 1,
		__DIR__"npc/gits" : 1,
	]));
	set("exits",([
  		"west" : __DIR__"qingxi",
	]) );

	set("indoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	me->delete_temp("annie/gits");
	return ::valid_leave(who,dir);
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("bamboo desk", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/yawnbook");
		if(stone)
			stone->move(river);
	}
	return;
}

/*
间关莺语花
底滑,幽咽泉流水下滩。水泉冷涩弦凝绝,凝绝不通声渐歇。
*/