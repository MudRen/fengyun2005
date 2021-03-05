inherit ROOM;
void create()
{
	set("short", "琴室");
	set("long", @LONG
未入此房，似乎就能听见阵阵清幽而悦耳的琴声，琴声悠悠扬扬、绵绵密密，
若有若无，似断似续。令人醒忧忘倦。就连杀气再重的人也有一种爱怜的感觉。
LONG
	);
	set("exits", ([
	"east" : __DIR__"qishi",
        "down"    : __DIR__"dating"
	]));

	set("objects", ([
        __DIR__"npc/tong1": 1,
    ]));

	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

