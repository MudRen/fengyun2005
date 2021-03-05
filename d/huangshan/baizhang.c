// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "百丈泉");
        set("long", @LONG
黄山三大名瀑之一，因飞流直下而得名，由观瀑亭远看极为壮观。到此近观，
只见峭壁如刀削，寸草不生，瀑布尤如一条白色的丝绦从上落下，撞击在青石上，
但见飞珠溅玉，水声轰鸣，一股清凉之气扑面而来，别有一番妩媚风情。
LONG
        );
	set("exits", ([ 
		"south" : __DIR__"qingluan",
  		"northwest" : __DIR__"mroad1",
	]));
    set("objects", ([
        __DIR__"npc/shui" : 1,
    ]) );
	set("resources/water",1);
    set("outdoors", "huangshan");
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",10);
	setup();
    replace_program(ROOM);
}
