#include <ansi.h>
inherit ROOM;
void do_leave();
int poison();
void create()
{
        set("short", "玉女峰");
        set("long", @LONG
一路行来风景秀丽，峰上更是林木茂密，环境清幽。巨石边，小溪侧奇花异草
多不知名。绝崖边沿长有一棵松树，树干光洁，树身乘半凌空远出崖外，成舍身扑
崖之势。密林中一角飞檐探出树梢，似空中的巨鹰，透过林间缝隙，可以看到一座
小院坐落林中。
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"canglong",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-58);
	set("coor/z",37);
	setup();
}

void init(){
	object me;
	
	me = this_player();
	if((int)me->query_condition("music") > 0 ) {
		call_out("music_npc", 1, me);
	}
	add_action("do_slide", "slide");
}

int music_npc(object me){
	object obj;
	
	if(!interactive(me) || environment(me) != this_object()){
		return 0;
	}
	if(present("zhen zhen", this_object()) || present("qing qing", this_object())) {
		return 0;
	}

	me->change_condition_duration("music",0);
	
	if (REWARD_D->riddle_check(me,"听琴毛女洞") == 3)
	{
		message_vision(HIY"\n就在这时候，忽然有一阵风吹过来，风中仿佛有个淡淡的影子。\n"NOR, me);
		obj = new(__DIR__"npc/qing");
		obj->delete("chat_msg");
		poison();

	}
	else if (REWARD_D->riddle_check(me,"听琴毛女洞") == 4 
		|| REWARD_D->riddle_check(me,"听琴毛女洞") == 5 
		|| REWARD_D->check_m_success(me,"听琴毛女洞"))
	{
		message_vision(HIG"琴声戛然而止。黑暗中，似乎有人叹了一口气。\n"NOR, me);
		obj = new(__DIR__"npc/zhenzhen");
	}
	if(objectp(obj))
		obj->move(this_object());
	return 1;

}

int poison(){
	object *inv, *players/*, me*/;
	int i;
	inv = all_inventory();
    players = filter_array(inv, (: interactive($1) :));
	for(i=0; i<sizeof(players); i++) {
		if(players[i]->query_condition("music") > 0) {
			players[i]->clear_condition("music");
		} else {
			players[i]->apply_condition("rose_poison", random(10));
    		tell_object(players[i], "空气中浮着一种淡淡的香气。\n");
    	}
    }   	
}

void go_cliff(object ob){
	object room;
	
	tell_object(ob, YEL"\n你惊讶地走到绝壁傍边。突然，耳边传来一声轻笑，一只手 
把你一拉，竟然把你拉进石壁。\n"NOR);
	message("vision", ob->name() + "身影一晃，竟然从绝壁边消失了。\n", environment(ob), ob);
	room = find_object(__DIR__"cave1");
	if(!objectp(room)) {
		room = load_object(__DIR__"cave1");
	}	
	ob->move(room);
}

int do_slide(string arg){
	object me, room;
	
	me = this_player();
	if(!me->query("marks/华山密洞")) {
		return 0;
	}
	if(!arg || arg != "rock") {
		return notify_fail("你要推开什么？\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("你正在忙。\n");
	}
	tell_object(me, "你伸手在石壁上推了一下，闪身进入了密洞。\n");
	message("vision", me->name() + "的身影在崖边一闪就消失不见了。\n", environment(me), me);
	room = find_object(__DIR__"cave1");
	if(!objectp(room)) {
		room = load_object(__DIR__"cave1");
	}
	me->move(room);
	message("vision", "石壁突然被推开一条缝，" + me->name() + "闪身走了进来。\n", 
			environment(me), me);
	return 1;	
}

void do_leave(){
	object obj, obj2;
	obj = present("hua zhenzhen", this_object());
	obj2 = present("qing qing", this_object());
	if(obj) {	
		message_vision("黑暗中，$N悠悠叹了一口气，身影一闪，消失在夜幕中。\n", obj);
		destruct(obj);
	}
	if(obj2) {	
		message_vision("黑暗中，$N悠悠叹了一口气，身影一闪，消失在夜幕中。\n", obj2);
		destruct(obj2);
	}	
}

void do_leavee(){
	object obj;
	obj = present("eagle man", this_object());
	if(obj) {
		message_vision("$N身形一展，犹如一只大鹏鸟消失在无边的黑夜中。\n", obj);
		destruct(obj);
	}
}

void do_leaveq(){
	object obj;
	obj = present("qing qing", this_object());
	if(obj) {
		message_vision("$N幽幽看了$n一眼，一言不发，转身消失在黑暗中。 。\n", obj, this_player());
		destruct(obj);
	}
}	

void wang_you(){
	object stone;
	if(!present("qing shi", this_object()))
	{
		stone = new(__DIR__"obj/stone");
		stone->move(this_object());
	}	
	add_action("do_climb", "climb");
}

int do_climb(string arg){
	object me, qing, stone;
	int i;
	me = this_player();
	i = me->query_temp("marks/qingshi_fall");

	if (REWARD_D->riddle_check(me,"听琴毛女洞") != 3)
		return 0;

	if(!arg || (arg != "stone" && arg != "青石" && arg != "qing shi"
				&& arg != "rock" && arg != "石")) {
		return notify_fail("你要爬什么？\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("你正在忙。\n");
	}
	if(!random(8) 
		&& me->query_skill("move",1)>=150){
		stone = find_object(__DIR__"qingshi");
		message_vision("$N终于爬上了光光的岩石。\n", me);
		if(!objectp(stone)) {
			stone = load_object(__DIR__"qingshi");
		}
		me->move(stone);
	} else {
		message_vision("光滑如镜的岩石上滑不溜手，$N跌了下来。\n", me);
		if (me->query_skill("move",1)< 150)	
			tell_object(me,"（还是跟师傅去多学点轻功吧）\n");
		me->receive_wound("kee", random(20));
		me->receive_wound("gin", random(20));
		me->receive_wound("sen", random(20));
		me->set_temp("last_damage_from","在华山陡崖摔死了。\n");
		me->set_temp("marks/qingshi_fall", i+1);
	}
	if(i == 4) {
		message_vision("\n$N一次又一次的往青石上爬，$N一次又一次的摔了下来，全身都跌得发青。\n", me);
		if(qing = present("qing qing", this_object())){
			message_vision("\n$N悠悠站在旁边上，看着$n一次次跌下去，既没有去拉一把，也没有来拉的意思。\n", qing, me);
		}	
	}	 
	return 1;
}

int eagle_come(object me){
	object obj;
	if(!interactive(me) || environment(me) != this_object()) {
		do_leave();
		return 0;
	}
	if(!present("eagle man", this_object())){
		message_vision("\n忽然，一个身影如大鹰一般飘落而下。就像是一片叶子轻飘飘地落在岩石上，
凡人是不会有这么轻妙的身法的。\n", me);
		obj = new(__DIR__"npc/eagleman");
		obj->move(this_object());
		obj->wangyou(me);
	}
}