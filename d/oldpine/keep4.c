#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "老云寨长廊");
        set("long", @LONG
一条长长的走廊自大厅延伸过来，长廊两侧的土壁上每隔几步就插着一根燃烧
的火把。再向南行去即是一处转折，转折后或许埋伏着山贼土匪，还是要小心提防
为上。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"keep3",
                "east" : __DIR__"keep5",
        ]));
        set("coor/x",80);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
	set("no_fly", 1);
	set("max_lv",25);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"keep3");
	if (!exitroom)
		exitroom = load_object(__DIR__"keep3");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"富有江湖历练的你暗自沉思：若贸然行事，误中埋伏，反而不妙。\n既然常老大就在这里，也没有必要冒险多事。\n"NOR);
	}
}

