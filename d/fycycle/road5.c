inherit ROOM;
void create()
{
        set("short", "无名小镇南");
        set("long", @LONG
小路到了这里忽然分为两条，一条沿护城河伸向东南，而靠北面的一条则通往
一个无名的小镇。与繁荣的风云城相比，那个小镇显得破落冷清。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north":"/d/libie/stoneroad3",
  "west" : __DIR__"road4",
  "southeast" : __DIR__"road6",
]));
        set("outdoors", "fengyun");
 
	set("coor/x",200);
	set("coor/y",320);
	set("coor/z",0);
	setup();
}
