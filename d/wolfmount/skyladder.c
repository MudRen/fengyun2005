inherit ROOM;

void create()
{
	set("short", "天梯");

	set("long", @LONG
一座由数十根手腕粗细的铁索搭成的天梯，依天而立。下面就是一条汹涌激荡
的山涧，“轰轰”有如雷鸣。山风呼啸而过，天梯摇摇晃晃，一个不留神就可能从
天梯上坠入万劫不复的深渊。
LONG);

	set("type","road");
	set("exits",([
		"down":__DIR__"cliffroad4",
		"southeast":__DIR__"moonrock",
	]) );
       set("outdoors", "wolfmount");
		set("objects",([
            __DIR__"npc/zhongli":1,
    	]) );
	set("coor/x",50);
	set("coor/y",15);
	set("coor/z",20);

	setup();
}

void init(){
	add_action("do_go","go");
}

int do_go(string str){

	object ob,room, me = this_player();
	object *inv;
	int i;
	
	if (userp(me))
	if (str == "southeast" || str == "down") {
		switch(random(6))
            {
         		case 0:
                        message_vision("钢索剧烈地抖动着，$N不禁在天梯上晃来倒去．．\n",me);
                        tell_object(me,"还好，没掉下去！\n");
                        return 1;
                case 1:
                        inv = all_inventory(me);
                        if(sizeof(inv)>=1)      
                        {
                            ob = inv[random(sizeof(inv))];
                            if (ob->query("no_drop") || ob->query("owner")
                            	||me->query("timer/insurance") + 259200 > time()) 
                            	return 0;
                            message_vision(ob->name()+"从$N身上滑了出来，落入万丈深渊．\n",me);
                            destruct(ob);
                        }
                        return 0;
                case 2:
                        message_vision("$N在天梯上不住地摇晃着。。。\n",me);
            			if ( me->query("kar") <= 20 )
                        {
                                message_vision("伴随着一声杀猪般的凄厉惨嚎，$N失足坠入万丈深渊。。\n",me);
                                me->unconcious();
                                room = find_object(__DIR__"undercliff");
                                if(!objectp(room)) room = load_object(__DIR__"undercliff");
                                me->move(room);
                                return 1;
                        }
                        else
                               {
                                message_vision("$N死死扣住钢索，长长吁了口气，终于安全了。。\n",me);
                                return 1;
                        }
                        break;
                    default:
                            return 0;
            }
	}	
		
	return 0;		
}