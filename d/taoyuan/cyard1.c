inherit __DIR__"no_killing_place";
void create()
{
	set("short", "小院");
    set("long", @LONG
手臂粗细的葡萄藤被架子撑起一大片，一串串的小葡萄象用碧玉雕成，淡黄的
阳光斜斜的照在上面，更加的晶莹剔透。葡萄架下是一口水井，水井上是一个木头
轱辘，摇起来发出咿咿呀呀的声音。
LONG
        );
	set("exits", ([ 
		"east" : __DIR__"cyard",
	]) );
	
	set("item_desc", ([
		"葡萄藤" : "架起的葡萄藤下挂满了一串串的小葡萄。\n",
		"grape vine" : "架起的葡萄藤下挂满了一串串的小葡萄。\n",
	]) );
	set("grape_amount", 5);
    	set("no_magic", 1);
    	set("outdoors","taoyuan");
	set("coor/x",15);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}


void init()
{
	::init();
	add_action("do_pick", "pick");
    	add_action("do_look", "look");
    	add_action("do_approach", "approach");
}

int do_pick(string arg)
{
    object me, grape;

   	me = this_player(); 
   	if(!arg || arg != "grape" && arg != "葡萄") return 0;	
   	if ((int) query ("grape_amount") >= 0)
   	{
  		grape = new(__DIR__"obj/grape");
      	grape->move(me);
      	add("grape_amount", -1);
      	message_vision("\n$N伸手摘了一串葡萄下来。\n", me);
   	} else { 
      write ("葡萄都被摘光啦！！！ \n");
    }
      return 1;
}

int do_look(string arg)
{
	object me;
	object room;
	me = this_player();
	if(!arg)	return 0;
	
	if (arg != "井" && arg != "well" && arg != "水井") return 0;
	
	switch ( random (2)) {
		case 0:
			tell_object(me,"水井边上湿漉漉的，好象才有人打过水，还是不要靠（ａｐｐｒｏａｃｈ）的太近。\n"); 
			break;
		case 1:
			message_vision("$N探头向水井里望去。 \n", me); 
			tell_object(me,"黑不隆咚的水井深不见底。 \n");
                break;
	}
        return 1;
}

int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
	if(!arg || arg != "井" && arg != "well" ) return 0;
	switch ( random (3)) {
		case 0:
message_vision("$N走近水井探头向里望去。 \n", me); 
tell_object(me,"水井深不见底，不过你似乎可以听到底下流水的声音。 \n");
                break;
		case 1:
message_vision("$N走近水井探头向里望去。哎呀！一不小心掉了进去！\n", me); 
message_vision("$N的头撞在井壁上，一下子昏了过去！\n", me);
		me->unconcious();
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
		case 2:
message_vision("$N走近水井探头向里望去。哎呀！一不小心掉了进去！\n", me); 
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
	}

        return 1;
}

void reset(){
	::reset();
	set("grape_amount", 5);
}
