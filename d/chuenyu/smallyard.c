
inherit ROOM;

void create()
{
        set("short", "翠绿的小草坪");
        set("long", @LONG
小草坪修剪的很整齐，正值初春，翠绿的草苗儿争先恐后地钻出地面，走近了，
扑鼻的便是清香和吱吱哑哑虫儿们的欢叫声，这儿是各种小生命的天堂，也是附近
孩子们最喜爱的戏耍之地。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"home",
  "south" : __DIR__"dustyroad3",
]));
        set("objects", ([
                __DIR__"npc/frog" : 2,
		__DIR__"npc/ant"  : 2,
		__DIR__"npc/fly"  : 2,
        ]) );
        set("outdoors", "chuenyu");
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",-20);
	setup();
}

