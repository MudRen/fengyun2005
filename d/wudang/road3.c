
inherit ROOM;

void create()
{
	set("short", "上山路");
	set("long", @LONG
弯弯曲曲的泥土路，却很平坦。左右两边都是茂盛的松林，雨过天晴时，泥土
的香气和松树的芬芳混在一起，能使人心胸开朗，忘记一切烦恼。在这里，从松林
的缝隙间可见到武当观的红色围墙。
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"rock",
		"southup" : __DIR__"wudang",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
