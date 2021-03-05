 
#include <ansi.h>
inherit NPC;
int answer();
int do_leave();
void create()
{
	set_name("青青", ({ "qing qing", "qing" }) );
	set("gender", "女性" );
	set("age", 18);
	
	set("long", @LONG
青青穿着一身淡青色的衣服，就像是春天晴朗的天空，晴空下清澈的湖 
水，湖水中倒映着的远山，美得神秘而朦胧。青青的腰纤细而柔软，就 
像是春风中的杨柳。青青的弯刀是用纯银作刀鞘，刀柄上镶着一粒光泽 
圆润的明珠。青青的眼波比珠光更美丽，更温柔。 
LONG
);

	set("inquiry",([
	"wandao" : (: answer :),
        "圆月弯刀" : (: answer :),
        "弯刀" : (: answer :),
    ]) );
/*    set("chat_chance", 1);
	set("chat_msg", ({
		(: random_move :),
	})); */
        set("combat_exp", 1000000);
	set("attitude", "friendly");
	set("finish", 0);
	set_skill("move", 200);
	set_skill("parry", 250);
	set_skill("blade", 250);
	set_skill("dodge", 250);
	set_skill("moon-blade", 80);
	map_skill("blade", "moon-blade");
	set("reset", 1);
	set("arrive_msg", "有一阵风吹过来，风中仿佛有个影子。一条淡淡的影子，带着种淡淡的香气。\n");
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "青衫",
			"long": "淡青色的衣服。\n" ])
		)->wear();
	carry_object(__DIR__"obj/basket")->wield();
	carry_object(__DIR__"obj/wandao");
}

void init(){
	::init();
	if(environment(this_object())->query("short") == "玉女峰") {
		remove_call_out("do_leave");	
		call_out("do_leave", 120);
	}
}

int answer(){
	object /*stone,*/ me;
	
	me = this_player();
	message_vision("$N看着$n，浅浅地笑了：“你也用刀？”\n", this_object(), me);
	if(environment(this_object())->query("short") == "玉女峰") {
		message_vision("\n$N忽然又转过头，若有所思地看着绝壁远方的一块青石。\n", this_object());
		message_vision("$N有点遗憾地自语：“忘忧草的叶子每年只长一次，每次只有三片，如果你来 
得迟些，它的叶子就要枯萎了。” \n", this_object());
		environment(this_object())->wang_you();
	}
	return 1;
}

int xiaolou(object me){
	object obj, petal;
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	}
	obj = present("eagle man", environment(this_object()));
	message_vision("\n$N阴森森的道：“拿来！小楼一夜听春雨。”\n", obj);
	message_vision("\n$N的脸色变了，忽然抛下了手里的花蓝，握住了那柄弯刀的刀柄。\n",
			this_object()); 
	petal = new(__DIR__"obj/petal");
	petal->move(environment(this_object()));
	if(obj) {
		obj->wf(me);
	} else {
		environment(this_object())->do_leavee();
		environment(this_object())->do_leave();
	}
}

int do_killeagle(object me){
	object obj;
	
	message("vision", HIW"\n就在这时候，青青使出了她的刀。刀光飞起时，" 
+ me->name() + HIW"的眼睛已将要合起。\n"NOR, environment(me), me);	
	tell_object(me, HIC"\n似乎看见青青手里刀光一闪，黑暗中忽然有了光，月光，圆月。\n"NOR); 
	me->unconcious();
	obj = present("eagle man", environment(this_object()));
	message_vision("只见刀光没入$N的胸前。\n", obj);
	obj->die();
	call_out("check_wake", 5, me);
	return 1;
}

void check_wake(object me){
	object blade;
	
	if(environment(me) != environment(this_object())){
		set("finish", 1);
		do_leave();
	}
	if(me->query_temp("is_unconcious")){
		remove_call_out("check_wake");
		call_out("check_wake", 3, me);
	} else {
		tell_object(me, "\n你睁开眼，就看见一轮冰盘般的圆月，也看见了青青那双比月光更美的眼睛。\n"); 
		tell_object(me, "无论是在天上还是在地下，都不会有第二双这么美丽的眼睛。\n");
		message_vision("$N守在$n身旁，眼睛里还闪着泪光。\n", this_object(), me);
		message_vision("\n$N纤手拂过面颊，脸色慢慢变了，连身子都已开始颤抖，忽然道：“我真的在流泪？”\n", 
				this_object());
		message_vision("$N脸色变得更奇怪，仿佛变得说不出的害怕。$P慢慢地从腰间解下那柄弯弯的刀，\n"
+ "放在$n怀里。\n", this_object(), me);
		set("finish", 1);
		if(blade = present("moonblade", this_object())){
			blade->move(me);
		}

		blade = present("wang you",me);
		if (blade && REWARD_D->riddle_check(me,"听琴毛女洞") == 3)
		{
			destruct(blade);
			REWARD_D->riddle_done(me,"圆月弯刀",10);
			REWARD_D->riddle_set(me,"听琴毛女洞",4);
			blade=new(__DIR__"obj/grass");
			blade->move(me);
			blade->set("owner",me);
		}

		do_leave();
	}
}

int do_leave(){
//	message_vision("hehe\n", this_object());	
	if(find_call_out("check_wake") == 1) {
		call_out("do_leave", 20);
		return 1;
	}
//	message_vision("ha\n", this_object());
	if(this_object()->query("finish")) {
		message_vision("\n$P慢慢地向后退去，消失在夜幕中。\n", this_object());
		message_vision("轻轻的叹息声从幽远的山谷传来，如同幽静的夜里幽远的风。。。 \n", this_object());
		destruct(this_object());
	} else {
		message_vision("$N身影一纵，犹如蜻蜓点水在青石上略一停顿就没入了黑暗之中。\n", this_object());
		destruct(this_object());
	}
	return 1;
 
}
int die(){
	object obj;
	if(present("eagle man", environment(this_object()))){
		environment(this_object())->leavee();
	}
	message_vision("只见一股青烟升起，$N已然失去了踪影。\n", this_object());
	obj = new(__DIR__"obj/basket");
	obj->move(environment(this_object()));
	destruct(this_object());
	return 1;	
}