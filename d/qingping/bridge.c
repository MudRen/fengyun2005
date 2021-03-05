//XXDER
inherit ROOM;
void create()
{
    set("short", "拱桥");
    set("long", @LONG
一座小巧精制的拱桥横跨在池塘上，池塘就这样被一分为二。池塘里的水碧绿
清澈，上面浮着些盛开的睡莲，透过睡莲的缝隙隐约可见几尾红色金鲤在水中悠闲
地缓缓游动。远处靠墙窗下的一丛芭蕉，火红的花朵开的正热闹，给这宁静的池塘
带来无限生机。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"eastdown" : __DIR__"backdoor",
	"westdown" : __DIR__"pond",
      ]));

    set("objects", ([
	__DIR__"npc/qin": 1,
      ]) );
    set("coor/x",10);
    set("coor/y",0);
    set("coor/z",10);
    setup();

    set("outdoors", "qingping");
}

void init()
{
    add_action("do_search", "search");
}

int do_search (string arg)
{
    object me, obj;
    int clvl;

    me = this_player();
    
    if(!arg || arg != "bridge" && arg != "桥") {
    	tell_object(me,"你想在哪儿搜索？\n"); 
		return 1;
	} 
	
	clvl = (int)me->query("kar");
    if(me->query_temp("marks/bridge")) {
		message_vision("$N探头看了看桥边的石头。\n", me);		
		tell_object(me, "你凭着对黑斑地点的印象，仔仔细细地查看了一遍桥边的石头。\n");
		if(clvl > 19) {
		    if(random(100) < clvl) {
			tell_object(me, "你发现桥头的一块石头上凹进去了一块，在凹进去的地方有一个小孔。\n"); 
			me->set_temp("marks/key",1);
			return 1;
		    }
		}
		else {
		    if(random(300) < clvl) {
				tell_object(me, "你发现桥头的一块石头上凹进去了一块，在凹进去的地方有一个小孔。\n"); 
				me->set_temp("marks/key",1);
				return 1;
		    }
		    else 
				tell_object(me, "你什么也没发现。\n");       
		    return 1;
		}
    }
    message("vision", me->name()+"似乎在找寻什么？\n", environment(me), me);
    tell_object(me, "你什么也没发现。\n");       
    return 1;
}


void key_notify(object obj, int i)
{
    object me;
    me = this_player();
    if(me->query_temp("marks/key")) { 
		tell_object(me, "你把钥匙插入石孔，左右转了几下。\n");
		me->start_busy(2);
		call_out("open_door", 5, me);
		return;
    }
    return;
}

void open_door(object me)
{
    int llvl;

    llvl = (int)me->query("kar");

    if(me && environment(me) == this_object()) {
	if(random(100) < llvl)  {
	    me->set_temp("marks/opened",1);
	    tell_object(me, "平静的池塘水面上似乎起了一个小小的漩涡，不仔细是看不出来的。\n");
	}
	else 
	    tell_object(me, "你没有感觉到任何变化。\n");
    }
    return;
}
