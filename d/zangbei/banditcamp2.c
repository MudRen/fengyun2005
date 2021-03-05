inherit ROOM;

void create()
{
        set("short", "马圈");
        set("long", @LONG
营地旁用木条围起一个大圈，圈里养了十多匹马，这马也跟人一样，匹匹瘦骨
嶙峋，有气无力，显然是缺少饲料的缘故，看来在这无人烟的荒原上，做强盗也不
是一件容易的行当。
LONG
        );
        set("exits", ([ 
	  	"southeast" : __DIR__"banditcamp1",
	  	"west" : __DIR__"banditcamp3",
			]));
	set("objects", ([

	]));
	set("outdoors", "zangbei");

        set("coor/x",-450);
	set("coor/y",620);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

