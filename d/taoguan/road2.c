
inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
站在这阶梯的起点, 纯白色宽敞的石英岩蜿蜒而上, 在青翠的山色中仿佛一条
纯白色的巨龙。抬头仰望山峦深处的那座庙宇, 虽然无情的岁月已经在它身上留下
痕迹, 但仍不失其庄严神圣的气象。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"putian",
  		"northup" : __DIR__"road3",
  		"southdown" : __DIR__"road1",
]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
