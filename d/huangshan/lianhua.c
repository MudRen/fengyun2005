#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "莲花峰");
        set("long", @LONG
黄山第一高峰。它超然鹤立，群峰簇拥，象一多初绽莲花，仰天怒放，融雄伟
俏丽于一体，是当之无愧的“菡萏金芙蓉”。峰上景色皆以莲花为名，如莲花沟，莲
花梗等。每逢天气晴朗，东望天目，西瞻匡庐，北眺九华，南临诸峰，视野极为开
阔。西去便是后山。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"yuping",
  		"westdown" : __DIR__"guangming",
	]));
        set("outdoors", "huangshan");
	set("coor/x",-80);
	set("coor/y",-10);
	set("coor/z",40);
	setup();

}
