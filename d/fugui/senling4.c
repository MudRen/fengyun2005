inherit ROOM;

void create()
{
	set("short", "山路");

	set("long", @LONG
这是条崎岖的山路，路旁杂草不生，生迹罕见，恶石狰狞，路旁依稀可以看见
几具小动物的骸骨，一种刺鼻的恶臭几乎让人忍不住想要呕吐，拨开蔓藤，前方赫
然便是个漆黑的山洞，令人几乎眩晕的腥气迎面扑来。
LONG);

	set("outdoors", "fugui");
	set("type","mountain");
	set("exits",([
		"south":__DIR__"senling3",
		"northeast":__DIR__"dongkou",
	]) );

	set("coor/x",-20);
	set("coor/y",260);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
