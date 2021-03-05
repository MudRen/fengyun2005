inherit ROOM;

void create()
{
    set("short", "大牢外");
	set("long", @LONG
这是一座用巨石建成的大牢，高耸的围墙是一般围墙的三四倍之高，即使最好
的轻功也难一越而入。青黑色的大石头给人一种肃穆的感觉，东面是两扇厚厚的木
门，让人难窥究竟。
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
       	"northwest" : __DIR__"street5",
//       "east" : __DIR__"dalao1",
    	]));
    	set("objects", ([
        	__DIR__"npc/yuzu" : 2,
    	]) );
    	set("item_desc", ([
    		"door" : "黑色的大门异常的厚实（ｏｐｅｎ）。\n",
    		"木门" : "黑色的大门异常的厚实（ｏｐｅｎ）。\n",
	
    	]));
    	set("outdoors", "jinan");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("open_door", "open");
}

int open_door(string arg){
	object me, obj;
	
	me = this_player();
	if(arg == "door"){
		if(query("exits/east")){
			return notify_fail("门是开着的。\n");
		}
		if(!me->query_temp("探监") && !me->query("vendetta_mark")){
			return notify_fail("牢房还是不要乱闯的为妙。\n");
		} else {
			if(load_object(__DIR__"dalao1")){
				tell_object(me,"你伸手推开了沉重的大门。\n");
				set("exits/east", __DIR__"dalao1");
			}				
		}
	}
	return 1;
}

int valid_leave(object me, string dir){
	object obj;
	
	if(dir == "east" && (!me->query_temp("探监") && !me->query("vendetta_mark"))) {
		if(obj=present("yu zu", this_object())) {
			return notify_fail("狱卒喝道：“站住，牢房重地不可乱闯。”\n");
		} else {
			return notify_fail("牢房还是不要乱闯的为妙。\n");
		}
	}
	if(query("exits/east")){
		message_vision("咣铛一声，大门又关上了。\n", me);
		delete("exits/east");
	}
//	me->delete_temp("探监");
	return 1;
}
