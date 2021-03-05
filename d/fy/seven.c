#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"小吃摊"NOR);
    set("long", @LONG
几张破破烂烂的桌椅，一盏摇摇晃晃的孤灯，卖面的一对夫妇虽然不过中年，
却已经满脸是被生活所累的皱纹。阵阵瑟人的寒风掠过，你的心变得更冷，忍不住
想要坐下，来一碗热腾腾的面食。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"lssquare1",
      ]));
    set("no_fly",1);	// no,dont fly here.
    set("outdoors", "fengyun");
    set("objects", ([
	__DIR__"npc/seller1": 1,
	__DIR__"npc/seller2": 1,
	__DIR__"npc/ass1": 1,
	__DIR__"npc/ass2": 1,
	__DIR__"npc/ass3": 1,
      ]) );

    set("coor/x",110);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}




int	valid_leave(object who, string dir)
{
    if (!present("spiced beef",who) && !present("stewed pork",who) && !present("pork noodles",who) && !present("pork noodles",who))
	return ::valid_leave(who,dir);

    write("还是先把东西吃光再走吧。\n");
    return notify_fail("");
}


// 凝輕·dancing_faery@hotmail.com

