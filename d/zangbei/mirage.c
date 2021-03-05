#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", WHT"小屋"NOR);
        set("long", @LONG
漫天的黄沙中，这座小屋突然如蜃影般出现。小屋是白色的，白色的外墙、白
色的门窗、白色的檐瓦，竟然不染尘沙。屋外有一个穿著飘舞白纱，俨然飞天仙女
般的绝色女子，檐下挂著的一串小小的风铃在灼热的焚风中轻摇作响，清脆的铃声
将你的思绪带回了初春暮雨的江南．．．
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"desert_ambush",
		]));
	set("objects", ([
		
	]));
	set("outdoors", "zangbei");
        set("coor/x",-90);
	set("coor/y",280);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",50);	
}


int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"desert_cabin");
	if (!exitroom)
		exitroom = load_object(__DIR__"desert_cabin");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,YEL"你走近小屋，眼前忽然一花，那座白色的房子和屋前白色的人影瞬间消失，\n错落的是几间破败的木屋，莫非刚才所见的一切都只不过是海市蜃楼而已？\n"NOR);
	}
}

