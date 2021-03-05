inherit __DIR__"no_killing_place";
void create()
{
        set("short", "安然居");
        set("long", @LONG
原木为篱，青藤作绳，粗粗围就一方院落。多年的风吹雨打，原木与青藤不但
没有腐烂，还又生了根，长出了碧绿的叶子，翠绿的篱笆别有一番风味。柴门不甚
坚固，主人也似乎并不在乎。门两旁高书：花径不曾缘客扫  蓬门今始为君开。正
中横书：安然居。
LONG
        );

    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"road3",
	]) );

	set("objects", ([
		__DIR__"npc/dog" : 1,
	]) );

	set("item_desc", ([
		"door" : "不甚坚固的柴门只是轻掩着，似乎轻轻一推就开了。\n",
		"柴门" : "不甚坚固的柴门只是轻掩着，似乎轻轻一推就开了。\n",
	]) );

	set("no_magic", 1);	
   	set("outdoors","taoyuan");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}

void init() {
	::init();
	add_action("do_push", "push");
} 

void close_path()
{
	if( query("exits/north") ) {
    message("vision","柴门来回荡了几荡，最后终于静止了。\n",this_object() );
    delete("exits/north");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="door" || arg =="柴门") {
    	message_vision("$N往柴门上轻轻地一推，吱。。。的一声柴门开了。\n", me);
		set("exits/north", __DIR__"cyard");
		call_out("close_path", 5);
	}
	else {
		write("你要推什么呢？\n");
	}
	return 1;	
 }
