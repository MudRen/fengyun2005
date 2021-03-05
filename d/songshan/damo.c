// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "达摩洞");
        set("long", @LONG
蜿蜒的山间小路，伴随着路边摇曳的竹影，就到了五乳峰的达摩洞，洞口朝向
西南，洞外有明建石坊，正面额题“默玄处”，相传禅宗初祖达摩在此面壁九年而
成正果，现在为少林圣地，由少林僧兵之佼佼者把守此地。若再往上行片刻，便是
五乳峰顶。
LONG
        );
	set("exits", ([ 
		"southeast" : __DIR__"talin",
		"westup" : __DIR__"wuru",
		"enter" : __DIR__"damocave",
	]));
	set("objects", ([
		__DIR__"npc/guardmonk" : 2,
	]));
	set("coor/x",64);
	set("coor/y",26);
	set("coor/z",0);
	setup();

}

int valid_leave(object obj, string dir){
	object monk;
	if(dir == "enter" && monk = present("guard monk", this_object())){
		if(obj->query("class") != "shaolin") {
			message_vision("$N横棍道：“此乃少林弟子面壁之所，请留步。”\n", monk);
			return notify_fail("");
		}
	}
	return 1;
}
