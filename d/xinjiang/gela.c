/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "喀拉乌成山");
        set("long", @LONG
天山支脉喀拉乌成山常年冰雪封山，除了当地人之外没有几个人愿意冒险从这
里入天山，去寻找传说中的天山雪莲。相传百年来只有一个人活着从天山中走了出
来，找到了武林奇宝－－天山雪莲。
LONG
        );
        set("exits", ([ 
  			"northeast" : __DIR__"bingchuan",
  			"southwest" :  __DIR__"tianshan",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
