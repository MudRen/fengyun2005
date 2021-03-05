// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "星星小楼");
        set("long", @LONG
进得楼来，只见四周陈设皆为黑色，四壁也是黑色，除了南边有一扇窗，微微
透过些亮色外，就只有屋中桌子上的油灯发出微弱的光，靠窗边有一床榻，上面铺
着简单的被褥。窗口传来一阵阵海涛声，似在向你呼唤，又似在倾诉什么，你忍不
住想侧耳聆听。
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"ruanhong",
   ]));
   set("objects", ([
      __DIR__"npc/lingyu" : 1,
   ]) );
  
   set("item_desc", ([
      "window": "临窗下看，只见危崖百尺，黑色的海浪拍打着岸边的乱石。
你可以从此爬上跳下去（ｃｌｉｍｂ　ｗｉｎｄｏｗ）。 \n",
      "窗": "临窗下看，只见危崖百尺，黑色的海浪拍打着岸边的乱石。
你可以从此爬上跳下去（ｃｌｉｍｂ　ｗｉｎｄｏｗ）。 \n",
   ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void init(){
    add_action("do_climb", "climb");
    add_action("do_listen", "listen");
    add_action("do_answer", "answer");
}

int do_climb(string arg)
{
    	object me;
    	int cl;
    	me = this_player();
    	cl = (int)me->query_cps();
    	if(!arg || (arg != "window" && arg != "窗")){
        		return 0;
    	} 
   		if (cl >= 20 || random(100)>90) {
        	message_vision("$N爬到窗口，纵身向窗外跳去。\n\n", me);          
        	call_out("fall_out", 1, me);
        	me->start_busy(2);
    	} else {
        	tell_object(me, "你跳到窗口，向外看了看，有点犹豫，再试试吧？\n\n", me);
        	message("vision", me->name()+"跳到窗口，向外看了看，脸色煞白地又跳了下来。\n\n", environment(me), me);
    	}   
    	return 1;
}

int fall_out(object me){
    	int ml, cl;
    	object room;
    	
    	if (!me || me->is_ghost() || environment(me)!=this_object())	return 1;
	
		if (me->query_skill("move")<50) {
       		tell_object(me, "你只觉的身子向下坠落，慌乱中你伸出右脚踏向一颗从岩缝中长出的小
树，咔喳一声小树断了，你下降的势力也缓了缓，扑通一声你落入了水中。。\n\n");
    	} else {
        	tell_object(me, "你只觉的身子向下坠落...坠落....似乎坠向无底的深渊，终于扑通一
声你落入了水中。\n");
    	}
    	
    	room = find_object(__DIR__"yadi");
    	if(!objectp(room)) room = load_object(__DIR__"yadi");
    	me->move(room);
    	message("vision", "你觉得有一团黑忽忽的事物从上面落下，扑通一声落入你身旁的水中。\n", environment(me), me);
    	return 1;
} 

int do_listen(string arg){
    	object me, obj;
    
    	me = this_player();
    	if(!arg || (arg != "wave" && arg != "海涛" && arg != "海涛声" && arg != "haitao")) {
        	return notify_fail("你要听什么？\n");
    	}
    	message_vision("$N侧耳聆听海涛拍打岸边的声音。\n", me);
    	if(obj = present("ling yu", this_object())){
    	if(!me->query_temp("marks/lingyu_asked")){
	    	message_vision("$N微笑着对$n道：“海是一个神秘的世界，不是吗？你可相信蛟人的存在？”
（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ／ｄｕｎｎｏ）\n", obj, me);
    		me->set_temp("marks/lingyu_asked", 1);
    	} else {
    		tell_object(me, "只听到一阵阵海涛冲击岸边岩石的声音。\n");
    	}
    }
    return 1;
}

int do_answer(string arg){
    	object ly, me, mask;
    
    	me = this_player();
    	if(!arg || (arg != "yes" && arg != "no" && arg != "dunno")) {
        	return 0;
    	} 
    	if (!me->query_temp("marks/lingyu_asked")) {
        	return 0;
    	} 
    	if(ly = present("ling yu", this_object())){
        	ly->answer_react(me, arg);
    	}
	return 1;
}
