inherit ROOM;

void create()
{
        set("short", "木屋");
        set("long", @LONG
木屋里宽大空阔，中壁的木板却已很陈旧，有的甚至已干裂，无疑是栋多年的
老屋。屋里只有一张低矮的木桌和一个巨大的火盆。
LONG
        );
     
        set("exits", ([ 
		"west" : __DIR__"wallhole",
	]));
        set("objects", ([
                __DIR__"npc/yansong" : 1,
        ]) );

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}