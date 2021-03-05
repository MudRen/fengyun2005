// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "轩辕峰");
        set("long", @LONG
这是黄山后山东的最高峰，因一路怪石嶙峋，加之前面采石峰异常
难行，所以很少人烟。据说这里便是黄帝得道飞升的所在，也不知真假
但是至今留有许多道家遗迹，可见确有人在此修道。南边有一矮峰，上
面居然隐约有一茅庐，似乎有人居住，两峰之间仅有一根铁索。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"caishi",
  "north" : __DIR__"tiesuo",
]));
        set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
