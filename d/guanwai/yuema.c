inherit ROOM;

void create()
{
      set("short", "跃马峡");

	set("long", @LONG
一路而来，雅鲁藏布江咆哮汹涌，该名藏语意为“高山流下的雪水”，宛如一
条银色的巨龙，由西向东奔腾在青藏高原的南部。一路形成了宽阔的河谷，流到藏
滇的交界处，被喜马拉雅山东段最高峰南迦巴瓦峰挡住去路而被迫改向，形成了险
绝天下的的“马蹄形”大拐弯峡谷，藏人称为“跃马峡”。悬崖直落江面，那一线
江水就象嵌在巨斧劈开的石缝里，急流奔腾，声震山峡。
LONG);

         set("exits", ([ 
                "east" : __DIR__"hutiao",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
        ]) ); 
	set("coor/x",350);
	set("coor/y",-490);
	set("coor/z",0);
	set("objects", ([
                __DIR__"npc/yema2" : 1,
       ]) );

	setup();
	replace_program(ROOM);
}
