// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "启母石");
        set("long", @LONG
出县城不远，便到启母石，相传夏启的母亲所化，当年大禹治水，开少室，太
室之间的通道，妻子涂山氏来往送饭，一日山石拦路，大禹化做巨熊开山，妻子见
到化做熊的大禹，惊吓过度化为石头，其时身怀六甲，后大禹抚石痛哭，居然石开
而生子启，此石便从此叫做“启母石”，是游嵩山必历的奇景。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"shaoshi",
  "southeast" : AREA_QUICKSAND"dengfeng",
]));
        set("objects", ([
                __DIR__"npc/yumo" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
