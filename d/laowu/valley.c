// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "谷地");
        set("long", @LONG
转到这里眼前豁然开朗，不知不觉中你已经爬了很高，身处云雾之中，这里群
峰环绕，然而在这群峰环绕之中有一湖泊，远远望去水呈白色，在这茫茫雾海之中
很难看到，但湖水又怎么可能是白色的呢，你心里充满了疑惑。
LONG
        );
        set("outdoors","laowu");
        set("exits", ([ 
   "west" : __DIR__"tianti2",
   "east" : __DIR__"baishui", 
]));

	set("coor/x",170);
	set("coor/y",190);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
