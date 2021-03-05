// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "鲫鱼背");
        set("long", @LONG
这是一段长约十余丈，宽仅半丈，两侧凌空，下临深渊的石质刃脊，其形状甚
象鲫鱼背。每当山风强劲，站在这上面你都有会被风刮走的感觉。前人所谓“天都
欲上路难通”指的就是这一段。
LONG
        );
        set("exits", ([ 
  "northup"  : __DIR__"tiandu",
  "southwest" : __DIR__"tanhai",
  "west" : __DIR__"erxian",

]));
        set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
