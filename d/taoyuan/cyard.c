inherit __DIR__"no_killing_place";
void create()
{
    set("short", "小院");
    set("long", @LONG
小小的院落，西边一方葡萄架遮住了半边，阳光斜斜的照在上面，把嫩绿的叶
脉变得透明，一串串比豌豆大一些的葡萄晶莹剔透。篱笆的一角有一个小小的木棚，
南面柴门轻掩着，东面的房间传出阵阵饭菜香。
LONG
        );
    set("exits", ([ 
	"east" : __DIR__"kitchen",
	"north" : __DIR__"livingroom",
	"west" : __DIR__"cyard1",
	]) );

    set("objects", ([
	__DIR__"obj/storage": 1,
	]) );
	
	set("item_desc", ([
		"door" : "不甚坚固的柴门只是轻掩着，似乎轻轻一推就开了。\n",
		"柴门" : "不甚坚固的柴门只是轻掩着，似乎轻轻一推就开了。\n",
	]) );

    set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
    setup();
}


void init() {
	::init();
	add_action("do_push", "push");
} 

void close_path()
{
	if( query("exits/south") ) {
    message("vision","柴门来回荡了几荡，最后终于静止了。\n",this_object() );
    delete("exits/south");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="door" || arg =="柴门") {
    	message_vision("$N往柴门上轻轻地一推，吱。。。的一声柴门开了。\n", me);
		set("exits/south", __DIR__"anju");
		call_out("close_path", 5);
	}
	else {
		write("你要推什么呢？\n");
	}
	return 1;
}

void reset()
{
    int i;
    object *inv;
    object item1, item2, storage ;
    ::reset();
    storage = present("storage", this_object());
    inv = all_inventory(storage);
    for(i=0;i<sizeof(inv);i++)
        destruct(inv[i]);
    item1 = new(__DIR__"obj/saoba");
    item1->move(storage);
    item2 = new(__DIR__"obj/gao");
    item2->move(storage);
}
