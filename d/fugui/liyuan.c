inherit ROOM;
#include "/questnpc/lovestory1/event_place.h"
void create()
{
	set("short", "梨园");

	set("long", @LONG
这里便是富贵山庄的“圣地”梨园，之所以这样说，因为对王动他们来说，这
儿不仅意味着饿了可以拿几只梨子充饥，更加重要的是，酒虫上来了，也能摘几筐
梨拿去换酒喝，时已深秋，梨树上原本还有满树又甜又大的梨子，但现在却已经被
摘得几乎所剩无几了。
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("exits",([
		"west":__DIR__"shibanlu2",
	]) );
        set("objects", ([
		__DIR__"obj/pear" : 2,
	]) );
	set("coor/x",30);
	set("coor/y",210);
	set("coor/z",80);
	setup();

}

int valid_enter(object me)
{

	if(me->query("lovestory1"))
		add_trigger_count(me);
	return 1;
}

void reset(){
        object item;
        int i;
        ::reset();
      
	if(!present("pear", this_object())){
                for (i=1; i<=2 ; i++) {
                	item = new(__DIR__"obj/pear");
	                if(objectp(item)){
                        item->move(this_object());
                	}
	        }
        }
        return;
}         