inherit ROOM;
void create()
{
        set("short", "偏厅");
        set("long", @LONG
偏厅设一对梅花式洋漆小几。左边几上文王鼎匙箸香盒，右边几上汝窑美人觚，
觚内插着时鲜花卉，并茗碗痰盒等物。地下面西一溜四张椅上，都搭着银红撒花椅
搭。椅之两边，也有一对高几，几上茗碗瓶花俱备。
LONG
        );
        set("exits", ([ 
		"north": __DIR__"redhouse0",
	]));
        set("item_desc", ([
	
	 ]));
        set("objects", ([
        	__DIR__"npc/maid":	1,
        ]));
	set("coor/x",-80);
	set("coor/y",-60);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
