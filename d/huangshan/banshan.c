// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小寺庙");
        set("long", @LONG
一座小小的寺庙倚山势而建，寺庙外古柏遮天，鲜有人迹，寺庙大门紧闭，四
周寂静无声，从寺里传出的晨钟暮鼓的声音可以传出很远很远。站在寺庙门口向四
周观望，只见山奇水秀，好似一巨幅山水画。
LONG
        );
    set("exits", ([ 
 		"southdown" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));    

    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
