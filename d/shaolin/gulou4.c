// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object ob,con;
        set("short", "击鼓楼");
        set("long", @LONG
一间亭子似的建筑，中间一张牛皮巨鼓，相传是印度神牛皮制成，几个僧人守
在鼓旁，按时击鼓，一般都是暮鼓晨钟，日落时分你便可以听到这悠扬的鼓声。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"gulou3",
]));
        set("objects", ([
                __DIR__"npc/monk5" : 1,
                __DIR__"npc/monk51" : 1,
                __DIR__"npc/monk52" : 1,
                __DIR__"npc/monk53" : 1,			
       ]) );
	set("coor/x",-10);
	set("coor/y",-60);
	set("coor/z",20);
	set("outdoors","shaolin");
	setup();
	con = new(__DIR__"obj/gu");
	con->move(this_object());
}


void init(){
	add_action("do_get","get");
}


int do_get(string arg){
	
	object monk, me;
	
	monk = present("shaolin monk");
	if (!monk)	return 0;
	if (!arg)	return 0;
			
	if (arg[0..1] == "gu" || arg == "all"){
		monk->ccommand("stare");
		return 1;
	}
	
	return 0;
}
			