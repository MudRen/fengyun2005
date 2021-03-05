// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "人字瀑");
        set("long", @LONG
山路一转，眼前出现一个小山坳，四周草木茂盛，耳边不时传来虫叫蛙鸣声，
一条小溪缓缓从你身边流过。抬头向前看，一道瀑布从山峰落下，由于倾泄到半山
之时，忽有巨石从山中斜插而出，所以半途一分为二，形成一个人字，宛若两条飞
舞的玉龙，分道扬镳，直落崖下。
LONG
        );
  	set("exits", ([ 
 		"north" : __DIR__"qingluan",
		"westup" : __DIR__"chayuan",
	]));
        set("objects", ([
                __DIR__"npc/xiangke" : 3,
       ]) );
	set("resource/water",1);
	set("liquid/name","人字瀑水");
    set("outdoors", "huangshan");
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
