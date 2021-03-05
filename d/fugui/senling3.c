inherit ROOM;

void create()
{
	set("short", "松林尽头");

	set("long", @LONG
终于走到了松林尽头，你不禁长长舒了口气，可是愈往前走，四周草木渐稀，
恶石狰狞，路旁依稀可以看见几具小动物的骸骨，一种刺鼻的恶臭几乎让人忍不住
想要呕吐，拨开蔓藤，前方赫然便是个漆黑的山洞，令人眩晕的腥气迎面扑来。
LONG);

	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"south":__DIR__"senling2",
		"north":__DIR__"senling4",
	]) );
        set("objects", ([
		__DIR__"obj/skeleton" : 1,
        ]) );

	set("coor/x",-20);
	set("coor/y",250);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
