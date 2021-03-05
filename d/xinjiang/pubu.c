/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "瀑布");
        set("long", @LONG
这里是沟的尽头，数十丈高的悬崖就象是被人一刀砍出来的。一丈多宽的瀑布
一泻而下，在阳光下就象是闪着银光的绸缎，颇为壮观。瀑布以一泄千里之势击入
湖中，隆隆之声不绝于耳。
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"goudi2",
  		"eastup" : __DIR__"aiding",
	]));
        set("objects", ([
        	__DIR__"npc/serpent" : 1,
                        ]) );
		
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","清凉的水");
        set("liquid/container", "闪着银光的瀑布");
	set("coor/x",40);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
