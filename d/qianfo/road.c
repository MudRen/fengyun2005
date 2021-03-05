// road.c
// QC'ed by Tie@fy2
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这里靠近佛教名山千佛洞，又是往来山上山下的必经之路。在路边有一片小小
树林，一张石桌，几张石凳。一个小贩在大声叫卖，生意颇为兴隆。（如果要小贩
的树叶需给１０两白银）
LONG
        );
        set("exits", ([ 
  		"eastup" : __DIR__"road0",
  		"west" : AREA_JINAN"tanghuai",
	]));
        set("objects", ([
               AREA_TIEFLAG"npc/xiaofan" : 1, 
        ]) );
        set("outdoors", "qianfo");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
