#include <ansi.h>
inherit ROOM;
string stone();
void create()
{
        set("short", "怪树林");
        set("long", @LONG
这里是一片奇怪的树林，林木并不是非常的密集，白天的阳光依旧透过林木照
耀进来，然而你明显的感觉到一种阴冷的接近死亡的气息。林间没有任何可以辨认
的道路，走到这里已经是树林的尽头，峭壁陡立，再也没有出路。
LONG
        );
	set("item_desc", ([
		"stone" : (: stone :),
		"山石" : (: stone :),
		"峭壁" : (: stone :),
	]));
	
	set("exits", ([ /* sizeof() == 4 */
	  	 "west" : __DIR__"path1",	
   ]));
   
	set("outdoors","qingping");
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){

    add_action("do_push", "push");
}

string stone(){
	object me;
	me = this_player();
	if(me->query("class") == "shenshui"){
		tell_object(me, "峭壁上布满了各式各样的山石，其中一块你可以推。（ｐｕｓｈ）\n");
	} else {
		tell_object(me, "峭壁上布满了各式各样的山石。\n");
	}
	return "";
}

int do_push(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "stone" && arg != "山石" && arg!="峭壁")){
		return notify_fail("你要触摸什么？\n");
	}
	if(me->query("class") == "shenshui"){
		tell_object(me, "你伸手在山石上运力一推。\n");
		tell_object(me, CYN"山石上裂开了一道逢，你闪身进去。山石又在你身后合拢。\n\n"NOR);
		message("vision", YEL"你隐约看到" + me->name()+"的身影在石壁旁一闪就消失不见了。\n"NOR, 
				environment(me), me);
		room = find_object(AREA_SHENSHUI"huoyan");
		if(!objectp(room)){
			room = load_object(AREA_SHENSHUI"huoyan");
		}
		me->move(room);
	} else {
		tell_object(me, "你左推右推也不得法，山石纹丝不动。\n");
	}
	return 1;
}

