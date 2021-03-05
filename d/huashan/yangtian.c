
inherit ROOM;

void create()
{
        set("short", "仰天池");
        set("long", @LONG
仰天池在华山南峰绝顶，池为岩石上一天然石凹，呈不规则形，水深约一米，
水色清澈，略带绿色。池水涝不盈溢，旱不耗竭，令人叹为奇异。站在池边，仰首
望晴天似近在咫尺，触手可及。
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"yanluo",
	]));
	set("objects", ([
		__DIR__"npc/yu": 1,
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-45);
	set("coor/y",-58);
	set("coor/z",40);
	setup();
    replace_program(ROOM);
}

