// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "寒潭深处");
    set("long", @LONG
这里是一片宁静的幽碧，阳光透过数丈深的潭水，散漫的映在潭底的薄沙上，
投射出点点好似林中疏漏的光斑。几块形态各异的鹅卵石散布在沙地上，几缕水草
在潭中微摆，冷冽的潭水寒绸般覆着你的身躯。
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"pond", 
    	]) );
    	set("item_desc",([
        	"鹅卵石" : "一块鹅卵石在水里轻轻摇晃，下面似乎垫着什么东西。\n", 
        	"cobble" : "一块鹅卵石在水里轻轻摇晃，下面似乎垫着什么东西。\n", 
    	]) );
    	set("no_fly",1);
    	set("count",1);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",-20);
	set("underwater",40);
	set("water_damage",20);
    	setup();
}

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
	add_action("do_search", "search");
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
    	message_vision("$N在潭底仔细搜寻。\n", me);
    	me->start_busy(2);
    	call_out("result", 4, me);
    	return 1;
}

int result(object me)
{
	object seashell;
	if(environment(me) == this_object())
	{
		if(!random(5) && query("count"))
		{
			message_vision("$N伸出手去，按开一块鹅卵石，在石下摸出了什么东西。\n", me);
			seashell = new(__DIR__"obj/icecrystal");
			seashell->move(me);
			set("count",0);
			return 1;
		}
		tell_object(me, "你什么也没有发现。\n");
	}
    return 1;
}


int valid_leave(string dir)
{
	object me;
	me = this_player();
	message_vision("$N蹬了蹬腿向上游去。\n", me);
	return 1;
}
