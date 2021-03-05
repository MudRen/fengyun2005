// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "飞来石");
        set("long", @LONG
在平坦的山面之上，突然冒出一块石头，似乎除了飞来一说，别的实在难以解
释。石面光滑，上书三字“飞来石”，远看石头，上粗下细，好象摇晃不止，实在令
人匪夷所思。
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"guangming",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-90);
	set("coor/y",-20);
	set("coor/z",30);
	setup();
}

