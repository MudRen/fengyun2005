inherit ROOM;
void create()
{
	set("short", "桃源村");
	set("long", @LONG
眼前树影山阴之下，离离地散布着几户房舍，袅袅炊烟轻若无痕，偶有犬吠，
也很快归于平静。在这里，你感觉不到任何尘世的嘈杂，一切都是那样的安宁，就
连轻风拂面，也只带来清清泥草芳香，和远山鸟啼。一道简单的木栅栏门设在向西
北的路上；一条青色的石板路向东蜿蜒的伸展过去，路边矗立着一块巨大的山石。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
    "east" : __DIR__"road1",
	]) );
	set("objects", ([
		__DIR__"obj/stone": 1,
	]) );
	
	set("item_desc", ([
		"gate" : "简单的木栅栏门半掩着（ｐｕｓｈ　ｇａｔｅ）。\n",
		"door" : "简单的木栅栏门半掩着（ｐｕｓｈ　ｇａｔｅ）。\n",
		"栅栏门" : "简单的木栅栏门半掩着（ｐｕｓｈ　ｇａｔｅ）。\n",
	]) );
	set("outdoors","taoyuan");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("deer",1);
        setup();
}


void pipe_notify()
{
	object  room;
	message_vision("哨音在这里显得格外地幽美动听。\n", this_player());
	if (query("deer")) {
		call_out("animal_come", 3);
		set("deer",0);
	}
}

void animal_come()
{
	object deer;

	deer = present("little deer", this_object());
	if(!objectp(deer)) {
		deer = new(__DIR__"npc/deer");
		deer->move(this_object());
		message("vision","哨音未落，一只小梅花鹿就从树丛后跑了出来。\n", this_object());
	}
}

void reset() {
	set("deer",1);
	::reset();
}

//int init_enter(object ob) {
//   write("\n\nLEAVE LEAVE LEAVE!\n");
//   return 0;
//}

void init() {
	add_action("do_push", "push");
} 

void close_path()
{
	if( query("exits/northwest") ) {
    		message("vision","栅栏门在你身后自动掩上。\n",this_object() );
    		delete("exits/northwest");
    	}
}

int do_push(string arg)
{
	object me;
    	me = this_player();
    	if( arg=="door" || arg =="栅栏门" || arg == "gate") {
    		message_vision("$N往半掩的栅栏门上一推，咯吱吱。。。的一声栅栏门打开了。\n", me);
		set("exits/northwest", __DIR__"fenghuo");
		call_out("close_path", 5);
	}
	else {
		write("你要推什么呢？\n");
	}
	return 1;	
}
