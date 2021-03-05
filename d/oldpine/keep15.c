// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
        set("short", "山寨外围");
        set("long", @LONG
此是泰山中极东之所，成年山雾缭绕，烟霞弥漫，怪石，密林，层峦叠嶂，实
在是易守难攻之地，千百年来有无数绿林好汉占山为王，无数豪杰男儿揭竿而起，
地势险要可见一斑，至今仍可见当年山寨模样。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
 	 "west" : __DIR__"keep1",
  	"east" : __DIR__"keep2",
]));
        set("objects", ([ /* sizeof() == 1 */
  		__DIR__"npc/bandit_guard" : 4,
	]));
        
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
