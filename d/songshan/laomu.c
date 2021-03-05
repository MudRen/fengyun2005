// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "老母洞");
        set("long", @LONG
从崇福宫到这，山路蜿蜒，到此两边山岩夹道，宛若行走洞中，故人称老母洞，
相传是一古代少年为救被怪兽夺走的母亲，力劈山石，路从中崩，引出了这么一个
险峻所在，打此向上攀行，便是峻极峰了。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"junji", 
  "south" : __DIR__"chongfu",
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"npc/zihe" : 1,
       ]) );
	set("coor/x",15);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
