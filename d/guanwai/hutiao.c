inherit ROOM;

void create()
{
      set("short", "虎跳峡");

	set("long", @LONG
北来的冲江河汇入南来的金沙江，在此浩浩荡荡转向东北流，撞进哈巴雪山与
玉龙雪山之间的巨大缝隙中，划开了一道狭长的峡谷，虎跳峡。对岸远处巍峨耸立
的山峰便是玉龙雪山。激流的轰鸣回荡在山谷中，让人觉大地似乎都在颤斗。江水
湍急气浪激荡，令人觉得天地间一片雾气空朦，又是心惊胆颤又是豪情万丈。     
LONG);

         set("exits", ([ 
                "west" : __DIR__"yuema",
                "southeast" : __DIR__"shudao1",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
        ]) ); 
	set("coor/x",380);

	set("coor/y",-490);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
