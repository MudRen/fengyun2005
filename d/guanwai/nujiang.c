inherit ROOM;

void create()
{
      set("short", "怒江");

	set("long", @LONG
汹涌的雅鲁藏布江奔流至此，江口突然奇窄，江水怒涛拍岸，轰轰如雷，仿佛
一条蛰伏千年的苍龙终于按奈不住那凌云之志，翻滚着，怒吼着，咆哮着。江边一
群野马自由自在的洒蹄飞奔着。
LONG);

         set("exits", ([ 
        "northwest" : __DIR__"tearoad2",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
                __DIR__"npc/yema" : 1,
        ]) ); 
	set("coor/x",240);
	set("coor/y",-190);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
