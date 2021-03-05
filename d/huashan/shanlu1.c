// annie. 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "断崖");
        set("long", @LONG
峰回路转，一片断崖立于眼前，四周林木茂密，一片翠绿。断崖不高，崖壁之
上盘藤交错，密不透风，一道水流如银线玉丝从崖上飘落，水花飞溅在古藤绿叶之
上，在阳光的照耀下闪闪发光，犹如夜空下的星辰。
LONG
        );
    set("exits", ([ 
  		"eastup" : __DIR__"yanluo",
        "northwest" : __DIR__"shanlu2",
	]));
	set("objects", ([
		__DIR__"obj/vine1" : 1, 
		__DIR__"npc/xian": 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",-55);
	set("coor/y",-60);
	set("coor/z",36);
	setup();
}

void init()
{
	object me;
	me = this_player();
	add_action("do_open", ({ "open","push","pull" }));
	if (REWARD_D->check_m_success(me,"听琴毛女洞") 
		&& REWARD_D->riddle_check(me,"绝世芳华") == 3 
		&& !random(10))
	{
		tell_object(me,HIG"\n方踏进断崖，你就嗅到一种与闻香瓶中的气味仿佛的淡淡幽香。\n\n"NOR);
		REWARD_D->riddle_set(me,"绝世芳华",4);
	}
}

int do_open(string arg)
{
	object me;
	me = this_player();
	if(arg != "古藤" && arg != "vine" && arg!="盘藤")
		return 0;
	if (me->is_fighting() || me->is_busy())
		return notify_fail("你现在正忙。\n");
			
	if (REWARD_D->riddle_check(me,"绝世芳华") != 4 )
		return notify_fail("你掀开古藤，却什么都没有发现。\n");
	message_vision("$N掀开古藤，钻进了崖壁中的一个漆黑小洞。\n",me);
	me->move(load_object("/d/huashan/hole"));
	tell_object(me,"你在洞中行了片刻，惊讶的发现山腹里竟别有洞天。\n");
	message("vision","$N走了过来",environment(me),me);
	return 1;
}

