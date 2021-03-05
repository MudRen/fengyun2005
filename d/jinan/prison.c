inherit ROOM;
void create()
{
        set("short", "天牢");
        set("long", @LONG
这里便是衙门中令人心惊胆战的天字号牢房，约莫两丈见方的一间大石屋，
墙壁都是一块块粗糙的大石所砌，地下也是大石块铺成，已经很多年没有清扫，
所以地上遍地尽是碎草屑，泥垢，污水。墙角一头放着一只粪桶，鼻中闻到的
尽是臭气和霉气。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"andao2",
]));
        set("objects", ([
        __DIR__"npc/jin9" : 1,
                        ]) );

	set("coor/x",70);
	set("coor/y",10);
	set("coor/z",-10);
	set("jinan_prison",1);
	set("no_fly",1);
	setup();
        
}
