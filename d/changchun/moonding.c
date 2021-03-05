// searoad.c
inherit ROOM;
void create()
{
        set("short", "观月顶");
        set("long", @LONG
这里是摘星峰观月顶。峰巅一方青石平台，四面围着青玉栏杆，雾气留在山顶，
阳光直射，将这平台映得更是辉煌灿烂。数个青衣少女围坐在栏杆旁，中央是一方
淡黄色的凉席，看来微闪金光，也不知是什么织成。一个青衣妇人斜倚在席上，远
眺着海洋－－极目望去，但见白云悠悠，大海与苍天连接成一片青碧。
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl2" : 1,
        	AREA_TIEFLAG"npc/qinggirl3" : 2,
        	AREA_TIEFLAG"npc/master2"  : 1,
        ]) );
        set("exits", ([ 
	  	"westdown" : __DIR__"uproad4",
        
		]));
		set("valid_startroom",1);
        set("outdoors", "tieflag");
	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",60);
	setup();
	replace_program(ROOM);
}
