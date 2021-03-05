// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "灵阙潭");
        set("long", @LONG
乳白色的薄雾笼罩着这里，潭边的草木长得分外茂密。一湾幽碧的潭水，
如一枚清澈而深邃的绿色水晶，镶嵌在青翠欲滴的草木丛中。远山上传来几声
细碎的鸟鸣，一切都那么和谐，构筑成一片绿色的宁静。
LONG
        );
	set("objects", ([
		__DIR__"npc/jiang" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"shuangtian",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}



int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"shuangtian");
	if (!exitroom)
		exitroom = load_object(__DIR__"shuangtian");
	if (userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"欸，偷看人家女孩子洗澡像什么话？\n"NOR);
	}
}
