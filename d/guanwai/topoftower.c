inherit ROOM;

void create()
{
        set("short", "塔顶");
        set("long", @LONG
这里异常窄小，使人无法移动。但从这里看出去，那些布满在山头上的楼阁、
禅房、寺院、那高耸在岩石上的巨人城堡，看起来仍然是那么瑰丽，那么调和。
LONG
        );

        set("exits", ([ 
		"down"   : __DIR__"citygate",
	]));
        set("objects", ([
                __DIR__"npc/towerguard1" : 2,
		__DIR__"npc/biglama" :1,
        ]) );
	set("coor/x",45);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}