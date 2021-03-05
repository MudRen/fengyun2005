inherit ROOM;
void create()
{
        set("short", "暗道");
        set("long", @LONG
门内是一条暗道，才不过三四尺宽阔。门口的灯光已足够照亮这条还不到两丈
的暗道。暗道尽头是一面墙壁，既没有水火风雾，也没有迷人的天魔女。人门不过
一丈，暗道的地面便已下陷，一直到那面墙壁为止。差不多一丈的地方根本已没有
地面。那之下昏暗一片，昏暗之中浮着迷朦的光影。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"pingfeng",
		"eastdown": __DIR__"andao2",
	]));
        set("item_desc", ([
	
	 ]));
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
