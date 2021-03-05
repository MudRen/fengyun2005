// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "九龙瀑");
        set("long", @LONG
峰回路转，眼前景色又是一变，一道瀑水自天都，峰玉屏诸峰，然后在香炉，
罗汉两峰的悬崖九折而下，一折一潭，九瀑九潭，因此得名。每逢大雨之后，瀑水
从天而降，流而复折，折而复聚，悬于千仞绝壁，宛如九龙飞舞，姿态曼妙。
LONG
        );
        set("exits", ([ 
		  "southdown" : __DIR__"mroad1",
  		"northwest" : __DIR__"zhulin",
		]));
    set("item_desc", ([
    	"绝壁": "这里虽然陡峭无比，但石壁突兀不平，你可以试着从这爬上去。\n",
    	"cliff": "这里虽然陡峭无比，但石壁突兀不平，你可以试着从这爬上去。\n",
    ]) );
    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",20);
	setup();
}


void init(){
	add_action("do_climb","climb");
}


int do_climb(string arg){
	object me;
	me= this_player();
	if(!arg || (arg != "cliff" && arg!="up" && arg!="绝壁")){
		return 0;
	}	
	if (me->query_temp("jiulong_climb")) {
		tell_object(me,"你已经在试着爬了。\n");
		return 1;
	}
	message_vision("$N抓住绝壁上突出的石块，向上小心爬去！\n", me);
	me->start_busy(2);
	call_out("arrive", 2, me);
	me->set_temp("jiulong_climb",1);
	return 1;
}



int arrive(object me){
	int i;
	object room;
	if (!me)	return 1;
	if (me->is_ghost())	return 1;
	i = me->query_skill("move",1);
	me->delete_temp("jiulong_climb");
	
	if(i < 100) {
		message_vision("$N腿肚子发软，抖抖索索怎么也爬不上去。\n",me);
		return 1;
	} else if(random (5)){
		message_vision("$N一失手，从上面掉了下来！\n",me);
		me->receive_wound("kee",100);
		me->set_temp("last_damage_from","爬山摔死了。\n");
	} else if  (me->query("cps")< 32) {		// 150 chanting + 2 ability if you don't distribute and w/o master
		tell_object(me, "慢慢地，你到了半山腰，
"WHT"身畔白雾缭绕，耳边猿啼声声，望着陡峭的石壁，你不禁胆怯起来。\n"NOR);
		tell_object(me,"（再往上爬需要实际定力32点）\n");
		message_vision("$N垂头丧气地又爬了下来。\n", me);	
	} else if (me->query("kar")< 34) {
		tell_object(me, WHT"越往上，山势越是险峻，几乎已没有落脚之地，
爬呀爬，眼看就要到顶了，

忽然，你手中攀住的岩石一松，竟然向下滚去！

你胡乱地向空中乱抓，运气太差，什么都没抓住。\n\n"NOR);
		message_vision("$N从山崖上一个倒栽葱掉了下来。\n",me);
		tell_object(me,"（再往上爬需要实际运气34点）\n");
		return 1;	
	} else {
		room=find_object(AREA_HUANGSHAN"pond");
		if(!objectp(room)) 
        	room = load_object(AREA_HUANGSHAN"pond"); 
		me->move(room);
		message_vision("$N慢慢地爬了上来。\n",me);
	}	
	return 1;
}
