inherit ROOM;
void create()
{
        set("short", "白杨沟");
        set("long", @LONG
白杨沟位于天山支脉喀拉乌成山北麓中底山过渡带，沟中古树葱郁，长满高大
挺拔的[37m榆树[32m、[37m杨树[32m、[37m槐树[32m及说不出名字的[37m灌木[32m、鲜花。就是在盛夏的阳光下，这里
还是清凉无比，令人感到无限舒畅。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"chairong",
  		"south" : __DIR__"bingchuan",
  		"east" :  __DIR__"goudi",
	]));

        set("outdoors", "xinjiang");
		set("coor/x",10);
		set("coor/y",-60);
		set("coor/z",0);
		setup();
}

void init()
{
   	add_action("do_look", "look");
}

int do_look(string arg)
{
   	object me;

   	me = this_player();

   	if (arg == "榆树" || arg == "槐树" || arg == "灌木") {
   		tell_object(me, "白杨沟里虽然多的是白杨树，" + arg + "依然长得郁郁葱葱。\n");
   		return 1;
   	}
   		
   	if (arg == "杨树" || arg == "白杨树" || arg == "yangshu") {
   	  	tell_object(me, "灰白色的杨树干上结满了一个个象眼睛似的疤痕，有的象在笑，有
的似在哭．．目光似乎正落在地上一堆新土上。\n");
		me->set_temp("marks/xj_noticed_yangshu",1);
		return 1;
	}

	if ( (arg == "新土" || arg == "dirt") && me->query_temp("marks/xj_noticed_yangshu")){
		tell_object(me,"一堆褐色的泥土，像是最近有人在这里挖过什么。\n");
		me->set_temp("marks/xj_noticed_dirt",1);
		return 1;
	}
	
	return 0;
}
	
	
void dig_notify()
{
	object me, box;
	int llvl;
		
	me = this_player();
	llvl = (int)me->query("kar");
	
	box = present("iron box", this_object());
	
	if (!me->query_temp("marks/xj_noticed_dirt")){
		tell_object(me,"你胡乱在地上挖了起来，挖遍了整个山沟，累得半死可什么也没有找到。\n");
		return;
	}		
		
	if(llvl > 12 ) {
		tell_object(me,"你顺着那新土的位置挖了下去。\n");
		if (query("already")) {
			tell_object(me,"地上出现了一个土坑，除了腐朽的枝叶，你什么都没有发现。\n",me);  
			return;
		}
		message_vision("铛．．得一声，$N的镐似乎敲在了一个铁东西上。\n", me);
	    tell_object(me, "低头一看，土坑里露出了一个铁盒。\n");
	    if(!objectp(box)) {
	         box = new(__DIR__"obj/box");
	         box->move(this_object());
			 set("already",1);
	    }
	}
	else
		tell_object(me,"你在地上狂乱地挖了起来，可是你的运气太差了，什么也没有找到。\n");
	
	return;	
}

void reset(){
	::reset();
	if (!random(8))
		set("already",0);
}
