inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"戏台上"NOR);
    set("long", @LONG
水是眼波横，山是眉峰聚。欲问行人去那边，眉眼盈盈处。这短短一阕宋人王
观的卜算子却道出了现如今的风云城的两大名景；“眼波横”说的便是此处这家富
丽堂皇的戏楼；风云城中的人士历来有附庸风雅的喜好，自从金钱帮帮主上官金虹
在此出巨资建了这家戏楼后，全国各地但凡有点名气的戏班名角，无不以在此登台
为荣；名声之盛，甚至传言当今皇上也时常微服来此听戏。
LONG
    );
    set("objects", ([
	__DIR__"npc/singgirl": 1,
	__DIR__"npc/singgirl2": 1,
      ]) );


    set("outdoors", "fengyun");
    set("no_fight", 1);
    set("coor/x",-80);
    set("coor/y",-30);
    set("coor/z",10);
    setup();
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
