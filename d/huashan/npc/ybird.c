#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("小黄雀", ({ "yellow bird", "bird" }) );
    	set("race", "飞禽");
    	set("age", 1);
    	set("gender", "雄性");
    	set("long", "这是一只小黄雀，原本美丽的羽毛凌乱不堪。
你可以轻易的抓住它（ｃａｔｃｈ）。\n");
    	set("attitude","peaceful");
    
//    set("unique_amount", 1);  
//    ITEM_D->setup_unique(this_object());  
    	set("eff_kee", 1);
		set("weight", 200);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
    	setup();
}


int kill_ob(object me){   
    	message_vision("$N抽搐了几下，就静止不动了。 \n",this_object());
    	me->set("marks/残忍", 1);
    	::die();
    	return 1;
}


void init() {
    	::init();
	if (this_player() == environment()) {
		add_action("do_release", "release");
	}
	add_action("do_catch", "catch");
   	call_out("not_cured", 60);
}

void not_cured(){
//    if(!userp(environment(this_object()))){
	if(query("eff_kee") == 1){
	   	message_vision("$N抽搐了几下，就一动不动了。 \n",this_object());
   		set("long", "这是一只小黄雀，原本美丽的羽毛凌乱不堪。\n");
   		::die();
	}
}

void Cured(object bird){
    	set("long", "这是一只小黄雀，脖子上有一圈桔黄色，犹如点漆似的眼睛正在上下的打量你。
你可以试着把它放了（ ｒｅｌｅａｓｅ　ｂｉｒｄ）。\n");  
    	set("rescue_time", time());
}

int do_catch(string arg) {
	object me, bird, ob;
	
	me = this_player();
	bird = present("yellow bird", environment(me));
	if(!arg || (arg != "yellow bird" && arg != "bird")) {
		return 0;
	}
	if(!present("yellow bird", environment(me))){
		return 0;
	}

	if (present("yellow bird", me)) {
		tell_object(me,"抓这么多鸟藏在身上干吗？\n");
		return 1;
	}
		
	message_vision("\n$N小心地伸出手，轻轻的把$n捧了起来。\n$n的羽毛微微颤动着，静静地躺在$N的手心。\n", me, bird);
	bird->move(me);
	return 1;
}


int do_release(string arg) {
	object me;
	int i;
	
	me = this_player();
    i = query("rescue_time");	
	if (!arg || (arg != "bird" && arg != "yellow bird")) {
		return 0;
	}
	
	if(!environment(me)->query("outdoors")) {
	    return notify_fail("要放小鸟还是去室外吧。\n");
	}
    
    if (!i)
    	return notify_fail("小黄雀努力地扇了扇翅膀，怎么也飞不起来。\n");
    	
    if(time() - i > 1440) { // useless check, 99% true when i=0, :P
		message_vision("$N把$n捧在手中，$n振翅高飞，在$N头顶盘旋了三圈，\n然后恋恋不舍地穿云而去。\n"
		        , me, this_object());
	
		if (!REWARD_D->check_m_success( me, "黄雀传奇"))
			REWARD_D->riddle_set( me, "黄雀传奇", 10, 1);
		destruct(this_object());	
		return 1;
	} else {
	    	message_vision("$N把$n捧在手中，$n抖了抖翅膀，没能飞起来，被伤到的羽毛似乎还没有长好。\n", me, this_object());
		return 1;
	}	
	return 1;
}

     
