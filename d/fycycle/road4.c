inherit ROOM;
void create()
{
        set("short", "城北小路");
        set("long", @LONG
弯弯曲曲的小路向东西方向延伸。路的旁边是风云城的护城河，河的另外一边
就是高大的风云城城墙了。从这里可以看到城墙上值勤的士兵在站岗。河堤上长满
了绿草。微风拂来，一股的泥土的气息。从西边隐隐约约传来车马喧嚣的声音。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */

  "west" : __DIR__"fynorth",
  "east" : __DIR__"road5",
]));
        set("outdoors", "fengyun");

	set("coor/x",100);
	set("coor/y",320);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
