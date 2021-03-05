inherit ROOM;
void create()
{
        set("short", "地下石室");
        set("long", @LONG
石门的后面是一个地下石室，差不多有上面的大堂那么宽阔，并不高，才不过
丈许。左右一共十六条石柱，每一条都几乎两人合抱那么粗，柱左右都嵌着莲花般
的石灯。灯是灯，点灯的却不知是什么东西，在莲花灯座之中冒出来的竟是碧绿色
的火焰。整个石室都笼罩在碧绿色的火光之中，所有的东西看起来都是碧绿的颜色。
人也是一样。
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"andao3",
		"south": __DIR__"stoneroom2",
	]));
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",110);
	set("coor/y",-40);
	set("coor/z",-20);
	set("map","taiping");
	setup();
}
