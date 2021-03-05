inherit ROOM;
void create()
{
        set("short", "暗道");
        set("long", @LONG
脚下，是一列石级，二三十级石级斜斜地伸展下去，门外见到的迷朦光影正是
从下面透上来的。灯光中，整条通道闪耀着异样的寒芒，令人窒息和胆颤。这莫非
也是某种邪恶与不祥的象征？
LONG
        );
        set("exits", ([ 
		"westup":  __DIR__"andao1",
		"eastdown":  __DIR__"andao3",
	]));
        set("item_desc", ([
	
	 ]));
	set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",-10);
	set("map","taiping");
	setup();
}
