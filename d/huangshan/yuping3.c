// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "玉屏楼二楼");
        set("long", @LONG
清凉的山风吹来，让人精神一振。楼下石榴树的枝叶紧临长廊，探手可触。站
在此处东观天都，从山顶直落山脚，近乎垂直，西看莲花，恰似“突兀撑青穹”的
盛开莲花。玉屏峰地处三大主峰中心，集黄山奇景大成。
LONG
        );
    set("exits", ([ 
  		"down" : __DIR__"yuping2",
	]));

    set("indoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",60);
            set("objects", ([
	__DIR__"npc/taihuwang" : 1,
                        ]) );
    
    
	setup();
        replace_program(ROOM);
}
