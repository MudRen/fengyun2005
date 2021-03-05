#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "树洞中");
        set("long", @LONG
黑漆漆的树洞中散发着一股药味，地上的积叶有半尺来厚，踩上去发出沙沙的
声响，仔细看去，周围偶尔会有磷火，不知道是什么动物的骨头。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"up" : __DIR__"groupn2",

]));
        set("outdoors", "manglin");
		set("coor/x",60);
		set("coor/y",-50);
		set("coor/z",0);
		set("no_fly", 1);
		set("max_lv",45);	
		setup();

}




int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"groupn2");
	if (!exitroom)
		exitroom = load_object(__DIR__"groupn2");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"树洞里又臭又黑，你觉得进去太失身分了。\n"NOR);
	}
}







