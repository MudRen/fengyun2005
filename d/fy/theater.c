inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"眼波横"NOR);
    set("long", @LONG
水是眼波横，山是眉峰聚。欲问行人去那边，眉眼盈盈处。这短短一阕宋人王
观的卜算子却道出了现如今的风云城的两大名景；“眼波横”说的便是此处这家富
丽堂皇的戏楼；风云城中的人士历来有附庸风雅的喜好，自从金钱帮帮主上官金虹
在此出巨资建了这家戏楼后，全国各地但凡有点名气的戏班名角，无不以在此登台
为荣；名声之盛，甚至传言当今皇上也时常微服来此听戏。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"wcloud1",
	"southup" : __DIR__"theater2",
      ]));
    set("objects", ([
	__DIR__"npc/kid": 2,
      ]) );


    set("outdoors", "fengyun");
    set("coor/x",-80);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

int	valid_leave(object who, string dir)
{
    if (dir == "southup")
	return notify_fail("戏台之上不容寻常人等涉足。\n");
    return ::valid_leave(who,dir);
}


void init()
{
    remove_call_out("greeting");
    call_out("greeting",1);
}

void greeting()
{
    object room/*,me*/;
//  object *olist;
    mixed *local;
//  int i,flag=0;
    local = NATURE_D->getTime(time());
    if (local[1] == 4)
    {
	if (query("create_void") < local[2])
	{
	    room = find_object(__DIR__"theater2");
	    if (!room)
		room = load_object(__DIR__"theater2");
	    present("silencer",room)->do_ggyy();
	    set("create_void",local[2]);
	}
    }
    if (local[1] == 8)
    {
	if (query("create_void2") < local[2])
	{
	    room = find_object(__DIR__"theater2");
	    if (!room)
		room = load_object(__DIR__"theater2");
	    present("sinny",room)->do_ggyy();
	    set("create_void2",local[2]);
	}
    }
    remove_call_out("greeting");
    call_out("greeting",60);
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/