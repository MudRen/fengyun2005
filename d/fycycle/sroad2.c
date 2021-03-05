inherit ROOM;
void create()
{
        set("short", "城西小路");
        set("long", @LONG
一条小路弯弯曲曲向南延伸。路的旁边是风云城的护城河，河的另外一边就是
高大的风云城城墙了。从这里可以看到城墙上值勤的士兵在站岗。河堤上长满了绿
草。微风拂来，一股的泥土的芳香。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"sroad1",
  "southeast": __DIR__"sroad3",
]));
        set("outdoors", "fengyun");
         

	set("coor/x",-200);
	set("coor/y",-200);
	set("coor/z",0);
	setup();
}

