
inherit ROOM;
void create()
{
        set("short", "荒凉小径");
        set("long", @LONG
白色幔帐前是一条小路，曲曲弯弯的小路上生满了杂草，似乎已久未有人从这
里走动，小路两旁是苍劲的巨柏古松，四周奇石林立，蔓草横生，只有不时跳来跳
去的小松鼠打破这里的寂静。
LONG
        );
    set("exits", ([ 
		"east" : __DIR__"hpath2",
	]));
 	set("item_desc", ([
 		"白色幔帐" : "白色幔帐的一角似乎没有绑紧，你也许可以掀开（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",	
		"幔帐" : "白色幔帐的一角似乎没有绑紧，你也许可以掀开（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",
 		"curtain" : "白色幔帐的一角似乎没有绑紧，你也许可以掀开（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",
 	]) );  
    	set("objects", ([
    		__DIR__"obj/stone2" : 1,
    		"/obj/animal/songshu" : 2,
    	]));
    	set("outdoors", "huashan");
	set("coor/x",-9);
	set("coor/y",15);
	set("coor/z",-10);

	setup();
}

void init(){
	add_action("do_open", "open");
}

int do_open(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "幔帐" && arg != "白色幔帐" && arg != "curtain")) {
		return 0;
	}
	if( !query("exits/west") ) {
		room = find_object(__DIR__"path1");
		if(!objectp(room)) {
			room = load_object(__DIR__"path1");
		}
		message_vision("$N掀开白色幔帐的一角。\n", me);
		set("exits/west", __DIR__"path1");
		message("vision", "有人掀开白色幔帐的一角。\n", room);
        room->set("exits/east", __DIR__"hpath1");
        call_out("close_path", 5);
	}
	return 1;
}
void close_path(){
	object room;
	
	if( !query("exits/west") ) {
		return;
	}
	if(!objectp(room = find_object(__DIR__"path1"))){
		room = load_object(__DIR__"path1");
	}
	message("vision", "白色幔帐垂下挡住了去路。\n", this_object());
	message("vision", "白色幔帐垂下挡住了去路。\n", room);
	room->delete("exits/east");
	delete("exits/west");

}

int valid_leave(object me, string dir){
	if(dir == "west") {
		message_vision("$N矮身钻入幔帐之中。\n", me);
	}
	return 1;
}
