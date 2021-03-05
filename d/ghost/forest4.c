
inherit ROOM;

void create()
{
	set("short", "原始丛林");
	set("long", @LONG
无边无际的丛林中一片黑暗，就是再烈的日光也穿不透那密密的树叶，黑暗中
充满了各式各样的危险，每一种都可以致命。落叶是湿的，泥土也是湿的。林子中
间一个人倒在落叶湿泥中，全身都已因痛苦而扭曲。
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest6",
		"south" : __DIR__"forest2",
		"east" : __DIR__"forest3",
		"west" : __DIR__"forest1",
	]));
	set("objects", ([
		__DIR__"npc/gudumei" : 1,
	]));
	set("outdoors", "ghost");
	set("no_lu_letter",1);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void init(){
	add_action("do_go","go");
}

int do_go(string dir){
	object who = this_player();
	
	if (dir == "east" && userp(who) && who->query_temp("marks/gudumei_route")){
		who->move(__DIR__"forest_c");
		return 1;
	}
	
	return 0;
}
