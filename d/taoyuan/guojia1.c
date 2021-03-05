inherit __DIR__"no_killing_place";
void create()
{
	set("short", "内宅");
	set("long", @LONG
农舍虽为破旧却收拾得十分干净整齐，门外的土墙上悬挂着金黄色的玉米，还
有几瓣大蒜。屋内有两张土炕，上面被褥齐全，东面炕上放了一张小几。墙根处放
几个瓦缸，里面似乎装有粮食。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
   		"east" : __DIR__"guojia",
   	]) );

	set("item_desc", ([
	"table": "小几上放了一个小盆，里面装着各式各样的豆类。\n",
	"小几": "小几上放了一个小盆，里面装着各式各样的豆类。\n",
	]) );

	set("objects", ([
		__DIR__"npc/guo": 1,
	]) );
	

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void init()
{
	::init();
	add_action("do_get", "get");
}																				
								
int do_get(string arg)
{
	if(!arg || arg != "豆类" && arg != "beans" && arg != "豆") return 0;
}
									
