inherit ROOM;

void create()
{
        set("short", "大松树上");
        set("long", @LONG
松树很高，你小心翼翼地往上爬到了一半的地方，幸好松树也很密，到处是盘
曲的丫枝，很容易就找到歇脚的地方。从这里可以很清楚地看到直共寺的院子里的
动静。寺院里的几只藏马鸡正在堤上寻食，咯咯咯的叫声听的清清楚楚。
LONG
        );
        set("objects", ([
                
        ]) );

        set("exits", ([ 
  		"down" : __DIR__"temple5",
	]));
        set("coor/x",-1900);
	set("coor/y",720);
	set("coor/z",20);
	set("map","zbwest");
	setup();

}

void init(){

	add_action("do_climb","climb");
}

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg) {
		tell_object( me, "你想爬什么？\n");
		return 1;
	}
	
	if (arg == "tree" || arg == "树"){
		tell_object( me, "嗯，那么爬哪棵树呢？\n");
		return 1;
	}
		
	if (arg=="pine"|| arg=="松树" || arg == "大松树") {
		room=find_object(__DIR__"pine2");
		if (!objectp(room)) room=load_object(__DIR__"pine2");
		message_vision("$N手脚并用，敏捷地继续向树顶爬去。\n",me);
        tell_room(room, this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(room);
      	return 1;
      }
      
      return notify_fail("这个大概没法爬。\n");
}

