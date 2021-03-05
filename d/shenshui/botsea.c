#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "海底");
    set("long", @LONG
这里是一片宁静的深蓝，那种深蓝很容易令人联想到夏日的夜空。海底铺满了
一层洁白的沙，几块长满珊瑚的礁石散布在沙地上，柔长的海草微微的摇摆着，偶
尔有几条小鱼游过，却不能打破这里的幽寂。
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"midsea", 
    	]) );
    	set("item_desc",([
        	"sand" : "洁白的细沙铺在海底，下面似乎有什么东西。\n", 
        	"沙" : "洁白的细沙铺在海底，下面似乎有什么东西。\n", 
    	]) );
    	set("no_fly",1);
    	set("count",1);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-90);
	set("underwater",100);
	set("water_damage",20);
    	setup();
}

void init(){
    	
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
    	add_action("do_search", "search");
    	if(!random(20)){
        	call_out("see_light", 3, this_player());
    	}
}

int do_search(){
    	object me;
    	me = this_player();
    
    	if(me->is_busy()) {
        	return notify_fail("你正在忙。\n");
    	}
    	if(me->is_fighting()){
        	return notify_fail("还是先打完再说吧。\n");
    	}
    	message_vision("$N在海底仔细搜寻。\n", me);
    	me->start_busy(2);
    	call_out("result", 4, me);
    	return 1;
}

int result(object me) {
    	object seashell;
    	if(environment(me) == this_object()){
        	if(!random(5) && !present("sea shell", this_object()) && query("count")) {
	            	tell_object(me, "\n你忽然摸到一个大海蚌。\n");
	            	message_vision(HIC"\n你只觉得一丝蓝莹莹的光从眼前一闪而逝。\n"NOR, me);
	            	message_vision("海蚌微微动了一下，蚌壳紧紧闭上了。\n", me);
	            	seashell = new(__DIR__"obj/seashell");
	            	seashell->move(this_object());
	            	set("count",0);
	            	return 1;
        	}
        	tell_object(me, "你什么也没有发现。\n");
    	}
    return 1;
}

int see_light(object me){
    	if(environment(me) == this_object()) {
        	message("vision", HIC"\n一道蓝莹莹的微光一闪而逝。\n"NOR, environment(me));
    	}
}

int valid_leave(string dir){
	object me;
    	me = this_player();
    	message_vision("$N蹬了蹬腿向上游去。\n", me);
    	return 1;
}

void reset(){
	::reset();
	set("count",1);
}

