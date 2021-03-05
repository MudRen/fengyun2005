 
#include <ansi.h>
inherit NPC;
void do_leave(object me);
void create()
{
	set_name("发鬃零乱的少女", ({ "girl", "fang girl" }) );
	set("gender", "女性" );
	set("age", 18);
	
	set("long", @LONG
她虽然发鬃零乱，衣着不整，但两道黑白分明，秋水为神的眼光，却让人为之沉迷。
LONG
);
	set("fall_down", 0);
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "淡黄衫",
			"long": "淡黄色的衣服上已被刮破了几个洞。\n" ])
		)->wear();
}

void init(){
	::init();
	add_action("do_getup", "getup");
}

void do_leave(object me){
	object yu, fang;
	
	if(!yu = present("yu yifei", environment(this_object()))) {
		message_vision("$N站起身来，纵身往树林中跑去。\n", this_object());
	} else if(!interactive(me) || environment(me) != environment(this_object())) {
		message_vision("$N站起身来，纵身往树林中跑去。\n", this_object());
	} else {
	message_vision("少女站起身来，两道黑白分明，秋水为神的眼光在$N和$n脸上一扫，
纵身往树林中跑去。$n也急急地跟了过去。\n", me, yu);
	}
	destruct(yu);
	destruct(this_object());
}

int fall(object me){
	message_vision(HIY"\n只见一个少女飞奔而来，$N一个躲闪不及被撞倒在地。\n"NOR, me);
	tell_object(me, "\n你感觉到压在身上的是一个极柔软而温暖的身躯，而且刚好与你面对着面，\n");
	tell_object(me, "娇喘依依，都吹在你脸上。（ｇｅｔｕｐ）\n");
	set("fall_down", 1);
	call_out("self_get_up", 20, me);
}

int do_getup(){
	object me, yu;
	me = this_player();
	if(!query("fall_down")) {
		return 0;
	}
	if (me!= query("target"))	return 0;
	remove_call_out("self_get_up");
	message_vision("$N站起身来，伸手扶起$n。\n", me, this_object());
	message_vision("\n$N鬓发凌乱，衣衫不整，丰满的胸膛急剧地起伏着，哀声对$n道：“救救我！”\n", 
			this_object(), me);
	tell_object(me, "你想起方才的情景，脸上又是一热，不由得心猿意马。\n"); 
	message_vision(WHT"\n$N话音未落，只见一道白影掠过，$N的身影已然消失不见。\n"NOR,this_object());
	REWARD_D->riddle_set(me,"华山救美",1);
	me->set("marks/初见方少璧", 1);
	if(yu = present("yu yifei", environment(this_object()))) {
		message_vision("只听$N道：“江里白龙。。”话音未落人也不见了。\n", yu);
		destruct(yu);
	}	
	destruct(this_object());
	return 1;
}

void self_get_up(object me){
	object fang;

	do_leave(me);
	set("fall_down", 0);
	return;
}
