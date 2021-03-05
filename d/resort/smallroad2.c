
inherit ROOM;

void create()
{
        set("short", "羊肠小道");
        set("long", @LONG
大昭寺的北面是恰克卜里山，一条山间小路弯弯曲曲地向山顶延伸，道旁的茅
草高达五尺，遮住了天光，山幽中的一切都显的阴森幽暗，偶尔传来几声野兽的啸
叫。除了砍柴的樵夫，这儿很少有人涉足。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad",
  "north" : __DIR__"smallroad3",
]));
        set("outdoors", "resort");

	set("coor/x",40);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

