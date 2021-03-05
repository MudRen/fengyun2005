
inherit ROOM;

void create()
{
        set("short", "日朝园");
        set("long", @LONG
帝王谷的另一侧是一座典雅的花园，看门，只见正门五间，上面筒瓦泥鳅脊，
那门栏窗阁俱是细雕花样，并无朱粉涂饰，一色水磨群墙，白石台阶，凿成西番莲
花样，左右雪白粉墙，下面虎皮石砌成纹理。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"palace_front",
  		"southeast" : __DIR__"entrance",
]));
        set("outdoors", "palace");

	set("coor/x",-120);
	set("coor/y",110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

