#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "沙穴");
	set("long", @LONG
地势越走越高，四周依然是黑黑的，周围怪石也越来越少，到最后你感觉似乎
是在一个沙洞之中，脚下是柔软的沙子，空间越来越小，四周的沙墙象随时就可能
坍塌而把你埋葬，头顶不时的有细沙落下，这里的空气虽然感觉不到流动却已不再
那么沉闷。
LONG
	);
	set("exits", ([ 
  		"northdown" : __DIR__"dongd2",
	]));
    	set("item_desc", ([
    		"sand" : "沙粒很细，摸在手中的感觉一定很柔软。沙地上有半根铁链露在外面。
你似乎可以拉（ｐｕｌｌ　ｃｈａｉｎ）。\n",
    		"沙子" : "沙粒很细，摸在手中的感觉一定很柔软。沙地上有半根铁链露在外面。
你似乎可以拉（ｐｕｌｌ　ｃｈａｉｎ）。\n",
    	]) );
	set("indoors", "quicksand");
	set("coor/x",-1020);
	set("coor/y",-30);
	set("coor/z",-5);
	setup();
}

void init(){
    	add_action("do_pull", "pull");
}

int do_pull(string arg){
    	object ro;
    	if(!arg || arg != "chain") {
        	return notify_fail("你要拉什么？\n");
    	}
    	if (query("exits/up"))
    		return notify_fail("洞口已经打开了。\n");
    		
    	ro = load_object(__DIR__"desert_entrance");
    	if(NATURE_D->is_day_time()){
        	message_vision("随着一阵轻微的齿轮转动的声音，一阵沙雨落下，紧接着一道
刺眼的光芒射入，亮的让你睁不开眼。\n", this_player());
	 } else {
        	message_vision("
随着一阵轻微的齿轮转动的声音，一阵沙雨落下，清新的空气扑面而来。\n", this_player());
    	}
    	if(!objectp(ro)){
        	ro = load_object(__DIR__"desert_entrance");
    	}
    	set("exits/up", __DIR__"desert_entrance");
    	ro->set("exits/down", __DIR__"dongd3");
    	call_out("close_path", 10);
    	return 1;
}


void close_path(){
    	object ro;
	if(!objectp(ro)){
        ro = load_object(__DIR__"desert_entrance");
    	}
    	if(query("exits/up")){
        	message("vision", "随着一阵轻微的齿轮转动的声音，一切又陷入漆黑之中。\n", this_object());
        	delete("exits/up");
    	}
    	if(ro->query("exits/down")){
        	ro->delete("exits/down");
    	}
}
