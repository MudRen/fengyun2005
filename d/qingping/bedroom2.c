inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
此处是魏不贪等人的住处，因为魏不贪生性爱财，所以屋中绝无装饰，钱全被
魏不贪嬴去存了起来。屋中墙上一柄长剑，上书一个忍字，正是石不为的爱物。石
不为行事阴沉，近来更是反常，不知道所为何事。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"road2",
]));

	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
