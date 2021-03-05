#include <ansi.h>

inherit NPC;
void create()
{
    	set_name("绿毛小乌龟", ({ "green turtle", "turtle" }) );
    	set("race", "野兽");
    	set("age", 1);
    	set("gender", "雄性");
    	set("long", "
这是一只巴掌大小的乌龟，壳上长满细细长长的绿毛，看起来就象个小绿球。 
它不时伸头看看，一双小圆眼睛很灵动，似乎充满了灵性，可爱的让你想抓
住它。（ｃａｔｃｈ）\n");
    	set("attitude","peaceful");
    	set("chat_msg", ({
			"绿毛小乌龟伸头不停往四周看，好象急切地寻找什么... ... 它是不是想家了？\n",
		}) );
		set("chat_chance", 1);
		set("weight", 3000);
		set("no_drop", 1);
		set("no_get", 1);
    	setup();
}


int kill_ob(object me)
{
    	message_vision("$N的头脚缩了回去，象个小绿球，咕噜噜滚到草丛中不见了。 \n",this_object());
    	me->set("marks/残忍", 1);
    	destruct(this_object());
    	return 1;
}

void init() {
	if (this_player() == environment()) {
		add_action("do_release", "release");
	}
	add_action("do_catch", "catch");
}

int query_autoload() { 
	return 1; 
}

int do_catch(string arg) {
	object me, turtle;
	
	me = this_player();
	turtle = present("green turtle", environment(me));
	if(!arg || (arg != "green turtle" && arg != "turtle")) {
		return 0;
	}
	if(!present("green turtle", environment(me))){
		return 0;
	}
	if (turtle->query("turtle_owner")!=me)
	{
		message_vision("$N的头脚缩了回去，象个小绿球，咕噜噜滚到草丛中不见了。 \n",this_object());
    		destruct(this_object());
    		return 1;
	}    
	message_vision(HIG"$N小心地伸出手，把$n捉了起来。$n把头缩进壳里，\n"NOR, me, turtle);
	message_vision(HIG"一双小眼睛紧张地往外看。\n"NOR, me); 
	if (turtle->move(me))
		set("long", "
这是一只巴掌大小的乌龟，壳上长满细细长长的绿毛，远远一看就像一块
晶莹的小"HIG"翡翠"NOR"，它不时伸头看看，一双小圆眼睛很灵动，似乎充满了灵性，
又可爱又可怜，也许你可以找个什么地方放了它（release）\n");
	return 1;
}


int do_release(string arg) {
	object me;
	
	me = this_player();

	if (!arg || (arg != "turtle" && arg != "green turtle")) {
		tell_object(me,"你想ｒｅｌｅａｓｅ什么？\n");
		return 1;
	}
	if(environment(me)->release_turtle(this_object())) {
		tell_object(me, "你在翡翠池边摊开手，轻轻地把绿毛小乌龟放了下来。\n");
		tell_object(me, "绿毛小乌龟兴奋地从你手上爬下，又回头看了你一眼，转身游进翡翠池。\n", this_object(), me); 
		message("vision", me->name() + "在翡翠池边轻轻的把一个绿毛小乌龟放下。\n", environment(me), me);
		destruct(this_object());	
		return 1;
	} else {
		tell_object(me, "绿毛小乌龟胆怯地探头看看周围环境，不肯离开你。\n");
		message("vision","绿毛小乌龟从"+ me->name() + "怀中胆怯地探头看看周围，不肯离开" 
				+ me ->name() + "。\n", environment(me), me); 
		return 1;
	}	
	return 1;
}

     
