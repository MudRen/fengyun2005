 //Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
        set("short", "沙滩");
        set("long", @LONG
在这里，你已分不清天上人间。阳光灿烂，沙滩洁白柔细，海水湛蓝如碧，浪
涛带着新鲜美丽的白沫轻拍着海岸。极目而望，海中有天，天中有海。仰视碧空，
但见天做沧海，云做轻帆。沙滩上摆放着几张渔网，三两个渔家姑娘正在一边修补
渔网，一边哼着渔家小调。海水荡漾下，软软的沙子踏上去格外舒服。
LONG
           );
        set("exits", 
           ([ 
 	     "east"  : __DIR__"beach1",
	    ]));
	set("item_desc", 
	   ([
	     "海水": "透过清澈碧蓝的海水，你可以看到在水中嘻戏的鱼虾，还有随著海浪婆娑起舞的海藻。\n",
	     "seawater":"透过清澈碧蓝的海水，你可以看到在水中嘻戏的鱼虾，还有随著海浪波婆娑起舞的海藻。\n",
	    ]));
	set("objects", 
	   ([ 
	     AREA_BAIYUN"obj/sand" : 1,
             AREA_BAIYUN"npc/xian3" : 1,
	    ]));
	set("littlething", 10);
        set("outdoors", "baiyun");
	set("coor/x",40);
	set("coor/y",-250);
	set("coor/z",10);
	setup();
}


void init()
{
    add_action("do_search", "search");
}

int do_search(string arg)
{
	object me, obj, sand;
	me = this_player();
	sand = present("sand", this_object());
	if(!arg) {
	    write("你要在哪里找东西？\n");
	    return 1;
	}
	if( me->is_busy() ) {
	    return notify_fail("你上一个动作还没有完成，不能搜索。\n");
	}
	if( arg == "sand" || arg == "沙子"  ){
	    if ( query("littlething") > 0 && !random(3) ) {
			message_vision("$N蹲下身子，在沙子里搜寻着，突然从沙里挖出个小玩意。\n",me);
			obj = new(AREA_BAIYUN"obj/littlething");
			obj->move(environment(me));
			add("littlething", -1);
	    } else {
            message_vision("$N不耐烦的翻了半天，但什么都没有找到。\n",me);
            me->start_busy(3);
	    }
	}
	return 1;
}

void reset()
{
        ::reset();
        set("littlething", 10);
}

