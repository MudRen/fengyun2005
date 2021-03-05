inherit ROOM;

void create()
{
	set("short", "断塔顶");

	set("long", @LONG
这里是断塔顶，一盏黄油纸灯笼，用竹竿斜斜挑起。竹竿插在断墙里，灯笼不
停地摇晃。昏暗的灯光下有三个人，一个衰老佝偻的残废人，阴暗丑陋的脸上满是
刀疤。一个中年锦衣大汉，另一个则是个很高大的黑衣人，冷冷地站在[33m窗[32m边。 
LONG);

	set("type","street");
	set("exits",([
		"down":__DIR__"broketower5",
	]) );

	set("item_desc", ([
		"窗":	"一扇破旧的窗户，窗栏已经没剩下几根了，你可以试着跳出去（jumpout window）\n",
		"window":	"一扇破旧的窗户，窗栏已经没剩下几根了，你可以试着跳出去（jumpout window）\n",

	]));
	
	set("objects", ([
		__DIR__"npc/baili_changqing": 1,
		__DIR__"npc/deng":1,
		__DIR__"npc/hu_5":1
	]));
	set("indoors", "bawang");
	setup();

	set("coor/x",-15);
	set("coor/y",10);
	set("coor/z",40);
}



void init(){	
	add_action("do_jump","jumpout");
}


int do_jump(string arg){
	
	object me, ob, room;
	
	me = this_player();
	
	if (!arg || arg!="window")	return 0;

	if (ob=present("baili"))
		return notify_fail(ob->name()+"冷冷地挡在你的身前道：是非之地，哪里来的，还从哪里下去吧。\n");
		
	message_vision("$N跃上窗台，四下看了看，纵身向外跳去。\n", me);
		
	room = find_object("/d/bawang/undertower2");
	if(!room) room=load_object("/d/bawang/undertower2");
	me->move(room);
	message("vision", me->name()+"从塔上面缓缓落了下来，\n", environment(me), me);
	
	return 1;
}