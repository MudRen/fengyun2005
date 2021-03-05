inherit ROOM;
void create()
{
        set("short", "荒野小径");
        set("long", @LONG
高高的围墙上有一扇小小的木门，前面是一个条小路，荒凉的小径上布满了野
草，看来鲜少有人在这里走动。小路蜿蜒的伸向远方，隐没在前方的一片丛林中，
树林再过去则是巍巍的高山。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
	   "east" : __DIR__"path1",	
   ]));
	set("item_desc", ([
		"door" : "小门紧闭着，里面悄然无声。\n",
		"木门" : "小门紧闭着，里面悄然无声。\n",
	]));
	set("outdoors","qingping");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}

void init(){
	add_action("do_push", "push");
}

int do_push(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "door" && arg != "小木门" && arg != "木门")){
		return notify_fail("你要推什么？\n");
	}
	if(query("exits/west")) {
		return notify_fail("门已经是开着的了。\n");
	}
	message_vision("$N探手往小木门上一推，咯吱吱。。小门随手打开。\n", me);
	set("exits/west", __DIR__"backdoor");
	room = find_object(__DIR__"backdoor");
	if(!objectp(room)){
		room = load_object(__DIR__"backdoor");
	}
	message("vision", "小门被人从里面打开。\n", room);
	room->set("exits/east", __DIR__"path");
	call_out("close_path", 5);
	return 1;
}

void close_path(){
	if( query("exits/west") ) {
		message("vision","咯吱吱。。小门掩上又遮住了小径。\n",this_object() );
		delete("exits/west");
	}
}
