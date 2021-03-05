inherit ROOM;
void create()
{
        set("short", "后门");
        set("long", @LONG
花园的东墙有一个小[37m木门[32m，木门正对着一座小拱桥，一条铺满鹅卵石的小路蜿
蜒地从木门前穿过，消失在花丛中。因为这里平时少有人行走，地上的石缝中不知
何时长出些不知名的花草，虽是无名野花，却也开的芬芳艳丽。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "westup" : __DIR__"bridge",
   "northwest" : __DIR__"northpond.c",	
   "south" : __DIR__"southpond1.c",	
   ]));

   set("objects", ([
      __DIR__"obj/cao": 1,
   ]) );
	set("item_desc", ([
		"door" : "小门紧闭着，不知道后面通向那里。\n",
		"木门" : "小门紧闭着，不知道后面通向那里 。\n",
	]));
   set("outdoors","qingping");
	set("coor/x",20);
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
	if(query("exits/east")) {
		return notify_fail("门已经是开着的了。\n");
	}
	message_vision("$N探手往小木门上一推，咯吱吱。。小门随手打开，露出一条荒凉的小径。\n", me);
	set("exits/east", __DIR__"path");
	room = find_object(__DIR__"path");
	if(!objectp(room)){
		room = load_object(__DIR__"path");
	}
	message("vision", "小门被人从里面打开。\n", room);
	room->set("exits/west", __DIR__"backdoor");
	call_out("close_path", 5);
	return 1;
}

void close_path(){
	if( query("exits/east") ) {
		message("vision","咯吱吱。。小门掩上又遮住了小径。\n",this_object() );
		delete("exits/east");
	}
}

void reset()
{
   object *inv;
   object item1, cao;
   ::reset();

   cao = present("cao", this_object());
   inv = all_inventory(cao);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(cao);
   }
}

