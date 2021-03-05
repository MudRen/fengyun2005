
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
穿过一扇挂著蓝布帘的小门，是一间小得不能再小的厨房。左面靠墙放著一个
大水缸和几只酒坛。右面则是一个大炉子，火烧得正旺。一个老妇人挤在中间正在
做饭。 
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xzhouse1",
	]));
        set("objects", ([
                __DIR__"npc/oldwoman" : 1,
        ]) );
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}
