inherit ROOM;

void create()
{
	set("short", "云雾石径");

	set("long", @LONG
山中云雾缭绕，小路蜿蜒而上，一丛丛不知名的小花在山风中摇曳，正值花落
时节，斜斜的石径上落花缤纷。踏着落花，“沙沙”之声在寂静的山谷中似乎格外
清晰，风中也充满了干燥木叶和百花的芬芳，青天下远山如翠。
LONG);

	set("type","road");
	set("exits",([
        "southup":__DIR__"fogpath3",
		"northwest":__DIR__"pubyard",
	]) );
       set("outdoors", "wolfmount");
        set("objects", ([
                __DIR__"obj/dropflower" : 1,
       ]) );
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);

	setup();
	replace_program(ROOM);
}
